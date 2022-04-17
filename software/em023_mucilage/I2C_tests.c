/* these test were created to show how to use the opencores I2C along with a driver found in
 * the I2C_opencores component to talk to various components. 
 * This test example uses a littel daughter board from microtronix
 * it has a I2c to parallel chip (PCA9554A) a EEPORM and real time clock. 
 * I chose not to impliment the real time clock. 
 * But you can see how the calls work
 * There are only 4 functions associalted with the I2C driver
 * I2C start  -  send start bit and address of the chip
 * I2C_read - read data
 * I2C_write. - write data
 * how and when each of these get used is based on the device you
 * are talking to. 
 * See the driver code for details of each function. 
 * */
#include <stdio.h>
#include "system.h"
#include "terasic_includes.h"
#include "water_sensor.h"

#define NUMBYTESSIZE 16
#define WRITE 0
#define READ 1



int main() {
	int data;
	uint8_t i;
	volatile alt_u16 timeout;
	bool exitloop = false;
	volatile alt_u8 tempError;
	uint8_t numbytes;
	uint8_t Slave_Rx_Buffer[200] = {0};
	uint8_t Slave_Rx_Index = 0;
	char    tempChar = 0;

	volatile	alt_u8 initialcycle = 1;
	volatile	alt_u32 I2CA_BASE = WATER_I2C_OPENCORES_BASE;

	Water_I2C_init(I2CA_BASE, ALT_CPU_FREQ, 100000);
	printf(" CODE IS STARTED IN I2C_TEST.C \n");
	usleep(100);
	if (initialcycle) {
		numbytes = 0;
		myI2CReadWrite(READ, BYTES_TO_READ, (uint8_t *)&numbytes,1);
		while (numbytes > 0) {
			//myI2CReadWrite(READ, BYTES_TO, (uint8_t*)&Slave_Rx_Buffer[0], (alt_u16)numbytes);
			i = 0;
			Water_I2C_start(I2CA_BASE,0x4Cu,0);
			Water_I2C_write(I2CA_BASE,BYTES_TO,1);
			Water_I2C_start(I2CA_BASE,0x4Cu,1);
			while (i <numbytes){
				Slave_Rx_Buffer[i]= Water_I2C_read(BYTES_TO,numbytes);
				printf("\n%d",Slave_Rx_Buffer[i]);
				i=i+1;
			}

			usleep(100);
			while (Slave_Rx_Index < numbytes) {
				tempChar = Slave_Rx_Buffer[Slave_Rx_Index];
				Slave_Rx_Buffer[Slave_Rx_Index] = '\0';
				if (tempChar != '~' && tempChar != '\0') {
					printf((const char *)&tempChar);
				}
				if(Slave_Rx_Index<numbytes){
					Slave_Rx_Index= Slave_Rx_Index+1;
				}
			}
			myI2CReadWrite(READ, BYTES_TO_READ, (alt_u8 *)&numbytes, 1);
			usleep(100);
		}
		initialcycle=0;
	}
	timeout = 600;
	exitloop = false;

	do{
		usleep(2000);
		numbytes =0;
		myI2CReadWrite(READ, BYTES_TO_READ, (alt_u8 *)&numbytes, 1); //numbytes can be 0 to 255, but there can be more than 255 bytes in slave buffer
		usleep(50);

		while (numbytes > 0) { //data available
			tempError = myI2CReadWrite(READ, BYTES_TO, &Slave_Rx_Buffer[0], numbytes);
			printf("temperror = %d" , tempError);
			if (tempError != 0) {
				printf("Error reading from sensor");
			}
			usleep(100);

			for (Slave_Rx_Index = 0; Slave_Rx_Index < numbytes; Slave_Rx_Index++) {
				tempChar = Slave_Rx_Buffer[Slave_Rx_Index];
				Slave_Rx_Buffer[Slave_Rx_Index] = '\0'; //clean buffer
				if (tempChar == '~') {
					exitloop = true;
				}
				else { //end message character received
					printf((const char *)&tempChar);
				}
			}
			myI2CReadWrite(READ, BYTES_TO_READ, (alt_u8 *)&numbytes,1);

			usleep(50);
		}// end data available while loop

		usleep(10);
		timeout--;

	}while (timeout > 0 && !exitloop);
	if (timeout == 0) {
		printf("Slave timeout.");
	}
	usleep(100);

}






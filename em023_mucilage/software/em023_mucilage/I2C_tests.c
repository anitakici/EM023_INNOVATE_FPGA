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
#include "shared_mem_def.h"

#define NUMBYTESSIZE 16
#define WRITE 0
#define READ 1

#define READ_COMMUNICATION_REGISTER IORD(NIOS_SYSTEM_SHARED_MEMORY_BASE, 1)
#define SEND_ACK_COMMUNICATION_REGISTER IOWR(NIOS_SYSTEM_SHARED_MEMORY_BASE, 1, 0)
#define SEND_STATUS_REGISTER(x) IOWR(NIOS_SYSTEM_SHARED_MEMORY_BASE, 0, (x))

int main() {
	alt_u16 timeout=0;
	bool exitloop = false;
	uint8_t tempError;
	uint8_t numbytes;
	uint8_t Slave_Rx_Buffer[200] = {0};
	uint8_t Slave_Rx_Index = 0;
	char    tempChar = 0;
	alt_u32 I2CA_BASE = WATER_I2C_OPENCORES_BASE;

	Water_I2C_init(I2CA_BASE, ALT_CPU_FREQ, 100000);

	//	myI2CReadWrite(WRITE, BYTES_TO, (alt_u8 *)&numbytes, 1);
	timeout = 600;
	exitloop = false;

	usleep(185000);
	numbytes =0;
	myI2CReadWrite(READ, BYTES_TO_READ, (alt_u8 *)&numbytes, 1); //numbytes can be 0 to 255, but there can be more than 255 bytes in slave buffer
	usleep(5000);
	/*
		while (numbytes > 0) { //data available
			tempError = myI2CReadWrite(READ, BYTES_TO, &Slave_Rx_Buffer[0], numbytes);
			if (tempError != 0) {
				printf("Error reading from sensor");
			}
			usleep(10000);

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
	//		Slave_Rx_Index =Slave_Rx_Index+1;
			Slave_Rx_Buffer[Slave_Rx_Index] = '\0';
	//		myI2CReadWrite(READ, BYTES_TO_READ, (alt_u8 *)&numbytes,1);
			numbytes=0;
			usleep(5000);
		}// end data available while loop
	 */

int loop_cnt = 0;
	while(1){
		SEND_STATUS_REGISTER(loop_cnt|0x80000000);
		  		//Mode select
		  		unsigned com_reg = READ_COMMUNICATION_REGISTER;
				if ( (com_reg&0xffff0000)== 0xaaaa0000 ) {
					SEND_ACK_COMMUNICATION_REGISTER; // Send ACK
					switch (com_reg&0xffff) {
					case 1:
						//g_clear_OOR_flag = false;
						break;
					case 2:
						//g_clear_OOR_flag = true;
						break;
					default :
						break;
					}
				}
		unsigned offst;
		float pH= 20;
		float phosphorus = 1;
		float nitrogen = 5;
		offst = PH_SENSOR_VALUE >> 2;
		IOWR(NIOS_SYSTEM_SHARED_MEMORY_BASE, offst, pH);
		offst = PHOSPHORUS_SENSOR_VALUE >> 2;
		IOWR(NIOS_SYSTEM_SHARED_MEMORY_BASE, offst, phosphorus);
		offst = NITROGEN_SENSOR_VALUE >> 2;
		IOWR(NIOS_SYSTEM_SHARED_MEMORY_BASE, offst, nitrogen);
		printf(".");
		usleep(1000);
		loop_cnt++;
	}
}






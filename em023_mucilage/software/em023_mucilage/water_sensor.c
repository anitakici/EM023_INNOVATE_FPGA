#include "terasic_includes.h"
#include "alt_types.h"
#include "i2c_opencores_regs.h"
#include "water_sensor.h"
#include "I2C_core.h"

#define I2C_DEBUG
#define WATER_ADDR 0x4C
#define sensor_address 0x0A

#define I2CA_BASE_1 0x41100




/* these functions are polled only.  */
/* all functions wait until the I2C is done before exiting */

/****************************************************************
 int I2C_init
 This function initializes the prescalor for the scl
 and then enables the core. This must be run before
 any other i2c code is executed
 inputs
 base = the base address of the component
 clk = freuqency of the clock driving this component  ( in Hz)
 speed = SCL speed ie 100K, 400K ...            (in Hz)
 15-OCT-07 initial release
 *****************************************************************/
void Water_I2C_init(alt_u32 base, alt_u32 clk, alt_u32 speed) {
	alt_u32 prescale = (clk / (5 * speed)) - 1;
#ifdef  I2C_DEBUG
	printf(
			" Initializing  I2C at 0x%x, \n\twith clock speed 0x%x \n\tand SCL speed 0x%x \n\tand prescale 0x%x\n",
			base, clk, speed, prescale);
#endif
	IOWR_I2C_OPENCORES_CTR(base, 0x00); /* turn off the core*/

	IOWR_I2C_OPENCORES_CR(base, I2C_OPENCORES_CR_IACK_MSK); /* clear any penning IRQ*/

	IOWR_I2C_OPENCORES_PRERLO(base, (0xff & prescale)); /* load low prescale bit*/

	IOWR_I2C_OPENCORES_PRERHI(base, (0xff & (prescale >> 8))); /* load upper prescale bit */

	IOWR_I2C_OPENCORES_CTR(base, I2C_OPENCORES_CTR_EN_MSK); /* turn on the core*/


	// reset
	oc_i2c_init_ex(I2CA_BASE_1, clk, speed);

}
/**
	   @brief  reads or writes data to/from the gas sensor

	   @param  void

	   @return returns result of I2C communication

	   @details
 */
uint8_t myI2CReadWrite(alt_u8 RW, alt_u8 RegAddr, uint8_t *pdata, alt_u16 size) {
	uint8_t i=0;
	if (RW == 1) {
		//	i = RegAddr;
		Water_I2C_start(I2CA_BASE_1,0x4C,0);
		Water_I2C_write(I2CA_BASE_1,RegAddr,0);

		Water_I2C_start(I2CA_BASE_1,0x4C,1);
		for (i=0; i<size;){ //i = regaddr6
			pdata[i]= Water_I2C_read(I2CA_BASE_1,0);
			printf("\tanswer = 0x%x\n",pdata[i]);
			i=i+1;
		}
		pdata[i]= Water_I2C_read(I2CA_BASE_1,1);
		printf("\tres_last = 0x%x\n",pdata[i]);
	} else if (RW == 0) {

		Water_I2C_start(I2CA_BASE_1,0x4Cu,0);
		for (i = 0; i < size; i++){
			Water_I2C_write(I2CA_BASE_1,pdata[i],0);
		}
		Water_I2C_write(I2CA_BASE_1,pdata[i],1);  // write last one with last flag
		while (Water_I2C_start(I2CA_BASE_1,0x4Cu,0));
		i = 0;
	}
	return 0;
}

/****************************************************************
 int I2C_start
 Sets the start bit and then sends the first byte which
 is the address of the device + the write bit.
 inputs
 base = the base address of the component
 add = address of I2C device
 read =  1== read    0== write
 return value
 0 if address is acknowledged
 1 if address was not acknowledged0x50
 15-OCT-07 initial release
 *****************************************************************/
int Water_I2C_start(alt_u32 base, alt_u32 add, alt_u8 read) {
#ifdef  I2C_DEBUG
	printf(
			" Start  I2C at 0x%x, \n\twith address 0x%x \n\tand read 0x%x \n\tand prescale 0x%x\n",
			base, add, read);
#endif

	/* transmit the address shifted by one and the read/write bit*/
	IOWR_I2C_OPENCORES_TXR(base, ((add << 1) + (0x1 & read)));

	/* set start and write  bits which will start the transaction*/
	IOWR_I2C_OPENCORES_CR(base,
			I2C_OPENCORES_CR_STA_MSK | I2C_OPENCORES_CR_WR_MSK);

	/* wait for the transaction to be over.*/
	while ( IORD_I2C_OPENCORES_SR(base) & I2C_OPENCORES_SR_TIP_MSK)
		;

	/* now check to see if the address was acknowledged */
	if(IORD_I2C_OPENCORES_SR(base) & I2C_OPENCORES_SR_RXNACK_MSK)
	{
#ifdef  I2C_DEBUG
		printf("\tNOACK\n");
#endif
		return (I2C_NOACK);
	}
	else
	{
#ifdef  I2C_DEBUG
		printf("\tACK\n");
#endif
		return (I2C_ACK);
	}
}

/****************************************************************
 int I2C_read
 assumes that any addressing and start
 has already been done.
 reads one byte of data from the slave.  on the last read
 we don't acknowldge and set the stop bit.
 inputs
 base = the base address of the component
 last = on the last read there must not be a ack

 return value
 byte read back.
 15-OCT-07 initial release
 *****************************************************************/
alt_u32 Water_I2C_read(alt_u8 base, alt_u16 last) {
#ifdef  I2C_DEBUG
	printf(" Read I2C at 0x%x, \n\twith last0x%x\n", base, last);
#endif
	if (last) {
		/* start a read and no ack and stop bit*/
		IOWR_I2C_OPENCORES_CR(base,
				I2C_OPENCORES_CR_RD_MSK | I2C_OPENCORES_CR_NACK_MSK | I2C_OPENCORES_CR_STO_MSK);
	} else {
		/* start read*/
		IOWR_I2C_OPENCORES_CR(base, I2C_OPENCORES_CR_RD_MSK);
	}
	/* wait for the trnasaction to be over.*/
	while ( IORD_I2C_OPENCORES_SR(base) & I2C_OPENCORES_SR_TIP_MSK)
		;
	/* now read the data */
	return (IORD_I2C_OPENCORES_RXR(base));

}



/****************************************************************
 int I2C_write
 assumes that any addressing and start
 has already been done.
 writes one byte of data from the slave.  
 If last is set the stop bit set.
 inputs
 base = the base address of the component
 data = byte to write
 last = on the last read there must not be a ack

 return value
 0 if address is acknowledged
 1 if address was not acknowledged
 15-OCT-07 initial release
 *****************************************************************/
uint8_t Water_I2C_write(alt_u8 base, uint8_t data, alt_u16 last) {
#ifdef  I2C_DEBUG
	printf(" Read I2C at 0x%x, \n\twith data 0x%x,\n\twith last0x%x\n", base,
			data, last);
#endif
	/* transmit the data*/
	IOWR_I2C_OPENCORES_TXR(base, data);

	if (last) {
		/* start a read and no ack and stop bit*/
		IOWR_I2C_OPENCORES_CR(base,
				I2C_OPENCORES_CR_WR_MSK | I2C_OPENCORES_CR_STO_MSK);
	} else {
		/* start read*/
		IOWR_I2C_OPENCORES_CR(base, I2C_OPENCORES_CR_WR_MSK);
	}
	/* wait for the trnasaction to be over.*/
	while ( IORD_I2C_OPENCORES_SR(base) & I2C_OPENCORES_SR_TIP_MSK)
		;

	/* now check to see if the address was acknowledged */
	if(IORD_I2C_OPENCORES_SR(base) & I2C_OPENCORES_SR_RXNACK_MSK)
	{
#ifdef  I2C_DEBUG
		printf("\tNOACK\n");
#endif
		return (I2C_NOACK);
	}
	else
	{
#ifdef  I2C_DEBUG
		printf("\tACK\n");
#endif
		return (I2C_ACK);
	}

}


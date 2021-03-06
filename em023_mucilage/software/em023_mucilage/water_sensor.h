#ifndef WATER_SENSOR_H_
#define WATER_SENSOR_H_



#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void Water_I2C_init(alt_u32 base, alt_u32 clk, alt_u32 speed);

uint8_t myI2CReadWrite(alt_u8 RW, alt_u8 RegAddr, uint8_t *pdata, alt_u16 size);
int Water_I2C_start(alt_u32 base, alt_u32 add, alt_u8 read);

alt_u32 Water_I2C_read(alt_u8 base, alt_u16 last);
uint8_t Water_I2C_write(alt_u8 base, uint8_t data, alt_u16 last);

#define SENSOR_ERROR_NONE  0u
//Add water quality command for how many bytes to read from slave
#define BYTES_TO_READ 0x61
#define SET_I2C_ADDRESS	0x80
#define BYTES_TO 0x63
#define	GET_STATUS 0x02
#define I2C_OK (0)
#define I2C_ABITRATION_LOST (2)
#define I2C_ACK (0)
#define I2C_NOACK (1)
#define I2C_OPENCORES_INSTANCE(name, dev) extern int alt_no_storage
#define I2C_OPENCORES_INIT(name, dev) while (0)
/*! Sensor error types */

#define  SENSOR_ERROR_GPIO   3u        /*!< GPIO driver reported an error          */
#define  SENSOR_ERROR_I2C    4u        /*!< I2C driver reported an error           */
#define ADI_CFG_I2C_SENSOR1_ADDR 0x0Au
#define  SENSOR_ERROR_PH     14u       /*!< PH sensor reported an error            */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* WATER_SENSOR_H_ */


from package.sensor import *
from package.sensorcontroller import *

class AdcSensor(SensorController):
    def __init__(self,name='adc', real=False, offset=0x0) -> None:
        self.name = name
        self.modules = {
            'adc0'          : Sensor('adc0',            'int',real,       offset),
            'adc1'          : Sensor('adc1',            'int',real,       offset+0x8)
        }
        
        if(real) :
            logger.debug(" \n\
                    AdcSensors: \n\
                        ADC0: \n\
                            Data : {} \n\
                        ADC1: \n\
                            Data : {} \n"
                .format(
                    hex(self.modules.get('adc0').offset),
                    hex(self.modules.get('adc1').offset)
                )
            )
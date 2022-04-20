# Copyright (C) 2021 Intel Corporation
# Licensed under the MIT license. See LICENSE file in the project root for
# full license information
from tokenize import String
from package.utility import logger
from package.sensor import *
from package.sensorcontroller import *


class waterSensor(SensorController):
    def __init__(self, name='rfsSensors', real=False, offset=0x0) -> None:
        self.name = name
        self.modules = {
            'pH': Sensor("pH", 'float', real, offset + 0x4),
            'phosphorus': Sensor('phosphorus', 'float', real, offset + 0x4 * 2),
            'nitrogen': Sensor('nitrogen', 'float', real, offset + 0x4 * 3),
            'status': ""
        }

        if (real):
            logger.debug(" \n\
                    waterSensor: \n\
                        Phosphorus : \n\
                            Data : {} \n\
                        Nitrogen : \n\
                            Data : {} \n\
                        pH : \n\
                            Data : {} \n\
                        status : \n\
                            Data : {}"
                        
                .format(
                hex(self.modules.get('phosphorus').offset),
                hex(self.modules.get('nitrogen').offset),
                hex(self.modules.get('pH').offset),
                hex(self.modules.get("status"))

            )
            )


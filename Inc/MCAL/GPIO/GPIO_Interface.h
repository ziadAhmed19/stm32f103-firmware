/*
 * GPIO_Interface.h
 *
 *  Created on: Dec 13, 2025
 *      Author: ziad-ahmed
 */
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "GPIO_Config.h"


// FUNCTION PROTOTYPES

stm_err_t GPIO_INPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, INPUT_CNF eMode);
stm_err_t GPIO_OUTPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, OUTPUT_MODE eMode, OUTPUT_CNF eCnf);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */

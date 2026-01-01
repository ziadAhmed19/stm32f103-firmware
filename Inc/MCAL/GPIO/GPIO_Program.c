/*
 * GPIO_Program.c
 *
 *  Created on: Dec 13, 2025
 *      Author: ziad-ahmed
 *
 */
#include 	"GPIO_Interface.h"
#include 	"GPIO_Private.h"

/*
 * Step 1: Choose CRL or CRH and calculate bit position
 * Step 2: Clear the 4 bits MODE and CNF to this pin
 * Step 3: Set the Configuration
 */
stm_err_t GPIO_INPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, INPUT_CNF eCnf) {

	// Error Checking
    if (nPin > 15)
    	return STM_ERROR;

    volatile uint32_t* pConfigReg;
    volatile uint32_t* pODR_Reg;
    uint8_t nBitPos;
    // STEP 1
    if (nPin < 8) {
    	// Setting the POS
        nBitPos = nPin * 4;
        // Port Selection
        switch(ePort) {
            case PORTA:
            	pConfigReg 	= &GPIOA_CRL;
            	pODR_Reg	= &GPIOA_ODR;
            	break;

            case PORTB:
            	pConfigReg 	= &GPIOB_CRL;
            	pODR_Reg	= &GPIOB_ODR;
            	break;

            case PORTC:
            	pConfigReg 	= &GPIOC_CRL;
            	pODR_Reg	= &GPIOC_ODR;
            	break;

            default:
            	return STM_ERROR;
        }
    }

    else {
    	// Setting the POS
        nBitPos = (nPin - 8) * 4;
        // Port Selection
        switch(ePort) {
            case PORTA:
            	pConfigReg 	= &GPIOA_CRH;
            	pODR_Reg	= &GPIOA_ODR;
            	break;

            case PORTB:
            	pConfigReg 	= &GPIOB_CRH;
            	pODR_Reg	= &GPIOB_ODR;
            	break;

            case PORTC:
            	pConfigReg 	= &GPIOC_CRH;
            	pODR_Reg	= &GPIOC_ODR;
            	break;

            default:
            	return STM_ERROR;
        }
    }
    // STEP 2
    CLR_BITS(*pConfigReg,0xF,nBitPos);
    // STEP 3
    uint8_t nConfigValue;
    switch(eCnf) {
        case FLOATING:
        	nConfigValue = 0b0100;
        	break;

        case PULL_UP:
        	nConfigValue = 0b1000;
        	SET_BIT(*pODR_Reg,nPin);
        	break;

        case PULL_DOWN:
        	nConfigValue = 0b1000;
        	CLR_BIT(*pODR_Reg,nPin);
        	break;

        case ANALOG:
        	nConfigValue = 0b0000;
        	break;

        default:
        	return STM_ERROR;
    }

    WRITE_BITS(*pConfigReg, nConfigValue, nBitPos);

    return STM_OK;
}

stm_err_t GPIO_INPUT_READ(GPIO_PORTS ePort, uint8_t nPin){

	if(nPin > 15)
		return STM_ERROR;

	switch (ePort) {
		case PORTA:
			GET_BIT(GPIOA_IDR,nPin);
			break;

		case PORTB:
			GET_BIT(GPIOB_IDR,nPin);
			break;

		case PORTC:
			GET_BIT(GPIOC_IDR,nPin);
			break;

		default:
			return STM_ERROR;
			break;
	}
	return STM_OK;
}

/*
 * Step 1: Choose CRL or CRH and calculate bit position
 * Step 2: Choose Output MODE bits
 * Step 3: Choose Output Configuration Bits
 * Step 4: Configure the Register
 */
stm_err_t GPIO_OUTPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, OUTPUT_MODE eMode, OUTPUT_CNF eCnf){

	// Error Checking
	    if (nPin > 15)
	    	return STM_ERROR;

	    volatile uint32_t* pConfigReg;
	    uint8_t nBitPos;
	    // STEP 1: Choose CRL or CRH and calculate bit position
	    if (nPin < 8) {
	    	// Setting the POS
	        nBitPos = nPin * 4;
	        // Port Selection
	        switch(ePort) {
	            case PORTA:
	            	pConfigReg = &GPIOA_CRL;
	            	break;

	            case PORTB:
	            	pConfigReg = &GPIOB_CRL;
	            	break;

	            case PORTC:
	            	pConfigReg = &GPIOC_CRL;
	            	break;

	            default:
	            	return STM_ERROR;
	        }
	    }

	    else {
	    	// Setting the POS
	        nBitPos = (nPin - 8) * 4;
	        // Port Selection
	        switch(ePort) {
	            case PORTA:
	            	pConfigReg = &GPIOA_CRH;
	            	break;

	            case PORTB:
	            	pConfigReg = &GPIOB_CRH;
	            	break;

	            case PORTC:
	            	pConfigReg = &GPIOC_CRH;
	            	break;

	            default:
	            	return STM_ERROR;
	        }
	    }
	    // STEP 2: Choose Output MODE bits
	    uint8_t nModeBits;

	    switch (eMode) {
			case MAX_OUTPUT_SPEED_10MHZ:
				nModeBits = 0b01;
				break;

			case MAX_OUTPUT_SPEED_2MHZ:
				nModeBits = 0b10;
				break;

			case MAX_OUTPUT_SPEED_50MHZ:
				nModeBits = 0b11;
				break;

			default:
				return STM_ERROR;
				break;
		}
	    // STEP 3: Set the Configuration
	    uint8_t nConfigBits;

	    switch (eCnf) {
			case OPEN_DRAIN:
				nConfigBits = 0b01;
				break;

			case PUSH_PULL:
				nConfigBits = 0b00;
				break;

			case ALT_FN_PUSH_PULL:
				nConfigBits = 0b10;
				break;

			case ALT_FN_OPEN_DRAIN:
				nConfigBits = 0b11;
				break;

			default:
				return STM_ERROR;
				break;
		}
	    // STEP 4

	    //Combine the MODE and CNF bits
	    uint8_t nConfigVal = (nConfigBits<<2) | nModeBits;
	    // Clear Register from previous Config
	    CLR_BITS(*pConfigReg, 0xF, nBitPos);
	    // Write new Config
	    WRITE_BITS(*pConfigReg, nConfigVal, nBitPos);
return STM_OK;}



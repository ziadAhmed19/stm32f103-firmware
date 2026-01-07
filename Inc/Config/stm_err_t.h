/*
 * stm_err_t.h
 *
 *  Created on: Jan 1, 2026
 *      Author: ziad-ahmed
 *
 *      ERROR GROUPS:
 *      0x10 -> Generic Error Group
 *
 */

#ifndef CONFIG_STM_ERR_T_H_
#define CONFIG_STM_ERR_T_H_

typedef int stm_err_t;

// Definitions For Error Constants
#define STM_OK		 0 	// stm_err_t value indicating success
#define STM_ERROR 	-1 // Generic stm_err_t code indicating failure

// Generic Error Group
#define STM_ERR_INVALID_ARG 	0x10 // Invalid Argument
#define STM_ERR_INVALID_SIZE	0x11 // Invalid Size
#define STM_ERR_INVALID_STATE 	0x12 // Invalid State
#define STM_ERR_NOT_FOUND 		0x13 // Requested Resource Not Found
#define STM_ERR_TIMEOUT 		0x14 // Operation Timed Out
#define STM_ERR_NOT_FINISHED	0x15 // Operation Has Not Fully Completed


// Function Prototypes
char* stm_err_to_name(stm_err_t ERROR_CODE);
void STM_CHECK_ERROR(stm_err_t returned_valueFrom_function);

#endif /* CONFIG_STM_ERR_T_H_ */

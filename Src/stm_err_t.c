/*
 * stm_err_t.c
 *
 *  Created on: Jan 7, 2026
 *      Author: ziad-ahmed
 */

#include "stm_err_t.h"

char* stm_err_to_name(stm_err_t ERROR_CODE){

	switch(ERROR_CODE){

		case STM_ERR_INVALID_ARG:	return"STM_ERR_INVALID_ARG";	break;
		case STM_ERR_INVALID_SIZE:	return"STM_ERR_INVALID_SIZE";	break;
		case STM_ERR_INVALID_STATE:	return"STM_ERR_INVALID_STATE";	break;
		case STM_ERR_NOT_FOUND:		return"STM_ERR_NOT_FOUND";		break;
		case STM_ERR_TIMEOUT:		return"STM_ERR_TIMEOUT";		break;
		case STM_ERR_NOT_FINISHED:	return"STM_ERR_NOT_FINISHED";	break;

		default: return "UNKNOWN ERROR"; break;


	}
}

void STM_CHECK_ERROR(stm_err_t returned_valueFrom_function){

	if(returned_valueFrom_function != STM_OK)
		while(1){/*do nothing*/}

}

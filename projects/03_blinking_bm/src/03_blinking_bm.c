/* Copyright 2016, XXXX
 *
 *  * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "03_blinking_bm.h"       /* <= own header */
#include "switch.h"
#define SW1_MUX_GROUP 	6
#define SW1_MUX_PIN 	10
#define SW1_GPIO_PORT 	3
#define SW1_GPIO_PIN 	6

#define SW2_MUX_GROUP 	6
#define SW2_MUX_PIN 	7
#define SW2_GPIO_PORT 	5
#define SW2_GPIO_PIN 	15
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
#define DELAY_INIT 5000000

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
void Delay(uint32_t);
/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */


void Delay(uint32_t delay_value)
{
	uint32_t loop;
	for ( loop=delay_value; loop!=0; loop-- )
	{
	}
}


int main(void)
{
   /* inicializaciones */
	uint32_t retardo = DELAY_INIT;
	uint8_t tecla;
  	uint8_t nro_led = 2;
   
   /*acá va mi programa principal */
   
	InitLeds();
	Init_Switches();
	EncenderLed(1);
	Delay(retardo);
	ApagarLed(1);
	EncenderLed(2);
	Delay(retardo);
	ApagarLed(2);
    while(1){
    tecla = Read_Switches();

    if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,SW1_GPIO_PORT,SW1_GPIO_PIN)){
    	InvierteLed(1);
	}

     if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,SW2_GPIO_PORT,SW2_GPIO_PIN)){
    	InvierteLed(2);
    }
/*
    if (tecla==TEC2){
    		retardo=retardo+1000000;
    		if (retardo>10000000)
    		{
    			retardo=10000000;
    		}
		}

    if (tecla==TEC1){
		retardo=retardo-1000000;
    		if (retardo<10000)
    		{
    			retardo=1000000;
    		}
		}

    	EncenderLed(nro_led);
   		Delay(retardo);

    	ApagarLed(nro_led);*/
    	Delay(retardo);

    }

	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


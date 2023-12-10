#include "stdint.h"
#include "chip.h"
#include "botones.h"
#include "ciaaPOSIX_stdbool.h"
#include <stdbool.h>
#include <stdio.h>
#include "led.h"


void Inicializar_Botones(void )
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	/* configura los pines donde estan conectados los botones, en sus correspondientes GPIO x[y]*/
	//numero de puerto, numero de pin,
	Chip_SCU_PinMux(BT1_MUX_GROUP,BT1_MUX_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* BT1 */
	Chip_SCU_PinMux(BT2_MUX_GROUP,BT2_MUX_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* BT2 */
	Chip_SCU_PinMux(BT3_MUX_GROUP,BT3_MUX_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* BT3 */
	Chip_SCU_PinMux(BT4_MUX_GROUP,BT4_MUX_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* BT4 */
	Chip_SCU_PinMux(BT5_MUX_GROUP,BT5_MUX_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* BT5 */
	Chip_SCU_PinMux(BT6_MUX_GROUP,BT6_MUX_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* BT6 */
	/* Define a los pines donde estan los SW como entradas */
	//numero de puerto,numero de bit,entrada o salida
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT1_GPIO_PORT, BT1, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT2_GPIO_PORT, BT2, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT3_GPIO_PORT, BT3, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT4_GPIO_PORT, BT4, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT5_GPIO_PORT, BT5, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT6_GPIO_PORT, BT6, ENTRADA);
 }

bool Leer_Estado_Boton(uint8_t tecla)
 {
	 int dato=0;
	 switch(tecla)
	 {
	 case BT1:
		 dato=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, BT1_GPIO_PORT,BT1_GPIO_PIN);
		 break;
	 case BT2:
		 dato=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, BT2_GPIO_PORT,BT2_GPIO_PIN);
		 break;
	 case BT3:
		 dato=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, BT3_GPIO_PORT,BT3_GPIO_PIN);
		 break;
	 case BT4:
		 dato=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, BT4_GPIO_PORT,BT4_GPIO_PIN);
		 break;
	 case BT5:
	 	 dato=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, BT5_GPIO_PORT,BT5_GPIO_PIN);
	 	 break;
	 case BT6:
	 	 dato=Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, BT6_GPIO_PORT,BT6_GPIO_PIN);
	 	 break;
	 default:
		 break;
	 }
	 return dato;
 }

 void UpdateBotones(){
	 if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT1_GPIO_PORT,BT1_GPIO_PIN)){
	     InvierteLed(1);
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT2_GPIO_PORT,BT2_GPIO_PIN)){
	 	// printf("Se presionó el botón 2\n");
		 InvierteLed(1);
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT3_GPIO_PORT,BT3_GPIO_PIN)){
	 	 //printf("Se presionó el botón 3\n");
		 InvierteLed(1);
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT4_GPIO_PORT,BT4_GPIO_PIN)){
	 	 //printf("Se presionó el botón 4\n");
		 InvierteLed(1);
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT5_GPIO_PORT,BT5_GPIO_PIN)){
	 	 //printf("Se presionó el botón 5\n");
		 InvierteLed(1);
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT6_GPIO_PORT,BT6_GPIO_PIN)){
	 	 //printf("Se presionó el botón 6\n");
		 InvierteLed(1);
	 }
 }

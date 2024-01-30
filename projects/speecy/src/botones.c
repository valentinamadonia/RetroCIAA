#include "stdint.h"
#include "chip.h"
#include "botones.h"
#include "ciaaPOSIX_stdbool.h"
#include <stdbool.h>
#include <stdio.h>
#include "led.h"
#include "ILI9341.h"
#include "tm_stm32f4_fonts.h"

int start = 0;


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
	Chip_SCU_PinMux(LED_MUX_GROUP,LED_MUX_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* LED */
	/* Define a los pines donde estan los SW como entradas */
	//numero de puerto,numero de bit,entrada o salida
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT1_GPIO_PORT, 1<<BT1_GPIO_PIN, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT2_GPIO_PORT, 1<<BT2_GPIO_PIN, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT3_GPIO_PORT, 1<<BT3_GPIO_PIN, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT4_GPIO_PORT, 1<<BT4_GPIO_PIN, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT5_GPIO_PORT, 1<<BT5_GPIO_PIN, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, BT6_GPIO_PORT, 1<<BT6_GPIO_PIN, ENTRADA);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LED_GPIO_PORT, 1<<LED_GPIO_PIN, SALIDA);
 }

void Prender_Led(void)
 {
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, LED_GPIO_PORT, LED_GPIO_PIN);
 }

void Apagar_Led(void)
 {
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, LED_GPIO_PORT, LED_GPIO_PIN);
 }

unsigned char UpdateBotonesOpcion1(){
	 unsigned char tecla;
	 if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT1_GPIO_PORT,BT1_GPIO_PIN)){
		 tecla = 'Q'; //arriba
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT2_GPIO_PORT,BT2_GPIO_PIN)){
	 	tecla = 'O'; // izquierda
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT3_GPIO_PORT,BT3_GPIO_PIN)){
		 tecla = 'UP'; // derecha
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT4_GPIO_PORT,BT4_GPIO_PIN)){
		 tecla = 'A'; //abajo
	 }
	 return tecla;
 }

unsigned char UpdateBotonesOpcion2(){
	 unsigned char tecla;

	 if (!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT1_GPIO_PORT,BT1_GPIO_PIN)){
		 tecla = 'A'; // adelante
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT2_GPIO_PORT,BT2_GPIO_PIN)){
	 	tecla = 'Z'; // cambio de posicion
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT3_GPIO_PORT,BT3_GPIO_PIN)){
		 tecla = 'UP'; // ataque
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT4_GPIO_PORT,BT4_GPIO_PIN)){
			 tecla = 'Q'; // saltar
	 }
	 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT5_GPIO_PORT,BT5_GPIO_PIN)){
		 tecla = '0'; // start
	 }
	 return tecla;
 }

int Menu(void){
	char *str= "RETRO CIAA";
	TM_ILI9341_Puts(80,20,str,&TM_Font_16x26, ILI9341_COLOR_MAGENTA, ILI9341_COLOR_BLACK);
	TM_ILI9341_DrawLine(2, 50, 319, 50, ILI9341_COLOR_MAGENTA);
	TM_ILI9341_DrawLine(2, 52, 319, 52, ILI9341_COLOR_MAGENTA);
	TM_ILI9341_Puts(75,75,"01-Pacman",&TM_Font_11x18, ILI9341_COLOR_MAGENTA, ILI9341_COLOR_BLACK);
	TM_ILI9341_Puts(75,105,"02-Pentagram",&TM_Font_11x18, ILI9341_COLOR_MAGENTA, ILI9341_COLOR_BLACK);
	str= "by Guerrero, Madonia, Santana";
	TM_ILI9341_Puts(110,230,str,&TM_Font_7x10, ILI9341_COLOR_MAGENTA, ILI9341_COLOR_BLACK);
	int option=0;
	while(option==0){
		if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT6_GPIO_PORT,BT6_GPIO_PIN)){
			option=1;
		}
		if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,BT5_GPIO_PORT,BT5_GPIO_PIN)){
			option=2;
		}
	}
	return option;
}

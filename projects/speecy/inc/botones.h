#ifndef BOTONES_H_
#define BOTONES_H_

#define ENTRADA 0
#define SALIDA 1

#define BT1_MUX_GROUP     6		//BT1 = GPIO7 : pin38
#define BT1_MUX_PIN       11
#define BT1_GPIO_PORT     3
#define BT1_GPIO_PIN      7

#define BT2_MUX_GROUP     6		//BT2 = GPIO4 : pin33
#define BT2_MUX_PIN       8
#define BT2_GPIO_PORT     5
#define BT2_GPIO_PIN      16

#define BT3_MUX_GROUP     6		//BT3 = GPIO5 : pin36
#define BT3_MUX_PIN       9
#define BT3_GPIO_PORT     3
#define BT3_GPIO_PIN      5

#define BT4_MUX_GROUP     6		//BT4 = GPIO8 : pin40
#define BT4_MUX_PIN       12
#define BT4_GPIO_PORT     2
#define BT4_GPIO_PIN      8

#define BT5_MUX_GROUP     6		//BT5 = GPIO3 : pin34
#define BT5_MUX_PIN       7
#define BT5_GPIO_PORT     5
#define BT5_GPIO_PIN      15

#define BT6_MUX_GROUP     6		//BT6 = GPIO6 : pin35
#define BT6_MUX_PIN       10
#define BT6_GPIO_PORT     3
#define BT6_GPIO_PIN      6

#define LED_MUX_GROUP     6		//LED = GPIO6 : pin35
#define LED_MUX_PIN       4
#define LED_GPIO_PORT     3
#define LED_GPIO_PIN      3



void Inicializar_Botones(void);

void Prender_Led(void);

void Apagar_Led(void);

unsigned char UpdateBotonesOpcion1(void);

unsigned char UpdateBotonesOpcion2(void);

int Menu(void);

#endif

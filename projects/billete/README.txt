# Organizador Separador de Billetes (OSB)

Composici�n del grupo de trabajo:

Ing. Telmo Moya
Ing. Daniel Steiner


Introducci�n:

El Organizador Billetes es necesario para realizar la separaci�n autom�tica de billetes de denominaci�n conocida considerando su valor y el estado de validez del mismo.

Objetivos y alcance del sistema

El objetivo del sistema es presentar la informaci�n del estado de procesamiento de un lote de billetes de entrada y dar aviso cuando est� disponible una cantidad especificada de una determinada denominaci�n y rechazara los que no cumplan con estado para circular.
 
Descripci�n general

El sistema OSB tiene un lector de billetes BV 20 y para la verificaci�n del sistema se utikiza un LCD gr�fico.


Cat�logo de Requisitos del Sistema 


1.	Requisitos funcionales (comportamientos)

1.1		La informaci�n del lote en proceso se visualizar� en un display grafico tipo GLCD de 128x64 dots y utilizando la librer�a grafica disponible
1.2		El recibir� �nicamente informaci�n por l�nea serie desde el lector
1.3		El OSB brinda la informai�n por el puerto serie USB



2.	Requisitos de interfaces externas

2.1.	El OSB tendr� conectado el un display grafico tipo GLCD de 128x64 dots mediante el BUS expansi�n de EDU-CIAA
2.2.	La trama con informaci�n procesada de se�ales locales se transmite hacia el equipo de         Propuesta: RS-232 (9600 baudios) 


3.	Requisitos de desarrollo y restricciones de dise�o

3.1.	El OSB deber� dise�arse en base a una EDU- CIAA NXP
3.2.	Un OSB deber� dise�arse utilizando los DRIVERS provistos por el curso de la 7ma ESE

4.	Descomposici�n del sistema en subsistemas:

4.1.	Sensores Lector de billetes, barrera detector sobre vidrio, 
4.2.	Procesador EDU- CIAA NXP
4.3.	Alimentaci�n desde fuente adicional a la placa


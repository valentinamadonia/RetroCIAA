# Reproductor de Audio con EDU-CIAA DAC

La idea es reproducir sonido enviando al DAC datos contenido en la memoria de programa (mayor capacidad).
El programa principal utiliza interrupciones para enviar cada 125us (8KHz) los valores contenidos en el array speak[] de tipo char.
Para la craci�n del array, que contiene 84036 valores se uso el siguiente procedimiento:
1- Abrir en Audacity un archivo de sonido, en este caso un mp3 de Los Tekis
2- Recortar, s�lo unos cuantos segundos
3- Pasar a Mono
4- Cambiar la "Frecuencia del Proyecto" a 8000Hz
5- Exportar Audio como tipo: RAW(header-less) y Codificaci�n Unsigned 8-bit PCM
6- Usando bin2header* (https://sourceforge.net/projects/bin2header) generar speak.h desde el audio exportado


* Puedes usar bin2h (http://www.deadnode.org/sw/bin2h) que tiene la ventaja de crearnos variable_size con la cantidad de datos (que ser�a TOTAL_SAMPLES), pero la definici�n que hace del array no es constante, por eso al archivo generado deber�s agregar en la definici�n del array "static const"
Emulador de Spectrum con salida VGA para EduCIAA
==================================

Es una aplicaci�n baremetal multicore: M4 corre el emulador ASpectrum y M0 genera las se�ales VGA.
La emulaci�n puede funcionar m�s r�pido que el Spectrum original.
Para almacenar el frame VGA (48kb) se usan las memorias AHB32 y AHB16.
El render que corre en M4 escribe en ellas y M0 las lee para generar las se�ales RGB. Para minimizar los accesos de escritura se utiliza un render diferencial que s�lo escribe las actualizaciones.

La generaci�n de los sincronismos VGA es muy simple, est� implementada por polling y por lo tanto en el c�digo se ven claramente los momentos de los sincronismos y p�rticos.
Para las se�ales RGB se usa GPIO por DMA que (a diferencia de implementaciones que usan SPI para video monocrom�tico) permite obtener hasta 256 colores por pixel (aunque aqu� el Spectrum s�lo usa 8).

Para m�s detalles de la emulaci�n, render y uso de memoria pueden ver la versi�n single-core para TFT.
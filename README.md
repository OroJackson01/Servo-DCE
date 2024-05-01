# Servo-DCE

Este repositorio contiene Proyecto de robots desarrollado como parte de actividades académicas o personales.

## Basado en [Miniq 2wd v2.1](https://www.dfrobot.com/product-555.html) 

Especificaciones:
- Micro: ATMega32u4
- Peso: 350g
- Fuente de alimentación: 4.5--6V
- Bootloader: Arduino Leonardo
- Sensores de seguimiento de línea x5
- Diodo fotosensible x2
- Botones muy cómodos
- LED RGB WS2812
- Conector de puerto: I2C
- Tamaño: 109*122mm(4.29*4.8")

## Programación 

Se programará en C y se cargará en el dispositivo con AVR versión 7.3. Los comandos que utilizaremos para cargar en la placa son:

```bash
C:\Program Files\avrdude_7_3\avrdude.exe
-b 115200 -v -p atmega328p -c arduino -PCOM5 -D -U flash:w:"$(ProjectDir)Debug\$(TargetName).hex":i
```
## Fases de desarollo del proyecto 

1. **Robot que emite sonidos**  
   - Descripción: Un robot capaz de producir diferentes sonidos utilizando un microcontrolador.
   - Nivel de Dificultad: 
   - Estado: Completo
   
2. **Robot detector de blanco y negro**  
   - Descripción: Un robot diseñado para detectar y distinguir entre áreas blancas y negras.
   - Nivel de Dificultad: 
   - Estado: En Progreso
   
3. **Robot móvil que emite sonidos**  
   - Descripción: Un robot móvil con capacidades de desplazamiento y emisión de sonidos.
   - Nivel de Dificultad: 
   - Estado: En Progreso
   
4. **Robot móvil sigue líneas**  
   - Descripción: Un robot capaz de seguir una línea trazada en el suelo.
   - Nivel de Dificultad: 
   - Estado: En Progreso

## Contribución
¡Se aceptan contribuciones! Si tienes ideas para mejorar alguno de estos proyectos o te gustaría colaborar, ¡no dudes en ponerte en contacto!

## Licencia
Este proyecto está bajo la [Supervisión](https://www.fernandoalonso.com/wp-content/uploads/2023/11/GP2320_141541_ONZ8936.jpg)


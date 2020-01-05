# Carnaval
Some special led effects for de carnavalsvereniging 

## Belangrijk
De leds werken op 5V (DUS NIET OP 12)
Altijd +- goed aansluiten...anders rook!!!

## Aansluiten
In alle gevallen zijn de verbindingen dus de leds en de microcontroller alsvolgt:

- Led rood = 5V           <--> Arduino pin 5V
- led wit = GND           <--> Arduino pin GND 
- led groen/grijs = DATA  <--> Arduino pin D6

## Software
Alles is geschreven met behulp van de Arduino ontwikkelomgeving (http:www.arduino.cc). 
Deze software is gratis te downloaden en te gebruiken met Windows/Max/Linux.

Hieronder een beschrijving van de programma's:

## NeoMatrixEyes.ino
Programma voor de ogen van de Mexicaan
Elk oog heeft zijn eigen electronica en aansturing.
Gebruikte hardware:
- Arduino Nano microcontroller
- Neomatrix led paneel (ws2812b) met 16x16 pixels
- De ogen maken gebruik van een gemeenschappelijke 5V dc/dc converter


## NeoPixelGuitar.ino
Led guitaar vas de Mexicaan
Aangestuurd door Arduino Uno en 3 ledstrips (ws2812b) van elk 2 meter (3x120 pixels)
Alle 3 de strips zijn zigzag met elkaar doorverbonden.
Het systeem maakt gebruik van een 5v dc/dc converter.


## Sombrero.ino
Mexicaanse ledponcho met Sombrero
Hardware:
- 1 Arduino Nano
- 1 ledstring voor de hoed
- 1 ledstring voor de poncho
ledstrings doorverbonden (battery->poncho->sombrero)

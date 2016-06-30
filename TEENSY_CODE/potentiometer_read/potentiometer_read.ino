 /*
  ---------------------------- Pin Assignments -------------------------------------

    Teensy 3.1 / 3.2                       ______
                                          |      |
                                  --------|______|--------
                                 [] Gnd              Vin []
                                 [] RX1             AGND []
                                 [] TX1             3.3V [] 
                                 [] 02                23 []
                                 [] 03                22 []
                                 [] 04                21 []
                                 [] 05                20 []
                                 [] 06                19 [] 
                                 [] 07                18 [] 
                                 [] 08                17 [] 
                                 [] 09                16 [] 
                                 [] 10                15 [] 
                                 [] 11                14 [] 
                                 [] 12                13 []
                                  ------------------------

 * Analog Read to LED
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead(). In the easiest case we connect
 * a potentiometer to analog pin 2.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */
#include "ADC.h"

const int readPin = A9;    // select the input pin for the potentiometer
const int ledPin = 13;   // select the pin for the LED
double value = 0;       // variable to store the value coming from the sensor

ADC *adc = new ADC(); // adc object

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  pinMode(readPin, INPUT); //pin 23 single ended

  Serial.begin(9600);

  // reference can be ADC_REF_3V3, ADC_REF_1V2 (not for Teensy LC) or ADC_REF_EXT.
  //adc->setReference(ADC_REF_1V2, ADC_0); // change all 3.3 to 1.2 if you change the reference to 1V2

  adc->setAveraging(8); // set number of averages
  adc->setResolution(12); // set bits of resolution

  adc->setAveraging(32, ADC_1); // set number of averages
  adc->setResolution(12, ADC_1); // set bits of resolution

  // always call the compare functions after changing the resolution!
  //adc->enableCompare(1.0/3.3*adc->getMaxValue(ADC_0), 0, ADC_0); // measurement will be ready if value < 1.0V
  //adc->enableCompareRange(1.0*adc->getMaxValue(ADC_1)/3.3, 2.0*adc->getMaxValue(ADC_1)/3.3, 0, 1, ADC_1); // ready if value lies out of [1.0,2.0] V

}

void loop() {
  value = adc->analogRead(readPin);

  
  
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  Serial.println(value);
  delay(10);                   // stop the program for some time
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(10);                   // stop the program for some time
}

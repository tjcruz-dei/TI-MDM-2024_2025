<#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);  
CapacitiveSensor   cs_5_4 = CapacitiveSensor(5,4);  // 10M resistor between pins 7 & 6, pin 6 is sensor pin, add a wire and or foil if desired

void setup()                    
{
   cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_5_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_3_2.capacitiveSensor(10);
    long total2 =  cs_5_4.capacitiveSensor(10);
    
    // Uncomment the next lines to check the sensor output values
    //Serial.print(millis() - start);        // check on performance in milliseconds
    //Serial.print("\t");                    // tab character for debug windown spacing
    Serial.print(total1);                  // print sensor output 1
    Serial.print(":");
    Serial.println(total2);
    //if (total1>150) Serial.println("touch");
    delay(10);                             // arbitrary delay to limit data to serial port 
}

// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

/*
 * Start Bell comments:
 * Serial clock = SCL = SDC = pin 5 on Uno 
 * Serial Data = SDA = pin 4 on Uno
 * 
 */

#include <Wire.h>

int numBytesReceived = 2u;

void setup()
{
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);    // start serial for output
}

void loop()
{
  delay(1000);
  Serial.print("loop \n");
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
// takes number of bytes to be received as parameter
void receiveEvent(int numBytesReceived)
{   
  while(Wire.available() > 0) // loop through all but the last
  {
    int  c = Wire.read(); // receive byte 
    Serial.print("c, current \n");
    Serial.print(c);        // print the character
    c = c << 8;    // shift high byte to be high 8 bits
    c |= Wire.read(); // receive low byte as lower 8 bits
    Serial.print(" \nilluminance c << 8 \n");
    Serial.println(c);   // print the reading
  }
  delay(200);
}

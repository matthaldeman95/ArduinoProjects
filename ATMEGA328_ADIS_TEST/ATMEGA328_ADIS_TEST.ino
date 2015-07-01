#include <SPI.h>

/* Code for the Analog Devices ADIS16300 */
//Registers used
#define SUPPLY_OUT     0x02
#define GYRO_OUT       0x04
#define XACCL_OUT      0x0A
#define YACCL_OUT      0x0C
#define ZACCL_OUT      0x0E
#define TEMP_OUT       0x10
#define PITCH_OUT      0x12
#define ROLL_OUT       0x14

//Number of bits of data transferred by registers
#define SUPPLYBITS      12
#define ACCBITS         14
#define TEMPBITS        12
#define GYROBITS        14
#define ROLLBITS        13
#define PITCHBITS       13

//Scale for each data type
#define SUPPLYSCALE     0.00242
#define GYROSCALE       0.05
#define ACCSCALE        0.0006
#define TEMPSCALE       0.14
#define ROLLSCALE       0.044
#define PITCHSCALE      0.044

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  //SPI Mode from the datashet
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE3);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  delay(1000);
}

void loop() {
  readADIS();
}

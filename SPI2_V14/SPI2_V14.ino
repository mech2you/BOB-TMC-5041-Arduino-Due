/*
    Erstellt am: 25.07.2019
    Author: Adam Wilczek
*/

#include <SPI.h>
#include "SPI_5041.h"
//https://github.com/jenesaisdiq/TMC5041/blob/master/TMC5041.cpp

// Pinbelegung
DataOut in, out;
void setup() {
  // PINS
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);// Chip ist aktiv
  pinMode(CHIP_SELECT, OUTPUT);
  digitalWrite(CHIP_SELECT, HIGH);
  //SPI
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setDataMode(SPI_MODE3);
  SPI.begin();
  
  in = { 0x80, 0x00000000 };
  sendData(in);     //GCONF

  //SpiStatusBit(out.adresse);
  in = { 0xA0, 0x00000000 };
  sendData(in);    //RAMPMODE=0
  in = { 0xC0, 0x00000000};
  sendData(in);    //RAMPMODE=0

  // Motor 1
  in = { 0xA3, 0x0000000F};// VSTART = 15
  sendData(in);
  in = { 0xA4, 0x000003E8};//A1=1000
  sendData(in);
  in = { 0xA5, 0x000186A0};//V1=100000
  sendData(in);
  in = { 0xA6, 0x00000200};//AMAX=50000
  sendData(in);
  //in = { 0xA7, 0x000186A0};
  in = { 0xA7, 0x00DFFFFF}; // //VMAX=100000 Geschwindigkeit auf MAX
  sendData(in);
  in = { 0xA8, 0x0000F550}; //DMAX
  sendData(in);
  in = { 0xAA, 0x0000F578};//D1=1400
  sendData(in);
  in = { 0xAB, 0x00000020};//VSTOP=32
  sendData(in);
  in = { 0xAC, 0x0000000A};//TPOWERDOWN=10
  sendData(in);


  // Motor 2
  in = { 0xC3, 0x0000000F}; // VSTART = 15
  sendData(in);
  in = { 0xC4, 0x00000008}; //A1=1000
  sendData(in);
  in = { 0xC5, 0x000056A0}; //V1=100000
  sendData(in);
  in = { 0xC6, 0x0000C350}; //AMAX=50000
  sendData(in);
  in = { 0xC7, 0x000086A0}; //VMAX=100000
  sendData(in);
  in = { 0xC8, 0x000002BC}; //DMAX
  sendData(in);
  in = { 0xCA, 0x00000578}; //D1=1400
  sendData(in);
  in = { 0xCB, 0x00000020}; //VSTOP=32
  sendData(in);
  in = { 0xCC, 0x0000000A}; //TPOWERDOWN=10
  sendData(in);




  //IHOLD Config                                            delay  irun   ihold
  // unsigned long iholdconfig = 0b 0000 0000 0000 0000 00   0011  11110  00000;
  unsigned long iholdconfig = 0b00000000000000000000111111000011;
  in = { 0xB0, iholdconfig};// Motor 1
  sendData(in);
  in = { 0xD0, iholdconfig};// Motor 2
  sendData(in);

  //CHOPPER Config
  //sendData(0xEC,0x000101D5);      //CHOPCONF: TOFF=5, HSTRT=5, HEND=3, TBL=2, CHM=0 (spreadcycle)
  unsigned long chopconfig = 0b00000000000000001000000000000010;
  in = { 0xEC, chopconfig};// Motor 1
  sendData(in);
  in = { 0xFC, chopconfig};// Motor 2
  sendData(in);

  // PWM Config                                freewheel    autoscale   pwm_freq    pwm_grad   pwm_amplitude
  //unsigned long pwmconfig = 0b 0000 0000  00     01    0      1          01       11111111   11111111;
  unsigned long pwmconfig = 0b00000000001001011111111111111111;
  in = { 0x90, pwmconfig};
  sendData(in);      // PWMCONF Motor 1
  in = { 0x98, pwmconfig};
  sendData(in);      // PWMCONF Motor 2

  // Set up origins
  //correctLocation();
  in = { 0xA1, 0x00000000};// Motor 1 XACTUAL
  sendData(in);
  in = { 0xAD, 0x00000000};// Motor 1 XTARGET
  sendData(in);
  in = { 0xC1, 0x00000000};// Motor 2 XACTUAL
  sendData(in);
  in = { 0xCD, 0x00000000};// Motor 2 XTARGET
  sendData(in);
  delay(1000);
  unsigned long MicroStepp = 5 * 51200;
  // Fahre 50 Umdrehungen
  in = { 0xAD, MicroStepp};
  sendData(in);   //0xAD = 0x2D + 0x80 for write access
  in = { 0xCD, MicroStepp};
  sendData(in);   //0xAD = 0x2D + 0x80 for write access
}
void loop()
{

}

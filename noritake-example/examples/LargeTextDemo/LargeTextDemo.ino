#include <GU7000_Interface.h>
#include <GU7000_Parallel.h>
#include <SoftwareSerial.h>
#include <GU7000_SoftwareSerial.h>
#include <GU7000_Serial_Async.h>
#include <GU7000_Serial_SPI.h>
#include <GU7000_Serial_Sync.h>
#include <Noritake_VFD_GU7000.h>

// ****************************************************
// ****************************************************
// Uncomment one of the communication interfaces below.
//
//GU7000_Serial_Async interface(38400,3, 5, 7); // BAUD RATE,SIN,BUSY,RESET
//GU7000_Serial_Sync interface(3, 5, 6, 7); // SIN,BUSY,SCK,RESET
//GU7000_Serial_SPI interface(3, 5, 6, 7, 8); // SIN,BUSY,SCK,RESET,CS
//GU7000_Parallel interface('R', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=RESET; BUSY,RESET,WR,RD,D0-D7
//GU7000_Parallel interface('B', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=BUSY; BUSY,RESET,WR,RD,D0-D7
//GU7000_Parallel interface('N', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=nothing; BUSY,RESET,WR,RD,D0-D7

//
// ****************************************************
// ****************************************************
Noritake_VFD_GU7000 vfd;

void setup() {
  _delay_ms(500);           // wait for device to power up
  vfd.begin(140, 16);       // 140x16 module
  vfd.interface(interface); // select which interface to use
  // Enter the 4-digit model class number
  // E.g. 7040 for GU140X16G-7040A
  vfd.isModelClass(7000);
  //vfd.isGeneration('B');    // Uncomment this for B generation
  vfd.GU7000_reset();       // reset module
  vfd.GU7000_init();        // initialize module

  vfd.GU7000_setFontSize(1,1,false); // 1x1 normal font
  vfd.print("1x1");
  vfd.GU7000_setFontSize(2,2,false); // 2x2 tall & wide font
  vfd.print("2x2");
  vfd.GU7000_setFontSize(3,2,false); // 3x2 wide font
  vfd.print("3x2");
}

void loop() {
}



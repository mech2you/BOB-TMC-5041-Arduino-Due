/*
    ChopperConfiguration.h
    Created on: 29.07.2019
    Author: Adam Wilczek

    Chopper Configuration 6.5.2 Seite 50 TMC5160 DATASHEET (Rev. 1.10 / 2019-FEB-05)
*/
#ifndef ChopperConf
#define ChopperConf
#include <SPI.h>
void ChopperConfigurationRead(unsigned long x32BitRegisters) {
  // Adresse ist 0X6C
  // Siehe Seite 50 vom Datenblatt TMC 5160 Kapitel 6.5.2 CHOPCONF – Chopper Configuration
  // Bitmuster wird in Text aus den Datenblatt umgesetzt
  String error = "---------------Chopper Configuration---------------\r\n";
  // BIT 0
  error += AusgabeRegister(x32BitRegisters, 0x00000001, "toff0");
  // BIT 1
  error += AusgabeRegister(x32BitRegisters, 0x00000002, "toff1");
  // BIT 2
  error += AusgabeRegister(x32BitRegisters, 0x00000004, "toff2");
  // BIT 3
  error += AusgabeRegister(x32BitRegisters, 0x00000008, "toff3");
  error += "TOFF off time and driver enable\r\n";
  error += "Off time setting controls duration of slow decay phase NCLK= 24 + 32*TOFF %0000: Driver disable, all bridges off %0001: 1 – use only with TBL ≥ 2 %0010 … %1111: 2 … 15";
  Serial.print(error);
  error = "";
  // BIT 4
  error += AusgabeRegister(x32BitRegisters, 0x00000010, "hstrt0");
  // BIT 5
  error += AusgabeRegister(x32BitRegisters, 0x00000020, "hstrt1");
  // BIT 6
  error += AusgabeRegister(x32BitRegisters, 0x00000040, "hstrt2");
  error += "HSTRT hysteresis start value added to HEND\r\n";
  error += "chm=0\r\n %000 … %111: Add 1, 2, …, 8 to hysteresis low value HEND (1/512 of this setting adds to current setting) Attention: Effective HEND+HSTRT ≤ 16. Hint: Hysteresis decrement is done each 16";
  error += "TFD [2..0] fast decay time setting\r\n";
  error += "chm=1\r\n Fast decay time setting (MSB: fd3): %0000 … %1111: Fast decay time setting TFD with NCLK= 32*TFD (%0000: slow decay only)";
  Serial.print(error);
  error = "";
  // BIT 7
  error += AusgabeRegister(x32BitRegisters, 0x00000080, "hend0");
  // BIT 8
  error += AusgabeRegister(x32BitRegisters, 0x00000100, "hend1");
  // BIT 9
  error += AusgabeRegister(x32BitRegisters, 0x00000200, "hend2");
  // BIT 10
  error += AusgabeRegister(x32BitRegisters, 0x00000400, "hend3");
  error += "HEND hysteresis low value OFFSET sine wave offset) ";
  error += "chm=0 \r\n%0000 … %1111: Hysteresis is -3, -2, -1, 0, 1, …, 12 (1/512 of this setting adds to current setting) This is the hysteresis value which becomes used for the hysteresis chopper.\r\n";
  error += "chm=1 \r\n%0000 … %1111: Offset is -3, -2, -1, 0, 1, …, 12 This is the sine wave offset and 1/512 of the value becomes added to the absolute value of each sine wave entry.";
  Serial.print(error);
  error = "";

  // BIT 11
  error += AusgabeRegister(x32BitRegisters, 0x00000800, "fd3 TFD [3] chm=1: MSB of fast decay time setting TFD");
  // BIT 12
  error += AusgabeRegister(x32BitRegisters, 0x00001000, "disfdcc fast decay mode chm=1: disfdcc=1 disables current comparator usage for termi-nation of the fast decay cycle");
  // BIT 13
  error += AusgabeRegister(x32BitRegisters, 0x00002000, "reserved Reserved, set to 0");
  // BIT 14
  error += AusgabeRegister(x32BitRegisters, 0x00004000, "chm chopper mode \r\n0 Standard mode (SpreadCycle)\r\n1 Constant off time with fast decay time. Fast decay time is also terminated when the negative nominal current is reached. Fast decay is after on time.");
  // BIT 15
  error += AusgabeRegister(x32BitRegisters, 0x00008000, "tbl0");
  // BIT 16
  error += AusgabeRegister(x32BitRegisters, 0x00010000, "tbl1");
  error += "TBL blank time select\r\n";
  error += "%00 … %11: Set comparator blank time to 16, 24, 36 or 54 clocks Hint: %01 or %10 is recommended for most applications\r\n";
  Serial.print(error);
  error = "";
  // BIT 17
  error += AusgabeRegister(x32BitRegisters, 0x00020000, "reserved reserved, set to 0");
  // BIT 18
  error += AusgabeRegister(x32BitRegisters, 0x00040000, "vhighfs high velocity fullstep selection This bit enables switching to fullstep, when VHIGH is exceeded. Switching takes place only at 45° position. The fullstep target current uses the current value from the microstep table at the 45° position.");
  // BIT 19
  error += AusgabeRegister(x32BitRegisters, 0x00080000, "vhighchm high velocity chopper mode This bit enables switching to chm=1 and fd=0, when VHIGH is exceeded. This way, a higher velocity can be achieved. Can be combined with vhighfs=1. If set, the TOFF setting automatically becomes doubled during high velocity operation in order to avoid doubling of the chopper frequency.");
  // BIT 20
  error += AusgabeRegister(x32BitRegisters, 0x00100000, "rtpfd0");
  // BIT 21
  error += AusgabeRegister(x32BitRegisters, 0x00200000, "rtpfd0");
  // BIT 22
  error += AusgabeRegister(x32BitRegisters, 0x00400000, "rtpfd0");
  // BIT 23
  error += AusgabeRegister(x32BitRegisters, 0x00800000, "rtpfd0");
  error += "TPFD passive fast decay time\r\n";
  error += "TPFD allows dampening of motor mid-range resonances. Passive fast decay time setting controls duration of the fast decay phase inserted after bridge polarity change NCLK= 128*TPFD %0000: Disable %0001 … %1111: 1 … 15\r\n";
  Serial.print(error);
  // BIT 24
  error += AusgabeRegister(x32BitRegisters, 0x01000000, "mres0");
  // BIT 25
  error += AusgabeRegister(x32BitRegisters, 0x02000000, "mres1");
  // BIT 26
  error += AusgabeRegister(x32BitRegisters, 0x04000000, "mres2");
  // BIT 27
  error += AusgabeRegister(x32BitRegisters, 0x08000000, "mres3");
  error += "MRES micro step resolution\r\n";
  error += "%0000: Native 256 microstep setting. Normally use this setting with the internal motion controller. \r\n%0001 … %1000: 128, 64, 32, 16, 8, 4, 2, FULLSTEP Reduced microstep resolution esp. for STEP/DIR operation. The resolution gives the number of microstep entries per sine quarter wave. The driver automatically uses microstep positions which result in a symmetrical wave, when choosing a lower microstep resolution. step width=2^MRES [microsteps]\r\n";
  Serial.print(error);
  error = "";
  // BIT 28
  error += AusgabeRegister(x32BitRegisters, 0x10000000, "intpol interpolation to 256 microsteps 1: The actual microstep resolution (MRES) becomes extrapolated to 256 microsteps for smoothest motor operation (useful for STEP/DIR operation, only)");
  // BIT 29
  error += AusgabeRegister(x32BitRegisters, 0x20000000, "dedge enable double edge step pulses 1: Enable step impulse at each step edge to reduce step frequency requirement.");
  // BIT 30
  error += AusgabeRegister(x32BitRegisters, 0x40000000, "diss2g short to GND protection disable 0: Short to GND protection is on 1: Short to GND protection is disabled");
  // BIT 31
  error += AusgabeRegister(x32BitRegisters, 0x80000000, "diss2vs short to supply protection disable 0: Short to VS protection is on 1: Short to VS protection is disabled");
  
  error += "---------------Chopper Configuration---------------";
  Serial.print(error);
}
#endif

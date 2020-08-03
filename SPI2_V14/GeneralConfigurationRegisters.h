/*
    ChopperConfiguration.h
    Created on: 29.07.2019
    Author: Adam Wilczek

    Chopper Configuration 6.5.2 Seite 50 TMC5160 DATASHEET (Rev. 1.10 / 2019-FEB-05)
*/

#include <avr/pgmspace.h>
//const char GeneralConfRegistersBit1[] PROGMEM = {"recalibrate 1: \r\nZero crossing recalibration during driver disable (via ENN or via TOFF setting)"};
//const char progMem_string3[] PROGMEM = "Lead Paradigm Architect";

#ifndef GeneralConfRegisters
#define GeneralConfRegisters
#include "SPI_5041.h"
void GeneralConfigurationRegistersRead(unsigned long x32BitRegisters) {
  // Siehe Seite 31 vom Datenblatt TMC 5160 Kapitel 6.1 General Configuration Registers
  // Bitmuster wird in Text aus den Datenblatt umgesetzt
  String error = "---------------General Configuration Registers---------------\r\n";
  // BIT 0
 // error+=AusgabeRegister(x32BitRegisters,0x00000001,GeneralConfRegistersBit1);
  // BIT 1
  error+=AusgabeRegister(x32BitRegisters,0x00000002,"faststandstill \r\nTimeout for step execution until standstill detection: 1: Short time: 2^18 clocks 0: Normal time: 2^20 clocks");
  // BIT 2
  error+=AusgabeRegister(x32BitRegisters,0x00000004,"en_pwm_mode 1: StealthChop voltage PWM mode enabled (depending on velocity thresholds). Switch from off to on state while in stand-still and at IHOLD= nominal IRUN current, only.");
  // BIT 3
  error+=AusgabeRegister(x32BitRegisters,0x00000008,"multistep_filt 1: Enable step input filtering for StealthChop optimization with external step source (default=1)");
  // BIT 4
  error+=AusgabeRegister(x32BitRegisters,0x00000010,"shaft 1: Inverse motor direction");
  // BIT 5
  error+=AusgabeRegister(x32BitRegisters,0x00000020,"diag0_error (only with SD_MODE=1) 1: Enable DIAG0 active on driver errors: Over temperature (ot), short to GND (s2g), undervoltage chargepump (uv_cp) DIAG0 always shows the reset-status, i.e. is active low during reset condition.");
  // BIT 6
  error+=AusgabeRegister(x32BitRegisters,0x00000040,"diag0_otpw (only with SD_MODE=1) 1: Enable DIAG0 active on driver over temperature prewarning (otpw)");
  // BIT 7
  error+=AusgabeRegister(x32BitRegisters,0x00000080,"diag0_stall (with SD_MODE=1) 1: Enable DIAG0 active on motor stall (set TCOOLTHRS before using this feature) diag0_step (with SD_MODE=0) 0: DIAG0 outputs interrupt signal 1: Enable DIAG0 as STEP output (dual edge triggered steps) for external STEP/DIR driver");
  // BIT 8
  error+=AusgabeRegister(x32BitRegisters,0x00000100,"diag1_stall (with SD_MODE=1) 1: Enable DIAG1 active on motor stall (set TCOOLTHRS before using this feature) diag1_dir (with SD_MODE=0) 0: DIAG1 outputs position compare signal 1: Enable DIAG1 as DIR output for external STEP/DIR driver");
  // BIT 9
  error+=AusgabeRegister(x32BitRegisters,0x00000200,"diag1_index (only with SD_MODE=1) 1: Enable DIAG1 active on index position (microstep look up table position 0)");
  // BIT 10
  Serial.print(error);
  error="";
  error+=AusgabeRegister(x32BitRegisters,0x00000400,"diag1_onstate (only with SD_MODE=1) 1: Enable DIAG1 active when chopper is on (for the coil which is in the second half of the fullstep)");
  // BIT 11
  error+=AusgabeRegister(x32BitRegisters,0x00000800,"diag1_onstate (only with SD_MODE=1) 1: Enable DIAG1 active when chopper is on (for the coil which is in the second half of the fullstep)");
  // BIT 12
  error+=AusgabeRegister(x32BitRegisters,0x00001000,"diag0_int_pushpull 0: SWN_DIAG0 is open collector output (active low) 1: Enable SWN_DIAG0 push pull output (active high)");
  // BIT 13
  error+=AusgabeRegister(x32BitRegisters,0x00002000,"diag1_poscomp_pushpull 0: SWP_DIAG1 is open collector output (active low) 1: Enable SWP_DIAG1 push pull output (active high)");
  // BIT 14
  error+=AusgabeRegister(x32BitRegisters,0x00004000,"small_hysteresis 0: Hysteresis for step frequency comparison is 1/16 1: Hysteresis for step frequency comparison is 1/32");
  // BIT 15
  error+=AusgabeRegister(x32BitRegisters,0x00008000,"stop_enable 0: Normal operation 1: Emergency stop: ENCA_DCIN stops the sequencer when tied high (no steps become executed by the sequencer, motor goes to standstill state).");
  // BIT 16
  error+=AusgabeRegister(x32BitRegisters,0x00010000,"direct_mode 0: Normal operation 1: Motor coil currents and polarity directly programmed via serial interface: Register XTARGET (0x2D) specifies signed coil A current (bits 8..0) and coil B current (bits 24..16). In this mode, the current is scaled by IHOLD setting. Velocity based current regulation of StealthChop is not available in this mode. The automatic StealthChop current regulation will work only for low stepper motor velocities.");
  // BIT 17
  error+=AusgabeRegister(x32BitRegisters,0x00020000,"test_mode 0: Normal operation 1: Enable analog test output on pin ENCN_DCO. IHOLD[1..0] selects the function of ENCN_DCO: 0…2: T120, DAC, VDDH Hint: Not for user, set to 0 for normal operation!");
  error += "---------------General Configuration Registers---------------\r\n";
  Serial.print(error);
}
#endif

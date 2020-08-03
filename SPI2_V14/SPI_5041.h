/*
   SPI_5160.h

    Created on: 24.07.2019
    Author: Adam Wilczek
*/
#ifndef SPI_5041
#define SPI_5041
#include "SPI_5041_var.h"

DataOut sendData(DataOut in)
{
  //TMC5130 braucht 40 Bit. Davon sind 8 Bit die Adresse und 32 Bit das Datenpaket
  DataOut out = { 0x00, 0x00000000 };// Erstellung eines leeren Pakets
 // delay(100);// Unnötig???
  digitalWrite(CHIP_SELECT, LOW);// Chip für die Kommunikation vorbereiten
  //delayMicroseconds(100); // Unnötig???

  out.adresse = SPI.transfer(in.adresse);// Adresse wird verschicket und der letzte SPI Status wird empfangen
  out.daten |= SPI.transfer((in.daten >> 24) & 0xff);// ES Werden immer 8 BIT Geschickt und gleichzeitig empfangen und gesendet
  out.daten <<= 8;
  out.daten |= SPI.transfer((in.daten >> 16) & 0xff);
  out.daten <<= 8;
  out.daten |= SPI.transfer((in.daten >> 8) & 0xff);
  out.daten <<= 8;
  out.daten |= SPI.transfer((in.daten) & 0xff);// Datenpaket erfolgreich geschreiben mit jeweils 8 Bit SPI.transfer
  digitalWrite(CHIP_SELECT, HIGH);// Chip für die Kommunikation wieder freigeben
  return out;
}
#endif

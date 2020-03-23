#include <Arduino.h>
#include <SPI.h>

#define FPC_IRQ 22
#define FPC_RST 4

#include "FPC1020.h"

void FPC1020::init()
{
    // Chip select
    pinMode(SS, OUTPUT);
    digitalWrite(SS, HIGH);

    // IRQ / data ready
    pinMode(FPC_IRQ, INPUT);
    digitalWrite(FPC_IRQ, LOW);

    // RST
    pinMode(FPC_RST, OUTPUT);
}

void FPC1020::reset()
{
    digitalWrite(FPC_RST, LOW);
    delay(10);
    digitalWrite(FPC_RST, HIGH);
}

uint16_t FPC1020::hardware_id()
{
    digitalWrite(SS, LOW);
    SPI.write(0xFC);
    uint16_t status = SPI.transfer16(0x0);
    digitalWrite(SS, HIGH);

    return status;
}
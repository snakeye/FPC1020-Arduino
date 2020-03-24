#include <Arduino.h>
#include <SPI.h>

#define FPC_IRQ D1
#define FPC_RST D0

#include "FPC1020.h"

void FPC1020::init()
{
    // Chip select
    pinMode(PIN_SPI_SS, OUTPUT);
    digitalWrite(PIN_SPI_SS, HIGH);

    // IRQ / data ready
    pinMode(FPC_IRQ, INPUT);
    digitalWrite(FPC_IRQ, LOW);

    // RST
    pinMode(FPC_RST, OUTPUT);

    SPI.begin();
}

void FPC1020::reset()
{
    digitalWrite(FPC_RST, LOW);
    delay(10);
    digitalWrite(FPC_RST, HIGH);
}

uint16_t FPC1020::hardware_id()
{
    digitalWrite(PIN_SPI_SS, LOW);
    SPI.write(0xFC);
    uint16_t status = SPI.transfer16(0x0);
    digitalWrite(PIN_SPI_SS, HIGH);

    return status;
}
#include <Arduino.h>

#include "FPC1020.h"

FPC1020 fpc;

void setup()
{
    Serial.begin(115200);

    fpc.init();
    fpc.reset();

    delay(2000);

    Serial.println("FPC1020 test");

    fpc.setup();
}

void loop()
{
    Serial.printf("Hardware ID: 0x%04X\n", fpc.hardware_id());

    fpc.command(FPC102X_REG_FINGER_PRESENT_QUERY);
    // fpc.command(FPC102X_REG_WAIT_FOR_FINGER);

    delay(10);

    uint8_t interrupt = fpc.interrupt(true);

    Serial.printf("Interrupt status: 0x%02X\n", interrupt);

    if (interrupt == 0x81)
    {
        Serial.printf("Finger present status: 0x%04X\n", fpc.finger_present_status());
    }

    Serial.printf("Error status: 0x%02X\n", fpc.error());

    Serial.println();

    delay(1000);
}
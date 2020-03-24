#include <Arduino.h>

#include "FPC1020.h"

FPC1020 fpc;

void setup()
{
    Serial.begin(115200);

    fpc.init();
}

void loop()
{
    Serial.println("FPC1020 test");
    fpc.reset();

    delay(300);

    Serial.printf("Hardware ID: 0x%04X\n", fpc.hardware_id());

    delay(1000);
}
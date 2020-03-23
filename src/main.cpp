#include <Arduino.h>

#include "FPC1020.h"

FPC1020 fpc;

void setup()
{
    Serial.begin(115200);

    fpc.init();
    fpc.reset();

    delay(300);
}

void loop()
{
    Serial.println("FPC1020 test");
    Serial.print("Hardware ID: ");
    Serial.println(fpc.hardware_id());

    delay(1000);
}
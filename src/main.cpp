#include <stdio.h>
#include "Evelyn.h"

int pinA2 = 0;

class AnalogPinTwoEvent : public Event
{
private:
    int pinValue;
public:
    void updateState() override
    {
        pinValue = pinA2;
    }
    void handle() override
    {
        printf("%d\n", pinValue);
    }
    bool canBeTrigger() override {
        return pinA2 == 512 || pinA2 == 1024;
    }
};

Evelyn evelyn;

// Arduino simulation setup
void setup()
{
    evelyn.useEvent(EV_ID_PIN_A2, new AnalogPinTwoEvent());
}

// Arduino simulation loop
void loop()
{
    evelyn.mainloop();
}

// Entry point
int isRunning = 1;

int main()
{
    setup();

    while (isRunning)
    {   
        pinA2++;
        loop();
        if (pinA2 == 1024) {
            pinA2 = 0;
        }
    }

    return 0;
}
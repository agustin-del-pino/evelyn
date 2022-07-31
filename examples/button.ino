#include <Evelyn.h>

#define BTN_PIN 3

class ButtonEvent : public Event
{
public:
    void updateState() override
    {
        // Nothing to update.
    }
    void handle() override
    {
        Serial.println("The button was pressed");
    }
    bool canBeTrigger() override
    {
        return digitalRead(BTN_PIN) == HIGH;
    }
};


Evelyn evelyn;

void setup()
{
    pinMode(BTN_PIN, INPUT);
    evelyn.useEvent(EV_ID_PIN_3, new ButtonEvent());
}

void loop()
{
    evelyn.mainloop();
}
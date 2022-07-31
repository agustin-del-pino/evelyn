#include <Evelyn.h>

#define PTM_QUARTER 256
#define PTM_HALF 512
#define PTM_THREE_QUARTER 768
#define PTM_MAX 1024

#define PTM_MIN_STATE 0
#define PTM_QUARTER_STATE 1
#define PTM_HALF_STATE 2
#define PTM_THREE_STATE 3
#define PTM_MAX_STATE 4

class PotentiometerEvent : public Event
{
private:
    int potentiometer = 0;
    int state = PTM_MIN_STATE;

public:
    void updateState() override
    {
        if (potentiometer >= PTM_QUARTER && potentiometer <= PTM_HALF)
        {
            state = PTM_QUARTER_STATE;
        }
        else if (potentiometer >= PTM_HALF && potentiometer <= PTM_THREE_QUARTER)
        {
            state = PTM_HALF_STATE;
        }
        else if (potentiometer >= PTM_HALF && potentiometer <= PTM_THREE_QUARTER)
        {
            state = PTM_THREE_STATE;
        }
        else if (potentiometer >= PTM_HALF && potentiometer <= PTM_THREE_QUARTER)
        {
            state = PTM_MAX_STATE;
        }
        else
        {
            state = PTM_MIN_STATE;
        }
    }
    void handle() override
    {
        switch (state)
        {
        case PTM_MIN_STATE:
            Serial.println("The voltage is less than a quarter of the full capacity.");
            break;
        case PTM_QUARTER_STATE:
            Serial.println("The voltage is equal or more than a quarter of the full capacity.");
            break;
        case PTM_HALF_STATE:
            Serial.println("The voltage is equal or more than a the half of the full capacity.");
            break;
        case PTM_THREE_STATE:
            Serial.println("The voltage is equal or more than a three quarters of the full capacity.");
            break;
        case PTM_MAX_STATE:
            Serial.println("The voltage reached the full capacity.");
            break;
        }
    }
    bool canBeTrigger() override
    {
        potentiometer = analogRead(A0);
        return potentiometer >= PTM_QUARTER;
    }
};


Evelyn evelyn;

void setup()
{
    evelyn.useEvent(EV_ID_PIN_A0, new PotentiometerEvent());
}

void loop()
{
    evelyn.mainloop();
}
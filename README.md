# evelyn
Lib that pretends use events for manage the Ardunio flow.

## C or C++?
For now, the lib is quite C++ more than C, that because the lib use classes, but in the future I pretend switch to full C.


## Infrastructure

There are two simple objects: the Event Manager, and the Event itself.
The first one will pulling the state of the registered events searching for some which can be trigger.

### Diagram
```
Arduino Loop --------------------------> Evelyn
|                                          |
|                            |-> Search for an event <--------|                  
|                            |   /      |                     |
|                            |  /       |                     |
|                            | /        |                     |
|                            |/   Can be trigger?             |   
|                           /|    / No       Yes \            |
|                          / |_ Continue        Update State  |                           
|                         |                          &        | 
|                         |                     Execute the   |
|                         |                    event handler _|
|<------- No more events _|        
```

Using the mainloop the Evelyn inside of the Arduino Loop, it will search the registered events and then ask them if "can be trigger", depending on the response of the event, it will be update and execute or just ignore and pass to the next event.

## The Event Interface

This interface is the way someone can create an event. There are three method to implement:
- `bool canBeTrigger()` Determinate when the event can be executed. Returning True for granted otherwise False.
- `void updateState()`  Sort kind of "prepare event" method. It will execute before the handler.
- `void handle()`       The "callback" of the event.

## Registering Events
_Do this inside the setup Arduino function._

Already created the Event, just use the `useEvent()` method from `Evelyn`class for register it.
As first param is needed pass the `eventId` (there are many MACROs inside the lib for that), and as second, the new instance of the event.


```cpp
Evelyn evelyn;

void setup(){
    evelyn.useEvent(EV_ID_PIN_A0, new MyEvent());
}
```

# Quick Start
It can be useful the `/examples`. Here is a boilerplate.

```cpp
#include <Evelyn.h>

class MyEvent : public Event
{
public:
    void updateState() override
    {
        // Update your variables.
    }
    void handle() override
    {
        // Write some logic.
    }
    bool canBeTrigger() override
    {
        // return true or false
    }
};


Evelyn evelyn;

void setup()
{
    evelyn.useEvent(EV_ID_PIN_A0, new MyEvent());
}

void loop()
{
    evelyn.mainloop();
}
```
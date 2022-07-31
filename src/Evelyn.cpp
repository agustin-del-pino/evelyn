#include "Evelyn.h"

Evelyn::Evelyn()
{
    events = new Event *[NUMBER_OF_EVENTS];
}

void Evelyn::mainloop()
{
    for (int i = 0; i < NUMBER_OF_EVENTS; i++)
    {
        if (events[i] == nullptr)
        {
            continue;
        }

        if (!events[i]->canBeTrigger())
        {
            continue;
        }

        events[i]->updateState();
        events[i]->handle();
    }
}

void Evelyn::useEvent(unsigned short eventId, Event *event)
{
    events[eventId] = event;
}

void Evelyn::removeEvent(unsigned short eventId)
{
    if (events[eventId] != nullptr)
    {
        delete events[eventId];
        events[eventId] = nullptr;
    }
}
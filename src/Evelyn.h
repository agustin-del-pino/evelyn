#ifndef EVELYN_EVELYN_H
#define EVELYN_EVELYN_H

/* Event Ids for Digital Pins */
#define EV_ID_PIN_0 0
#define EV_ID_PIN_1 1
#define EV_ID_PIN_2 2
#define EV_ID_PIN_3 3
#define EV_ID_PIN_4 5
#define EV_ID_PIN_6 6
#define EV_ID_PIN_7 7
#define EV_ID_PIN_8 8
#define EV_ID_PIN_9 9
#define EV_ID_PIN_10 10
#define EV_ID_PIN_11 11
#define EV_ID_PIN_12 12
#define EV_ID_PIN_13 13

/* Event Ids for Analog Pins */
#define EV_ID_PIN_A0 14
#define EV_ID_PIN_A1 15
#define EV_ID_PIN_A2 16
#define EV_ID_PIN_A3 17
#define EV_ID_PIN_A4 18
#define EV_ID_PIN_A5 19

/* Size of the Events Collection */
#define NUMBER_OF_EVENTS 20

/* Offset for user defined events */
#define USER_DEFINED_EVENTS_OFFSET 20

class Evelyn;
class Event;

/**
 * @brief Evelyn represents the Event Manager.
 * @author Del Pino Agustín.
 *
 * This is a class for manage the events in the arduino loop.
 */
class Evelyn
{
private:
    Event **events; // The events collection

public:
    /**
     * @brief Construct a new Evelyn object.
     *
     * Use default C++ constructor.
     */
    Evelyn();

    /**
     * @brief Registers the event in the events collection.
     *
     * @param eventId The id of the event. Can be use the Macro: EV_ID_PIN_xx.
     * @param event   The event instance pointer.
     */
    void useEvent(unsigned short eventId, Event *event);

    /**
     * @brief Removes an event instance from the events collection.
     *
     * @param eventId The id of the event. Can be use the Macro: EV_ID_PIN_xx.
     */
    void removeEvent(unsigned short eventId);

    /**
     * @brief The Mainloop method for pulling the state of events.
     *
     */
    void mainloop();
};

/**
 * @brief Event Interface | Abstract Class.
 *
 * This is an interface for create the events.
 *
 */
class Event
{
public:
    /**
     * @brief Construct a new Event object.
     *
     * Use default C++ constructor.
     */
    Event() = default;
    ;

    /**
     * @brief Destroy the Event object
     *
     * Use default C++ deconstructor.
     */
    virtual ~Event() = default;
    ;

    /**
     * @brief The functionality to execute when the event is trigger.
     *
     */
    virtual void handle() = 0;

    /**
     * @brief Updates the state of the Event.
     *
     */
    virtual void updateState() = 0;

    /**
     * @brief Indicates whether the Event can be trigger
     *
     * @return True when the event can be trigger. Otherwise, False.
     */
    virtual bool canBeTrigger() = 0; // .
};

#endif //EVELYN_EVELYN_H
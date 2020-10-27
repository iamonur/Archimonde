#ifndef EVENTS_H
#define EVENTS_H

class Event{

};

class Event_with_position : public Event{

}; //Could be a click, a touchscreen event etc.

class Event_without_position : public Event{

}; //Could be a mic. event, or like a wakeup event on a touchscreen.

#endif//EVENTS_H
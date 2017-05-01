// guidisplay.hpp

#include "guidisplay.hpp"

using namespace gui;

#define SLEEP_DELAY 0.001


Display::Display ( ALLEGRO_DISPLAY *al_display )
{
  this->al_display = al_display;
  this->event_queue = al_create_event_queue();
  al_register_event_source(this->event_queue, al_get_display_event_source(al_display));
}



void Display::run ()
{
  ALLEGRO_EVENT event;
  while (1)
    {
      if (al_get_next_event(this->event_queue, &event))
        {
          switch (event.type)
            {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
              DEBUG("display close, bye!");
              exit(0);
              break;
            default:
              DEBUG("unknown event: %d", event.type);
            }
        }
      else
        {
          al_rest(SLEEP_DELAY);
        }
    }
}

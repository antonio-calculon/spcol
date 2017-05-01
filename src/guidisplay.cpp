// guidisplay.hpp

#include "private.hpp"
#include "guidisplay.hpp"
#include "guiwindow.hpp"

using namespace gui;

#define SLEEP_DELAY 0.001


static void _event_handler ( Display *display, ALLEGRO_EVENT *event, void *data )
{
  display->process_event(event);
}


Display::Display ( ALLEGRO_DISPLAY *al_display )
{
  this->al_display = al_display;
  this->event_queue = al_create_event_queue();
  al_register_event_source(this->event_queue, al_get_display_event_source(al_display));
  this->event_handler = _event_handler;
  this->event_handler_data = NULL;
}



void Display::attach_root_window ( Window *window )
{
  DEBUG("new root window");
  this->root_windows.push_back((Window *) window->ref());
}



void Display::set_event_handler ( EventHandler handler,
                                  void *data )
{
  this->event_handler = handler;
  this->event_handler_data = data;
}



void Display::register_event_source ( ALLEGRO_EVENT_SOURCE *source )
{
  al_register_event_source(this->event_queue, source);
}


bool Display::process_resize ()
{
  bool r = false;
  auto end = this->root_windows.end();
  for (auto it=this->root_windows.begin(); it != end; it++)
    {
      if ((*it)->needs_resize())
        {
          (*it)->process_resize();
          r = true;
        }
    }
  return r;
}



void Display::run ()
{
  ALLEGRO_EVENT event;
  while (1)
    {
      if (al_get_next_event(this->event_queue, &event))
        {
          this->event_handler(this, &event, this->event_handler_data);
        }
      else if (this->process_resize())
        {
        }
      else
        {
          al_rest(SLEEP_DELAY);
        }
    }
}


void Display::process_event ( ALLEGRO_EVENT *event )
{
  switch (event->type)
    {
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      DEBUG("display close, bye!");
      exit(0);
      break;
    default:
      DEBUG("unknown event: %d", event->type);
    }
}

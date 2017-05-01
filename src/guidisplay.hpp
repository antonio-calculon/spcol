// guidisplay.hpp

#ifndef _GUIDISPLAY_HPP_
#define _GUIDISPLAY_HPP_

#include "private.hpp"
#include "guibase.hpp"

// gui::Display
//
namespace gui
{
  class Display
  {
  private:
    ALLEGRO_DISPLAY *al_display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    
  public:
    Display ( ALLEGRO_DISPLAY *al_display );
    void run ();
  };
}

#endif

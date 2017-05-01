// guidisplay.hpp

#ifndef _GUIDISPLAY_HPP_
#define _GUIDISPLAY_HPP_

#include "private.hpp"
#include "guibase.hpp"
#include <vector>

// gui::Display
//
namespace gui
{
  class Display;
  class Window;
  
  typedef void (* EventHandler) ( Display *display,
                                  ALLEGRO_EVENT *event,
                                  void *data );
  
  class Display
  {
    friend Window; // [FIXME] only for attach_root_window
    
  private:
    ALLEGRO_DISPLAY *al_display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    EventHandler event_handler;
    void *event_handler_data;
    std::vector<Window *> root_windows;
    
    void attach_root_window ( Window *window );
    bool process_resize ();
    
  public:
    Display ( ALLEGRO_DISPLAY *al_display );
    void set_event_handler ( EventHandler handler,
                             void *data );
    void register_event_source ( ALLEGRO_EVENT_SOURCE *source );
    void process_event ( ALLEGRO_EVENT *event );
    void run ();
  };
}

#endif

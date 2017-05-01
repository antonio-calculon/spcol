// guidisplay.hpp

#ifndef _GUIDISPLAY_HPP_
#define _GUIDISPLAY_HPP_

#include "guibase.hpp"

// gui::Display
//
namespace gui
{
  class Display
  {
  private:
    ALLEGRO_DISPLAY *al_display;

  public:
    Display ( ALLEGRO_DISPLAY *al_display );
  };
}

#endif

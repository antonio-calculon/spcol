// guiwindow.hpp

#ifndef _GUIWINDOW_HPP_
#define _GUIWINDOW_HPP_

#include "guibin.hpp"

// gui::Window
//
namespace gui
{
  class Display;
  
  class Window : public Bin
  {
  private:
    Display *display;

  public:
    Window ( Display *display );
  };
}

#endif

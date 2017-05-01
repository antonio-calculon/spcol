// guiwindow.hpp

#ifndef _GUIWINDOW_HPP_
#define _GUIWINDOW_HPP_

#include "guiwidget.hpp"

// gui::Window
//
namespace gui
{
  class Display;
  
  class Window : public Widget
  {
  private:
    Display *display;

  public:
    Window ( Display *display );
  };
}

#endif

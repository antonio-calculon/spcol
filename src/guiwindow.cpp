// guiwindow.hpp

#include "guiwindow.hpp"
#include "guidisplay.hpp"

using namespace gui;



Window::Window ( Display *display )
{
  this->display = display;
  display->attach_root_window(this);
}

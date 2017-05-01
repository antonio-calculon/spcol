// guiwindow.hpp

#include "private.hpp"
#include "guiwindow.hpp"
#include "guidisplay.hpp"

using namespace gui;



Window::Window ( Display *display )
{
  DEBUG("window construct");
  this->display = display;
  display->attach_root_window(this);
}

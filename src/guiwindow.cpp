// guiwindow.hpp

#include "private.hpp"
#include "guiwindow.hpp"
#include "guidisplay.hpp"

using namespace gui;



Window::Window ( Display *display )
{
  DEBUG("window construct");
  this->set_root_widget();
  this->display = display;
  display->attach_root_window(this);
}



Display *Window::get_display ()
{
  return display;
}

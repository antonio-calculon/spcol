// guiwidget.hpp

#ifndef _GUIWIDGET_HPP_
#define _GUIWIDGET_HPP_

#include "guibase.hpp"

// gui::Widget
//
namespace gui
{
  class Widget
  {
  public:
    virtual void show ();
    virtual void show_all ();
  };
}

#endif

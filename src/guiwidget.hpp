// guiwidget.hpp

#ifndef _GUIWIDGET_HPP_
#define _GUIWIDGET_HPP_

#include "guibase.hpp"

// gui::Widget
//
namespace gui
{
  class Container;
  
  enum
    {
      WIDGET_FLAG_NEEDS_RESIZE = 1 << 0,
    };

  class Widget
  {
  private:
    int flags;
    Container *parent;

  public:
    Widget ();
    void set_parent ( Container *parent ); // [FIXME] should be private or something
    virtual void show ();
    virtual void show_all ();
  };
}

#endif

// guicontainer.hpp

#ifndef _GUICONTAINER_HPP_
#define _GUICONTAINER_HPP_

#include "guiwidget.hpp"

// gui::Container
//
namespace gui
{
  class Container : public Widget
  {
  public:
    virtual void add ( Widget *child ) = 0;
  };
}

#endif

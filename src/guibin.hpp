// guibin.hpp

#ifndef _GUIBIN_HPP_
#define _GUIBIN_HPP_

#include "guicontainer.hpp"

// gui::Bin
//
namespace gui
{
  class Bin : public Container
  {
  private:
    Widget *child;
    
  public:
    Bin ();
    void add ( Widget *child );
  };
}

#endif

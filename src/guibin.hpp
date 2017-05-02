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
    virtual void on_size_request ( SizeRequest *req );
    virtual void on_size_allocate ( Allocation *alloc );
    void add ( Widget *child );
  };
}

#endif

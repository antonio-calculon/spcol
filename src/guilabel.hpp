// guilabel.hpp

#ifndef _GUILABEL_HPP_
#define _GUILABEL_HPP_

#include "guiwidget.hpp"
#include <string>

// gui::Label
//
namespace gui
{
  class Label : public Widget
  {
  private:
    std::string text;
    
  public:
    Label ( const char *text );
    virtual void on_size_request ( SizeRequest *req );
    virtual void on_size_allocate ( Allocation *alloc );
  };
}

#endif

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
  };
}

#endif

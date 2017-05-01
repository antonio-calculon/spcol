// guiobject.hpp

#ifndef _GUIOBJECT_HPP_
#define _GUIOBJECT_HPP_

#include "guibase.hpp"

// gui::Object
//
namespace gui
{
  class Object
  {
  private:
    unsigned int ref_count;
  public:
    Object();
    virtual ~Object();
    Object *ref ();
    void unref ();
  };
}

#endif

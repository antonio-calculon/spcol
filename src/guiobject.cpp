// guiobject.hpp

#include "private.hpp"
#include "guiobject.hpp"

using namespace gui;



Object::Object()
{
  ref_count = 1;
}



Object::~Object()
{
  DEBUG("object destroyed");
}



Object *Object::ref ()
{
  ref_count++;
  return this;
}



void Object::unref ()
{
  if (!(--ref_count))
    delete this;
}


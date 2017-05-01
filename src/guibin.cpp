// guibin.hpp

#include "private.hpp"
#include "guibin.hpp"

using namespace gui;



Bin::Bin ()
{
  this->child = NULL;
}



void Bin::add ( Widget *child )
{
  DEBUG("Bin::add()");
  ASSERT(!this->child);
  child->set_parent(this);
  this->child = child;
}

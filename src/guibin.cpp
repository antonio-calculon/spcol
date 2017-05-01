// guibin.hpp

#include "private.hpp"
#include "guibin.hpp"

using namespace gui;



Bin::Bin ()
{
  this->child = NULL;
}



void Bin::on_size_request ( SizeRequest *req )
{
  DEBUG("bin size request (%p)", child);
  if (child)
    {
      child->size_request(req);
    }
}



void Bin::on_size_allocate ( Allocation *alloc )
{
  DEBUG("bin alloc...");
  if (child)
    {
      child->size_allocate(alloc);
    }
}



void Bin::add ( Widget *child )
{
  DEBUG("Bin::add()");
  ASSERT(!this->child);
  child->set_parent(this);
  this->child = child;
  child->queue_resize();
}

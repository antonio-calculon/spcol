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
  if (child && child->visible())
    {
      child->size_request(req);
    }
}



void Bin::on_size_allocate ( Allocation *alloc )
{
  DEBUG("bin alloc...");
  if (child && child->visible())
    {
      child->size_allocate(alloc);
    }
}



void Bin::add ( Widget *child )
{
  DEBUG("Bin::add()");
  ASSERT(!this->child);
  this->child = (Bin *) child->ref();
  child->set_parent(this);
  child->queue_resize();
}



bool Bin::foreach ( ForeachFunc func,
                    void *data )
{
  DEBUG("Bin::foreach()");
  if (child)
    {
      return func(child, data);
    }
  else
    {
      return true;
    }
}

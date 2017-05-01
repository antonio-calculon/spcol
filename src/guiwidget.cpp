// guiwidget.hpp

#include "private.hpp"
#include "guiwidget.hpp"

using namespace gui;


Widget::Widget ()
{
  this->flags = 0;
  this->parent = NULL;
}



void Widget::set_parent ( Widget *parent )
{
  ASSERT(!this->parent);
  this->parent = parent;
}



void Widget::queue_resize ()
{
  Widget *w = this;
  while (w && w->visible())
    {
      w->flags |= WIDGET_FLAG_NEEDS_SIZE_REQUEST;
      if ((!w->parent) && (w->flags & WIDGET_FLAG_ROOT_WIDGET))
        w->flags |= WIDGET_FLAG_NEEDS_RESIZE;
      w = w->parent;
    }
}



void Widget::size_request ( SizeRequest *req )
{
  if (needs_size_request())
    {
      on_size_request(req);
      request = *req;
      flags &= ~WIDGET_FLAG_NEEDS_SIZE_REQUEST;
    }
  else
    {
      *req = request;
    }
}



void Widget::size_allocate ( Allocation *alloc )
{
  on_size_allocate(alloc);
}



void Widget::process_resize ()
{
  SizeRequest req = { 0, 0 };
  Allocation alloc;
  size_request(&req);
  DEBUG("size_request -> %d, %d", req.width, req.height);
  alloc.x = 0;
  alloc.y = 0;
  alloc.width = req.width;
  alloc.height = req.height;
  size_allocate(&alloc);
  flags &= ~WIDGET_FLAG_NEEDS_RESIZE;
}



void Widget::show ()
{
}


void Widget::show_all ()
{
}

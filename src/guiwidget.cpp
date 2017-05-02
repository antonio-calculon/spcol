// guiwidget.hpp

#include "private.hpp"
#include "guiwidget.hpp"
#include "guidisplay.hpp"

using namespace gui;


Widget::Widget ()
{
  this->flags = 0;
  this->parent = NULL;
}



void Widget::set_parent ( Widget *parent )
{
  ASSERT(!this->parent);
  ASSERT(!root_widget());
  this->parent = parent; // [FIXME] weakref
}


Widget *Widget::get_root ()
{
  Widget *w = this;
  while (w->parent)
    w = w->parent;
  return w->root_widget() ? w : NULL;
}



Display *Widget::get_display ()
{
  Widget *root = get_root();
  return root ? root->get_display() : NULL;
}



void Widget::queue_resize ()
{
  Widget *w = this;
  while (w && w->visible())
    {
      w->flags |= WIDGET_FLAG_NEEDS_RESIZE;
      if ((!w->parent) && (w->flags & WIDGET_FLAG_ROOT_WIDGET))
        {
          Display *d = w->get_display();
          if (d)
            d->queue_resize(w);
          break;
        }
      w = w->parent;
    }
}



void Widget::size_request ( SizeRequest *req )
{
  if (needs_resize())
    {
      on_size_request(req);
      request = *req;
      flags &= ~WIDGET_FLAG_NEEDS_RESIZE;
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

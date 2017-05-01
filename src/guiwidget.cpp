// guiwidget.hpp

#include "private.hpp"
#include "guiwidget.hpp"

using namespace gui;


Widget::Widget ()
{
  this->flags = 0;
  this->parent = NULL;
}



void Widget::set_parent ( Container *parent )
{
  ASSERT(!this->parent);
  this->parent = parent;
}



void Widget::show ()
{
}


void Widget::show_all ()
{
}

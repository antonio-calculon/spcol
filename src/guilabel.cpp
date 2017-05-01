// guilabel.hpp

#include "private.hpp"
#include "guilabel.hpp"

using namespace gui;



Label::Label ( const char *text )
{
  this->text = text;
}



void Label::on_size_request ( SizeRequest *req )
{
  DEBUG("label size request");
  req->width = 80;
  req->height = 10;
}



void Label::on_size_allocate ( Allocation *alloc )
{
  DEBUG("label alloc: %d, %d, %d, %d", alloc->x, alloc->y, alloc->width, alloc->height);
}

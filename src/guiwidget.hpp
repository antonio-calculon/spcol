// guiwidget.hpp

#ifndef _GUIWIDGET_HPP_
#define _GUIWIDGET_HPP_

#include "guiobject.hpp"

// gui::Widget
//
namespace gui
{
  class Display;
  class Container;
  
  typedef struct _SizeRequest SizeRequest;
  typedef struct _Allocation Allocation;
  
  enum
    {
      WIDGET_FLAG_ROOT_WIDGET  = 1 << 0,
      WIDGET_FLAG_NEEDS_RESIZE = 1 << 1,
      WIDGET_FLAG_NEEDS_SIZE_REQUEST = 1 << 2,
      WIDGET_FLAG_VISIBLE = 1 << 3,
    };

  struct _SizeRequest
  {
    int width;
    int height;
  };

  struct _Allocation
  {
    int x;
    int y;
    int width;
    int height;
  };

  class Widget : public Object
  {
    friend Display; // [FIXME] really ??
    
  private:
    int flags;
    Widget *parent;
    SizeRequest request;
    int x;
    int y;
    int width;
    int height;
    
    void process_resize ();
    
  public:
    // flags
    bool visible () { return flags & WIDGET_FLAG_VISIBLE; }
    bool needs_resize () { return this->flags & WIDGET_FLAG_NEEDS_RESIZE; }
    bool needs_size_request () { return this->flags & WIDGET_FLAG_NEEDS_SIZE_REQUEST; }
    //
    Widget ();
    void set_root_widget () { this->flags |= WIDGET_FLAG_ROOT_WIDGET; } // [FIXME] should be private
    void set_parent ( Widget *parent ); // [FIXME] should be private
    void size_request ( SizeRequest *req );
    void size_allocate ( Allocation *alloc );
    virtual void on_size_request ( SizeRequest *req ) = 0;
    virtual void on_size_allocate ( Allocation *alloc ) = 0;
    
    void queue_resize ();
    virtual void show ();
    virtual void show_all ();
  };
}

#endif

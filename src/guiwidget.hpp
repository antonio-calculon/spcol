// guiwidget.hpp

#ifndef _GUIWIDGET_HPP_
#define _GUIWIDGET_HPP_

#include "guibase.hpp"

#include <vector>

// gui::Widget
//
namespace gui
{
  class Widget;
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

  class Widget
  {
    friend Display; // [FIXME] really ??
    
  private:
    unsigned int ref_count;
    int flags;
    std::vector<Widget *> children;
    Widget *parent;
    SizeRequest request;
    int x;
    int y;
    int width;
    int height;
    
    void process_resize ();
    void _show_all();
    
  public:
    // flags
    bool visible () { return flags & WIDGET_FLAG_VISIBLE; }
    bool needs_resize () { return this->flags & WIDGET_FLAG_NEEDS_RESIZE; }
    bool needs_size_request () { return this->flags & WIDGET_FLAG_NEEDS_SIZE_REQUEST; }
    //
    Widget ();
    virtual ~Widget ();
    Widget *ref ();
    void unref ();
    void set_root_widget () { this->flags |= WIDGET_FLAG_ROOT_WIDGET; } // [FIXME] should be private
    void add ( Widget *child );
    void give ( Widget *child );
    void size_request ( SizeRequest *req );
    void size_allocate ( Allocation *alloc );
    virtual void on_size_request ( SizeRequest *req );
    virtual void on_size_allocate ( Allocation *alloc );
    void queue_resize ();
    virtual void show ();
    virtual void show_all ();
  };
}

#endif

// guiwidget.hpp

#ifndef _GUIWIDGET_HPP_
#define _GUIWIDGET_HPP_

#include "guiobject.hpp"

#include <iterator>

// gui::Widget
//
namespace gui
{
  class Widget;
  class Display;
  class Container;
  
  typedef struct _SizeRequest SizeRequest;
  typedef struct _Allocation Allocation;

  typedef bool (* ForeachFunc) ( Widget *widget,
                                 void *data );
  
  enum
    {
      WIDGET_FLAG_ROOT_WIDGET  = 1 << 0,
      WIDGET_FLAG_NEEDS_RESIZE = 1 << 1,
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
    static bool _show_all ( Widget *widget,
                            void *data );
    
  public:
    // flags
    bool destroyed () { return false; } // [TODO]
    bool visible () { return flags & WIDGET_FLAG_VISIBLE; }
    bool needs_resize () { return this->flags & WIDGET_FLAG_NEEDS_RESIZE; }
    bool root_widget () { return this->flags & WIDGET_FLAG_ROOT_WIDGET; }
    //
    Widget ();
    void set_root_widget () { this->flags |= WIDGET_FLAG_ROOT_WIDGET; } // [FIXME] should be private
    Widget *get_root ();
    virtual Display *get_display ();
    void set_parent ( Widget *parent ); // [FIXME] should be private
    void size_request ( SizeRequest *req );
    void size_allocate ( Allocation *alloc );
    virtual void on_size_request ( SizeRequest *req ) = 0;
    virtual void on_size_allocate ( Allocation *alloc ) = 0;
    
    void queue_resize ();
    virtual void show ();
    virtual void show_all ();
    // for containers
    virtual bool foreach ( ForeachFunc func,
                           void *data )
    {
      return true;
    }
    virtual bool forall ( ForeachFunc func,
                          void *data )
    {
      return foreach(func, data);
    }
  };
}

#endif

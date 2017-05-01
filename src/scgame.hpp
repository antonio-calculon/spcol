
#ifndef _SCGAME_HPP_
#define _SCGAME_HPP_

#include "scbase.hpp"
#include "gui.hpp"

namespace Sc
{
  class Game
  {
  private:
    iso::Map *map;
    iso::View *main_view;
    gui::Display *display;
    ALLEGRO_TIMER *timer;
  public:
    Game();
    void setup ();
    void start ( gui::Display *display );
    void update ();
    void render ();
  };
}

#endif

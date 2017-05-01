
#ifndef _SCGAME_HPP_
#define _SCGAME_HPP_

#include "scbase.hpp"

namespace Sc
{
  class Game
  {
  private:
    iso::Map *map;
    iso::View *main_view;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_DISPLAY *al_display; // shouldn't be here
  public:
    Game();
    void setup ();
    void start ();
    void update ();
    void display ();
  };
}

#endif

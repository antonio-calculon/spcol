
#ifndef _SCGAME_HPP_
#define _SCGAME_HPP_

#include "scbase.hpp"
#include "scmap.hpp"

namespace Sc
{
  class Game
  {
  private:
    Map map;
    ALLEGRO_DISPLAY *display; // shouldn't be here
  public:
    Game();
    void setup ();
  };
}

#endif

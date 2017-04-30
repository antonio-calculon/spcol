
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
  public:
    Game();
    void setup ();
  };
}

#endif

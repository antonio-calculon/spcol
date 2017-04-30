// main.cxx

#include "private.hpp"
#include "scbase.hpp"
#include "scgame.hpp"

using namespace Sc;


// main:
//
int main ()
{
  Game game;
  DEBUG("Hello!");
  al_init();
  game.setup();
  return 0;
}

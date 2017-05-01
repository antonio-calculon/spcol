// main.cxx

#include "private.hpp"
#include "scbase.hpp"
#include "scgame.hpp"
#include "gui.hpp"

using namespace Sc;
using namespace gui;


// main:
//
int main ()
{
  Game game;
  DEBUG("Hello!");
  al_init();
  game.setup();
  ALLEGRO_DISPLAY *al_display = al_create_display(640, 480);
  Display *display = new Display(al_display);
  game.start(display);
  return 0;
}

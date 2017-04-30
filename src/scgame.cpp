//

#include "private.hpp"
#include "scgame.hpp"

using namespace Sc;

Game::Game()
{
  DEBUG("new game");
}

void Game::setup ()
{
  DEBUG("game setup");
  this->map.setup();
  iso::LayerMesh layer(256, 256);
  this->map.add_layer(&layer);
  this->display = al_create_display(640, 400);
  al_rest(2);
}

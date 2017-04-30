//

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
}

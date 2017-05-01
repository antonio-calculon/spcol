//

#include "private.hpp"
#include "scgame.hpp"
#include "gui.hpp"

using namespace Sc;
using namespace gui;

Game::Game()
{
  DEBUG("new game");
  this->display = NULL;
}

void Game::setup ()
{
  DEBUG("game setup");
  this->map = new iso::Map();
  this->map->setup();
  iso::Layer *layer = new iso::LayerMesh(256, 256);
  this->map->add_layer(layer);
  this->main_view = new iso::View(this->map);
}

void Game::start ( Display *display )
{
  this->display = display;
  this->display->run();
}

void Game::update ()
{
  // DEBUG("update...");
}

void Game::render ()
{
  // al_set_target_backbuffer(this->al_display);
  // this->main_view->display();
  // void al_flip_display();
}

//

#include "private.hpp"
#include "scgame.hpp"
#include "gui.hpp"

using namespace Sc;
using namespace gui;

static void _event_handler ( Display *display,
                             ALLEGRO_EVENT *event,
                             Game *game );

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

void Game::setup_gui ()
{
  this->side_panel = new Window(this->display);
  Label *label = new Label("Hello!");
  this->side_panel->add(label);
  this->side_panel->show_all();
}

void Game::start ( Display *display )
{
  this->display = display;
  this->display->set_event_handler((EventHandler) _event_handler, this);
  this->setup_gui();
  this->timer = al_create_timer(1.0/10.0);
  this->display->register_event_source(al_get_timer_event_source(this->timer));
  al_start_timer(this->timer);
  this->display->run();
}

void Game::update ()
{
  DEBUG("update...");
}

static void _event_handler ( Display *display,
                             ALLEGRO_EVENT *event,
                             Game *game )
{
  if (event->type == ALLEGRO_EVENT_TIMER && event->timer.source == game->get_timer())
    {
      game->update();
    }
  else
    {
      display->process_event(event);
    }
}

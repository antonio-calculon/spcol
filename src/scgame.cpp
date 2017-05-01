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
  this->event_queue = al_create_event_queue();
  this->timer = al_create_timer(1.0/10.0);
  al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
  this->map = new iso::Map();
  this->map->setup();
  iso::Layer *layer = new iso::LayerMesh(256, 256);
  this->map->add_layer(layer);
  this->main_view = new iso::View(this->map);
  // should not be here
  this->al_display = al_create_display(640, 400);
  al_register_event_source(this->event_queue, al_get_display_event_source(this->al_display));
}

void Game::start ()
{
  DEBUG("starting game");
  al_start_timer(this->timer);
  while (1)
    {
      ALLEGRO_EVENT event;
      al_wait_for_event(this->event_queue, &event);
      switch (event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
          DEBUG("close!");
          exit(0);
          break;
        case ALLEGRO_EVENT_TIMER:
          // DEBUG("timer!");
          this->update();
          this->display();
          break;
        default:
          DEBUG("unknown event: %d", event.type);
        }
    }
}

void Game::update ()
{
  // DEBUG("update...");
}

void Game::display ()
{
  al_set_target_backbuffer(this->al_display);
  this->main_view->display();
  void al_flip_display();
}

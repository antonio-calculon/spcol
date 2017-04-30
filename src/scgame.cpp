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
  this->map.setup();
  iso::LayerMesh layer(256, 256);
  this->map.add_layer(&layer);
  // should not be here
  this->display = al_create_display(640, 400);
  al_register_event_source(this->event_queue, al_get_display_event_source(this->display));
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
          DEBUG("timer!");
          break;
        default:
          DEBUG("unknown event: %d", event.type);
        }
    }
}

#include "Spaceship.h"

Spaceship::Spaceship() {
  pos.x = (float)SCREEN_WIDTH / 2;
  pos.y = (float)SCREEN_HEIGHT / 2;

  rot = DEG2RAD * 180.0f;

  ship_dir.x = cos(rot);
  ship_dir.y = sin(rot);
}

void Spaceship::draw_ship() { // draw_lines(ship_map, 5, position, 16.0f, 1.0f);
  draw_lines(ship_map, sizeof(ship_map) / sizeof(ship_map[0]), pos, SCALE, rot,
             THICKNESS);
}

void Spaceship::draw_thrust() {
  draw_lines(thrust_map, sizeof(thrust_map) / sizeof(thrust_map[0]), pos, SCALE,
             rot, THICKNESS);
}

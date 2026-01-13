#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "constants.h"

#include "utils.h"
#include <raylib.h>

class Spaceship {
private:
public:
  static constexpr Vector2 ship_map[] = SHIP_MAP;
  static constexpr Vector2 thrust_map[] = THRUST_MAP;

  Vector2 pos;
  Vector2 vel;
  float rot;
  Vector2 ship_dir;

  Spaceship();
  // void set_rot(float rot_) { rot = rot_; };

  // update
  void handle_movement();

  // render
  void draw_ship();
  void draw_thrust();
};

#endif

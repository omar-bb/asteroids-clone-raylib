#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "constants.h"

#include "utils.h"
#include <raylib.h>

class Spaceship {
public:
  static const std::array<Vector2, SHIP_MAP_LENGTH> ship_map;
  static const std::array<Vector2, THRUST_MAP_LENGTH> thrust_map;

  // constructor
  Spaceship();

  // destructor
  ~Spaceship() = default;

  // setters and getters
  Vector2 get_pos() const;
  Vector2 get_vel() const;
  float get_rot() const;
  Vector2 get_ship_dir() const;

  void set_pos(const Vector2 &pos);
  void set_vel(const Vector2 &vel);
  void set_rot(float rot);
  void set_ship_dir(const Vector2 &ship_dir);

  // render
  void draw_ship();
  void draw_thrust();

private:
  Vector2 pos_;
  Vector2 vel_;
  float rot_;
  Vector2 ship_dir_;
};

#endif

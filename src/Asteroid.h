#ifndef ASTEROID_H
#define ASTEROID_H

#include "constants.h"

#include "utils.h"
#include <ctime>
#include <iostream>
#include <raylib.h>

enum class AsteroidSize { BIG, MEDIUM, SMALL };

class AsteroidSizeWrapper {
public:
  AsteroidSizeWrapper(AsteroidSize size) : size_(size) {};

  float size() {
    constexpr float size[] = {ASTER_BIG, ASTER_MEDIUM, ASTER_SMALL};
    return size[static_cast<int>(this->size_)];
  }

  float vel_scale() {
    const float vel_scale[] = {ASTER_VELSCALE_BIG, ASTER_VELSCALE_MEDIUM,
                               ASTER_VELSCALE_SMALL};
    return vel_scale[static_cast<int>(this->size_)];
  }

private:
  AsteroidSize size_;
};

class Asteroid {
public:
  Asteroid(float size_, Vector2 pos_, Vector2 vel);

  ~Asteroid() = default;

  Vector2 get_pos() const;
  Vector2 get_vel() const;
  AsteroidSize get_size() const;

  void set_pos(const Vector2 &pos);
  void set_vel(const Vector2 &vel);

  void draw_asteroid();

private:
  std::array<Vector2, MAX_NB_SIDES> asteroid_map;
  int nb_of_sides_;

  Vector2 vel_;
  Vector2 pos_;
  float size_;
};

#endif

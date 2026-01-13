#ifndef ASTEROID_H
#define ASTEROID_H

#include "constants.h"

#include "utils.h"
#include <ctime>
#include <iostream>
#include <raylib.h>

// typedef enum AsteroidSize { BIG = 30, MEDIUM = 15, SMALL = 5 } AsteroidSize;

namespace AsteroidSize {
constexpr float BIG = SCALE * 2.0f;
constexpr float MEDIUM = SCALE * 1.4f;
constexpr float SMALL = SCALE * 0.8;
} // namespace AsteroidSize

class Asteroid {
private:
  Vector2 *asteroid_map;
  Vector2 pos;
  Vector2 vel;
  float size;
  int nb_of_sides;

public:
  Asteroid(float size_, Vector2 pos_, Vector2 vel);
  ~Asteroid();

  void draw_asteroid();
};

#endif

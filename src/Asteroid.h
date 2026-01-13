#ifndef ASTEROID_H
#define ASTEROID_H

#include "constants.h"

#include "utils.h"
#include <ctime>
#include <iostream>
#include <raylib.h>

typedef enum AsteroidSize { BIG, MEDIUM, SMALL } AsteroidSize;

class Asteroid {
private:
  Vector2 *asteroid_map;

  Vector2 pos;
  AsteroidSize size;
  int nb_of_sides;

public:
  Asteroid(AsteroidSize size_, Vector2 pos_);
  ~Asteroid();

  void draw_asteroid();
};

#endif

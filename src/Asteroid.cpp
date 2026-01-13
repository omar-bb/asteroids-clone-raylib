#include "Asteroid.h"

Asteroid::Asteroid(float size_, Vector2 pos_, Vector2 vel_)
    : size(size_), pos(pos_), vel(vel_) {
  nb_of_sides = random_range<int>(MIN_NB_SIDES, MAX_NB_SIDES);
  asteroid_map = new Vector2[nb_of_sides];
  float ran_r = random_range<float>(MIN_R, MAX_R);
  float ran_ang = random_range<float>(0.7 * (ANGLE_DEG / nb_of_sides),
                                      ANGLE_DEG / nb_of_sides);
  float ran_ang_b = 0.0f;
  for (size_t i = 0; i < nb_of_sides; i++) {
    asteroid_map[i].x = ran_r * cos((ran_ang + ran_ang_b) * DEG2RAD);
    asteroid_map[i].y = ran_r * sin((ran_ang + ran_ang_b) * DEG2RAD);
    ran_r = random_range<float>(MIN_R, MAX_R);
    ran_ang_b += ran_ang;
    ran_ang = random_range<float>(0.7 * (ANGLE_DEG / nb_of_sides),
                                  ANGLE_DEG / nb_of_sides);
  }
}

Asteroid::~Asteroid() { delete[] asteroid_map; }

void Asteroid::draw_asteroid() {
  draw_lines(asteroid_map, nb_of_sides, pos, size, 0.0f, 1.0f);
}

#include "Asteroid.h"
#include "raylib.h"

Asteroid::Asteroid(float size, Vector2 pos, Vector2 vel)
    : size_(size), pos_(pos), vel_(vel) {
  nb_of_sides_ = random_range<int>(MIN_NB_SIDES, MAX_NB_SIDES);

  float ran_r = random_range<float>(MIN_R, MAX_R);
  float ran_ang = random_range<float>(0.7 * (ANGLE_DEG / nb_of_sides_),
                                      ANGLE_DEG / nb_of_sides_);
  float ran_ang_b = 0.0f;
  for (size_t i = 0; i < nb_of_sides_; i++) {
    asteroid_map[i].x = ran_r * cos((ran_ang + ran_ang_b) * DEG2RAD);
    asteroid_map[i].y = ran_r * sin((ran_ang + ran_ang_b) * DEG2RAD);
    ran_r = random_range<float>(MIN_R, MAX_R);
    ran_ang_b += ran_ang;
    ran_ang = random_range<float>(0.7 * (ANGLE_DEG / nb_of_sides_),
                                  ANGLE_DEG / nb_of_sides_);
  }
}

// getters
Vector2 Asteroid::get_pos() const { return pos_; }
Vector2 Asteroid::get_vel() const { return vel_; }
AsteroidSize Asteroid::get_size() const {
  return static_cast<AsteroidSize>(size_);
}

// setters
void Asteroid::set_pos(const Vector2 &pos) {
  pos_.x = pos.x;
  pos_.y = pos.y;
}
void Asteroid::set_vel(const Vector2 &vel) {
  vel_.x = vel.x;
  vel_.y = vel.y;
}

void Asteroid::draw_asteroid() {
  draw_lines(asteroid_map, pos_, size_, 0.0f, 1.0f, nb_of_sides_);
}

#include "Spaceship.h"
#include "constants.h"
#include "raylib.h"

const std::array<Vector2, SHIP_MAP_LENGTH> Spaceship::ship_map = {SHIP_MAP};
const std::array<Vector2, THRUST_MAP_LENGTH> Spaceship::thrust_map = {
    THRUST_MAP};

Spaceship::Spaceship() {
  pos_ = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  vel_ = {0.0f, 0.0F};
  rot_ = DEG2RAD_(180.0f);
  ship_dir_ = {cos(rot_), sin(rot_)};
}

// getters
Vector2 Spaceship::get_pos() const { return pos_; }
Vector2 Spaceship::get_vel() const { return vel_; }
float Spaceship::get_rot() const { return rot_; }
Vector2 Spaceship::get_ship_dir() const { return ship_dir_; }

// setters
void Spaceship::set_pos(const Vector2 &pos) {
  pos_.x = pos.x;
  pos_.y = pos.y;
}
void Spaceship::set_vel(const Vector2 &vel) {
  vel_.x = vel.x;
  vel_.y = vel.y;
}
void Spaceship::set_rot(float rot) { rot_ = rot; }
void Spaceship::set_ship_dir(const Vector2 &ship_dir) {
  ship_dir_.x = ship_dir.x;
  ship_dir_.y = ship_dir.y;
}

void Spaceship::draw_ship() {
  draw_lines(ship_map, pos_, SCALE, rot_, THICKNESS);
}

void Spaceship::draw_thrust() {
  draw_lines(thrust_map, pos_, SCALE, rot_, THICKNESS);
}

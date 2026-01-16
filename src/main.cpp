#include "Asteroid.h"
#include "Spaceship.h"
#include "constants.h"
#include <raylib.h>
#include <raymath.h>
#include <vector>

struct State {
  float now;
  float delta;
  Spaceship &ship;
  std::vector<Asteroid> asteroids;
};

void render(State &state) {

  ClearBackground(BLACK);
  state.ship.draw_ship();

  if (IsKeyDown(KEY_UP) && (int)(state.now * 100) % 2 == 0) {
    // 0.01s on / 0.01s off
    state.ship.draw_thrust();
  }

  for (Asteroid &aster : state.asteroids) {
    aster.draw_asteroid();
  }
}

void update(State &state) {
  // rotation / s

  state.delta = GetFrameTime();
  state.now += state.delta;

  if (IsKeyDown(KEY_RIGHT)) {
    state.ship.set_rot(state.ship.get_rot() + TAU * ROT_SPEED * state.delta);
  }

  if (IsKeyDown(KEY_LEFT)) {
    state.ship.set_rot(state.ship.get_rot() - TAU * ROT_SPEED * state.delta);
  }

  state.ship.set_ship_dir({cos(state.ship.get_rot() + PI * 0.5f),
                           sin(state.ship.get_rot() + PI * 0.5f)});

  if (IsKeyDown(KEY_UP)) {
    state.ship.set_vel(Vector2Add(
        state.ship.get_vel(),
        Vector2Scale(state.ship.get_ship_dir(), SHIP_SPEED * state.delta)));
  }

  state.ship.set_vel(
      Vector2Scale(state.ship.get_vel(), expf(-DRAG * state.delta)));
  state.ship.set_pos(Vector2Add(state.ship.get_pos(), state.ship.get_vel()));
  state.ship.set_pos(
      {fmodf(state.ship.get_pos().x + SCREEN_WIDTH, SCREEN_WIDTH),
       fmodf(state.ship.get_pos().y + SCREEN_HEIGHT, SCREEN_HEIGHT)});

  for (Asteroid &aster : state.asteroids) {
    aster.set_pos(Vector2Add(aster.get_pos(), aster.get_vel()));
    aster.set_pos({fmodf(aster.get_pos().x + SCREEN_WIDTH, SCREEN_WIDTH),
                   fmodf(aster.get_pos().y + SCREEN_HEIGHT, SCREEN_HEIGHT)});
  }
}

void init_level(State &state) {
  for (size_t i = 0; i < 20; i++) {
    float ran_ang = random_range<float>(0.0f, ANGLE_DEG);
    AsteroidSizeWrapper ran_aster_s(
        static_cast<AsteroidSize>(random_range<int>(0, 2)));
    Vector2 pos = {static_cast<float>(random_range<int>(0, SCREEN_WIDTH)),
                   static_cast<float>(random_range<int>(0, SCREEN_HEIGHT))};
    Vector2 vel_dir = {cos(ran_ang * DEG2RAD), sin(ran_ang * DEG2RAD)};
    Vector2 vel = Vector2Scale(vel_dir, ran_aster_s.vel_scale() *
                                            random_range<float>(1.0f, 3.0f));
    state.asteroids.emplace_back(ran_aster_s.size(), pos, vel);
  }
}

int main(void) {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroids Clone");

  SetTargetFPS(60);

  // init spaceship
  Spaceship ship;
  State state = {0.0f, 0.0f, ship};

  init_level(state);

  while (!WindowShouldClose()) {

    update(state);

    BeginDrawing();
    render(state);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

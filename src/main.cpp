#include "Asteroid.h"
#include "Spaceship.h"
#include "constants.h"
#include <memory>
#include <raylib.h>
#include <raymath.h>

#define TAU 2 * PI
#define DRAG 1.9f
#define SHIP_SPEED 25
#define ROT_SPEED 1.0f

typedef struct State {
  float now;
  float delta;
  Spaceship *ship;
  std::vector<Asteroid *> asteroids;
} State;

void render(State &state) {

  ClearBackground(BLACK);
  state.ship->draw_ship();

  // TraceLog(LOG_INFO,
  //          TextFormat("delta %f, now: %f", state.delta, state.now * 100));
  if (IsKeyDown(KEY_UP) && (int)(state.now * 100) % 2 == 0) {
    // 0.01s on / 0.01s off
    state.ship->draw_thrust();
  }

  for (Asteroid *aster : state.asteroids) {
    aster->draw_asteroid();
  }
}

void update(State &state) {
  // rotation / s

  state.delta = GetFrameTime();
  state.now += state.delta;
  // state.ship->set_rot(10.0f * state.now);

  if (IsKeyDown(KEY_RIGHT)) {
    state.ship->rot += TAU * ROT_SPEED * state.delta;
  }

  if (IsKeyDown(KEY_LEFT)) {
    state.ship->rot -= TAU * ROT_SPEED * state.delta;
  }

  state.ship->ship_dir.x = cos(state.ship->rot + (PI * 0.5));
  state.ship->ship_dir.y = sin(state.ship->rot + (PI * 0.5));

  if (IsKeyDown(KEY_UP)) {
    state.ship->vel =
        Vector2Add(state.ship->vel, Vector2Scale(state.ship->ship_dir,
                                                 SHIP_SPEED * state.delta));
  }

  state.ship->vel = Vector2Scale(state.ship->vel, expf(-DRAG * state.delta));
  state.ship->pos = Vector2Add(state.ship->pos, state.ship->vel);
  state.ship->pos.x = fmodf(state.ship->pos.x + SCREEN_WIDTH, SCREEN_WIDTH);
  state.ship->pos.y = fmodf(state.ship->pos.y + SCREEN_HEIGHT, SCREEN_HEIGHT);
}

void clean(State &state) {
  for (Asteroid *aster : state.asteroids) {
    delete aster;
  }
}

void init_level(State &state) {
  float ran_ang = random_range<float>(0.0f, ANGLE_DEG);
  for (size_t i = 0; i < 10; i++) {
    Asteroid *aster_ = new Asteroid(
        AsteroidSize::BIG,
        {static_cast<float>(random_range<int>(0, SCREEN_WIDTH)),
         static_cast<float>(random_range<int>(0, SCREEN_HEIGHT))},
        Vector2Scale({cos(ran_ang * DEG2RAD), sin(ran_ang * DEG2RAD)},
                     random_range<float>(1.0f, 3.0f)));
    state.asteroids.push_back(aster_);
    ran_ang = random_range<int>(0.0f, ANGLE_DEG);
  }
}

int main(void) {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroids Clone");

  SetTargetFPS(60);

  // init spaceship
  Spaceship ship;
  State state = {0.0f, 0.0f, &ship};

  init_level(state);

  while (!WindowShouldClose()) {
    // if (IsKeyPressed(KEY_R)) {
    //   delete aster_;
    //   aster_ =
    //       new Asteroid(AsteroidSize::BIG, (Vector2){(float)SCREEN_WIDTH / 2,
    //                                                 (float)SCREEN_HEIGHT /
    //                                                 2});
    // }

    update(state);

    BeginDrawing();
    render(state);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

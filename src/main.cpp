#include "Asteroid.h"
#include "Spaceship.h"
#include <raylib.h>
#include <raymath.h>

#define TAU 2 * PI
#define DRAG 1.9f
#define SHIP_SPEED 25
#define ROT_SPEED 1.0f

void render(State &state) {
  ClearBackground(BLACK);
  state.ship->draw_ship();

  // TraceLog(LOG_INFO,
  //          TextFormat("delta %f, now: %f", state.delta, state.now * 100));
  if (IsKeyDown(KEY_UP) && (int)(state.now * 100) % 2 == 0) {
    // 0.01s on / 0.01s off
    state.ship->draw_thrust();
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

int main(void) {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroids Clone");

  SetTargetFPS(60);

  // init spaceship
  Spaceship ship;
  Asteroid *aster_ =
      new Asteroid(AsteroidSize::SMALL, (Vector2){(float)SCREEN_WIDTH / 2,
                                                  (float)SCREEN_HEIGHT / 2});
  State state = {0.0f, 0.0f, &ship};

  const int point_s = 4;

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_R)) {
      delete aster_;
      aster_ = new Asteroid(
          AsteroidSize::SMALL,
          (Vector2){(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2});
    }

    update(state);

    BeginDrawing();
    render(state);
    aster_->draw_asteroid();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

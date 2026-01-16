#ifndef UTILS_H
#define UTILS_H

#include "constants.h"

#include <iostream>
#include <random>
#include <raylib.h>
#include <raymath.h>
#include <type_traits>

#define DEG2RAD_(_d) ((_d) * (PI / 180.0f))

// TODO: what does inline do?
// TODO: switch to span instead of std::array
template <std::size_t SIZE>
void draw_lines(const std::array<Vector2, SIZE> &points, Vector2 origin,
                float scale, float rot, float thickness,
                std::size_t d_size = SIZE) {
  auto apply_transform = [=](Vector2 vect) {
    return Vector2Add(Vector2Scale(Vector2Rotate(vect, rot), scale), origin);
  };

  for (std::size_t i = 0; i < d_size; i++) {
    DrawLineEx(apply_transform(points[i % d_size]),
               apply_transform(points[(i + 1) % d_size]), thickness, WHITE);
  }
}

template <typename T> T random_range(T min, T max) {
  static_assert(std::is_arithmetic_v<T>, "T must be numeric type");

  thread_local static std::mt19937 gen(std::random_device{}());

  if constexpr (std::is_integral_v<T>) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(gen);
  } else {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(gen);
  }
}

#endif

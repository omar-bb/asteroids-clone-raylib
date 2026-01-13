#ifndef UTILS_H
#define UTILS_H

#include "constants.h"

#include <iostream>
#include <random>
#include <raylib.h>
#include <raymath.h>
#include <type_traits>

void draw_lines(const Vector2 points_[], size_t arr_size_, Vector2 origin_,
                float scale_, float rot_, float thickness_);

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

#include "utils.h"

// template <std::size_t SIZE>
// void draw_lines(const std::array<Vector2, SIZE> &points, Vector2 origin,
//                 float scale, float rot, float thickness) {
//   auto apply_transform = [=](Vector2 vect) {
//     return Vector2Add(Vector2Scale(Vector2Rotate(vect, rot), scale), origin);
//   };
//
//   for (std::size_t i = 0; i < SIZE; i++) {
//     DrawLineEx(apply_transform(points[i % SIZE]),
//                apply_transform(points[(i + 1) % SIZE]), thickness, WHITE);
//   }
// }

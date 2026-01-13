#include "utils.h"

void draw_lines(const Vector2 points_[], size_t arr_size_, Vector2 origin_,
                float scale_, float rot_, float thickness_) {
  auto apply_transform = [=](Vector2 vect_) {
    return Vector2Add(Vector2Scale(Vector2Rotate(vect_, rot_), scale_),
                      origin_);
  };

  for (std::size_t x = 0; x < arr_size_; x++) {
    DrawLineEx(apply_transform(points_[x % arr_size_]),
               apply_transform(points_[(x + 1) % arr_size_]), thickness_,
               WHITE);
  }
}

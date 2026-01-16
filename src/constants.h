#ifndef CONSTANTS_H
#define CONSTANTS_H

// window constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// spaceship constants
#define TAU 2 * PI
#define DRAG 1.9f
#define SHIP_SPEED 25
#define ROT_SPEED 1.0f

#define SCALE 20.0f
#define THICKNESS 1.0f
#define SHIP_MAP                                                               \
  {{-0.4, -0.5}, {-0.3, -0.4}, {0.3, -0.4}, {0.4, -0.5}, {0, 0.5}}
#define SHIP_MAP_LENGTH 5
#define THRUST_MAP {{-0.2, -0.4}, {0.0, -0.8}, {0.2, -0.4}}
#define THRUST_MAP_LENGTH 3

// asteroid constants
#define MIN_NB_SIDES 6
#define MAX_NB_SIDES 12
#define MIN_R 0.3f
#define MAX_R 1.0f
#define ANGLE_DEG 360.0f

// aster size
#define ASTER_BIG SCALE * 2.0f
#define ASTER_MEDIUM SCALE * 1.4f
#define ASTER_SMALL SCALE * 0.8f

// aster vel
#define ASTER_VELSCALE_BIG 0.75f
#define ASTER_VELSCALE_MEDIUM 1.0f
#define ASTER_VELSCALE_SMALL 1.6f

#endif

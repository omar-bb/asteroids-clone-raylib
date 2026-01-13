#ifndef CONSTANTS_H
#define CONSTANTS_H

// window constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// spaceship constants
#define SCALE 20.0f
#define THICKNESS 1.0f
#define SHIP_MAP                                                               \
  {{-0.4, -0.5}, {-0.3, -0.4}, {0.3, -0.4}, {0.4, -0.5}, {0, 0.5}}
#define THRUST_MAP {{-0.2, -0.4}, {0.0, -0.8}, {0.2, -0.4}}

// asteroid constants
#define MIN_NB_SIDES 6
#define MAX_NB_SIDES 10
#define MIN_R 0.3f
#define MAX_R 1.0f
#define ANGLE_DEG 360.0f

#define NUMBER_OF_SIDES 10
#define MIN_ANG 25.0f
#define MAX_ANG 36.0f

#endif

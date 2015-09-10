#ifndef CONSTANTS
#define CONSTANTS

#include <random>

const float speed_factor = 1.4;

const int player_speed = 5 * speed_factor;
const unsigned int player_pos_tolerance = 3;
const int enemy_spawn_timeout = 1200 * speed_factor;

const unsigned int speed_e01 = 2 * speed_factor;
const unsigned int speed_e02 = 1 * speed_factor;
const unsigned int speed_eb01 = 3 * speed_factor;

const unsigned int health_e01 = 2;
const unsigned int health_e02 = 5;
const unsigned int health_eb01 = 1;

const unsigned int score_e01 = 1;
const unsigned int score_e02 = 2;
const unsigned int score_eb01 = 20;

const unsigned int bullet_speed_01 = 10 * speed_factor;
const unsigned int bullet_speed_02 = 4 * speed_factor;
const unsigned int bullet_speed_e01 = 6 * speed_factor;

#endif // CONSTANTS


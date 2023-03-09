#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <type_traits>
#include <vector>
#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

#define HEIGHT 1080
#define WIDTH 1920

/* Code for systems */
#define SYS_INPUT 1
#define SYS_MOVEMENT 2
#define SYS_GRAVITY 3
#define SYS_COLLISION 4
#define SYS_RENDER 5
#define SYS_SHOOTING 6
/* Type for components */
#define TYPE_POSITION 1
#define TYPE_SPRITE 2
#define TYPE_VELOCITY 3
#define TYPE_HITBOX 4
#define TYPE_CLOCK 5
#define TYPE_STATS 6
#define TYPE_OBJECTS 7
/* Type of objects */
#define TYPE_PARALLAX_ONE 1
#define TYPE_PARALLAX_TWO 2
#define TYPE_PARALLAX_THR 3
#define TYPE_PARALLAX_FOU 4
#define TYPE_PARALLAX_FIV 5
#define TYPE_PARALLAX_SIX 6
#define TYPE_PLAYER 100
#define TYPE_PLAYER_ONE 10
#define TYPE_PLAYER_TWO 11
#define TYPE_PLAYER_THR 12
#define TYPE_PLAYER_FOU 13
#define TYPE_ENEMY_ONE 20
#define TYPE_ENEMY_TWO 21
#define TYPE_BOSS_ONE 22
#define TYPE_SHOOT 32
#define TYPE_ENEMY_SHOOT 33
#define TYPE_BOSS_SHOOT 34
#define TYPE_BOSS_SPECIAL 35
/* Code key input */
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define SPACE 5
#define SPECIAL 6
#define ESCAPE 7

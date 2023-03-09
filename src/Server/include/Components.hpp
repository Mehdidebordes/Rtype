/*
** EPITECH PROJECT, 2022
** RTYPE
** File description:
** Components
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include "./ECS.hpp"
#include "./Component.hpp"

struct Position : public rtype::Component {
  sf::Vector2f pos;

  Position(sf::Vector2f pos) : pos(pos) {};
  static const rtype::ComponentType type = TYPE_POSITION;
};

struct Sprite : public rtype::Component {
  sf::Sprite sprite;
  sf::Texture texture;

  Sprite(const char *file, sf::Vector2f vect, sf::IntRect rect, sf::Vector2f scale) {
    texture.loadFromFile(file);
    sprite.setTextureRect(rect);
    sprite.setTexture(texture);
    sprite.setPosition(vect);
    sprite.setScale(scale.x, scale.y);
  };
  static const rtype::ComponentType type = TYPE_SPRITE;
};

struct Velocity : public rtype::Component {
  sf::Vector2f velocity;

  Velocity(sf::Vector2f velocity) : velocity(velocity) {};
  static const rtype::ComponentType type = TYPE_VELOCITY;
};

struct Hitbox : public rtype::Component {
  float x;
  float y;

  Hitbox(float x, float y) : x(x), y(y) {};
  static const rtype::ComponentType type = TYPE_HITBOX;
};

struct Clock : public rtype::Component {
  sf::Clock c_sprite;
  sf::Clock c_shoot;
  sf::Clock c_move;
  sf::Clock c_special;
  float t_sprite;
  float t_shoot;
  float t_move;
  float t_special;

  Clock(float t_sprite, float t_shoot, float t_move, float t_special) : t_sprite(t_sprite), t_shoot(t_shoot), t_move(t_move), t_special(t_special) {
    c_sprite.restart();
    c_shoot.restart();
    c_move.restart();
    c_special.restart();
  };
  static const rtype::ComponentType type = TYPE_CLOCK;
};

struct Type : public rtype::Component {
  std::size_t object;
 
  Type(std::size_t object) : object(object) {};
  static const rtype::ComponentType type = TYPE_OBJECTS;
};

struct Stats : public rtype::Component {
  int health;
  int attack;
  int defense;
  int level;
  bool alive;
 
  Stats(int health, int attack, int defense, int level) : health(health), attack(attack), defense(defense), level(level) {
    alive = true;
  };
  static const rtype::ComponentType type = TYPE_STATS;
};



#endif /* !COMPONENTS_HPP_ */

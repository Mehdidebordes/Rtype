/*
** EPITECH PROJECT, 2022
** 4RTYPE
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "./my.h"

typedef struct Sprite_s Sprite_t;
typedef struct Text_s Text_t;

struct Sprite_s {
  sf::Sprite sprite;
  sf::Texture texture;
  sf::Vector2f vect;
  sf::IntRect rect;
  float X;
  float Y;
  Sprite_s(const char *file, sf::Vector2f vect, sf::IntRect rect, float x, float y) : vect(vect), rect(rect), X(x), Y(x) {
    texture.loadFromFile(file);
    sprite.setTextureRect(rect);
    sprite.setScale(x, y);
    sprite.setTexture(texture);
    sprite.setPosition(vect);
  };
};

struct Text_s {
  sf::Text Text;
  sf::Font Font;
  sf::Color Color;
  int pos_X;
  int pos_Y;
  int size;
  Text_s(const char *file, sf::Color color, int x, int y, int size) : Color(color), pos_X(x), pos_Y(y), size(size) {
    Font.loadFromFile(file);
    Text.setFont(Font);
    Text.setCharacterSize(size);
    Text.setFillColor(Color);
    Text.setPosition(pos_X, pos_Y);
  };
};

class Game {
  public:
    Game();
    ~Game() {};
    void setData(std::string data) { _data = data; };
    std::string *getData(void) { return &_data; };

    void update(sf::RenderWindow *window);
    void draw(sf::RenderWindow *);

  protected:
  private:
    std::string _data;
    std::map<int, Sprite_t *> _sprite;
    std::vector<int> _toDraw;
    std::map<int, Text_t *> _text;
    std::vector<int> _toDrawText;
};

#endif /* !GAME_HPP_ */

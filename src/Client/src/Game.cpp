/*
** EPITECH PROJECT, 2022
** 4RTYPE
** File description:
** Game
*/

#include "../include/Game.hpp"

Game::Game() {

  sf::Font font;
  font.loadFromFile("assets/Fonts/Dosis-Light.ttf");

  int id = 0;
  // Sprite_t *s_boss_one = new Sprite_t("/home/phearoak/EPITECH/SEMESTER5/PROJECT/4RTYPE/assets/Game/player_one.png", { 500, 500 }, { 0, 0, 260, 143 });
  Sprite_t *one = new Sprite_t("assets/menu/one.png", { 0, 0 }, { 0, 0, WIDTH * 2, HEIGHT }, 1, 1);
  Sprite_t *two = new Sprite_t("assets/menu/two.png", { 0, 0 }, { 0, 0, WIDTH * 2, HEIGHT }, 1, 1);
  Sprite_t *three = new Sprite_t("assets/menu/three.png", { 0, 0 }, { 0, 0, WIDTH * 2, HEIGHT }, 1, 1);
  Sprite_t *four = new Sprite_t("assets/menu/four.png", { 0, 0 }, { 0, 0, WIDTH * 2, HEIGHT }, 1, 1);
  Sprite_t *five = new Sprite_t("assets/menu/five.png", { 0, 0 }, { 0, 0, WIDTH * 2, HEIGHT }, 1, 1);
  Sprite_t *six = new Sprite_t("assets/menu/six.png", { 0, 0 }, { 0, 0, WIDTH * 2, HEIGHT }, 1, 1);

  Sprite_t *s_player_one = new Sprite_t("assets/Game/player_one.png", { 200, 100 }, { 0, 0, 33, 17 }, 4, 4);
  Sprite_t *s_player_two = new Sprite_t("assets/Game/player_two.png", { 200, 300 }, { 0, 0, 33, 17 }, 4, 4);
  Sprite_t *s_player_thr = new Sprite_t("assets/Game/player_thr.png", { 200, 500 }, { 0, 0, 33, 17 }, 4, 4);
  Sprite_t *s_player_fou = new Sprite_t("assets/Game/player_fou.png", { 200, 700 }, { 0, 0, 33, 17 }, 4, 4);
  Sprite_t *s_shoot = new Sprite_t("assets/Game/player_shoot_one.png", { 1, 1}, { 0, 0, 313, 412 }, 2, 2);
  Sprite_t *s_enemy_one = new Sprite_t("assets/Game/enemy_one.png", { 500, 100}, { 0, 0, 33, 36 }, 3, 3);
  Sprite_t *s_enemy_two = new Sprite_t("assets/Game/enemy_two.png", { 500, 600}, { 0, 0, 33, 34 }, 3, 3);
  Sprite_t *s_boss_one = new Sprite_t("assets/Game/boss_one.png", { 500, 600}, { 0, 0, 33, 34 }, 3, 3);
  Sprite_t *s_enemy_shoot = new Sprite_t("assets/Game/enemy_shoot_one.png", { 1, 1}, { 0, 0, 313, 412 }, 3, 3);
  Sprite_t *s_boss_shoot = new Sprite_t("assets/Game/enemy_shoot_one.png", { 1, 1}, { 0, 0, 313, 412 }, 3, 3);
  Sprite_t *s_boss_special = new Sprite_t("assets/Game/boss_special.png", { 1, 1}, { 0, 0, 313, 412 }, 6, 6);

  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PARALLAX_ONE), one));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PARALLAX_TWO), two));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PARALLAX_THR), three));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PARALLAX_FOU), four));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PARALLAX_FIV), five));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PARALLAX_SIX), six));

  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PLAYER_ONE), s_player_one));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PLAYER_TWO), s_player_two));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PLAYER_THR), s_player_thr));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_PLAYER_FOU), s_player_fou));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_SHOOT), s_shoot));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_ENEMY_ONE), s_enemy_one));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_ENEMY_TWO), s_enemy_two));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_BOSS_ONE), s_boss_one));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_ENEMY_SHOOT), s_enemy_shoot));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_BOSS_SHOOT), s_boss_shoot));
  _sprite.insert(std::make_pair(static_cast<int>(TYPE_BOSS_SPECIAL), s_boss_special));
}

std::vector<int> parse_to_int(std::string s)
{
  if (s.empty()) return {};
  std::vector<int> vec;
  std::string token;
  for (size_t pos = 0; (pos = s.find(":")) != std::string::npos;) {
    token = s.substr(0, pos);
    try {
      vec.push_back(std::stoi(token));
      s.erase(0, pos + 1);
    } catch(const std::invalid_argument &e) {
      break;
    };
  }
  try {
    vec.push_back(std::stoi(s));
  } catch(const std::invalid_argument &e) {
    return vec;
  };
  return vec;
}

std::vector<std::string> parse_to_str(std::string s)
{
  if (s.empty()) return {};
  std::vector<std::string> vec;
  std::string token;
  for (size_t pos = 0; (pos = s.find("/")) != std::string::npos;) {
    token = s.substr(0, pos);
    vec.push_back(token);
    s.erase(0, pos + 1);
  }
  vec.push_back(s);
  return vec;
}

void Game::update(sf::RenderWindow *window)
{
  this->_toDraw.clear();
  std::vector<std::string> parsed_data = parse_to_str(_data);
  for (auto it: parsed_data) {
    std::vector<int> parsed_values = parse_to_int(it);

    if (parsed_values.size() != 7) continue;
    std::map<int, Sprite_t *>::iterator tmp = _sprite.find(parsed_values[0]);
    if (tmp == _sprite.end()) continue;
    Sprite_t *sprite = _sprite.find(parsed_values[0])->second;
    if (!sprite) continue;

    sprite->sprite.setPosition(parsed_values[1], parsed_values[2]);
    sprite->sprite.setTextureRect({parsed_values[3], parsed_values[4], parsed_values[5], parsed_values[6]});
    this->_toDraw.push_back(parsed_values[0]);
    window->draw(sprite->sprite);
  }
}

void Game::draw(sf::RenderWindow *window)
{
}

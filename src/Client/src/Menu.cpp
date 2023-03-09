/*
** EPITECH PROJECT, 2022
** 4RTYPE
** File description:
** Menu
*/

#include "../include/Menu.hpp"

Menu::Menu()
{
  float W = WIDTH/2 - 618/2;
  float H = HEIGHT/2 - 65;

  sf::IntRect Rect = {0, 0, 618, 65};
  sf::IntRect RectParallax = {0, 0, WIDTH * 2, HEIGHT};
  sf::Vector2f v_play = {W, H - 32 - 65 - 20 - 65 - 20};
  // sf::Vector2f v_save = {W, H - 32 - 65 - 20};
  sf::Vector2f v_settings = {W, H - 32};
  // sf::Vector2f v_credit = {W, H - 32 + 65 + 20};
  sf::Vector2f v_quit = {W, H - 32 + 65 + 20 + 65 + 20};
  sf::Vector2f VectParallax = { 0, 0 };

  t_play.loadFromFile("assets/menu/start.png");
  s_play.setTextureRect(Rect);
  s_play.setTexture(t_play);
  s_play.setPosition(v_play);

  t_settings.loadFromFile("assets/menu/settings.png");
  s_settings.setTextureRect(Rect);
  s_settings.setTexture(t_settings);
  s_settings.setPosition(v_settings);

  t_quit.loadFromFile("assets/menu/quit.png");
  s_quit.setTextureRect(Rect);
  s_quit.setTexture(t_quit);
  s_quit.setPosition(v_quit);
}

Menu::~Menu() { }

void Menu::draw(sf::RenderWindow *window)
{
  window->draw(s_play);
  window->draw(s_settings);
  window->draw(s_quit);
}
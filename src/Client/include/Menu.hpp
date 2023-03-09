/*
** EPITECH PROJECT, 2022
** 4RTYPE
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "./my.h"

class Menu {
  public:
    Menu();
    ~Menu();

    void update(void) {};
    void draw(sf::RenderWindow *window);
    sf::Vector2f getPlayPosition() { return s_play.getPosition(); };
    sf::Vector2f getSettingsPosition() { return s_settings.getPosition(); };
    sf::Vector2f getQuitPosition() { return s_quit.getPosition(); };

  private:
    sf::Texture t_play;
    sf::Texture t_settings;
    sf::Texture t_quit;

    sf::Sprite s_play;
    sf::Sprite s_settings;
    sf::Sprite s_quit;
};

#endif /* !MENU_HPP_ */

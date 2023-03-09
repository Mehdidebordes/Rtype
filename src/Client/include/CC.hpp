/*
** EPITECH PROJECT, 2022
** 4RTYPE
** File description:
** CC
*/

#ifndef CC_HPP_
#define CC_HPP_

#include "./my.h"
#include "./Menu.hpp"
#include "./Game.hpp"
#include "../../Socket/Socket.hpp"

/**
 * @brief The client manager.
 */
class CC {
  public:
    CC(boost::asio::io_service& io_service, unsigned short int port);
    ~CC();

    sf::RenderWindow *getWindow() { return &_window; };
    Menu *getMenu() { return &_menu; };
    Game *getGame() { return &_game; };
    Socket *getSocket() { return &_socket; };

    bool isOpen() { return _window.isOpen(); };
    void clear() { _window.clear(); };
    void draw();
    void update();
    void display() { _window.display(); };

    void Input();
    void gameInput();
    void menuInput();
    void eventState();
    void eventGameInput(sf::Event event);
    void eventMenuInput(float x, float y);

    void SynchronizeData();
  private:
    sf::RenderWindow _window;
    Menu _menu;
    Game _game;
    sf::Clock _clock;
    sf::Font _font;
    int _state;

    Socket _socket;
    unsigned short int _port;
};


#endif /* !CC_HPP_ */

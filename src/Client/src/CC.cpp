/*
** EPITECH PROJECT, 2022
** 4RTYPE
** File description:
** CC
*/

#include "../include/CC.hpp"

CC::CC(boost::asio::io_service& io_service, unsigned short int port) : _socket(io_service, port), _port(port)
{
  _window.create(sf::VideoMode(WIDTH, HEIGHT), "R-TYPE", sf::Style::Titlebar | sf::Style::Close);
  _window.setPosition({0, 0});
  _window.setFramerateLimit(200);
  _state = MENU;
}

CC::~CC()
{
  _window.close();
}

void CC::update(void)
{
  switch (_state) {
    case (MENU):
      getMenu()->update();
      break;
    case (GAME):
      getGame()->update(getWindow());
      break;
  }
}

void CC::draw(void)
{
  switch (_state) {
    case (MENU):
      getMenu()->draw(&_window);
      break;
    case (GAME):
      getGame()->draw(&_window);
      break;
  }
}

void CC::Input()
{
  switch (_state) {
    case MENU:
      menuInput();
      break;
    case GAME:
      gameInput();
      break;
    default:
      break;
  }
}

void CC::menuInput()
{
  sf::Event event;

  while (_window.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
      _window.close();
      break;

    case sf::Event::KeyPressed:
      switch (event.key.code) {
        case sf::Keyboard::Escape:
          _window.close();
          break;

        default:
          break;
      }
    case sf::Event::MouseButtonPressed:
      switch (event.mouseButton.button) {
        case sf::Mouse::Left:
          eventMenuInput(static_cast<float>(event.mouseButton.x),
          static_cast<float>(event.mouseButton.y));
          break;

        default:
          break;
      }
    default:
      break;
    }
  }
}

void CC::eventMenuInput(float x, float y)
{
  if (x >= getMenu()->getPlayPosition().x && x <= getMenu()->getPlayPosition().x + 618 && y >= getMenu()->getPlayPosition().y && y <= getMenu()->getPlayPosition().y + 65) {
    _state = GAME;
    _socket.sendMessage((std::to_string(_port) + ";99").c_str(), 1042);
  }
  if (x >= getMenu()->getSettingsPosition().x && x <= getMenu()->getSettingsPosition().x + 618 && y >= getMenu()->getSettingsPosition().y && y <= getMenu()->getSettingsPosition().y + 65) {
    _state = SETTINGS;
  }
  if (x >= getMenu()->getQuitPosition().x && x <= getMenu()->getQuitPosition().x + 618 && y >= getMenu()->getQuitPosition().y && y <= getMenu()->getQuitPosition().y + 65) {
    _state = QUIT;
  }
}

void CC::gameInput()
{
  sf::Event event;

  while (_window.pollEvent(event)) {
    switch (event.type) {
     case sf::Event::Closed:
        _window.close();
        break;
      case sf::Event::MouseButtonPressed:
        switch (event.mouseButton.button) {
          case sf::Mouse::Left:
            eventMenuInput(static_cast<float>(event.mouseButton.x),
            static_cast<float>(event.mouseButton.y));
            break;
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      _state = MENU;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
      _socket.sendMessage((std::to_string(_port) + ";1").c_str(), 1042);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
      _socket.sendMessage((std::to_string(_port) + ";2").c_str(), 1042);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      _socket.sendMessage((std::to_string(_port) + ";3").c_str(), 1042);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      _socket.sendMessage((std::to_string(_port) + ";4").c_str(), 1042);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      _socket.sendMessage((std::to_string(_port) + ";5").c_str(), 1042);
    }
  }
}

void CC::SynchronizeData()
{
  this->_game.setData(*_socket.getBuff());
}

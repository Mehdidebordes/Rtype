/*
 ** EPITECH PROJECT, 2022
 ** server
 ** File description:
 ** Server
 */

#include "../include/Server.hpp"
#include "../include/Components.hpp"
#include "../include/systems.hpp"


namespace rtype {

  Server::Server(boost::asio::io_service& io_service, unsigned short int port)
    : _socket(io_service, port)
  {
    srand(time(NULL));
    initializeManager(&_manager);
    createMenu(&_manager);
    // createPlayer(&_manager);
    // createEnemy(&_manager);
    // createBoss(&_manager);
  }

  Server::~Server() { }

  void Server::initializeManager(Manager *manager)
  {
    manager->createStoreFor(Position::type);
    manager->createStoreFor(Velocity::type);
    manager->createStoreFor(Hitbox::type);
    manager->createStoreFor(Sprite::type);
    manager->createStoreFor(Type::type);
    manager->createStoreFor(Stats::type);
    manager->createStoreFor(Clock::type);

    manager->addSystems(new Input(manager, manager->getWindow()));
    manager->addSystems(new Movement(manager));
    manager->addSystems(new Shooting(manager));
    manager->addSystems(new Collision(manager));
    manager->addSystems(new Render(manager, manager->getWindow()));
  }

  void Server::sendMessage(std::map<int, Entity> players, std::string buff) {
    std::map<int, Entity>::iterator it;
    for (it = players.begin(); it != players.end(); it++) {
      _socket.sendMessage(buff, it->first);
    }
  }
}
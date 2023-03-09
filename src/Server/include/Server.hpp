/*
** EPITECH PROJECT, 2022
** server
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_
#include "./Manager.hpp"
#include "../../Socket/Socket.hpp"

namespace rtype {

  class Server {
    public:
      Server(boost::asio::io_service& io_service, unsigned short int port);
      ~Server();
      Socket *getSocket() { return &_socket; };
      void initializeManager(Manager *);
      Manager *getManager(void) { return &_manager; };
      void sendMessage(std::map<int, Entity> players, std::string);

    private:
      Socket _socket;
      Manager _manager;
    };
}

#endif /* !SERVER_HPP_ */

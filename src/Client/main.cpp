/*
** EPITECH PROJECT, 2022
** 4RTYPE
** File description:
** main
*/

// #include "main.hpp"
// #include "../include/Menu.hpp"
#include "./include/CC.hpp"
// #include "../server/Client/Client.hpp"


int main(int ac, char **av)
{
  if (ac != 2) {
    std::cout << "Specify the port please." << std::endl;
    return 84;
  }

  unsigned short int port = std::stoi(av[1]);
  boost::asio::io_service io_service;
  CC cc(io_service, port);

  cc.getSocket()->startReceive();

  boost::thread thread(boost::bind(&boost::asio::io_service::run, &io_service));
  std::cout << "Client online at port " << port << std::endl;

  while (cc.isOpen()) {
    cc.clear();
    cc.update();
    cc.SynchronizeData();
    cc.draw();
    cc.Input();
    cc.display();
  }

  return 0;
}

#include "include/Server.hpp"

int main()
{
    boost::asio::io_service io_service;
    rtype::Server Server(io_service, 1042);

    Server.getSocket()->startReceive();

    boost::thread thread(boost::bind(&boost::asio::io_service::run, &io_service));
    std::cout << "Server online at port 1042" << std::endl;
    sf::Clock clock;

    while (Server.getManager()->getWindow()->isOpen()) {
        sf::Time elapsed = clock.restart();
        float delta = elapsed.asSeconds();
        Server.getManager()->spawnEnemy();
        Server.getManager()->getInput((Server.getSocket()->getBuff()));
        Server.getManager()->updateSystems(delta);
        Server.getManager()->postUpdate();
        Server.sendMessage(Server.getManager()->getPlayers(), Server.getManager()->getPostUpdate());
    }
    thread.join();
    return 0;
}

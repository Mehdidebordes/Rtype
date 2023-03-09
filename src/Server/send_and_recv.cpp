// #include "Client/Client.hpp"
// #include "Client/Client.cpp"

// int main(int ac, char **av)
// {
//     boost::asio::io_service io_service;

//     Client client(io_service, boost::lexical_cast<unsigned short>(av[1]));
//     std::string message = std::string(av[1]) + " Ping ?";
//     std::cout << "Message: " << message << std::endl;
//     client.sendMessage(message, 13);
//     client.startReceive();
//     io_service.run();
//     return 0;
// }

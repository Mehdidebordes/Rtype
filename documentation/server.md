# Server documentation

## Introduction
R-type is a multiplayer game. We therefore need a communication between clients and a server. You will find in this documentation every detail of how it works.

## Organisation
The server and the client both use the  `Socket` class. This class is defined in two files, respectively  `src/Socket/Socket.cpp` and `src/Socket/Socket.hpp`.
The goal of this class is to faciliate exchange between the server and his clients.
```c++
// src/Server/main.cpp
int main()
{
    boost::asio::io_service io_service;
    rtype::Server Server(io_service, 1042);
	
    Server.getSocket()->startReceive();
	
    boost::thread thread(boost::bind(
	    &boost::asio::io_service::run, &io_service));
    std::cout << "Server online at port 1042" << std::endl;
	...
}

// src/Client/main.cpp
int main(int ac, char **av)
{
	...
	boost::asio::io_service io_service;
	Client client(io_service, port);
	
	client.getSocket()->startReceive();
	
	boost::thread thread(boost::bind(
		&boost::asio::io_service::run, &io_service));
	std::cout << "Client online at port " << port << std::endl;
	...
}

// Note that we run io_service in a thread for async listening.
```


## Technical details
The server and clients communicate throw an udp connection. For this purpose, we use `boost::asio` library. We initialise the sockets like so:
```cpp
// Socket.cpp

using boost::asio::ip::address;
using boost::asio::ip::udp;

Socket::Socket(boost::asio::io_service& io_service, unsigned short int port)
    : _socket(io_service, udp::endpoint(udp::v4(), port)) {...}
```

### Communication
Communication is done by sending `strings` .  Depending on whether it is the server or the client that is sending the data, the format of the message change.
```
Cummunication Client/Server
   ┌──────┐                        ┌──────┐
   │CLIENT├──Socket───────►Socket──┤SERVER│
   └──────┘          data          └──────┘
```
**data:** inputs
```
Communication Server/Client
   ┌──────┐                        ┌──────┐
   │CLIENT├──Socket◄───────Socket──┤SERVER│
   └──────┘          data          └──────┘
```
**data:** sprites informations

For each exchange, the folowing happen:
```
Exemple of Client/Server exchange
   ┌──────┐ ┌──────┐                  ┌──────┐ ┌──────┐
   │CLIENT├─┤Socket│─────────────────►│Socket├─┤SERVER│
   └──────┘ └───┬──┘      data        └───┬──┘ └──────┘
                │                         │
               ─┴─                        │
  - client.socket.sendMessage(data)       │
                                         ─┴─
                             - server.socket.startReceive()
                             - server.socket.handleReceive(data)
```
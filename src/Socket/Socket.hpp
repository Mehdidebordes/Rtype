/*
** EPITECH PROJECT, 2022
** server
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/thread/thread.hpp>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <thread>
#include <boost/asio.hpp>
#include <unistd.h>
#include <vector>

#define IPADDRESS "127.0.0.1" 

using boost::asio::ip::address;
using boost::asio::ip::udp;


class Socket {
public:
    Socket(boost::asio::io_service& io_service, unsigned short int port);
    ~Socket();
    void startReceive();
    void handleReceive(const boost::system::error_code& error, size_t bytes_transferred);
    void handleSend(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t bytes_transferred);
    void sendMessage(std::string message, unsigned short int port);
    std::vector<int> parseReceive(std::string received);

    int checkPlayerPort(unsigned int port);

    std::string *getBuff(void) { return &_buff; };
    void setBuff(std::string buff) { this->_buff = buff; };

private:
    udp::socket _socket;
    udp::endpoint _remote_endpoint;
    boost::array<char, 1024*10> _recv_buffer;
    std::string _buff;
    boost::asio::io_service _io_service;
};

#endif /* !SOCKET_HPP_ */

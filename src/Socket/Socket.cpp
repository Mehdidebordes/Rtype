/*
 ** EPITECH PROJECT, 2022
 ** server
 ** File description:
 ** Socket
 */

#include "./Socket.hpp"

Socket::Socket(boost::asio::io_service& io_service, unsigned short int port)
    : _socket(io_service, udp::endpoint(udp::v4(), port))
{
    _buff.clear();
}

Socket::~Socket() { }

void Socket::startReceive()
{
    _socket.async_receive_from(
            boost::asio::buffer(_recv_buffer), _remote_endpoint,
            boost::bind(&Socket::handleReceive, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
}

int Socket::checkPlayerPort(unsigned int port)
{
    int count = 0;
    // for (auto player: game.players) {
    //     if (player.port == port)
    //         return count;
    //     count++;
    // }
    return -1;
}

std::vector<int> Socket::parseReceive(std::string s)
{
    std::vector<int> vec;
    std::string token;
    for (size_t pos = 0; (pos = s.find(" ")) != std::string::npos;) {
        token = s.substr(0, pos);
        vec.push_back(std::stoi(token));
        s.erase(0, pos + 1);
    }
    vec.push_back(std::stoi(token));
    return vec;
}

void Socket::handleReceive(const boost::system::error_code& error, size_t bytes_transferred)
{
    if (error && error != boost::asio::error::message_size) return; 

    _buff = std::string(_recv_buffer.begin(), _recv_buffer.begin()+bytes_transferred);
    startReceive();
}

void Socket::handleSend(boost::shared_ptr<std::string>, const boost::system::error_code&, std::size_t bytes_transferred)
{
}


void Socket::sendMessage(std::string content, unsigned short int port)
{
    boost::shared_ptr<std::string> message(new std::string(content));
    boost::asio::ip::udp::endpoint destination(boost::asio::ip::address::from_string("127.0.0.1"), port);
    _socket.async_send_to(boost::asio::buffer(*message), destination,
            boost::bind(&Socket::handleSend, this, message,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
}

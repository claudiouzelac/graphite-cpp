#pragma once

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

class graphite_connector {
public:
    graphite_connector(std::string hostA, int portA);
    void connect(void);
    void disconnect(void);
    void write(std::string messageA);
private:
    boost::asio::io_service serviceM;
    boost::asio::ip::tcp::endpoint endpointM;
    boost::asio::ip::tcp::socket * socketM;
};
//Copyright 2014, Stewart Henderson
#pragma once

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

/*! \brief Graphite server connector
 *  \author Stewart Henderson
 */
class Connector {
public:
    /**
    * \brief Create a graphite reporter for server at IP address and port
    * \param hostA, IP address for Graphite server
    * \param portA, port for Graphite server
    */
    Connector(const std::string& hostA, unsigned short portA);

    ~Connector();

    /// Connect to the specified server
    void connect(void);
    /// Disconnect from the specified server
    void disconnect(void);
    /**
     *  \brief Write a message to the server.  Connect must have
     *         been called prior to a write() call.
     *  \param messageA, message to be written to the server.
     */
    void write(std::string messageA);
private:
    boost::asio::io_service serviceM;
    boost::asio::ip::tcp::endpoint endpointM;
    boost::asio::ip::tcp::socket * socketM;
};

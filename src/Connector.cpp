#include "Connector.hpp"

Connector::Connector(const std::string& hostA, unsigned short portA) {
    endpointM = boost::asio::ip::tcp::endpoint(
            boost::asio::ip::address::from_string(hostA), portA);
}

void Connector::connect(void) {
    socketM = new boost::asio::ip::tcp::socket(serviceM);
    socketM->open(boost::asio::ip::tcp::v4());
    socketM->connect(endpointM);
}

void Connector::disconnect(void) {
    socketM->shutdown(boost::asio::ip::tcp::socket::shutdown_receive);
    socketM->close();
}

void Connector::write(std::string messageA) {
    socketM->write_some(boost::asio::buffer(messageA));
}

Connector::~Connector() {
    delete(socketM);
}

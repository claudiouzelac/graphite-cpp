#include "graphite_connector.h"

graphite_connector::graphite_connector(std::string hostA, int portA) {
    endpointM = boost::asio::ip::tcp::endpoint(
            boost::asio::ip::address::from_string(hostA), portA);
}

void graphite_connector::connect(void) {
    socketM = new boost::asio::ip::tcp::socket(serviceM);
    socketM->open(boost::asio::ip::tcp::v4());
    socketM->connect(endpointM);
}

void graphite_connector::disconnect(void) {
    socketM->shutdown(boost::asio::ip::tcp::socket::shutdown_receive);
    socketM->close();
}

void graphite_connector::write(std::string messageA) {
    socketM->write_some(boost::asio::buffer(messageA));
}

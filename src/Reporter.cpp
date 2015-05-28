#include "Reporter.hpp"

Reporter::Reporter(const std::string& hostA, int portA) {
    connectorM = new Connector(hostA, portA);
}

void Reporter::connect(void) {
    connectorM->connect();
}

void Reporter::disconnect(void) {
    connectorM->disconnect();
}

std::string Reporter::sanitizeString(std::string stringA) {
    std::replace(stringA.begin(), stringA.end(), ' ', '-');
    return stringA;
}

void Reporter::send(std::string metricA, const std::string& valueA) {
    std::string metric = sanitizeString(metricA);
    auto seconds =
            std::chrono::system_clock::now().time_since_epoch() /
                    std::chrono::seconds(1);
    std::stringstream ss;
    ss << metric << " " << valueA << " " << seconds << "\n" << std::endl;
    std::string message = ss.str();
    connectorM->write(message);
}


#include "graphite_reporter.h"

graphite_reporter::graphite_reporter(std::string hostA, int portA) {
    connectorM = new graphite_connector(hostA, portA);
}

void graphite_reporter::connect(void) {
    connectorM->connect();
}

void graphite_reporter::disconnect(void) {
    connectorM->disconnect();
}

std::string graphite_reporter::sanitizeString(std::string stringA) {
    std::replace(stringA.begin(), stringA.end(), ' ', '-');
    return stringA;
}

template <class T>
void graphite_reporter::send(std::string metricA, T valueA) {
    std::string metric = sanitizeString(metricA);
    auto seconds =
            std::chrono::system_clock::now().time_since_epoch() /
                    std::chrono::seconds(1);
    std::stringstream ss;
    ss << metric << " " << valueA << " " << seconds << "\n" << std::endl;
    std::string message = ss.str();
    connectorM->write(message);
}


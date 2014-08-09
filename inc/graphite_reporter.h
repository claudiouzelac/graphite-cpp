//Copyright 2014, Stewart Henderson

#include <chrono>
#include <string>
#include <sstream>
#include "graphite_connector.h"

class graphite_reporter {
  public:
    graphite_reporter(std::string hostA, int portA);
    void connect(void);
    void disconnect(void);

    template <class T>
    void send(std::string metricA, T valueA);
  private:
    graphite_connector * connectorM;
    std::string sanitizeString(std::string stringA);
};


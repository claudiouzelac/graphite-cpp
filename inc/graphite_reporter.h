//Copyright 2014, Stewart Henderson

#include <chrono>
#include <string>
#include <sstream>
#include "graphite_connector.h"

/*! \brief Graphite reporter
 *  \author Stewart Henderson
 */
class graphite_reporter {
  public:
    /**
     * \brief Create a graphite reporter for server at IP address and port
     * \param hostA, IP address for Graphite server
     * \param portA, port for Graphite server
     */
    graphite_reporter(std::string hostA, int portA);
    /// Connect to specified server
    void connect(void);
    /// Disconnect from server.
    void disconnect(void);

    /**
     * \brief Send a metric and value pair to the server
     * \param metricA, metric that you are posting a value to
     * \param valueA, corresponding value to the metric
     */
    template <class T>
    void send(std::string metricA, T valueA);
  private:
    graphite_connector * connectorM;
    std::string sanitizeString(std::string stringA);
};


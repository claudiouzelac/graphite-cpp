#pragma once
#ifndef __PERIODIC_PUBLISHER__
#define __PERIODIC_PUBLISHER__

#include "Connector.hpp"

class PeriodicPublisher {
public:
    PeriodicPublisher() = delete;
    PeriodicPublisher(Connector& connector, int interval);
private:
    Connector connector;
    int interval;
};

#endif
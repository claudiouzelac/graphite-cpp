#include <string>
#include "graphite_reporter.h"

int main() {
    graphite_reporter reporter("your host IP here", 2003);
    reporter.connect();
    reporter.send("local.random.dicerool", 5);
    return 0;
}
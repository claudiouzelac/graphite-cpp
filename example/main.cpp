#include <string>
#include "Reporter.hpp"

int main() {
    Reporter reporter("your host IP here", 2003);
    reporter.connect();
    reporter.send("local.random.dicerool", "5");
    return 0;
}
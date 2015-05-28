#include <string>
#include "Reporter.hpp"

int main() {
    Reporter reporter(std::move("127.0.0.1"), 2003);
    reporter.connect();
    reporter.send("local.random.dicerool", "5");
    return 0;
}
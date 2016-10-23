#include <iostream>
#include "Facade.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Facade facade = Facade();
    facade.run();
    return 0;
}
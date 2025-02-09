#include <iostream>
#include "hello.hpp"

namespace example {

void hello(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}
} // namespace example

#include <iostream>
#include <client.hpp>

namespace client {
    client::helloWorld() {
        std::cout << "Hello, world!\n";
    }
}

using namespace client;

int main(int argc,char* argv[])
{
    client::helloWorld();
    return 0;
}
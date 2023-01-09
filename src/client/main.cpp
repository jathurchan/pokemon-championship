#include <client.hpp>
#include <iostream>
#include "utilities.hpp"

int main(int argc,char* argv[])
{
    std::cout << "It Works !" <<std::endl;

    client::ClientEngine engine;
    engine.run();

    return 0;
}
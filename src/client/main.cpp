#include <iostream>
#include <hello_world.hpp>

using namespace std;

void World::Hello () {
    std::cout << "Hello, world!\n";
}

int main(int argc,char* argv[])
{
    World::Hello();
    return 0;
}
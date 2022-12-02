#include <client.hpp>
#include <iostream>
#include <chrono>

int main(int argc,char* argv[])
{
    std::cout << "It Works !" <<std::endl;

    //std::chrono::milliseconds::count();

    client::BattleScene battleScene(std::make_shared<client::LoginState>());

    return 0;
}
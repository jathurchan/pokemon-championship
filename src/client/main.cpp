#include <client.hpp>
#include <iostream>

int main(int argc,char* argv[])
{
    std::cout << "It Works !" <<std::endl;

    client::InterfaceJsonParser jsonParser;
    client::BattleScene battleScene(std::make_shared<client::LoginState>());

    return 0;
}
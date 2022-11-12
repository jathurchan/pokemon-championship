#include <client.hpp>
#include <iostream>

int main(int argc,char* argv[])
{
    std::cout << "It Works !" <<std::endl;

    client::BattleScene battleScene(std::make_shared<client::ChoiceState>());


    return 0;
}
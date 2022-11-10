#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.hpp>
#include <client.hpp>

using namespace std;
using namespace state;
using namespace client;

int main(int argc,char* argv[])
{
    hello helloWorld;
    helloWorld.helloWorld();
    cout << "It works !" << endl;

    return 0;
}

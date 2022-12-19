#include <model.hpp>
#include <iostream>

int main(int argc,char* argv[])
{
    std::cout << "It Works !" << std::endl;

    model::Model model("defaultCreatures", "defaultItems");

    std::cout << "Parsed successfully!" << std::endl;

    model.DispAll();

    return 0;
}
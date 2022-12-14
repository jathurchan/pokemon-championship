#include <iostream>
#include "LinkCode.h"

int main() {

    // Tests for LinkCode
    LinkCode firstLC = LinkCode("0123");
    LinkCode secondLC = LinkCode("123123");
    LinkCode thirdLC = LinkCode("123d");

    if (firstLC.Valid()) {
        std::cout << firstLC.GetContent() << std::endl;
    }

    if (secondLC.Valid()) {
        std::cout << secondLC.GetContent() << std::endl;
    }

    if (thirdLC.Valid()) {
        std::cout << thirdLC.GetContent() << std::endl;
    }
    return 0;
}

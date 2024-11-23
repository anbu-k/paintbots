// @author Anbu Krishnan - anbu@iastate.edu
#include "ExternalBoardSquare.h"
#include <iostream>
#include <type_traits>

int main() {
    bool isDerived = std::is_base_of<BoardSquare, ExternalBoardSquare>::value;

    std::cout << "ExternalBoardSquareTest: ";
    if (isDerived) {
        std::cout << "PASS - ExternalBoardSquare is a subclass of BoardSquare" << std::endl;
        return 0;
    } else {
        std::cout << "FAIL - ExternalBoardSquare is not a subclass of BoardSquare" << std::endl;
        return 1;
    }
}

// @author Anbu Krishnan - anbu@iastate.edu
#include "InternalBoardSquare.h"
#include <iostream>
#include <type_traits>

int main() {
    bool isDerived = std::is_base_of<BoardSquare, InternalBoardSquare>::value;

    std::cout << "InternalBoardSquareTest: ";
    if (isDerived) {
        std::cout << "PASS - InternalBoardSquare is a subclass of BoardSquare" << std::endl;
        return 0;
    } else {
        std::cout << "FAIL - InternalBoardSquare is not a subclass of BoardSquare" << std::endl;
        return 1;
    }
}

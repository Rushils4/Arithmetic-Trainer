#include "adder.hpp"

void addition_problem(int*& integer_list, unsigned int argument_quantity) {
    int16_t sum = 0;
    for (unsigned int idx = 0; idx < argument_quantity - 1; idx++) {
        sum += *(integer_list + idx);
        std::cout << *(integer_list + idx) << " + ";
    }
    std::cout << *(integer_list + argument_quantity - 1) << " = " << sum << std::endl;
}
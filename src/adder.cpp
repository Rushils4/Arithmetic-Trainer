#include "adder.hpp"

bool addition_problem(int*& integer_list, unsigned int argument_quantity) {
    int16_t sum = 0;
    int16_t user_answer = 0;
    for (unsigned int idx = 0; idx < argument_quantity - 1; idx++) {
        sum += *(integer_list + idx);
        std::cout << *(integer_list + idx) << " + ";
    }
    sum += *(integer_list + argument_quantity - 1);
    std::cout << *(integer_list + argument_quantity - 1) << " = ";
    std::cin >> user_answer;
    if (sum == user_answer) {
        std::cout << "--- CORRECT ---" << std::endl;
        return true;
    } else {
        std::cout << "--- INCORRECT | Answer is " << sum << " ---" << std::endl;
        return false;
    }
}
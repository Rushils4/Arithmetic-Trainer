#include "basic_arithmetic.hpp"
#include <stdexcept>

bool problem_chooser(void**& term_list, unsigned int argument_quantity, unsigned int problem_type) {
    /* Input Sanitization */
    if (problem_type > 4 || problem_type < 0) {
        throw std::invalid_argument("Illegal Problem Type");
        return false;
    }
    
    /* Returning Problem Based on Type */
    switch(problem_type) {
        case 0: {
            __float128* integer_list{new __float128[argument_quantity]};
            for (unsigned int idx = 0; idx < argument_quantity; idx++) {
                *(integer_list + idx) = *(static_cast<__float128*>(term_list[idx]));
            }
            bool to_return = addition_problem(integer_list, argument_quantity);
            delete[] integer_list;
            return to_return;
            break;
        }
        case 1: {
            __float128* integer_list{new __float128[argument_quantity]};
            for (unsigned int idx = 0; idx < argument_quantity; idx++) {
                *(integer_list + idx) = *(static_cast<__float128*>(term_list[idx]));
            }
            bool to_return = subtraction_problem(integer_list, argument_quantity);
            delete[] integer_list;
            return to_return;
            break;
        }
        case 2: {
            __float128* integer_list{new __float128[argument_quantity]};
            for (unsigned int idx = 0; idx < argument_quantity; idx++) {
                *(integer_list + idx) = *(static_cast<__float128*>(term_list[idx]));
            }
            bool to_return = multiplication_problem(integer_list, argument_quantity);
            delete[] integer_list;
            return to_return;
            break;
            break;
        }
        case 3: {
            return false;
            break;
        }
    }
    return false;
}

bool addition_problem(__float128*& integer_list, unsigned int argument_quantity) {
    /* Input Sanitization */
    if (integer_list == nullptr || argument_quantity <= 0) {
        throw std::invalid_argument("Illegal Argument Quantity || integer_list == nullptr");
    }
    
    /* Creating Variables */
    int16_t sum = 0;
    int16_t user_answer = 0;

    /* Printing integer_list According To argument_quantity */
    for (unsigned int idx = 0; idx < argument_quantity - 1; idx++) {
        sum += *(integer_list + idx);
        std::cout << *(integer_list + idx) << " + ";
    }
    sum += *(integer_list + argument_quantity - 1);
    std::cout << *(integer_list + argument_quantity - 1) << " = ";

    /* Get & Check User Answer */
    std::cin >> user_answer;
    if (sum == user_answer) {
        std::cout << "--- CORRECT ---" << std::endl;
        return true;
    } else {
        std::cout << "--- INCORRECT | Answer is " << sum << " ---" << std::endl;
        return false;
    }
}

bool subtraction_problem(__float128*& integer_list, unsigned int argument_quantity) {
    /* Input Sanitization */
    if (integer_list == nullptr || argument_quantity <= 0) {
        throw std::invalid_argument("Illegal Argument Quantity || integer_list == nullptr");
    }
    
    /* Creating Variables */
    int16_t difference = *integer_list;
    int16_t user_answer = 0;

    /* Printing integer_list According To argument_quantity */
    for (unsigned int idx = 0; idx < argument_quantity - 1; idx++) {
        difference -= (idx == 0) ? 0 : *(integer_list + idx);
        std::cout << *(integer_list + idx) << " - ";
    }
    difference -= argument_quantity > 1 ? *(integer_list + argument_quantity - 1) : 0;
    std::cout << *(integer_list + argument_quantity - 1) << " = ";

    /* Get & Check User Answer */
    std::cin >> user_answer;
    if (difference == user_answer) {
        std::cout << "--- CORRECT ---" << std::endl;
        return true;
    } else {
        std::cout << "--- INCORRECT | Answer is " << difference << " ---" << std::endl;
        return false;
    }
}

bool multiplication_problem(__float128*& integer_list, unsigned int argument_quantity) {
    /* Input Sanitization */
    if (integer_list == nullptr || argument_quantity <= 0) {
        throw std::invalid_argument("Illegal Argument Quantity || integer_list == nullptr");
    }
    
    /* Creating Variables */
    int16_t product = 1;
    int16_t user_answer = 0;

    /* Printing integer_list According To argument_quantity */
    for (unsigned int idx = 0; idx < argument_quantity - 1; idx++) {
        product *= *(integer_list + idx);
        std::cout << *(integer_list + idx) << " * ";
    }
    product *= *(integer_list + argument_quantity - 1);
    std::cout << *(integer_list + argument_quantity - 1) << " = ";

    /* Get & Check User Answer */
    std::cin >> user_answer;
    if (product == user_answer) {
        std::cout << "--- CORRECT ---" << std::endl;
        return true;
    } else {
        std::cout << "--- INCORRECT | Answer is " << product << " ---" << std::endl;
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, __float128 num) {
    os << num;
    return os;
}
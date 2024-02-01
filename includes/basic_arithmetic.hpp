#ifndef BASIC_ARITHMETIC_HPP
#define BASIC_ARITHMETIC_HPP
#include <iostream>

bool problem_chooser(void**& term_list, unsigned int argument_quantity, unsigned int problem_type);

bool addition_problem(int*& integer_list, unsigned int argument_quantity);

bool subtraction_problem(int*& integer_list, unsigned int argument_quantity);

#endif
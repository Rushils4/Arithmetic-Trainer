#include "adder.hpp"

int main() {
    unsigned int argument_quantity = 5;
    int* integer_list{new int[argument_quantity]{1, 2, 3, 4, 5}};
    addition_problem(integer_list, argument_quantity);
    delete[] integer_list;
    return 0;
}
#include "adder.hpp"
#include <vector>
#include <random>

unsigned int number_of_problems = 10;
unsigned int correct_answers = 0;
unsigned int argument_quantity = 2;
std::random_device generator;
std::uniform_int_distribution<int> distribution(1, 10);

int main() {
    std::cout << std::endl;
    for (unsigned int idx = 0; idx < number_of_problems; idx++) {
        int* integer_list{new int[argument_quantity]};
        for (unsigned int jdx = 0; jdx < argument_quantity; jdx++) {
            *(integer_list + jdx) = distribution(generator);
        }
        correct_answers += addition_problem(integer_list, argument_quantity);
        delete[] integer_list;
        std::cout << std::endl;
    }
    std::cout << "Number of Correct Answers: " << correct_answers << std::endl;
    return 0;
}
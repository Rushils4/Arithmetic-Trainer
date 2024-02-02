#include "basic_arithmetic.hpp"
#include <vector>
#include <random>

unsigned int number_of_problems = 10;
unsigned int correct_answers = 0;
unsigned int argument_quantity = 2;
std::random_device generator;
std::uniform_int_distribution<__float128> distribution1(1, 10);
std::uniform_int_distribution<__float128> distribution2(0, 2);

int main() {
    time_t start, end;
    std::time(&start);
    std::cout << std::endl;
    for (unsigned int idx = 0; idx < number_of_problems; idx++) {
        void** integer_list{new void*[argument_quantity]};
        for (unsigned int jdx = 0; jdx < argument_quantity; jdx++) {
            __float128* integer = new __float128(distribution1(generator));
            integer_list[jdx] = static_cast<void*>(integer);
        }
        correct_answers += problem_chooser(integer_list, argument_quantity, distribution2(generator));
        delete[] integer_list;
        std::cout << std::endl;
    }
    std::cout << "Number of Correct Answers: " << correct_answers << std::endl;
    std::time(&end);
    std::cout << "Took the User " << end - start << " Seconds to Complete." << std::endl;
    std::cout << "Correct Answers/Second: " << static_cast<double>(correct_answers) / (end - start) << std::endl;
    return 0;
}
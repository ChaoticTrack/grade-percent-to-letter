#include <iostream>
#include <string>
#include <array>

struct Grade
{
    int min, max;
    std::string symbol;
};

void initialize_grade(Grade *grade, std::string symbol, int min, int max);
int getInputGrade();

int main()
{
    Grade grade_aplus,
        grade_a,
        grade_b,
        grade_c,
        grade_d,
        grade_f;

    initialize_grade(&grade_aplus, "A+", 91, 100);
    initialize_grade(&grade_a, "A", 81, 90);
    initialize_grade(&grade_b, "B", 70, 80);
    initialize_grade(&grade_c, "C", 60, 69);
    initialize_grade(&grade_d, "D", 50, 59);
    initialize_grade(&grade_f, "F", 0, 49);

    const int kNumberOfGrades = 6;
    std::array<Grade*, kNumberOfGrades> grades = {
        &grade_aplus,
        &grade_a,
        &grade_b,
        &grade_c,
        &grade_d,
        &grade_f
    };

    int inputGrade = getInputGrade();

    // find which range inputGrade falls into
    for (int i = 0; i < kNumberOfGrades; i++) {
        // if inputGrade is within range of the current grade we're checking against... notify the user
        if (inputGrade <= grades[i]->max && inputGrade >= grades[i]->min) {
            std::cout << "You scored " << grades[i]->symbol
                << " (" << inputGrade << "%). ";
        }
    }

    if (inputGrade == 100)
        std::cout << "Congratulations, you got a perfect score!" << std::endl;

    return 0;
}

void initialize_grade(Grade *grade, std::string symbol, int min, int max)
{
    grade->symbol = symbol;
    grade->min = min;
    grade->max = max;
    return;
}

int getInputGrade()
{
    int inputGrade = 0;

    std::cout << "Please enter your grade as a percent." << std::endl;
    while (true) {
        std::cout << ">> ";
        std::cin >> inputGrade;
        std::cout << '\n';

        if (!std::cin.good() || inputGrade < 0 || inputGrade > 100) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cerr << "ERROR: Your grade must be a whole number between 0 and 100. Please try again." << std::endl;
        } else {
            break;
        }
    }

    return inputGrade;
}

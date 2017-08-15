#include <iostream>
#include <string>
#include <vector>

struct Grade
{
    int max;
    std::string symbol;
};

void initialize_grade(Grade *grade, std::string symbol, int max);
int getInputGrade();

int main()
{
    Grade grade_aplus,
        grade_a,
        grade_b,
        grade_c,
        grade_d,
        grade_f;

    initialize_grade(&grade_f, "F", 49);
    initialize_grade(&grade_d, "D", 59);
    initialize_grade(&grade_c, "C", 69);
    initialize_grade(&grade_b, "B", 80);
    initialize_grade(&grade_a, "A", 90);
    initialize_grade(&grade_aplus, "A+", 100);

    std::vector<Grade*> grades = {
        &grade_f,
        &grade_d,
        &grade_c,
        &grade_b,
        &grade_a,
        &grade_aplus
    };

    int inputGrade = getInputGrade();

    // find which range inputGrade falls into
    for (decltype(grades.size()) i = 0; i != grades.size(); ++i) {
        if (inputGrade <= grades[i]->max) {
            std::cout << "You scored " << grades[i]->symbol <<
                " (" << inputGrade << "%). ";
            break;
        }
    }

    if (inputGrade == 100)
        std::cout << "Congratulations, you got a perfect score!" << std::endl;

    return 0;
}

void initialize_grade(Grade *grade, std::string symbol, int max)
{
    grade->symbol = symbol;
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

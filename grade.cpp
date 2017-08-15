#include <iostream>     // cin, cout, endl, istream, cerr
#include <stdexcept>    // domain_error
#include <string>       // string
#include <vector>       // vector

using std::string;
using std::vector;

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::cerr;
using std::domain_error;

struct Grade
{
    int max;
    string symbol;
};

void initialize_grade(Grade&, string, int);
int getInputGrade();
istream& read(istream&, int&);

int main()
{
    /*
     * TODO: simplify how grades are represented, possibly without named objects?
     * REQUIREMENTS
     * 1. iterate through the objects to compare against input grade
     * 2. assign them distinct properties
    */
    Grade grade_aplus,
        grade_a,
        grade_b,
        grade_c,
        grade_d,
        grade_f;

    initialize_grade(grade_f, "F", 49);
    initialize_grade(grade_d, "D", 59);
    initialize_grade(grade_c, "C", 69);
    initialize_grade(grade_b, "B", 80);
    initialize_grade(grade_a, "A", 90);
    initialize_grade(grade_aplus, "A+", 100);

    // used to iterate through for comparison to input grade
    vector<Grade*> grades = {
        &grade_f,
        &grade_d,
        &grade_c,
        &grade_b,
        &grade_a,
        &grade_aplus
    };

    // get input for grade until valid
    int inputGrade;
    while (true) {
        try {
            cout << "Please enter your grade as a percent." << endl;
            read(cin, inputGrade);
            break;
        } catch (domain_error e) {
            cerr << e.what() << "\n\n";
        }
    }

    // find which range inputGrade falls into
    typedef vector<Grade*>::size_type vec_sz;
    for (vec_sz i = 0; i != grades.size(); ++i) {
        if (inputGrade <= grades[i]->max) {
            cout << "You scored " << grades[i]->symbol <<
                " (" << inputGrade << "%). ";
            break;
        }
    }

    if (inputGrade == 100)
        cout << "Congratulations, you got a perfect score!" << endl;

    return 0;
}

void initialize_grade(Grade& grade, string symbol, int max)
{
    grade.symbol = symbol;
    grade.max = max;
    return;
}

istream& read(istream& in, int& grade)
{
    if (in) {
        grade = 0;

        in >> grade;

        if (!cin.good() || grade < 0 || grade > 100) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            throw domain_error("ERROR: Your grade must be a whole number between 0 and 100. Try again.");
        }

    }

    return in;
}

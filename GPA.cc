
#include <cstdlib>
#include <iomanip>
#include <iostream>
const int MAX_GRADES = 6;

int numberOfGrades();
void inputGrades(int[], int);
double calculateGPA(int[], int);
void printPrompt();
double convertToGPA(int);

int main(int argc, char *argv[]) {
    int numGrades = numberOfGrades();
    int *Grades = new int[MAX_GRADES];
    printPrompt();
    inputGrades(Grades, numGrades);
    double gpa = calculateGPA(Grades, numGrades);
    std::cout << "Your GPA is: " << std::fixed << std::setprecision(2) << gpa
              << std::endl;
    delete[] Grades;
    return 0;
}

int numberOfGrades() {
    int numGrades = 0;
    std::cout << "Enter the number of classes you have: ";
    std::cin >> numGrades;
    return numGrades;
}

void inputGrades(int Grades[], int numGrades) {
    for (int i = 0; i < numGrades; i++) {
        std::cout << "Enter a grade: ";
        std::cin >> Grades[i];
        std::cout << std::endl;
    }
}

double calculateGPA(int Grades[], int numGrades) {
    double sum = 0.0;
    for (int i = 0; i < numGrades; i++) {
        double gpa = convertToGPA(Grades[i]);
        sum += gpa;
    }
    double gpa = sum / numGrades;
    return gpa;
}

void printPrompt() {
    std::cout << "Welcome to the GPA calculator!" << std::endl;
}

double ConvertToGPA(int grade) {
    if (grade >= 90 && grade <= 100) {
        return 4.0;
    } else if (grade >= 80 && grade < 90) {
        return 3.0;
    } else if (grade >= 70 && grade < 80) {
        return 2.0;
    } else if (grade >= 60 && grade < 70) {
        return 1.0;
    } else {
        return 0.0;
    }
}

char convertToLetter(double grade) {
    if (grade >= 90)
        return 'A';
    else if (grade >= 80)
        return 'B';
    else if (grade >= 70)
        return 'C';
    else if (grade >= 60)
        return 'D';
    else
        return 'F';
}

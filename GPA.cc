
#include <cstdlib>
#include <iomanip>
#include <iostream>
const int MAX_GRADES = 6;

int NumberOfGrades();
void InputGrades(int[], int);
double CalculateGPA(int[], int);
void PrintPrompt();
double ConvertToGPA(int);

int main(int argc, char *argv[]) {
  int numGrades = NumberOfGrades();
  int Grades[MAX_GRADES];
  PrintPrompt();
  InputGrades(Grades, numGrades);
  double gpa = CalculateGPA(Grades, numGrades);
  std::cout << "Your GPA is: " << std::fixed << std::setprecision(2) << gpa
            << std::endl;
  return 0;
}

int NumberOfGrades() {
  int numGrades = 0;
  std::cout << "Enter the number of classes you have: ";
  std::cin >> numGrades;
  return numGrades;
}

void InputGrades(int Grades[], int numGrades) {
  for (int i = 0; i < numGrades; i++) {
    std::cout << "Enter a grade: ";
    std::cin >> Grades[i];
    std::cout << std::endl;
  }
}

double CalculateGPA(int Grades[], int numGrades) {
  double sum = 0.0;
  for (int i = 0; i < numGrades; i++) {
    double gpa = ConvertToGPA(Grades[i]);
    sum += gpa;
  }
  double gpa = sum / numGrades;
  return gpa;
}

void PrintPrompt() {
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

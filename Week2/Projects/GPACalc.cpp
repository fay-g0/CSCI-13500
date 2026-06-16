#include <iostream>
#include <string>

//Function helper --> Converts incoming letters in a string into uppercase
std::string toUpperCase(std::string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = word[i] - 32;
        }
    }
    return word;
}

//Function helper --> Takes the grade string and matches it to respective credit point; Returns -1 if the grade is not valid
double gradeToPoints(std::string grade) {
    if (grade == "A+" || grade == "A")  return 4.0;
    else if (grade == "A-")             return 3.7;
    else if (grade == "B+")             return 3.3;
    else if (grade == "B")              return 3.0;
    else if (grade == "B-")             return 2.7;
    else if (grade == "C+")             return 2.3;
    else if (grade == "C")              return 2.0;
    else if (grade == "D")              return 1.0;
    else if (grade == "F")              return 0.0;
    else if (grade == "WU")             return 0.0;
    else if (grade == "FIN")            return 0.0;
    else if (grade == "FAB")            return 0.0;
    else                                return -1;
}

int main() {
//Instructions
    std::cout << "⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆" << std::endl;
    std::cout << "   Hunter College GPA Calculator" << std::endl;
    std::cout << "⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆⋆⭒˚｡⋆" << std::endl;
    std::cout << std::endl;
    std::cout << "HOW TO USE THIS CALCULATOR:" << std::endl;
    std::cout << "  Enter each course as: <credits><grade>" << std::endl;
    std::cout << "  - Credits : a single digit from 1 to 9" << std::endl;
    std::cout << "  - Grade   : A+, A, A-, B+, B, B-, C+, C, D, F, WU, FIN, FAB" << std::endl;
    std::cout << "  Input is case-insensitive (ex: 3a is the same as 3A)." << std::endl;
    std::cout << "  Examples: 3A   4B-   2WU   3fin" << std::endl;
    std::cout << std::endl;

int totalClasses = 0;
int totalCredits = 0;
double totalQualityPoints = 0;
std::string userInput;
std::string continueChoice;


while (true) {
    std::cout << "Enter course (credit(s) + grade): ";
    std::cin >> userInput;
//Error msg if incorrect
    if (std::cin.fail()) {
        std::cout << "Input error. Exiting program." << std::endl;
        break;
    }
if (userInput.length() < 2) {
    std::cout << " Error: Too short." << std::endl;
    std::cout << "  Try again? (y/yes to continue): ";
    std::cin >> continueChoice;
    continueChoice = toUpperCase(continueChoice);
    if (continueChoice == "Y" || continueChoice == "YES") continue;
    else break;
}

//First character validation
if (userInput[0] < '1' || userInput[0] > '9') {
    std::cout << "Error: First character must be a digit from 1 to 9. " << std::endl;
    std::cout << "Try again? (y/yes to continue or n/no to get results): ";
    std::cin >> continueChoice;
    continueChoice = toUpperCase(continueChoice);
    if (continueChoice == "Y" || continueChoice == "YES") continue;
    else break;
}

int credit = userInput[0] - '0'; //First character gets converted into credit value
std::string grade = userInput.substr(1); //Extract grade part and convert to uppercase
grade = toUpperCase(grade);
double points = gradeToPoints(grade); //Retrieve grade and get point value

//if -1 returned = the grade is not valid
if (points < 0) {
    std::cout << "Error: \"" << grade << "\" is not a valid grade." << std::endl;
    std::cout << "Valid grades: A+, A, A-, B+, B, B-, C+, C, D, F, WU, FIN, FAB" << std::endl;
    std::cout << "  Try again? (y/yes to continue or n/no to get results): ";
    std::cin >> continueChoice;
    continueChoice = toUpperCase(continueChoice);
    if (continueChoice == "Y" || continueChoice == "YES") continue;
    else break;
}

double qualityPts = credit * points;
totalClasses += 1;
totalCredits += credit;
totalQualityPoints += qualityPts;

std::cout << " Added: " << credit << " credit(s), Grade: " << grade << " (" << points << " pts)" << std::endl;

std::cout << " Add another course? (y/yes to continue or n/no to get results): ";
std::cin >> continueChoice;
continueChoice = toUpperCase(continueChoice);

if (continueChoice != "Y" && continueChoice != "YES") {
    break;
}
std::cout << std::endl;

}
    std::cout << std::endl;
    std::cout << "✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔ " << std::endl;
//No courses enter = no GPA calculated
    if (totalClasses == 0) {
        std::cout <<"Nothing entered. GPA cannot be determined." << std::endl;
    } else {
        double cumulativeGPA = totalQualityPoints / totalCredits;
        int rounded = (int)(cumulativeGPA * 100 + 0.5); //Rounded to the nearest hundreth
        double finalGPA = rounded / 100.0;
//RESULTS
        std::cout<< "Classes taken: " << totalClasses << ", Semester GPA: " << finalGPA << std::endl;
    }
    std::cout << "✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔ ✩࿐࿔" << std::endl;
    std::cout << "Thanks for using the GPA Calculator!" << std::endl;
    return 0;
}
/*
Assignment Reflection:
Used Ai, specifically asked Claude to break down the logic for th project.
It helped in a way that it gave me 3 pointers: Make the instructions, 
make a loop for the user until they are done using the calculator, and then
the aftermath of the loop should display the results of how many classed and the 
average GPA for whatever courses the user inputted. 

*/
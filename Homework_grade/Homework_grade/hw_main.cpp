// Homework_grade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include"HomeworkList.h"

int main() {

    string name, in1, yn;
    bool cont;
    int s, score, max;
    HomeworkList h;

    std::cout << "Enter student's name: ";
    std::cin >> name;

    cont = true;

    while (cont) {
        std::cout << "Enter score and max as two values: ";
        getline(cin, in1);
        
        s = in1.find(" ");
        score = std::stod(in1.substr(0, s));
        max = std::stod(in1.substr(s + 1));
        h.addScore(score, max);

        std::cout << "More scores? y/n: ";
        std::cin >> yn;

        if (yn == "n") {
            cont = false;
        }
    }
}

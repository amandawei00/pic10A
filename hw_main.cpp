
////////////////////////////////////////////////////////////////////////////////////////////////////// 
// pic10A assingment 4, homework grade                                                              //  
// author: Amanda Wei                                                                               //  
// student ID: 505 106 664                                                                          //  
// date: 10/24/2020                                                                                 //  
////////////////////////////////////////////////////////////////////////////////////////////////////// 

#include<iostream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include"HomeworkList.h"  // import HomeworkList class

int main() {

    string name, in1, yn;  //initializes variables to store student name, scores, yes/no input
    bool cont;  // condition for loop
    int s, score, max, num;  
    float best_avg;
    HomeworkList h;

    std::cout << "Enter student's name: ";  // prompt user for student name
    getline(cin, name);  // assign input to "name" variable

    cont = true;  // declare cont variable before entering loop

    while (cont) {
        std::cout << "Enter score and max as two values: ";  // as long as user wants to continue adding scores, prompt him/her for scores
        getline(cin, in1);
        
        s = in1.find(" ");  // find space between numbers to splice
        score = std::stod(in1.substr(0, s));  // convert the two numbers from strings to double values, assign to score, max variables accordingly
        max = std::stod(in1.substr(s + 1));
        h.addScore(score, max);  // invoke addScore() method from HomeworkList class

        std::cout << "More scores? y/n: ";  // ask to continue
        getline(cin, yn);

        if (yn == "n") {  // if user says "no", update cont to exit loop
            cont = false;
        }
    }

    // output

    std::cout << "How many scores should be used in computing the HW grade? ";
    std::cin >> num;

    best_avg = h.percentageFromBest(num);

    cout << fixed << showpoint << setprecision(2);
    std::cout << "The homework grade for " << name << " based on the best " << num << " out of " << h.numberOfHWs() << " is " << best_avg << "%" << endl;


    // if block to output final comment 
    if (best_avg > 95) {
        std::cout << "This is excellent.";
    } else if (best_avg >= 80 && best_avg < 95){
        std::cout << "This is good." << endl;
    } else if (best_avg >= 70 && best_avg < 80) {
        std::cout << "This is decent." << endl;
    } else {
        std::cout << "This is poor." << endl;
    }


}

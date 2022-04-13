// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 04/13/22
// Description: Calculates whether or not th year entered by the user
// is a leap year or not
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::stoi;
using std::endl;

// declaring variables
bool restartLoop = true, answerLoop = true;
int yearInt;

// function calculates whether or not the entered year is a leap year
void calculate() {
    // checks if it can be divided evenly by 4
    if (yearInt % 4 == 0) {
        // checks if it can be divided evenly by 400
        if (yearInt % 400 == 0) {
            cout << yearInt << " is a leap year!" << endl;
        // checks if it can be divided evenly by 100
        } else if (yearInt % 100 == 0) {
            cout << yearInt << " is not a leap year!" << endl;
        } else {
            cout << yearInt << " is a leap year!" << endl;
        }
    } else {
        cout << yearInt << " is not a leap year!" << endl;
    }
}


int main() {
    string year, answer;
    // loop allows for program to be restarted
    while (restartLoop) {
        // get user input
        cout << "Enter the year: " << endl;
        cin >> year;

        answerLoop = true;
        // try is for error checking
        try {
            // converting to int
            yearInt = stoi(year);

            // will only calculate if year is positive
            if (yearInt > 0) {
                calculate();

                // loop is for the answer to the question
                while (answerLoop) {
                    cout << "Would you like to calculate another year? (y/n): ";
                    cin >> answer;

                    // if statement to restart the program
                    if (answer == "y") {
                        cout << "Okay" << endl;
                        answerLoop = false;

                    } else if (answer == "n") {
                        cout << "Okay";
                        answerLoop = false;
                        restartLoop = false;
                    } else {
                        cout << "I don't understand, please try again" << endl;
                    }
                }
            } else {
                cout << "Please enter a year later than 0" << endl;
            }
        // catches any runtime errors
        } catch (...) {
            cout << "Invalid input, please try again." << endl;
        }
    }
}

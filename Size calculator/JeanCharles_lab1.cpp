#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<iomanip>

using namespace std;

void Input(double& height, double& weight, int& age) {
    cout << "What is your age?" << endl;
    cin >> age;
    cout << "What is your height in inches?" << endl;
    cin >> height;
    cout << "What is your weight in pounds?" << endl;
    cin >> weight;
}

double calculateHatSize(double height, double weight) {
    double hat = (weight / height) * 2.9;
    return hat;
}

double calculateJacketSize(double height, double weight, int age) {
    double Jsize = (height * weight) / 288.0;
    int adjustment = 0;
    if (age > 30) {
        adjustment = (age - 30) / 10;
    }
    return Jsize + (0.125 * adjustment);
}

double calculateWaistSize(double weight, int age) {
    double waist = weight / 5.7;
    int adjustment = 0;
    if (age > 28) {
        adjustment = (age - 28) / 2;
    }
    return waist + (0.1 * adjustment);
}

void printSizes(double height, double weight, int age) {
    double hat = calculateHatSize(height, weight);
    double jacket = calculateJacketSize(height, weight, age);
    double waist = calculateWaistSize(weight, age);
    cout << "**************************************Printing out the info*******************************************\n";
    cout << "Size for age " << age << ":" << endl;
    cout << "Hat size is: " << fixed << setprecision(2) << hat << endl;
    cout << "Jacket size is: " << fixed << setprecision(2) << jacket << endl;
    cout << "Waist size is: " << fixed << setprecision(2) << waist << endl;


    cout << "*****************************Printing out info for ages for the next 10 years**********************\n";
    for (int i = 1; i <= 10; i++) {
        double hatNext = calculateHatSize(height, weight);
        double jacketNext = calculateJacketSize(height, weight, age + i);
        double waistNext = calculateWaistSize(weight, age + i);
        cout << "--------------------------------------------------------------------------------\n";
        cout << "Size for age " << age + i << ":" << endl;
        cout << "Hat size is: " << fixed << setprecision(2) << hatNext << endl;
        cout << "Jacket size is: " << fixed << setprecision(2) << jacketNext << endl;
        cout << "Waist size is: " << fixed << setprecision(2) << waistNext << endl;
        cout << "--------------------------------------------------------------------------------\n";
    }

    ofstream out_file("size.txt");
    if (out_file.is_open()) {
        double hat = calculateHatSize(height, weight);
        double jacket = calculateJacketSize(height, weight, age);
        double waist = calculateWaistSize(weight, age);
        out_file << "**************************************Printing out the info*******************************************\n";
        out_file << "Size for age " << age << ":" << endl;
        out_file << "Hat size is: " << fixed << setprecision(2) << hat << endl;
        out_file << "Jacket size is: " << fixed << setprecision(2) << jacket << endl;
        out_file << "Waist size is: " << fixed << setprecision(2) << waist << endl;

        out_file << "*****************************Printing out info for ages for the next 10 years**********************\n";
        for (int i = 1; i <= 10; i++) {
            double hatNext = calculateHatSize(height, weight);
            double jacketNext = calculateJacketSize(height, weight, age + i);
            double waistNext = calculateWaistSize(weight, age + i);
            out_file << "--------------------------------------------------------------------------------\n";
            out_file << "Size for age " << age + i << ":" << endl;
            out_file << "Hat size is: " << fixed << setprecision(2) << hatNext << endl;
            out_file << "Jacket size is: " << fixed << setprecision(2) << jacketNext << endl;
            out_file << "Waist size is: " << fixed << setprecision(2) << waistNext << endl;
            out_file << "--------------------------------------------------------------------------------\n";
        }
    }
    else {
        cout << "File cannot open\n";
    }
}

int main() {
    double height, weight;
    int age;

    char repeat;
    do {
        Input(height, weight, age);
        printSizes(height, weight, age);

        cout << "Would you like to calculate again? (Y/N)" << endl;
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}




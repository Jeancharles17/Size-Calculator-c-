#include <iostream>
#include <string>
using namespace std;

class COP3014 {
private:
    string firstName, lastName, zNumber;
    int quiz1, quiz2, quiz3, midterm, finalExam;
    double totalGrade;
    char letterGrade;

public:
    COP3014() {}
    COP3014(string fname, string lname, string znum)
        : firstName(fname), lastName(lname), zNumber(znum),
        quiz1(100), quiz2(100), quiz3(100), midterm(100), finalExam(100) {}

    void setFirstName(string fname) { firstName = fname; }
    void setLastName(string lname) { lastName = lname; }
    void setZNumber(string znum) { zNumber = znum; }
    void setQuiz1(int grade) { quiz1 = grade; }
    void setQuiz2(int grade) { quiz2 = grade; }
    void setQuiz3(int grade) { quiz3 = grade; }
    void setMidterm(int grade) { midterm = grade; }
    void setFinalExam(int grade) { finalExam = grade; }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getZNumber() const { return zNumber; }
    int getQuiz1() const { return quiz1; }
    int getQuiz2() const { return quiz2; }
    int getQuiz3() const { return quiz3; }
    int getMidterm() const { return midterm; }
    int getFinalExam() const { return finalExam; }
    double getTotalGrade() const { return totalGrade; }
    char getLetterGrade() const { return letterGrade; }

    void computeTotalGrade() {
        totalGrade = (quiz1 + quiz2 + quiz3) / 3.0 + midterm * 0.3 + finalExam * 0.5;
    }

    void computeLetterGrade() {
        if (totalGrade >= 90) {
            letterGrade = 'A';
        }
        else if (totalGrade >= 80 && totalGrade <= 90) {
            letterGrade = 'B';
        }
        else if (totalGrade >= 70 && totalGrade <= 80) {
            letterGrade = 'C';
        }
        else if (totalGrade >= 60 && totalGrade <= 70) {
            letterGrade = 'D';
        }
        else {
            letterGrade = 'F';
        }
    }

    void checkAbsences() {
        if (midterm < 0 || finalExam < 0)
            letterGrade = 'F';
    }

    void printInfo() const {
        cout << firstName << " " << lastName << " - " << zNumber << endl;
        cout << "Quiz 1: " << quiz1 << endl;
        cout << "Quiz 2: " << quiz2 << endl;
        cout << "Quiz 3: " << quiz3 << endl;
        cout << "Mid term: " << midterm << endl;
        cout << "Final: " << finalExam << endl;
        cout << "Total grade: " << totalGrade << endl;
        cout << "Final grade: " << letterGrade << endl;
    }
};

int main() {
    string firstName, lastName, zNumber;
    int quiz1, quiz2, quiz3, midterm, finalExam;

    // Get student information and grades from user input
    cout << "Enter student's first name: ";
    getline(cin, firstName);

    cout << "Enter student's last name: ";
    getline(cin, lastName);

    cout << "Enter student's Z number: ";
    getline(cin, zNumber);

    cout << "Enter grade for Quiz 1(0 to 20): ";
    cin >> quiz1;

    cout << "Enter grade for Quiz 2(0 to 20 ): ";
    cin >> quiz2;

    cout << "Enter grade for Quiz 3(0 to 20): ";
    cin >> quiz3;

    cout << "Enter grade for Midterm(0 to 100): ";
    cin >> midterm;

    cout << "Enter grade for Final Exam(0 to 100): ";
    cin >> finalExam;

    // Create an instance of the COP3014 class
    COP3014 student(firstName, lastName, zNumber);
    student.setQuiz1(quiz1);
    student.setQuiz2(quiz2);
    student.setQuiz3(quiz3);
    student.setMidterm(midterm);
    student.setFinalExam(finalExam);

    // Compute the student's total grade and letter grade
    student.computeTotalGrade();
    student.checkAbsences();
    student.computeLetterGrade();

    // Print the student's information and grades
    student.printInfo();

    return 0;
}
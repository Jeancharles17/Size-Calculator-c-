
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

// define a function named amortization 
double amortization(double P, double r, int n) {
    double M = P * (r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
    return M;
}
// interest payement every month
void totalPaymentInterest(double M, double& totalPayment, double& totalInterest, double& interest)
{
    totalPayment += M;
    totalInterest += M - (M - interest);
}
//interest and balance 
void interestAndBalance(double P, double r, int n, double& totalInterest, double& totalPayments) {
    double balance = P, interest, principal, M = amortization(P, r, n);
    cout << "Loan Amount: " << " " << P << endl;
    cout << "Interest: " << " " << r << endl;
    cout << "Loan Period: " << " " << n << " " << "months" << endl;
    
    cout << "-------------------------------------------Amortization Schedule----------------------------------------------------------------------------" << endl;
    cout << setw(10) << "Month" << setw(20) << "Beginning Balance" << setw(20) << "Interest" << setw(20) << "Principal" << setw(20) << "Ending Balance" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    int year = 0, month = 1;
    for (int i = 1; i <= n; i++) {
        interest = balance * r;
        principal = M - interest;
        balance -= principal;
        totalInterest += interest;
        totalPayments += M;
        cout << fixed << setprecision(2) << setw(10) << month << setw(20) << P << setw(20) << interest << setw(20) << principal << setw(20) << balance << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        P = balance;
        int field_width = 30;
        if (i % 12 == 0) {
            year++;
            cout << setw(field_width) << "Year #" << year << " End" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------\n";
        }
        month++;
    }
}


void input(double& P, double& r, int& n) {
    // prompt the user to enter loan amount 
    cout << "Enter the loan amount: ";
    cin >> P;

    // prompt the user to enter interest rate
    cout << "Enter the interest rate: ";
    cin >> r;
    r = r / 100;

    // prompt the user to enter number number of months for payment
    cout << "Enter the number of payments over loan's lifetime in months: ";
    cin >> n;
    r /= 12;
}

void PrintingInfoToFile(double& P, double& r, int n, double& totalInterest, double& totalPayments) {
    //printing the loan table 
    ofstream out_file("loan.txt");

    if (out_file.is_open()) {
        double balance = P, interest, principal, M = amortization(P, r, n);
        out_file.width(5);
        out_file.setf(ios::fixed);
        out_file.setf(ios::showpoint);
        out_file << "Loan Amount: " << " " << P << endl;
        out_file << "Interest: " << " " << r << endl;
        out_file << "Loan Period: " << " " << n <<" "<<"months"<< endl;
        out_file << "-----------------------------------------Amortization Schedule------------------------------------------------------------------------------" << endl;
        out_file << setw(10) << "Month" << setw(20) << "Beginning Balance" << setw(20) << "Interest" << setw(20) << "Principal" << setw(20) << " Ending Balance" << endl;
        out_file << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;;
        out_file << fixed << setprecision(2);
        int year = 0, month = 1;
        for (int i = 1; i <= n; i++) {
            interest = balance * r;
            principal = M - interest;
            balance -= principal;
            out_file << fixed << setprecision(2) << setw(10) << month << setw(20) << P << setw(20) << interest << setw(20) << principal << setw(20) << balance << endl;
            out_file << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            P = balance;
            int field_width = 60;
            if (i % 12 == 0) {
                year++;

                out_file << setw(field_width) << "Year #" << year << " End" << endl;
                out_file << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";

            }
            month++;

        }

        out_file << "Payment Every Month: $" << M << endl;
        out_file << "Total Interest: $" << totalInterest << endl;
        out_file << "Total of " << n << " Payments: $" << totalPayments << endl;
        out_file << "----------------------------------------------------------------------------------------------------------------------------------";
        out_file.close();
        cout << "Loan information saved to file." << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    //main function
    double P, r, totalInterest = 0, totalPayments = 0;
    int n;
    char repeat;
    do {
        input(P, r, n);
        interestAndBalance(P, r, n, totalInterest, totalPayments);
        cout << "Payment Every Month: $" << amortization(P, r, n) << endl;
        cout << "Total of " << n << " Payments: $" << totalPayments << endl;
        cout << "Total Interest: $" << totalInterest << endl;
        PrintingInfoToFile(P, r, n, totalInterest, totalPayments);
        totalInterest = 0;
        totalPayments = 0;
        cout << "Do you want to repeat the calculation (y/n)? ";
        cin >> repeat;
    } while (repeat == 'y');
    return 0;
}
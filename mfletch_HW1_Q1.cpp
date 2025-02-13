#include <iostream>
using namespace std;

const int N = 5;

struct Check {
    int CheckNum; //string value since it can include numbers and letters
    string CheckMemo;
    float CheckAmount;
};

class CheckBook {
public:
    CheckBook():balance(0), numOfChecks(0), checkLimit(N) {}// initializing balance and numOfChecks, setting both to 0
    CheckBook(float initbal):balance(initbal), numOfChecks(0), checkLimit(N) {}//initializing balance, setting it to 'initbal' value, numOfChecks stays 0
    //separating constructors for user readability

    Check check[N]; //array set to N which = 5

    void deposit(float amount) { //function to add desired amount to current balance
        balance += amount;
        lastDeposit = amount;

    }

    void displayChecks() { //function to display checks in reverse chronological order
        for (int i = numOfChecks-1;i>=0; i--) {
            cout << check[i].CheckNum << " ";
            cout << check[i].CheckMemo << " ";
            cout << check[i].CheckAmount << " ";
            cout << endl;
        }
    }

    bool writeCheck(float amount) { //function to check if amount is less than or equal to balance
        if (amount <= balance) {
            string memo;
            cout<<"Enter memo for check: "<<endl;
            cin>>memo;

            //filling Check array information
            check[numOfChecks].CheckNum=numOfChecks+1;
            check[numOfChecks].CheckMemo=memo;
            check[numOfChecks].CheckAmount=amount;

            balance -= amount; //update balance
            numOfChecks++; //update numOfChecks
            return true;
        }
        else {
            return false;
        }
    }
private:
    //initializing data members
    float balance;
    float lastDeposit;
    int numOfChecks;
    int checkLimit;
};
int main() {
    CheckBook C1(900.98); //giving an initial balance

    C1.deposit (1000); //depositing 1000

    C1.writeCheck(400); //writing checks
    C1.writeCheck(500);

    C1.displayChecks(); // display checks starting with recent one


    return 0;
};

#include <iostream>
using namespace std;

const int N=5;  //const for array

class Check {
public:
    static int number;// static member

    //default constructor
    Check(): CheckNum(0), CheckMemo(""), CheckAmount(0) {
        number++; //increment static member
    }

    //get and set functions
    int getCheckNum() const {return CheckNum;}
    void setCheckNum(int num){CheckNum = num;}

    string getCheckMemo() const {return CheckMemo;}
    void setCheckMemo(string memo){CheckMemo = memo;}

    float getCheckAmount() const {return CheckAmount;}
    void setCheckAmount(float amount){CheckAmount = amount;}

private:
    //data members
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
};

class CheckBook {
public:
    CheckBook(): balance(0), numOfChecks(0) {} //default constructor
    CheckBook(float initBal): balance(initBal), numOfChecks(0){} // constructor with initial balance

    //static integer
    static int allChecks;

    //getter function for static int allChecks
    int getallChecks() const {return allChecks;}

    //deposit function (same as Q1)
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
    }

    //display checks function
    void displayChecks() {
        for (int i = numOfChecks-1; i>=0; i--) { //reverse order
            //stored values are printed
            cout << Checks[i].getCheckNum() <<" ";
            cout << Checks[i].getCheckMemo() << " ";
            cout <<  Checks[i].getCheckAmount()<< " ";
            cout << endl;
        }
    }

    //write check function
    bool writeCheck(float amount) {
        if (amount<=balance && numOfChecks<N && allChecks<10) { //conditions for writing a check
            //getting memo from user
            string memo;
            cout << "Please write your memo here: ";
            cin >> memo;

            //putting information in array
            Checks[numOfChecks].setCheckMemo(memo);
            Checks[numOfChecks].setCheckAmount(amount);
            Checks[numOfChecks].setCheckNum(numOfChecks);

            //update balance and number of checks
            balance -= amount;
            numOfChecks++;
            allChecks++;

            return true;
        }
        else { //when conditions are not met
            return false;
        }
    }


private:
    //data members
    float balance;
    int numOfChecks;
    float lastDeposit;
    int checkLimit= N;
    Check Checks[N];
};

//definitions of static members
int Check::number=0;
int CheckBook::allChecks=0;

int main() {
    CheckBook cb1(1000), cb2(500);
    for(int i=0; i<10;i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();
    cout<<cb1.getallChecks()<<endl;
    cout<<cb2.getallChecks()<<endl;

    return 0;
}
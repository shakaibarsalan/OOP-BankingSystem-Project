#include <iostream>     // for io
#include <fstream>      // files
#include <sstream>      // string casting
#include <cstring>      // for strcpy
#include <cctype>       // system CLS
#include <stdexcept>    // exeption handling
#include <Windows.h>    // colors
#include <vector>       // vector

using namespace std;

class DataBase;
class DataBase_Read;
class DataBase_Write;

class Account
{
private:
    int account_number;
    char type;
    char *name;
    double balance;
    string PIN;
    char status;
    char *CNIC;
    string email;
    char *phNo;
    string address;

    DataBase_Write *dbw;

public:
    Account(char typ, const char na[], double bal, string pin, const char cnic[], string eml, const char ph[], string add);

    template <typename T>
    void AllocateDynamically(Account *&A)
    {
        cout << "Allocated Account Dynamically\n";
        A = new T;
    }

    void block_acc ();
    void Input()
    {
        system("CLS");
        string in;

        cout << "\t\t\t\t\t Enter Full Name: ";
        cin.ignore();
        getline(cin, in);
        strcpy(name, in.c_str());

        cout << "\t\t\t\t\t Enter CNIC: ";
        bool cc = true;

        while (cc)
        {
            try
            {
                getline(cin, in);
                if (in.length() != 13)
                {
                    throw 404;
                }
                else
                {
                    cc = false;
                }
            }
            catch (int)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid CNIC" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "\t\t\t\t\t Again Enter CNIC: ";
            }
        }
        strcpy(CNIC, in.c_str());

        cc = true;
        cout << "\t\t\t\t\t Enter Phone Number: +92 ";
        while (cc)
        {
            try
            {
                getline(cin, in);
                if (in.length() != 10)
                {
                    throw 404;
                }
                else
                {
                    cc = false;
                }
            }
            catch (int)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid Phone Number." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "\t\t\t\t\t Again Enter Phone Number: +92 ";
            }
        }
        strcpy(phNo, in.c_str());

        cout << "\t\t\t\t\t Enter email: ";
        getline(cin, in);
        this->email = in;

        cout << "\t\t\t\t\t Enter Address: ";
        getline(cin, in);
        this->address = in;

        cc = true;
        cout << "\t\t\t\t\t Set your 4-Digit Security Pin: ";
        while (cc)
        {
            try
            {
                getline(cin, in);
                if (in.length() != 4)
                {
                    throw 404;
                }
                else
                {
                    cc = false;
                }
            }
            catch (int)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid PIN." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "\t\t\t\t\t Again Enter PIN: ";
            }
        }
        PIN = in;

        cc = true;

        cout << "\t\t\t\t\t Enter Deposit Amount: ";
        while (cc || balance<0)
        {
            try
            {
                cin >> balance;
                if (cin.fail() || balance<0)
                {
                    throw runtime_error("Error.");
                }
                else
                {
                    cc = false;
                }
            }
            catch (const exception &e)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid input." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "\t\t\t\t\t Again Enter Deposit Amount: ";
                cin.clear();
                cin.ignore();
            }
        }
    }

    void set_account_number(int account_number)
    {
        this->account_number = account_number;
    }
    void set_type(char type)
    {
        this->type = type;
    }
    void set_name(const char na[])
    {
        strcpy(name, na);
    }
    void set_balance(double balance)
    {
        this->balance = balance;
    }
    void set_PIN(string PIN)
    {
        this->PIN = PIN;
    }
    void set_status(char status)
    {
        this->status = status;
    }
    void set_CNIC(const char cnic[])
    {
        strcpy(CNIC, cnic);
    }
    void set_email(string email)
    {
        this->email = email;
    }
    void set_phNo(const char pH[])
    {
        strcpy(phNo, pH);
    }
    void set_address(string address)
    {
        this->address = address;
    }

    int get_account_number() const
    {
        return account_number;
    }
    char get_type() const
    {
        return type;
    }
    char *get_name() const
    {
        return name;
    }
    double get_balance() const
    {
        return balance;
    }
    string get_PIN() const
    {
        return PIN;
    }
    char get_status() const
    {
        return status;
    }
    char *get_CNIC() const
    {
        return CNIC;
    }
    string get_email() const
    {
        return email;
    }
    char *get_phNo() const
    {
        return phNo;
    }
    string get_address() const
    {
        return address;
    }

    double Send_Money();

    void change_Pin();

    void Display()
    {
        system("CLS");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        cout << "\t\t\t\t\t  ==== DISPLAY ====\n";
        cout << "\t\t\t\t\t Account Number: " << account_number << endl;
        cout << "\t\t\t\t\t Account Type: " << type << endl;
        cout << "\t\t\t\t\t Holder Name: " << name << endl;
        cout << "\t\t\t\t\t Balance: " << balance << endl;
        cout << "\t\t\t\t\t PIN: " << PIN << endl;
        cout << "\t\t\t\t\t Status: " << status << endl;
        cout << "\t\t\t\t\t CNIC: " << CNIC << endl;
        cout << "\t\t\t\t\t Email: " << email << endl;
        cout << "\t\t\t\t\t Phone Number: +92" << phNo << endl;
        cout << "\t\t\t\t\t Address: " << address << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    bool Login()
    {
        system("CLS");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 11);
        cout << "\t\t\t\t\t Welcome " << name << endl;
        cout << "\t\t\t\t\t Account Numner: " << account_number << endl;
        SetConsoleTextAttribute(hConsole, 7);

        bool found = false;
        int tries = 0;
        string in = "";

        do
        {
            tries++;
            cout << "try numer: " << tries << endl;

            cout << "\t\t\t\t\t Enter 4-Digit PIN: ";
            cin >> in;

            if (in == PIN)
            {
                found = true;
                return true;
            }
            else
            {
                if (tries < 3)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "\t\t\t\t\t Invalid! Try Again\n";
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }

        } while (!found && tries < 3);

        if (!found || tries >= 3)
        {
            cout << "\nBlock Ho gye\n";
            block_acc();
            return false;
        }
    }

    void serve_user();

    void User_Confirm_Disp()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 8);
        cout << "\t\t\t\t\t Holder Name: " << name << endl;
        cout << "\t\t\t\t\t CNIC: " << CNIC << endl;
        cout << "\t\t\t\t\t Email: " << email << endl;
        cout << "\t\t\t\t\t Phone Number: +92" << phNo << endl;
        cout << "\t\t\t\t\t Address: " << address << endl
             << endl;
        cout << "\t\t\t\t\t   Y for confirmation" << endl;
        cout << "\t\t\t\t\t   N for cancel" << endl;
        cout << "\t\t\t\t\t Enter 'y' for Yes or 'n' for No: ";
        SetConsoleTextAttribute(hConsole, 7);
    }
    ~Account()
    {
        cout << "Class Account Destructor." << endl;
        delete[] name;
        delete[] CNIC;
        delete[] phNo;
    }
};

class Checking_Account : virtual public Account
{
public:
    Checking_Account(char typ = '\0', const char na[] = "", double bal = 0, string pin = "", const char cnic[] = "", string eml = "", const char ph[] = "", string add = "")
        : Account(typ, na, bal, pin, cnic, eml, ph, add)
    {
        cout << "== Checking CONS ==\n";
        set_type('C');
        set_status('A');
        cout << "== Checking End ==\n\n";
    }
    ~Checking_Account()
    {
        cout << "Class Checking Account Destructor." << endl;
    }
};

class Savings_Account : virtual public Account
{
public:
    Savings_Account(char typ = '\0', const char na[] = "", double bal = 0, string pin = "", const char cnic[] = "", string eml = "", const char ph[] = "", string add = "")
        : Account(typ, na, bal, pin, cnic, eml, ph, add)
    {
        cout << "== Savings CONS ==\n";
        set_type('S');
        set_status('A');
        cout << "== Savings End ==\n\n";
    }
    ~Savings_Account()
    {
        cout << "Class Saving Account Destructor." << endl;
    }
};

class Business_Account : public Account
{
private:
    double loan;
public:
    Business_Account(char typ = '\0', const char na[] = "", double bal = 0, string pin = "", const char cnic[] = "", string eml = "", const char ph[] = "", string add = "")
        : Account(typ, na, bal, pin, cnic, eml, ph, add)
    {
        cout << "== Business CONS ==\n";
        set_type('B');
        set_status('A');
        cout << "== Business End ==\n\n";
    }
    ~Business_Account()
    {
        cout << "Class Business Account Destructor." << endl;
    }
};

class MMA_Account : public Checking_Account, public Savings_Account
{
    double fine;
    double min_bal;

public:
    MMA_Account(char typ = '\0', const char na[] = "", double bal = 0, string pin = "", const char cnic[] = "", string eml = "", const char ph[] = "", string add = "")
        : Account(typ, na, bal, pin, cnic, eml, ph, add)
    {
        cout << "== MMA CONS ==\n";
        set_type('M');
        set_status('A');
        cout << "== End ==\n\n";
    }
    ~MMA_Account()
    {
        cout << "Class MMA Account Destructor." << endl;
    }
};

class DataBase
{
protected:
    Account *ac;

    string pick; // picks while line from file
    bool found;  // to regulate while loop of file read

    int find_what;
    int find_acc;
    int picked_acc;
    char picked_type;

public:
    static int gen_accNo()
    {
        cout << "GEN ACC Func\n";
        string pick; // picks while line of file data
        int last_acc = 0, counter = 0;

        fstream obj;
        obj.open("Accounts.txt", ios::in);

        if (obj.is_open())
        {
            cout << "File is open\n";
        }

        else
        {
            cout << "File is not Open. Creating File\n";
            ofstream create;
            create.open("Accounts.txt");
        }

        while (getline(obj, pick))
        {
            counter++;
            istringstream iss(pick);
            iss >> last_acc;
        }
        obj.close();
        cout << "Last Acc: " << last_acc << endl;
        last_acc = (24228978) + (100077 * counter);
        cout << "Generrated Acc No: " << last_acc << endl;
        cout << "Numbr accounts: " << counter << endl;
        cout << "Gen acc end\n";
        return last_acc;
        obj.close();
    } // gen_accNo

    static string get_accountName(int &f)
    {
        cout << "we are in get name function" << endl;
        bool found = false;
        int picked_acc;
        string pick, temp, yeh_name;

        ifstream obj("Accounts.txt", ios ::in);

        while (!found && getline(obj, pick))
        {
            istringstream iss(pick);
            iss >> picked_acc >> temp;
            iss.ignore();
            getline(iss, yeh_name, '\t');

            if (f == picked_acc)
            {
                found = true;

                obj.close();
                return yeh_name;
            }

        } // while
        if (!found)
        {
            cout << "Account not found\n";
            return "";
        }
    } // func

    ~DataBase()
    {
        cout << "Class DateBase Destructor." << endl;
        delete ac;
    }
};

class DataBase_Write : public DataBase
{

public:
    void WriteAccount(Account *&A)
    {
        cout << "Write Account function me hoon\n";
        fstream obj("Accounts.txt", ios::app | ios::out);

        if (!obj.is_open())
        {
            cout << "File not open at write account, database write\n";
        }

        obj << A->get_account_number();
        obj << '\t';
        obj << A->get_type();
        obj << '\t';
        obj << A->get_name();
        obj << '\t';
        obj << A->get_balance();
        obj << '\t';
        obj << A->get_PIN();
        obj << '\t';
        obj << A->get_status();
        obj << '\t';
        obj << A->get_CNIC();
        obj << '\t';
        obj << A->get_email();
        obj << '\t';
        obj << A->get_phNo();
        obj << '\t';
        obj << A->get_address();
        obj << '\n';

        obj.close();
        cout << "Write account function khatam ho gya\n";
    }


    void UpdateAccount(Account *&A)
    {
        int acc_to_update = A->get_account_number(); //

        vector<string> data;
        string line;

        cout << "Update Account function me hoon\n";
        ifstream obj("Accounts.txt", ios::in);

        if (!obj.is_open())
        {
            cout << "File not open at write account, database write\n";
        }
        found = false;
        int count = 0;
        while (!found && getline(obj, pick))
        {
            count++;
            data.push_back(pick);
        }
      
    
        istringstream iss;

        ofstream write("Accounts.txt");
        for (int i = 0; i < count; i++)
        {

            iss.str(data[i]);
            iss >> picked_acc;
            if (picked_acc != acc_to_update)
            {
                write << data[i] << endl;
            }
            else
            {
                write << A->get_account_number();
                write << '\t';
                write << A->get_type();
                write << '\t';
                write << A->get_name();
                write << '\t';
                write << A->get_balance();
                write << '\t';
                write << A->get_PIN();
                write << '\t';
                write << A->get_status();
                write << '\t';
                write << A->get_CNIC();
                write << '\t';
                write << A->get_email();
                write << '\t';
                write << A->get_phNo();
                write << '\t';
                write << A->get_address();
                write << '\n';
            } // if

        } // for

        cout << "Data successfully updated \n";
    }

    ~DataBase_Write()
    {
        cout << "Class DataBase Write Destructor." << endl;
    }
};

class DataBase_Read : public DataBase
{

public:
    DataBase_Read()
    {
    }
    // to pick specific user data from file
    Account *ReadAccount(int &find, Account *&A) // accepts acc no to read data of
    {
        cout << "I am in ReadAcc\n";
        Account *p;
        p = A;

        find_acc = find;
        ifstream read;
        read.open("Accounts.txt", ios::in);

        if (!read.is_open())
        {
            cout << "File not open\n\n";
            return NULL;
        }
        else
        {
            cout << "File is open\n";

            found = false;
            while (!found && getline(read, pick))
            {
                istringstream iss(pick);
                iss >> picked_acc;

                if (picked_acc == find_acc)
                {
                    found = 1; // true
                }

            } //  while
            read.close();

            int acn;
            char typ, sts;
            double bal;
            string pin, eml, add;
            char na[20], cnic[14], phno[11];
            cout << "Data picked from file\n";
            istringstream iss(pick);
            string tempSts, nic;

            iss >> acn >> typ;
            iss.ignore();
            iss.getline(na, 20, '\t');
            iss >> bal >> pin >> tempSts >> nic;
            iss >> eml;
            iss.ignore();
            iss.getline(phno, 11, '\t');
            getline(iss, add);

            sts = tempSts[0];
            strcpy(cnic, nic.c_str());

            cout << "phno: " << phno << endl;

            cout << "Sending into acc obj\n";
            p->set_account_number(acn);
            cout << "Lmao XD\n";
            p->set_address(add);
            p->set_balance(bal);
            p->set_CNIC(cnic);
            p->set_email(eml);
            p->set_name(na);
            p->set_phNo(phno);
            p->set_PIN(pin);
            p->set_status(sts);

            cout << "Returning p\n";
            return p;
        } // if file was opened

        cout << "READ ACCOUNT END\n\n";
    } // read acc func

    char get_Account_Type(int &acc_tofind)
    {

        cout << "Im in get acc typ\n";
        found = false;
        picked_type = 'N';

        ifstream obj("Accounts.txt", ios ::in);

        while (!found && getline(obj, pick))
        {
            cout << pick << endl;
            istringstream iss(pick);
            iss >> picked_acc >> picked_type;
            if (picked_acc == acc_tofind)
            {
                found = true;
                cout << picked_acc << picked_type << endl;
                obj.close();
                return picked_type;
            }
        } // while
        if (picked_acc == 'N')
            cout << "Account Not found";
        return 'N';
    } // func
    ~DataBase_Read()
    {
        cout << "Class DataBase Read Destructor." << endl;
    }
};

Account::Account(char typ = '\0', const char na[] = "", double bal = 0, string pin = "", const char cnic[] = "", string eml = "", const char ph[] = "", string add = "")
{
    cout << "== ACCOUNT CONS ==\n";
    name = new char[20];
    CNIC = new char[13];
    phNo = new char[10];

    account_number = DataBase ::gen_accNo();
    type = 'C';
    strcpy(name, na);
    // name = na;
    balance = bal;
    PIN = pin;
    status = 'A';
    strcpy(CNIC, cnic);
    // CNIC = cnic;
    email = eml;
    strcpy(phNo, ph);
    // phNo = ph;
    address = add;
    cout << "== ACCOUNT End ==\n\n";
}

void Account ::change_Pin()
{
    string pin1, pin2, pinN;
    char c = 'n';
    do
    {
        cout << "Enter current 4-Digit PIN:";
        cin >> pinN;
        if (pinN.length() != 4 || pinN != this->get_PIN())
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Invalid!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
    } while (pinN.length() != 4 || pinN != this->get_PIN());

    do
    {
        cout << "Change Pin\n";
        cout << "\t\t\t\t\tEnter New 4-Digit PIN: ";
        cin >> pin1;
        cout << "\t\t\t\t\tEnter New 4-PIN again: ";
        cin >> pin2;

        if (pin1 != pin2)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t\t\t\tPINs don't match!\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if (pin1.length() != 4 || pin2.length() != 4)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t\t\t\tInvalid! PIN must be 4 Digit\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
    } while (pin1 != pin2 || pin1.length() != 4);

    cout << "\t\t\t\t\tNew PIN entered is: " << pin1 << endl;
    cout << "\t\t\t\t\tConfirm Change?(y/n) ";
    cin >> c;

    if (c == 'Y' || c == 'y')
    {
        this->set_PIN(pin1);
        cout << "New Pin set hua: " << this->get_PIN() << endl;

        DataBase_Write d;
        Account *t = this;
        d.UpdateAccount(t);
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\t\t\t\t\tPIN Changed Successfully\n";
        SetConsoleTextAttribute(hConsole, 7);
    }
    else
    {
        cout << "Cancelled\n";
    }

    return;
}

double Account ::Send_Money()
{
    double amount = 0;

    int r_acc;
    string r_name;
    do
    {
        cout << "\t\t\t\t\t Enter 8-Digit Account Number: ";
        cin >> r_acc;

        if (r_acc == account_number)
        {
            cout << "\t\t\t\t\t Invlid!\nCannot send money into YOUR OWN account\n";
        }
    } while (r_acc == account_number);

    r_name = (DataBase ::get_accountName(r_acc));

    if (r_name == "")
        cout << "\t\t\t\t\t Account Not Found\n";
    else
    {
        cout << "\t\t\t\t\t Name of Receiver is: " << r_name << endl;

        do
        {
            cout << "\t\t\t\t\t Enter Amount to Send: ";
            cin >> amount;
            if (amount <= 0 || amount > this->balance)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid Amount! Try Again\n";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                break;
            }

        } while (true);

        DataBase_Read d;
        char tt = d.get_Account_Type(r_acc);
        Account *p;

        if (tt == 'C')
        {
            p->AllocateDynamically<Checking_Account>(p);
        }
        else if (tt == 'S')
        {
            cout << "Case 2 chala\n";
            p->AllocateDynamically<Savings_Account>(p);
        }
        else if (tt == 'B')
        {
            p->AllocateDynamically<Business_Account>(p);
        }
        else if (tt == 'M')
        {
            p->AllocateDynamically<MMA_Account>(p);
        }


        *p = *(d.ReadAccount(r_acc, p));
        double temp = p->get_balance();
        p->set_balance(temp + amount);

        DataBase_Write b;
        b.UpdateAccount(p); // receiver

        // updating sender
        Account *t = this;
        int tempo = t->get_account_number();
        t->set_balance(t->get_balance() - amount);
        b.UpdateAccount(t);
        cout << "Updated sender too\n";

        cout << "Send money me return ho rha hai (receiver update) \n";

        delete p;
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 10);
                cout << "\t\t\t\t\tMoney Sent ............\n";
                SetConsoleTextAttribute(hConsole, 7);
        return 0;
    }
}

void Account :: block_acc (){

    cout << "Block Account func\n";

    this->set_status('B');
    Account *a = this;

    dbw = new DataBase_Write;
    dbw->UpdateAccount(a);

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\t\t\t\t\tAccount has been BLOCKED\n";
        SetConsoleTextAttribute(hConsole, 7);

    delete a;
}

void Account ::serve_user()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\t\t\t\t\t 1. Send Money" << endl;
    cout << "\t\t\t\t\t 2. Change Pin" << endl;
    cout << "\t\t\t\t\t 3. View Detils" << endl;
    cout << "\t\t\t\t\t 4. Exit" << endl;
    SetConsoleTextAttribute(hConsole, 7);

    string choice;
    int joice = 0;
    bool choi = false;
    cin.ignore();
    cout << "\t\t\t\t\tChoose: ";
    do
    {
        try
        {

            cin >> choice;
            if (choice.length() != 1 || (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7" && choice != "8"))
            {
                throw 404;
            }
            else{
                choi = true;
            }
            
        }
        catch (int)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t\t\t\t Invalid input.";
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\nPlease enter a valid option (1-4): ";
        }
    } while (!choi);

            // Convert the valid input to an integer
            istringstream op(choice);
            op >> joice;
            cout << "Enter kia: " << choice << endl << "joice is: " << joice+1 << endl;
    switch (joice)
    {
    case 1:
    {
        cout << "\t\t\t\t\t Send Money option selected" << endl;
        double amount;
        amount = Send_Money();
        break;
    }
    case 2:
    {
        cout << "\t\t\t\t\t Change pIN selected" << endl;
        change_Pin();
        break;
    }
    case 3:
    {
        cout << "\t\t\t\t\t View Information selected" << endl;
        this->Display();
        break;
    }
    case 4:
    {
        system("CLS");
        cout << "Exit Selected\n";
        cout << "\n\n\n\t\t\t\t\t\t GOODBYE :)\n";
        break;
    }
    default:
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\t\t\t\t\t Invalid joice" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        break;
    }
    }

} // serve user

class Start
{
private:
    int acc;
    string acc_in;
    DataBase_Write obj;
    char type; // current user acc type

public:
    Start() {}

    void screen()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 10);
        cout << "                          ===============================================================\n"
             << "                                 Welcome To Online Banking Management Sysytem\n"
             << "                          ===============================================================\n\n";
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\t\t\t\t\t 1. Current User\n"
             << "\t\t\t\t\t 2. Open new Account\n"
             << "\t\t\t\t\t 3. Exit\n\n"
             << "\t\t\t\t\t Enter Choice (1-3): ";
        string ch_01;
        do
        {
            try
            {
                cin >> ch_01;
                if (ch_01.length() != 1 || (ch_01 != "1" && ch_01 != "2" && ch_01 != "3"))
                {
                    throw 404;
                }
            }
            catch (int)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid Input." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "\t\t\t\t\t Enter Choice (1-3): ";
            }

        } while (ch_01 != "1" && ch_01 != "2" && ch_01 != "3");

        if (ch_01 == "1")
        {
            Current_Account();
        }
        else if (ch_01 == "2")
        {
            Open_Account();
        }
        else
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 14);
            cout << "\n\n\n\t\t\t\t\t GOODBYE :)\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
    }

    void Open_Account()
    {
        system("CLS");
        string select_type;
        Account *A;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Create Account\n";

        cout << "\t\t\t\t\t Select type of Account" << endl
             << "\t\t\t\t\t   1. Checking Account" << endl
             << "\t\t\t\t\t   2. Savings Account" << endl
             << "\t\t\t\t\t   3. Business Account" << endl
             << "\t\t\t\t\t   4. Money Market Account" << endl
             << endl;

        cout << "\t\t\t\t\t Enter Choice (1-4): ";
        SetConsoleTextAttribute(hConsole, 7);
        do
        {
            try
            {
                cin >> select_type;
                if (select_type.length() != 1 || (select_type != "1" && select_type != "2" && select_type != "3" && select_type != "4"))
                {
                    throw 404;
                }
            }
            catch (int)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid Input." << endl
                     << "\t\t\t\t\t Enter Choice (1-3): ";
                SetConsoleTextAttribute(hConsole, 7);
            }

        } while (select_type != "1" && select_type != "2" && select_type != "3" && select_type != "4");

        if (select_type == "1")
        {
            A->AllocateDynamically<Checking_Account>(A);
        }
        else if (select_type == "2")
        {
            cout << "Case 2 chala\n";
            A->AllocateDynamically<Savings_Account>(A);
        }
        else if (select_type == "3")
        {
            A->AllocateDynamically<Business_Account>(A);
        }
        else if (select_type == "4")
        {
            A->AllocateDynamically<MMA_Account>(A);
        }

        A->Input();
        char confirmation;

        system("CLS");
        cout << endl
             << endl
             << endl;
        A->User_Confirm_Disp();

        while (true)
        {
            cin >> confirmation;

            if (confirmation == 'Y' || confirmation == 'y')
            {
                cout << "\t\t\t\t\t Yes was selected\n";
                obj.WriteAccount(A);
                cout << "\t\t\t\t\t Account Created.............\n";
                break; // Exit the loop
            }
            else if (confirmation == 'n' || confirmation == 'N')
            {
                cout << "\t\t\t\t\t Cancelled\n";
                break; // Exit the loop
            }
            else
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t\t\t Invalid input. Please try again.\n";
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
        cout << "Open acc khatam hua\n";
        delete A;
    } // open acc

    void Current_Account()
    {
        Account *A;

        system("CLS");
        cout << "Current Account\n";
        DataBase_Read dr;
        char try_ = 'y';
        char try_again = 'y';
        do
        {
            do{
                cout << "\t\t\t\t\t Enter 8-digit Account Number: ";
                cin >> acc_in;
                if (acc_in.length()!=8){
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "\t\t\t\t\t Invalid Account Number" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            } while (acc_in.length()!=8);

            istringstream ik(acc_in);
            ik >> acc;

            type = dr.get_Account_Type(acc);
            if (type == 'N')
            {
                cout << "Account Not Found\nTry Again? ";
                cin >> try_;
            }
            else
            {
                cout << "Account Type of " << acc << " is "; // << type << endl;
                if (type == 'C')
                {
                    cout << "Checking" << endl;
                }
                else if (type == 'S')
                {
                    cout << "Saving" << endl;
                }
                else if (type == 'M')
                {
                    cout << "Money Market" << endl;
                }
                else if (type == 'B')
                {
                    cout << "Business" << endl;
                }
                try_ = 'n';
            }

        } while ((try_ != 'n' || try_ != 'n') && !cin.fail());

        if (type != 'N')
        {
            cout << "type of your acc is " << type << "\nNow allocating dynamically\n";
            switch (type)
            {
            case 'C':
            {
                A->AllocateDynamically<Checking_Account>(A);
                break;
            }
            case 'S':
            {
                A->AllocateDynamically<Savings_Account>(A);
                break;
            }
            case 'B':
            {
                A->AllocateDynamically<Business_Account>(A);
                break;
            }
            case 'M':
            {
                A->AllocateDynamically<MMA_Account>(A);
                break;
            }
            } // switch

            cout << "Putting readAcc wala return equal to yahan ya ptr\n";

            *A = *(dr.ReadAccount(acc, A)); // data utha lia into obj
            if (A->get_status() == 'B'){
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 14);
                cout << "\t\t\t\t\t Your Account has been BLOCKED\n"
                    << "\t\t\t\t\tContact Administration for further information\n";
                SetConsoleTextAttribute(hConsole, 7);
                return;
            }

            if (A->Login() == true)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 10);
                cout << "Login Success\n";
                SetConsoleTextAttribute(hConsole, 7);
                A->serve_user();
                return;
            }
            else
            {
                cout << "no beta no chori\n\n";
                return;
            }
            // A->Display();

        } // big if acc is present

    } // current acc
    ~Start()
    {
        cout << "Class Start Destructor." << endl;
    }
};

int main()
{

    Start S;
    S.screen();

    return 0;
}
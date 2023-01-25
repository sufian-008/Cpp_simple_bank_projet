#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
    public:

    string account_holder;
    string address;
    int age;
    int account_number;
    protected:
    int balance;
    private:
    string password;
    public:
    BankAccount(string account_holder,string account_number,int age,string password)
    {
        this->account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->account_number=rand()%100000000;
        this->balance=0;
        cout<<"Your account no is: "<<this->account_number<<endl;
    }
    int show_balance(string password){
        if(this->password==password){
            return this->balance;
        }else{
            return -1;
        }
    }
    void add_money(string password,int amount){
               if(this->password==password)

               {
                 this->balance +=amount;
                 cout<<"Add money successful"<<endl;
               }
               else{
                  cout<<"password didn't match"<<endl;
               }
    }

    void deposit_money(string password, int amount){
    if(this->password == password)
    {
        this->balance -= amount;
        cout<<"Deposite money successful"<<endl;
    }
    else{
        cout<<"Password didn't match"<<endl;
    }
}
     friend  class MyCash;
};


 

class MyCash 
{
   protected:
      int balance;
   public:
   MyCash()
   {
      this->balance=0;
   }
      void add_money_from_bank(BankAccount *myAccount, string password, int amount){
        if(myAccount->password == password){
            this->balance += amount;
            myAccount->balance -=amount;
            cout<<"Add money from bank is successful"<<endl;
        }
      }
};

BankAccount* create_account()
{
    string account_holder,password,address;
    int age;
    cout<<"FIRST CREATE ACCOUNT"<<endl;
    cout<<"Name: ";
    cin>>account_holder;
    cout<<"Adress: ";
    cin>>address;
    cout<<"Age: ";
    cin>>age;
    cout<<"Password: ";
    cin>>password;
 
    BankAccount *myAccount =new BankAccount(account_holder,address,age,password);
    return myAccount;
}

void add_money(BankAccount *myAccount){
      string password;
      int amount;
      cout<<"ADD MONEY"<<endl;
       cout<<"Give first Password then Number of Amount: ";
      cin>>password>>amount;
      myAccount->add_money(password,amount);
      cout<<"Your bank balance is "<<myAccount->show_balance("xyz")<<endl;
}

void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Deposite Money"<<endl;
     cout<<"Give first Password then Number of Amount: ";
    cin>>password>>amount;
    myAccount->add_money(password,amount);
    cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}
void add_money_from_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add  Money From Bank"<<endl;
    cout<<"Give first Password then Number of Amount: ";
    cin>>password>>amount;
  myCash->add_money_from_bank(myAccount,password,amount);
  cout<<"Your Bank balance is"<<myAccount->show_balance("xyz")<<endl;

}
int main()
{

   BankAccount *myAccount = create_account();
   MyCash *myCash =new MyCash();
   while(true)
   {
     cout<<"Select option: "<<endl;
     cout<<"1. Add Money to Bank "<<endl;
     cout<<"2. Deposit Money from Bank"<<endl;
     cout<<"3. Add Money to MyCash from Bank"<<endl;
     int option;
     cout<<"Please Select Your Option: ";
     cin>>option;
     if(option == 1)
     {
        add_money(myAccount);
     }
     else if(option ==2){
        deposit_money(myAccount);
     }
     else if(option== 3){
        add_money_from_bank(myCash,myAccount);
     }
     else{
        cout<<"Invalid option"<<endl;
     }
   }
      
    return 0;
}
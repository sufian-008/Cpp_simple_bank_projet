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
    cout<<"CREATE ACCOUNT"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *myAccount =new BankAccount(account_holder,address,age,password);
    return myAccount;
}

void add_money(BankAccount *myAccount){
      string password;
      int amount;
      cout<<"ADD MONEY"<<endl;
      cin>>password>>amount;
      myAccount->add_money(password,amount);
      cout<<"Your bank balance is "<<myAccount->show_balance("xyz")<<endl;
}

void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Deposite Money"<<endl;
    cin>>password>>amount;
    myAccount->add_money(password,amount);
    cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}
void add_money_from_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add  Money From Bank"<<endl;
    cin>>password>>amount;
  myCash->add_money_from_bank(myAccount,password,amount);
  cout<<"Your Bank balance is"<<myAccount->show_balance("xyz")<<endl;

}
int main()
{

    create_account();
      BankAccount *myAccount =create_account();
      add_money(myAccount);
       deposit_money(myAccount);
     MyCash *myCash = new MyCash();
     add_money_from_bank(myCash,myAccount);
      
    return 0;
}
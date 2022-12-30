#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;


class User{
protected :
    char *fname,*lname,*city,*state,*add,*pc;
    int DD,MM,YY;
    long long int i;
public :
    long double balance;
    User() {}
    User(char *f,char *l,char *ad,char *c,char *s,char *p,int D,int M,int Y,long long int a){
        fname=new char[strlen(f)+1];
        lname=new char[strlen(l)+1];
        city=new char[strlen(c)+1];
        state=new char[strlen(s)+1];
        add=new char[strlen(ad)+1];
        pc=new char[strlen(p)+1];
        strcpy(fname,f);
        strcpy(lname,l);
        strcpy(city,c);
        strcpy(state,s);
        strcpy(add,ad);
        strcpy(pc,p);
        DD=D;
        MM=M;
        YY=Y;
        i=a;
    }
};


class new_user:public User{
public :
    int ac = 0;
    char accType[30];
    new_user(char *F,char *L,char *AD,char *C,char *S,char *p,int Dd,int Mm,int Yy,long long int Aa):User(F,L,AD,C,S,p,Dd,Mm,Yy,Aa){
    }
    void account_no(){
        long double bbl;
        string USS;
        ifstream fo("accno.txt");
        int i = 0;
        while(fo>>ac){
            i = ac;
        }
        cout<<"\n\n\t\tSaving Data...\n";
        fo.close();
        ac = i+1;
        cout<<"\n\t\tYour Account No is :  "<<ac;
    }
    void show(){
        cout<<"\n\t\tAccount Type: "<<accType<<"\n";
        cout<<"\t\tAccount holder name : "<<fname<<" "<<lname;
        cout<<"\n\t\tMobile No : "<<i;
        cout<<"\n\t\tBirth Date is : "<<DD<<"-"<<MM<<"-"<<YY;
        cout<<"\n\t\tPancard No : "<<pc;
        cout<<"\n\t\tAddress : "<<add;
        cout<<"\n\t\tCity  :"<<city;
        cout<<"\n\t\tState : "<<state;
    }
    virtual void detail() {}
};

class sa:public new_user{
    string un;
public:
    sa(string UN,char *FN,char *LN,char *ADD,char *CY,char *ST,char *P,int DA,int MO,int YE,long long int AA):new_user(FN,LN,ADD,CY,ST,P,DA,MO,YE,AA){
        un=UN;
    }
    void detail(){
        strcpy(accType, "Saving");
        cout<<"\t\t----------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\tAccount Details\n";
        cout<<"\t\t----------------------------------------------------------------------------------------------";
        show();
        account_no();
    }
};

class ca:public new_user{
    string us;
public:
    ca(string Us,char *FN,char *LN,char *ADD,char *CY,char *ST,char *P,int DA,int MO,int YE,long long int AA):new_user(FN,LN,ADD,CY,ST,P,DA,MO,YE,AA){
        us=Us;
    }
    void detail(){
        strcpy(accType, "Current");
        cout<<"\t\t----------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\tAccount Details\n";
        cout<<"\t\t----------------------------------------------------------------------------------------------";
        show();
        account_no();
    }
};


class exi_user:public User{
    long double balance = 0;
public :
    double j;
    int ZZ;
    char acTy[30];
    exi_user(char* acT,double B,double b,char *f,char *l,char *AD,char *C,char *S,char *pc,int D,int M,int Y,long long int a):User(f,l,AD,C,S,pc,D,M,Y,a){
        j=b;
        balance=B;
        strcpy(acTy, acT);
    }
    void details(long double BB){
        balance=BB;
        cout<<"\t\t----------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\tAccount Details\n";
        cout<<"\t\t----------------------------------------------------------------------------------------------";
        cout<<"\n\t\tAccount Type : "<<acTy;
        cout<<"\n\t\tAccount Holder Name : "<<fname<<" "<<lname;
        cout<<"\n\t\tAccount No: "<<j;
        cout<<"\n\t\tBirth Date is : "<<DD<<"-"<<MM<<"-"<<YY;
        cout<<"\n\t\tMobile No : "<<i;
        cout<<"\n\t\tPancard No : "<<pc;
        cout<<"\n\t\tAddress : "<<add;
        cout<<"\n\t\tCity  : "<<city;
        cout<<"\n\t\tState : "<<state;
        cout<<"\n\t\tYour current Balance is : "<<balance<<"\n";
        cout<<"\t\t----------------------------------------------------------------------------------------------\n";
    }
    int check(long double amtt){
        if(balance==amtt){
            ZZ=1;
            return ZZ;
        }
        else{
            ZZ=0;
            return ZZ;
        }
    }
};


class transaction{
    long double amt;
    User *u1;
public:
    transaction(long double AMT,User *U){
        amt=AMT;
        u1=U;
    }
    void withdraw(long double amt){
        u1->balance=u1->balance-amt;
        cout<<"\t\t$$$$$ Transaction Done! $$$$$";
        cout<<"\n\t\tUpdated Balance is : "<<u1->balance;
        cout<<"\n\t\t-----------------------------------------------------\n";
    }
    void deposite(long double amt){
        u1->balance=u1->balance+amt;
        cout<<"\t\t$$$$$ Transaction Done! $$$$$";
        cout<<"\n\t\tUpdated Balance is : "<<u1->balance;
        cout<<"\n\t\t-----------------------------------------------------\n";
    }
};


void put(char* acT, char *First,char *Last,long long int Mo,int DD,int MM,int YY,char *Pan,char *ADD,char *City,char *State,long double Balance,string UName,double Acc){
    fstream myfile;
    myfile.open("data.txt",ios_base::app);
    myfile<<acT<<" ";
    myfile<<First<<" ";
    myfile<<Last<<" ";
    myfile<<Mo<<" ";
    myfile<<DD<<" ";
    myfile<<MM<<" ";
    myfile<<YY<<" ";
    myfile<<Pan<<" ";
    myfile<<ADD<<" ";
    myfile<<City<<" ";
    myfile<<State<<" ";
    myfile<<Balance<<" ";
    myfile<<UName<<" ";
    myfile<<Acc<<"\n";
    myfile.close();
    fstream accfile;
    accfile.open("accno.txt", ios::app);
    accfile<<Acc<<"\n";
    accfile.close();
}


void uipa(string USER,string PASS){
    fstream uids;
    uids.open("uid.txt",ios_base::app);
    uids<<USER<<"\n";
    uids.close();
    fstream pass;
    pass.open("pass.txt",ios_base::app);
    pass<<USER<<" "<<PASS<<"\n";
    pass.close();
}



int main(){
    system("cls");
    int choice;
    cout<<"\t\t----------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\tWelcome to Our Online Bank\n";
    cout<<"\t\t----------------------------------------------------------------------------------------------\n";
    do{
        cout<<"\t\t----------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\tMain Menu\n";
        cout<<"\t\t----------------------------------------------------------------------------------------------\n";
        cout<<"\n\t\t1-For New User";
        cout<<"\n\t\t2-For Existing User";
        cout<<"\n\t\tEnter your Choice: ";
        cin>>choice;
        cout<<"\t\t----------------------------------------------------------------------------------------------\n";
        if(choice==1){
            while(1){
                int l;
                cout<<"\t\t----------------------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\tWhich type of Account do you want to Create ?\n";
                cout<<"\t\t----------------------------------------------------------------------------------------------\n";
                cout<<"\n\t\tEnter 1 for Saving Account";
                cout<<"\n\t\tEnter 2 for Current Account";
                cout<<"\n\t\tEnter your Choice: ";
                cin>>l;
                int dd,mm,yy;
                long long int x;
                long double amount;
                char acT[30],z[30],i[30],p[30],Addr[30],City[10],State[10];
                string uname,pas;
                if(l==1){
                    strcpy(acT, "Saving");
                    cout<<"\n\t\t----------------------------------------------------------------------------------------------";
                    cout<<"\n\t\t\t\t\t\t\tEnter Details\n";
                    cout<<"\t\t----------------------------------------------------------------------------------------------\n\n";
                    cout<<"\t\tEnter your Mobile No : ";
                    cin>>x;
                    cout<<"\t\tEnter your First Name : ";
                    cin>>z;
                    cout<<"\t\tEnter your Last Name : ";
                    cin>>i;
                    cout<<"\t\tEnter your Birth Date :";
                    cin>>dd;
                    cin>>mm;
                    cin>>yy;
                    cout<<"\t\tEnter your Pancard no : ";
                    cin>>p;
                    cout<<"\t\tEnter your Address : ";
                    cin>>Addr;
                    cout<<"\t\tEnter your City Name : ";
                    cin>>City;
                    cout<<"\t\tEnter your State Name : ";
                    cin>>State;
                    cout<<"\t\tSet a New User Name : ";
                    cin>>uname;
                    cout<<"\t\tSet a Password : ";
                    cin>>pas;
                    cout<<"\t\t----------------------------------------------------------------------------------------------\n\n";
                    User U1;
                    U1.balance=0;
                    new_user *c1;
                    sa s1(uname,z,i,Addr,City,State,p,dd,mm,yy,x);
                    c1=&s1;
                    c1->detail();
                    while(1){
                        cout<<"\n\n\t\tYou Need to Deposit minimum Rs. 500 in order to Create Account.";
                        cout<<"\n\n\t\tEnter amount to be Deposit : ";
                        cin>>amount;
                        if(amount<500){
                            cout<<"\n\t\tInsufficient Amount!! (Please Enter amount more than Rs. 500)";
                        }
                        else{
                            transaction t1(amount,&U1);
                            t1.deposite(amount);
                            break;
                        }
                    }
                    string y;
                    cout<<"\n\t\tDo u want to make another Transaction?"<<"\n\t\tType Yes to continue with Transaction: ";
                    cin>>y;
                    cout<<"\n\t\t-----------------------------------------------------\n";
                    if(y=="Yes"){
                        while(1){
                            int Choice;
                            transaction t1(amount,&U1);
                            cout<<"\n\t\t-----Select Option-----";
                            cout<<"\n\t\t1-Withdraw Money";
                            cout<<"\n\t\t2-Deposit Money";
                            cout<<"\n\t\tEnter your choice : ";
                            cin>>Choice;
                            if(Choice==1){
                                cout<<"\n\t\t-----------------------------------------------------\n";
                                cout<<"\t\tEnter Amount you want to Withdraw: ";
                                cin>>amount;
                                if((U1.balance-amount)<500){
                                    cout<<"\t\tMinimum Balance of 500 Rs. Required in Account!!";
                                }
                                else
                                    t1.withdraw(amount);
                                cout<<"\n\t\tYour Account Balance :"<<U1.balance;
                                cout<<"\n\t\t-----------------------------------------------------\n";
                            }
                            else{
                                cout<<"\n\t\t-----------------------------------------------------\n";
                                cout<<"\t\tEnter Amount to be Deposit : ";
                                cin>>amount;
                                t1.deposite(amount);
                                cout<<"\n\t\tYour Account Balance :"<<U1.balance;
                                cout<<"\n\t\t-----------------------------------------------------\n";
                            }
                            string y;
                            cout<<"\n\t\tDo u want to make Another Transaction?"<<"\n\t\tType Yes to continue with Transaction: ";
                            cin>>y;
                            cout<<"\n\t\t-----------------------------------------------------\n";
                            if(y!="Yes"){
                                put(acT,z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                                uipa(uname,pas);
                                exit(0);
                            }
                        }
                    }
                    else{
                        put(acT,z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                        uipa(uname,pas);
                        exit(0);
                    }
                    break;
                }
                if(l==2){
                    strcpy(acT, "Current");
                    cout<<"\n\t\t----------------------------------------------------------------------------------------------";
                    cout<<"\n\t\t\t\t\t\t\tEnter Details\n";
                    cout<<"\t\t----------------------------------------------------------------------------------------------\n\n";
                    cout<<"\t\tEnter your Mobile No : ";
                    cin>>x;
                    cout<<"\t\tEnter your First Name : ";
                    cin>>z;
                    cout<<"\t\tEnter your Last Name : ";
                    cin>>i;
                    cout<<"\t\tEnter your Birth Date :";
                    cin>>dd;
                    cin>>mm;
                    cin>>yy;
                    cout<<"\t\tEnter your Pancard no : ";
                    cin>>p;
                    cout<<"\t\tEnter your Address : ";
                    cin>>Addr;
                    cout<<"\t\tEnter your City Name : ";
                    cin>>City;
                    cout<<"\t\tEnter your State Name : ";
                    cin>>State;
                    cout<<"\t\tSet a New User Name : ";
                    cin>>uname;
                    cout<<"\t\tSet a password : ";
                    cin>>pas;
                    cout<<"\t\t----------------------------------------------------------------------------------------------\n\n";
                    User U1;
                    U1.balance=0;
                    new_user *c1;
                    ca s1(uname,z,i,Addr,City,State,p,dd,mm,yy,x);
                    c1=&s1;
                    c1->detail();
                    while(1){
                        cout<<"\n\n\t\tYou Need Deposit a minimum Rs. 5000 in order to Creating Account.";
                        cout<<"\n\n\t\tEnter Amount you want to Deposit: ";
                        cin>>amount;
                        if(amount<5000){
                            cout<<"\t\tInsufficient amount!! Please Enter Amount more than Rs.5000";
                        }
                        else{
                            transaction t1(amount,&U1);
                            t1.deposite(amount);
                            break;
                        }
                    }
                    string y;
                    cout<<"\n\t\tDo u want to make Another Transaction ?"<<"\n\t\tType Yes to continue with Transaction: ";
                    cin>>y;
                    cout<<"\n\t\t-----------------------------------------------------\n";
                    if(y=="Yes"){
                        while(1){
                            int Choice;
                            transaction t1(amount,&U1);
                            cout<<"\n\t\t-----Select Option-----";
                            cout<<"\n\t\t1-Withdraw Money";
                            cout<<"\n\t\t2-Deposit Money";
                            cout<<"\n\t\tEnter your choice : ";
                            cin>>Choice;
                            if(Choice==1){
                                cout<<"\n\t\t-----------------------------------------------------\n";
                                cout<<"\t\tEnter Amount to be Withdraw : ";
                                cin>>amount;
                                if(5000>(U1.balance-amount)){
                                    cout<<"\t\tMinimum Balance of 5000 Rs. Required for Account!!";
                                }
                                else
                                    t1.withdraw(amount);
                                cout<<"\n\t\tYour Account Balance :"<<U1.balance;
                                cout<<"\n\t\t-----------------------------------------------------\n";
                            }
                            else{
                                cout<<"\n\t\t-----------------------------------------------------\n";
                                cout<<"\t\tEnter Amount to be Deposit : ";
                                cin>>amount;
                                t1.deposite(amount);
                                cout<<"\n\t\tYour Account Balance :"<<U1.balance;
                                cout<<"\n\t\t-----------------------------------------------------\n";
                            }
                            string y;
                            cout<<"\n\t\tDo u want to make another Transaction ?"<<"\n\t\tType Yes to continue with Transaction: ";;
                            cin>>y;
                            cout<<"\n\t\t-----------------------------------------------------\n";
                            if(y!="Yes"){
                                put(acT,z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                                uipa(uname,pas);
                                exit(0);
                            }
                        }
                    }
                    else{
                        put(acT,z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                        uipa(uname,pas);
                        exit(0);
                    }
                }
                else
                    cout<<"\t\tInvalid Choice!\n";
            }
        }
        if(choice==2){
            int k;
            char acT[30],z[30],i[30],p[30],Addr[30],City[10],State[10];
            long double Amount,Bal,Bil;
            long long int mo;
            double dd,mm,yy;
            string user,uid,UI,pass;
            fstream file;
            int I,j=0;
            while(j<3){
                file.open("uid.txt");
                cout<<"\t\tEnter your User Name: ";
                cin>>uid;
                while(!file.eof()){
                    file>>user;
                    if(uid==user){
                        I=1;
                        k=1;
                        break;
                    }
                }
                file.close();
                if(I==1)
                    break;
                else{
                    cout<<"\t\tInvalid User Name\n";
                    if(j==1)
                        cout<<"\t\tLast Chance\n";
                    if(j==2)
                        exit(0);
                }
                j++;
            }
            int J,Pa=0;
            string usid,pas;
            while(Pa<3){
                cout<<"\t\tEnter Password : ";
                cin>>pass;
                file.open("pass.txt");
                while(!file.eof()){
                    file>>usid>>pas;
                    if(usid==user && pas==pass){
                        J=1;
                        break;
                    }
                    else
                        J=2;
                }
                if(J==1){
                    break;
                }
                else{
                    if(Pa==1||Pa==0)
                        cout<<"\n\t\t### Access Denied! ###\n\n";
                    else{
                        exit(0);
                    }
                }
                Pa++;
                file.close();
            }
            while(1){
                int Choice;
                double AC;
                User U1;
                fstream file;
                file.open("data.txt");
                while(!file.eof()){
                    file>>acT>>z>>i>>mo>>dd>>mm>>yy>>p>>Addr>>City>>State>>Bal>>UI>>AC;
                    if(UI==uid){
                        k=1;
                        break;
                    }
                }
                file.close();
                if(k==1){
                    system("cls");
                    cout<<"\n\t\t$$$ Access Granted! $$$\n";
                }
                else{
                    cout<<"\t\tNo such Account Exist try changing Credentials.";
                    exit(0);
                }
                file.close();
                exi_user e1(acT,Bal,AC,z,i,Addr,City,State,p,dd,mm,yy,mo);
                U1.balance=Bal;
                Bil=Bal;
                transaction t1(Amount,&U1);
                while(1){
                    cout<<"\n\t\t-----Select Option-----\n";
                    cout<<"\n\t\t1-Account_Info";
                    cout<<"\n\t\t2-Withdraw Money";
                    cout<<"\n\t\t3-Deposit Money";
                    cout<<"\n\t\t4-Exit";
                    cout<<"\n\t\tEnter your choice : ";
                    cin>>Choice;
                    fstream Fol;
                    fstream newFol;
                    switch(Choice){
                    case 1 :
                        e1.details(U1.balance);
                        break;
                    case 2 : {
                        cout<<"\t\t-----------------------------------------------------\n";
                        cout<<"\t\tEnter Amount to be Withdraw : ";
                        cin>>Amount;
                        if(500>(U1.balance-Amount) && !strcmp(acT, "Saving")){
                            cout<<"\t\tMinimum Balance of 500 Rs. Required for Account!!\n";
                            cout<<"\t\t-----------------------------------------------------\n";
                        }
                        else if(5000>(U1.balance-Amount) && !strcmp(acT, "Current")){
                            cout<<"\t\tMinimum Balance of 5000 Rs. Required for Account!!\n";
                            cout<<"\t\t-----------------------------------------------------\n";
                        }
                        else
                            t1.withdraw(Amount);
                        Bil=U1.balance;
                        Fol.open("data.txt");
                        newFol.open("newData.txt", ios::app);
                        while(!Fol.eof()){
                            string aT, fname, lname, pan, add, city, state, newUI;
                            double d,m,y,bal,ac;
                            long long int mb;
                            Fol>>aT>>fname>>lname>>mb>>d>>m>>y>>pan>>add>>city>>state>>bal>>newUI>>ac;
                            if(uid == newUI){
                                newFol<<aT<<" ";
                                newFol<<fname<<" ";
                                newFol<<lname<<" ";
                                newFol<<mb<<" ";
                                newFol<<d<<" ";
                                newFol<<m<<" ";
                                newFol<<y<<" ";
                                newFol<<pan<<" ";
                                newFol<<add<<" ";
                                newFol<<city<<" ";
                                newFol<<state<<" ";
                                newFol<<Bil<<" ";
                                newFol<<newUI<<" ";
                                newFol<<ac<<"\n";
                                continue;
                            }
                            newFol<<aT<<" ";
                            newFol<<fname<<" ";
                            newFol<<lname<<" ";
                            newFol<<mb<<" ";
                            newFol<<d<<" ";
                            newFol<<m<<" ";
                            newFol<<y<<" ";
                            newFol<<pan<<" ";
                            newFol<<add<<" ";
                            newFol<<city<<" ";
                            newFol<<state<<" ";
                            newFol<<bal<<" ";
                            newFol<<newUI<<" ";
                            newFol<<ac<<"\n";
                        }
                        Fol.close();
                        newFol.close();
                        string line; 
                        vector<string> lines;
                        ifstream inputStream("newData.txt");

                        while (getline(inputStream,line)){
                            lines.push_back(line);
                        }
                        inputStream.close();

                        fstream outputStream("newData.txt", ios::out | ios::trunc);
                        if (outputStream.is_open()){
                            for (int i=0; i < lines.size()-1; i++){
                                outputStream << lines[i] << "\n";
                            }
                            outputStream.close();
                        }
                        remove("data.txt");
                        rename("newData.txt", "data.txt");
                        break;
                    }
                    case 3 : {
                        cout<<"\t\t-----------------------------------------------------\n";
                        cout<<"\t\tEnter Amount to be Deposit : ";
                        cin>>Amount;
                        t1.deposite(Amount);
                        Bil=U1.balance;
                        Fol.open("data.txt");
                        newFol.open("newData.txt", ios::app);
                        while(!Fol.eof()){
                            string aT, fname, lname, pan, add, city, state, newUI;
                            double d,m,y,bal,ac;
                            long long int mb;
                            Fol>>aT>>fname>>lname>>mb>>d>>m>>y>>pan>>add>>city>>state>>bal>>newUI>>ac;
                            if(uid == newUI){
                                newFol<<aT<<" ";
                                newFol<<fname<<" ";
                                newFol<<lname<<" ";
                                newFol<<mb<<" ";
                                newFol<<d<<" ";
                                newFol<<m<<" ";
                                newFol<<y<<" ";
                                newFol<<pan<<" ";
                                newFol<<add<<" ";
                                newFol<<city<<" ";
                                newFol<<state<<" ";
                                newFol<<Bil<<" ";
                                newFol<<newUI<<" ";
                                newFol<<ac<<"\n";
                                continue;
                            }
                            newFol<<aT<<" ";
                            newFol<<fname<<" ";
                            newFol<<lname<<" ";
                            newFol<<mb<<" ";
                            newFol<<d<<" ";
                            newFol<<m<<" ";
                            newFol<<y<<" ";
                            newFol<<pan<<" ";
                            newFol<<add<<" ";
                            newFol<<city<<" ";
                            newFol<<state<<" ";
                            newFol<<bal<<" ";
                            newFol<<newUI<<" ";
                            newFol<<ac<<"\n";
                        }
                        Fol.close();
                        newFol.close();
                        string line; 
                        vector<string> lines;
                        ifstream inputStream("newData.txt");

                        while (getline(inputStream,line)){
                            lines.push_back(line);
                        }
                        inputStream.close();

                        fstream outputStream("newData.txt", ios::out | ios::trunc);
                        if (outputStream.is_open()){
                            for (int i=0; i < lines.size()-1; i++){
                                outputStream << lines[i] << "\n";
                            }
                            outputStream.close();
                        }
                        remove("data.txt");
                        rename("newData.txt", "data.txt");
                        break;
                    }
                    case 4 :
                        cout<<"\t\tFinal Balance: "<<Bil<<"\n";
                        cout<<"\t\t----------------------------------------------------------------------------------------------";
                        cout<<"\n\t\t\t\t\t\tThank You for Banking with Us\n";
                        cout<<"\t\t----------------------------------------------------------------------------------------------\n";
                        exit(0);
                    default :
                        cout<<"\t\tInvalid Choice";
                    }
                }
            }
        }
        else
            cout<<"\t\tInvalid Choice!!";
    }
    while(1);

    return 0;
}

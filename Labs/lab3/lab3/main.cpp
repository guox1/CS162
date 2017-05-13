
#include"Header.h"

int main(){
    int days,surgery,pharmacy;
    fstream output;
    output.open("hospital.txt", ios::app);
    char* a;
    int choose=1;
    a =  new char[20];
    Patient Patient1, Patient2(0,NULL,0);
    Surgery Surgery1;
    Pharmacy Pharmacy2;
    cout <<"What's your name? ";
    cin >> a;
    Patient2.set_name(a);
    output<<Patient2.get_name()<<"|surg|";
    cout <<"How many days you are going to living in ";
    cin >> days;
    cout <<"Your daily charges would be: "<<Patient2.get_daily_charges()<<endl;
    Patient2.set_days(days);
    for(int i=0;i<5;i++){
        cout<<i+1<<". "<<Surgery1.str_at(i)<<" $"<<Surgery1.at(i)<<endl;
    }
    cout<<"which surgery you take? ";
    cin>>surgery;
    //Surgery1.update_Patient(surgery);
    Patient2.set_charges(Surgery1.at(surgery-1));
    output<<Surgery1.str_at(surgery-1)<<"|"<<Surgery1.at(surgery-1)<<"|Pharm|";
    while(choose == 1){
        for(int i=0;i<5;i++){
            cout<<i+1<<". "<<Pharmacy2.str_at(i)<<" $"<<Pharmacy2.at(i)<<endl;
        }
        cout<<"which medication you use(only enter one) ";
        cin >> pharmacy;
        //Pharmacy2.update_Patient(pharmacy);
        Patient2.set_charges(Pharmacy2.at(pharmacy-1));
        output<<Pharmacy2.str_at(pharmacy-1)<<"|"<<Pharmacy2.at(pharmacy-1)<<"|";
        cout<<"Do you need another medication?(1 - yes, 0 - no) ";
        cin >> choose;
    }
    cout <<"Your total would be: "<<Patient2.get_charges()<<endl;
    output<<Patient2.get_days()<<endl;
    output.close();
    return 0;
}
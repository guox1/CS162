#include"Header.h"

Pharmacy::Pharmacy(){
    charges = new int[5];
    type = new string[5];
    charges[0] = 300;
    charges[1] = 100;
    charges[2] = 150;
    charges[3] = 200;
    charges[4] = 250;
    type[0] = "Asprin";
    type[1] = "Novocaine";
    type[2] = "Painkiller";
    type[3] = "Amoxicillin";
    type[4] = "Cocaine";
}

int Pharmacy::at(int a){
    return charges[a];
}

string Pharmacy::str_at(int a){
    return type[a];
}

void Pharmacy::update_Patient(int a){
    Newcharge = charges[a + 1];
    Patient().set_charges(Newcharge);//就改改这个 怎么pass by pointer
}

Pharmacy::~Pharmacy(){
    delete [] charges;
    charges = NULL;
    delete [] type;
    type = NULL;
}
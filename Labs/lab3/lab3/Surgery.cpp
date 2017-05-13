
#include"Header.h"

Surgery::Surgery(){
    charges = new int[5];
    type = new string[5];
    charges[0] = 100;
    charges[1] = 200;
    charges[2] = 250;
    charges[3] = 50;
    charges[4] = 120;
    type[0] = "Arm biopsy";
    type[1] = "Arm lift";
    type[2] = "Ear tube replacement";
    type[3] = "Enterolysis";
    type[4] = "Lip lift";
    
}

int Surgery::at(int a){
    return charges[a];
}

string Surgery::str_at(int a){
    return type[a];
}

void Surgery::update_Patient(int a){
    Newcharge = charges[a + 1];
    Patient().set_charges(Newcharge);//就改改这个 怎么pass by pointer
}

Surgery::~Surgery(){
    delete [] charges;
    charges = NULL;
    delete [] type;
    type = NULL;
}

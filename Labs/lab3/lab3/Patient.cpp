
#include"Header.h"

Patient::Patient(){
    name = NULL;
    total_charges = 0;
    daily_charges = 100;
    days = 0;
}

Patient::Patient(int gcharges, char * gname, int gdays){
    total_charges = gcharges;
    name = gname;
    daily_charges = 100;
    days = gdays;
}

Patient::~Patient(){
    delete [] name;
    name = NULL;
}

double Patient::get_charges(){
    total_charges = total_charges+days*daily_charges;
    return total_charges;
}

void Patient::set_charges(int Newcharges){
    total_charges = total_charges + Newcharges;
}

int Patient::get_days(){
    return days;
}

void Patient::set_days(int Newdays){
    days = Newdays;
}

char* Patient::get_name(){
    return name;
}

void Patient::set_name(char* Newname){
    name = Newname;
}

int Patient::get_daily_charges(){
    return daily_charges;
}

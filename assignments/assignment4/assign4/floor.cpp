#include "floor.h"
#include <iostream>
#include <fstream>
using namespace std;
Floor::Floor()
{

}

Floor::~Floor()
{

}

void Floor::print_floor()
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.at(i).size();j++)
        {
            cout<<v.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
}

void Floor::setup_floor(string filename,int startingrow,int startingcol)
{
    this->obj_col = startingcol;
    this->obj_row = startingrow;
    std::ifstream f;
    f.open(filename.c_str(),std::ifstream::in);
    if(f.fail())
    {
        cout<<"can't find file "+filename+ " !"<<endl;
    }

    string line;
    int index=0;
    while(getline(f,line))
    {
        int count = 0;
        vector<char> vchar;
        for(int i=0;i<line.size();i++)
        {
            if(line[i]==' ')
                continue;
            if(line[i]=='f')
            {
                vchar.push_back('f');
                count++;
            }
            if(line[i]=='o')
            {
                vchar.push_back('o');
                count++;
            }
        }
        v.push_back(vchar);
        vchar.clear();
        index++;
    }
    //this->print_floor();
    cout<<"beginning:"<<endl;
    v[startingrow][startingcol] = 'r';
    this->print_floor();
}

 bool Floor::is_obj_out(int row,int col)
 {
     if(col<0||row<0)
     {
         return false;
     }
     if(row>=v.size())
         return false;
     if(col>=v.at(row).size())
         return false;
     return true;
 }

 void Floor::set_obj_row(int row)
 {
     this->obj_row = row;
 }
 void Floor::set_obj_col(int col)
 {
     this->obj_col = col;
 }

 int Floor::get_obj_row()
 {
     return this->obj_row;
 }
 int Floor::get_obj_col()
 {
     return this->obj_col;
 }

 std::vector<std::vector<char> > Floor::get_v()
 {
     return this->v;
 }

 void Floor::set_vector_char(int row,int col,char c)
 {
     v[row][col] = c;
 }

 char Floor::get_vector_char(int row,int col)
 {
     return v[row][col];
 }

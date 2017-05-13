#ifndef FLOOR_H
#define FLOOR_H
#include <vector>
#include <string>
using namespace std;
class Floor
{
private:
    std::vector<std::vector<char> > v;
    int obj_row; 
    int obj_col; 
public:
    Floor();
    ~Floor();
    void print_floor();
    void setup_floor(string filename,int startingrow,int startingcol);
    bool is_obj_out(int row,int col);
    void set_obj_row(int row);
    void set_obj_col(int col);
    int get_obj_row();
    int get_obj_col();

    std::vector<std::vector<char> >  get_v();
    char get_vector_char(int row,int col);
    void set_vector_char(int row,int col,char c);

};

#endif // FLOOR_H

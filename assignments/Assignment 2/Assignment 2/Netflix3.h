
#ifndef __lab10__Netflix__
#define __lab10__Netflix__

#include"Header.h"

class Netflix{

public:
    Netflix();
    Netflix(int);
    ~Netflix();
    void set_movie(class movie*);
    void set_movie_at(class movie, int);
    class movie* get_movie();
    class movie get_movie_at(int);
    int get_num();
    
private:
    movie *movie;
    int num_movie;
    
};


#endif

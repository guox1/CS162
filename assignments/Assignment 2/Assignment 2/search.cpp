
#include"Header.h"
#include"Netflix.h"

int find_line(){
    int line, x1 = 0, checkline = 0, x2 = 0;
    stringstream a1;
    string a2;
    ifstream check("/Users/Hao/Desktop/project/lab10/lab10/Netflix.dat");
    if (check.is_open() && (x1 == 0)){
        check.seekg(-1,ios_base::end);
        while(true) {
            char hehe = check.get();
            if(check.tellg() <= 1){
                if(x2 == 1){
                    x1 = 2;
                    break;
                }
                x1 = 1;
                checkline = 1;
                break;
            }
            else if (hehe == '\n')
                break;
            else{
                check.seekg(-2,ios_base::cur);
                x2 = 1;
            }
        }
        if (x1 == 0){
            char haha = check.get();
            a1 << haha;
            a1 >> a2;
            line = stoi (a2);
            line ++;
        }
        else if (x1 == 1)
            line = 1;
        else
            line = 2;
        check.close();
    }
    else
        cout << "Can't find flie.";
    return line-1;
}

void output_to_file1(int num_line, char* name, char* c){
    ofstream output;
    output.open("/Users/Hao/Desktop/project/lab10/lab10/Netflix2.dat",ios::app);
    if(num_line==1)
        output<<num_line<<"|"<<name<<c;
    else
        output<<endl<<num_line<<"|"<<name<<c;
    output.close();
}

void output_to_file2(movie* movie1, int line, int checkline){
    int num = line;
    ofstream output;
    output.open("/Users/Hao/Desktop/project/lab10/lab10/Netflix2.dat", ios::app);
    if (checkline == 1){
        if (line != checkline){
            output << endl <<num<<"|"<<movie1->get_name()<<"|"<<movie1->get_stars()<<"|"<<movie1->get_num_cast()<<"|";
        }
        else
            output <<num<<"|"<<movie1->get_name()<<"|"<<movie1->get_stars()<<"|"<<movie1->get_num_cast()<<"|";
    }
    else
        output << endl <<num<<"|"<<movie1->get_name()<<"|"<<movie1->get_stars()<<"|"<<movie1->get_num_cast()<<"|";
    num ++;
    for(int i=0;i<movie1->get_num_cast();i++){
        output<<movie1->get_cast()[i]<<"|";
    }
    output<<movie1->get_rating()<<"|"<<movie1->get_copies()<<"|"<<movie1->get_rented();
    output.close();
}

void save_it(Netflix* n){
    int line, x1 = 0, checkline = 0, x2 = 0;
    stringstream a1;
    string a2;
    ifstream check("/Users/Hao/Desktop/project/lab10/lab10/Netflix2.dat");
    if (check.is_open() && (x1 == 0)){
        check.seekg(-1,ios_base::end);
        while(true) {
            char hehe = check.get();
            if(check.tellg() <= 1){
                if(x2 == 1){
                    x1 = 2;
                    break;
                }
                x1 = 1;
                checkline = 1;
                break;
            }
            else if (hehe == '\n')
                break;
            else{
                check.seekg(-2,ios_base::cur);
                x2 = 1;
            }
        }
        if (x1 == 0){
            char haha = check.get();
            a1 << haha;
            a1 >> a2;
            line = stoi (a2);
            line ++;
        }
        else if (x1 == 1)
            line = 1;
        else
            line = 2;
        check.close();
    }
    else
        cout << "Can't find flie.";
    for(int i=0;i<n->get_num();i++){
        output_to_file2(&n->get_movie()[i], line+i, checkline);
    }

}

void print_information(class Netflix* n){
    movie* m;
    int num_movie,a,rented;
    num_movie = n->get_num();
    cout<<"We found "<<num_movie<<" movies."<<endl;
    m = n->get_movie();
    for(int i=0;i<num_movie;i++){
        cout<<"movie #"<<i+1<<endl;
        cout<<"Title: "<<m[i].get_name()<<endl<<"Stars: "<<m[i].get_stars()<<endl<<"Cast members: ";
        for(int x=0;x<m[i].get_num_cast();x++){
            if(x+1!=m[i].get_num_cast())
                cout<<m[i].get_cast()[x]<<", ";
            else{
                cout<<m[i].get_cast()[x]<<endl;
            }
        }
        cout<<"Rating: "<<m[i].get_rating()<<endl<<"Current copies to rent: "<<m[i].get_copies()<<endl;
    }
    if(num_movie!=0){
        cout<<"Which one do you want to rent: ";
        cin>>a;
        rented = m[a-1].get_rented();
        m[a-1].set_rented(rented + 1);
        n->set_movie(m);
        cout<<"Movie "<<a<<" rented"<<endl;
    }
}

void set_into_movie(movie* m,char* a,char* b){
    string name = b,stars,num_cast,rating,copies,rented;
    int istars,inum_cast,icopies,irented,y=0;
    string* information;
    string* cast;
    int len = strlen(a),n = -1;
    for(int i=0;i<len;i++){
        if(a[i]!='|'){
            if (n==1) {
                int w = i;
                do {
                    w++;
                } while (a[w]!='|');
                w = w-i;
                char* h = new char[w];
                for(int r=0;r<w;r++){
                    h[r] = a[r+i];
                }
                inum_cast = atoi(h);
                break;
            }
        }
        else if(a[i] == '|'){
            n++;
        }
    }
    information = new string[5+inum_cast];
    for(int i=0;i<len;i++){
        if(a[i]=='|'){
            int w = i+1;
            do {
                w++;
            } while (a[w]!='|');
            w = w-i-1;
            char* h = new char[w];
            for(int r=0;r<w;r++){
                h[r] = a[r+i+1];
            }
            information[y] = h;
            y++;
        }
    }
    stars = information[0];
    num_cast = information[1];
    cast = new string[inum_cast];
    y=0;
    for(int i=2;i<2+inum_cast;i++){
        cast[y] = information[i];
        y++;
    }
    rating = information[2+inum_cast];
    copies = information[3+inum_cast];
    rented = information[4+inum_cast];
    istars = stoi(stars);
    icopies = stoi(copies);
    irented = stoi(rented);
    m->set_cast_num(inum_cast);
    m->set_all_information(name, istars, cast, rating, icopies);
}

int check_num_movie(int p,char *d){
    int line,num_movie=0;
    char c[256];
    line = find_line();
    ifstream check;
    check.open("/Users/Hao/Desktop/project/lab10/lab10/Netflix.dat",ios::in);
    for(int i=0;i<line;i++){
        for(int x=0;x<p;x++){
            check.get(c,256,'|');
            check.get(c,2);
        }
        check.get(c,256,'|');
        if(strcmp(c,d)==0){
            check.getline(c,256);
            num_movie++;
        }
        else while(true) {
            char position = check.get();
            if (position == '\n')
                break;
            else if(position == EOF)
                break;
        }
    }
    check.close();
    return num_movie;
}


void Base_on_Title(){
    int line,num_movie,num=0,u=0;
    char c[256],d[256],e[256];
    line = find_line();
    ifstream input;
    input.open("/Users/Hao/Desktop/project/lab10/lab10/Netflix.dat",ios::in);
    cout<<"Enter the movie title you want: ";
    cin >> d;
    num_movie = check_num_movie(1,d);
    Netflix Netflix, Netflix2(num_movie);
    for(int i=0;i<line;i++){
        for(int x=0;x<1;x++){
            input.get(c,256,'|');
            input.get(c,2);
        }
        input.get(c,256,'|');
        if(strcmp(c,d)==0){
            input.getline(e, 256);
            set_into_movie(&Netflix2.get_movie()[num],e, c);
            num++;
        }
        else if (strcmp(c,d)!=0){
            u++;
            input.getline(e,256);
            output_to_file1(u, c, e);
        }
        else while(true) {
            char position = input.get();
            if (position == '\n')
                break;
            else if(position == EOF)
                break;
        }
    }
    print_information(&Netflix2);
    save_it(&Netflix2);
    input.close();
}

void Base_on_stars(){
    int line,num_movie,num=0,u=0;
    char c[256],d[256],e[256];
    line = find_line();
    ifstream input;
    input.open("/Users/Hao/Desktop/project/lab10/lab10/Netflix.dat",ios::in);
    cout<<"Enter the number of movie stars you want: ";
    cin >> d;
    num_movie = check_num_movie(2,d);
    Netflix Netflix, Netflix2(num_movie);
    for(int i=0;i<line;i++){
        for(int x=0;x<2;x++){
            input.get(c,256,'|');
            input.get(c,2);
        }
        input.get(c,256,'|');
        if(strcmp(c,d)==0){
            input.getline(e, 256);
            set_into_movie(&Netflix2.get_movie()[num],e, c);
            num++;
        }
        else if (strcmp(c,d)!=0){
            u++;
            input.getline(e,256);
            output_to_file1(u, c, e);
        }
        else while(true) {
            char position = input.get();
            if (position == '\n')
                break;
            else if(position == EOF)
                break;
        }
    }
    print_information(&Netflix2);
    save_it(&Netflix2);
    input.close();
}


int main(){
    Base_on_Title();
    return 0;
}


#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StandardIO
{
public:
    bool get_line(string &line){ return static_cast<bool>(getline(cin, line)); }
    void print_string(string line){  cout << line ; }
    void next_line(){ cout<<endl;}
    void print_number(int number){ cout<<number;}
    void print_char(char c){ cout<<c;}
};

#endif

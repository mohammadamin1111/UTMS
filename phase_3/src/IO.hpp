#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StandardIO
{
public:
    bool get_line(string &line);
    void print_string(string line);
    void next_line();
    void print_number(int number);
    void print_char(char c);
    void get_string(string & input);
};

#endif

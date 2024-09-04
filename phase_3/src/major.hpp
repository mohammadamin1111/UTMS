#ifndef MAJOR_HPP
#define MAJOR_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Major
{

public:
    Major(int mid, string major);
    string get_name();
    int get_id();

private:
    int major_id;
    string major;
};

#endif
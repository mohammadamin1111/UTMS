#ifndef MAJOR_HPP
#define MAJOR_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Major
{

public:
    Major(int mid, string major) : major_id(mid), major(major) {}
    string get_name(){return major;};
    int get_id(){ return major_id; };

private:
    int major_id;
    string major;
};

#endif
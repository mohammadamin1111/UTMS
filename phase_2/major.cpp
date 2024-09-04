#include "major.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

Major::Major(int mid, string major) : major_id(mid), major(major) {}
string Major::get_name() { return major; };
int Major::get_id() { return major_id; };
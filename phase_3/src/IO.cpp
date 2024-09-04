#include "IO.hpp"
bool StandardIO::get_line(string &line) { return static_cast<bool>(getline(cin, line)); }
void StandardIO::print_string(string line) { cout << line; }
void StandardIO::next_line() { cout << endl; }
void StandardIO::print_number(int number) { cout << number; }
void StandardIO::print_char(char c) { cout << c; }
void StandardIO::get_string(string &input) { cin >> input; };
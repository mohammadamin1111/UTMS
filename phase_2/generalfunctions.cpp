#include "generalfunctions.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
int string_to_int(string input_string)
{
    int int_number;
    stringstream(input_string) >> int_number;
    return int_number;
}
bool is_command_type_correct(string command_type, vector<string> command_words)
{

    if (command_words.size() < 2 || (command_type != "GET" && command_type != "POST" && command_type != "PUT" && command_type != "DELETE"))
    {
        throw runtime_error(BAD_REQUEST_ERROR);
    }
    else
    {
        return true;
    }
}
vector<string> string_splitter(string command_line, char splitter)
{   if(command_line.size()==0){

    throw runtime_error(BAD_REQUEST_ERROR);
}
    string word = "";
    vector<string> words;
    bool inside_quotes = false;

    for (int i = 0; i <= command_line.size(); ++i)
    {
        if (i < command_line.size())
        {
            if (command_line[i] == '"')
            {   word+='"';
                inside_quotes = !inside_quotes;
            }
            else if (command_line[i] == splitter && !inside_quotes)
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += command_line[i];
            }
        }
        else
        {
            if (!word.empty())
            {
                words.push_back(word);
            }
        }
    }

    return words;
}

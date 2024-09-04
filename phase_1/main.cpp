#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "system.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    {
        StandardIO io;
        System utms(io);
        utms.read_files(argv[1], argv[2], argv[3], argv[4]);
        utms.handle_commands();
    }

    return 0;
}

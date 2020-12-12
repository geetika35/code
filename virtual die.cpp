#include <iostream>
#include <random>

int main(int argc, char* argv[1])
{
    int range,max,min,randomint;
    max = 6;
    min = 1;
    range = max - min + 1;
    srand(time(0));
    randomint = rand() % range + min ;
    std::cout<< randomint <<std::endl;

    return 0;
}
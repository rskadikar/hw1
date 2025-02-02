#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;
    list.pop_back();
    list.pop_front();
    list.push_back("A");
    list.pop_front();
    list.push_front("L");
    list.pop_front();
    list.push_front("A");
    list.push_back("C");
    list.push_front("R");
    list.push_back("H");
    std::cout << "front: " << list.front() << std::endl;
    std::cout << "back: " << list.back() << std::endl;
    std::cout << "size: " << list.size() << std::endl;
}

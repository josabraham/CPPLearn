// compile using below commands
// g++ -c first.cpp second.cpp -o multiple.exe
//
// or
//
// g++ -c first.cpp
// g++ -c second.cpp
// g++ -o multiple.exe first.o second.o
////////////////////////////////////////


#include <stdio.h>

extern "C" int Add(int a, int b);

int main(int argc , char** argv)
{
    int a=100,b=200;
    printf("Add numbers : a = %d b = %d Result=%d",a,b,Add(a,b));
}
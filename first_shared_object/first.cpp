// compile using below commands
//
// g++ -c second.cpp
// g++ -c third.cpp
// g++ -shared -fPIC -o libArith.so second.o third.o
// g++ -o first_shaed_obj.exe  first.cpp libArith.so
////////////////////////////////////////////////////


#include <stdio.h>

extern "C" int Add(int a, int b);
extern "C" int Mul(int a , int b);

int main(int argc , char** argv)
{
    int a = 10,b = 20;
    printf("Add numbers : a = %d b = %d Result = %d \n",a,b,Add(a,b));
    printf("Multiply numbers : a = %d b=%d Result = %d \n",a,b,Mul(a,b));
}
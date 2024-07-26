#include <stdio.h>
#include <dlfcn.h>
// g++ dyncaller.cpp

typedef int(*BIN_FUNCTION)(int,int);

int main (int argc , char** argv)
{

    void* handle = dlopen("libArith.so",RTLD_LAZY);
    
    if(handle==0)
    {
        printf("Failed load library.\n");
        return 0;
    }

    BIN_FUNCTION bn = ( BIN_FUNCTION)dlsym(handle,"Add");

    if(bn==0)
    {
        printf("Failed to retrieve function \n");
        return 0;
    }

    int nc = (*bn)(10,10); 
    printf("Value is %d",nc);
    dlclose(handle);

}
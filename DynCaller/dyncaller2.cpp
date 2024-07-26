#include <stdio.h>
#include <dlfcn.h>
// g++ dyncaller2.cpp

typedef int(*BIN_FUNCTION)(int,int);

void * OpenLibrary(char * libName,int mode);
BIN_FUNCTION GetLibraryMethod(void* handle, char* methName);

int main (int argc , char** argv)
{

    void* handle = OpenLibrary((char*)"libArith.so",RTLD_LAZY);
    BIN_FUNCTION bnAdd = GetLibraryMethod(handle,(char*)"Add");
    BIN_FUNCTION bnMul = GetLibraryMethod(handle,(char*)"Mul");
    
    int a = 10,b = 20;
    printf("Add numbers : a = %d b = %d Result = %d \n",a,b,(*bnAdd)(a,b));
    printf("Multiply numbers : a = %d b = %d Result = %d \n",a,b,(*bnMul)(a,b));

    dlclose(handle);

}

void * OpenLibrary(char * libName,int mode)
{
    void* handle = dlopen(libName,mode);
    
    if(handle==0)
    {
        printf("Failed load library.\n");
        return 0;
    }
    return handle;
}

BIN_FUNCTION GetLibraryMethod(void* handle, char* methName)
{
    if ( handle != nullptr )
    {
        BIN_FUNCTION bn = ( BIN_FUNCTION)dlsym(handle,methName);

        if(bn==0)
        {
            printf("Failed to retrieve function \n");
            return 0;
        }
        return bn;
    }else
    {
         printf("Invalid library handle.\n");
         return 0;
    }
}
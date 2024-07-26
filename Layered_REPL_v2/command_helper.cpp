#include <dlfcn.h>
#include <stdio.h>

#include "first.h"

typedef int(*BIN_FUNCTION)(int,int);


void dump_params(T_PARAM_LIST *lst ) {
   int ns = lst->p_count;
   for(int i=1; i<ns; ++i ) {
          cout << ".." << lst->param_one[i].DATA.buffer << "..";

   }
   cout << endl;
   return;

}

BIN_FUNCTION LoadLibrary(char* libName, int mode,char* method)
{

    //void* handle = dlopen("libArith.so",RTLD_LAZY);
    void* handle = dlopen(libName,mode);
    
    if(handle==0)
    {
        printf("Failed load library.\n");
        return 0;
    }

    //BIN_FUNCTION bn = ( BIN_FUNCTION)dlsym(handle,"Add");
    BIN_FUNCTION bn = ( BIN_FUNCTION)dlsym(handle,method);

    if(bn==0)
    {
        printf("Failed to retrieve function \n");
        return 0;
    }

    //int nc = (*bn)(10,10); 
    //printf("Value is %d",nc);
    dlclose(handle);
    return bn;

}
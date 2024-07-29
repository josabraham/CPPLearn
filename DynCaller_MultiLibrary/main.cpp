#include <dlfcn.h>
#include <iostream>

// g++ -o main main.cpp -ldl
// runit using below command
//./main

typedef int (*AddFunction)(int, int);
typedef int (*CallMultiplyFunction)(int, int);
typedef int (*CallDivideFunction)(int, int);
typedef int (*CallSubtractFunction)(int, int);

int main() {
    void* handle = dlopen("./libA.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open libA.so: " << dlerror() << '\n';
        return 1;
    }

    AddFunction add = (AddFunction)dlsym(handle, "add");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'add': " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }

    CallMultiplyFunction callMultiply = (CallMultiplyFunction)dlsym(handle, "callMultiply");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'callMultiply': " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }

    CallDivideFunction callDivide = (CallDivideFunction)dlsym(handle, "callDivide");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'callDivide': " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }

    CallSubtractFunction callSubtract = (CallSubtractFunction)dlsym(handle, "callSubtract");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'callSubtract': " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }

    int sum = add(5, 3);
    int product = callMultiply(5, 3);
    int quotient = callDivide(10, 2);
    int difference = callSubtract(10, 3);

    std::cout << "Sum: " << sum << '\n';
    std::cout << "Product: " << product << '\n';
    std::cout << "Quotient: " << quotient << '\n';
    std::cout << "Difference: " << difference << '\n';

    dlclose(handle);
    return 0;
}

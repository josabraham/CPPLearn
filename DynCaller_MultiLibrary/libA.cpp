#include <dlfcn.h>
#include <iostream>

typedef int (*MultiplyFunction)(int, int);
typedef int (*DivideFunction)(int, int);
typedef int (*SubtractFunction)(int, int);

// g++ -shared -fPIC -o libA.so libA.cpp -ldl


extern "C" {
    int add(int a, int b) {
        return a + b;
    }

    int callMultiply(int a, int b) {
        void* handle = dlopen("./libB.so", RTLD_LAZY);
        if (!handle) {
            std::cerr << "Cannot open libB.so: " << dlerror() << '\n';
            return -1;
        }

        MultiplyFunction multiply = (MultiplyFunction)dlsym(handle, "multiply");
        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol 'multiply': " << dlsym_error << '\n';
            dlclose(handle);
            return -1;
        }

        int result = multiply(a, b);
        dlclose(handle);
        return result;
    }

    int callDivide(int a, int b) {
        void* handle = dlopen("./libB.so", RTLD_LAZY);
        if (!handle) {
            std::cerr << "Cannot open libB.so: " << dlerror() << '\n';
            return -1;
        }

        DivideFunction divide = (DivideFunction)dlsym(handle, "divide");
        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol 'divide': " << dlsym_error << '\n';
            dlclose(handle);
            return -1;
        }

        int result = divide(a, b);
        dlclose(handle);
        return result;
    }

    int callSubtract(int a, int b) {
        void* handle = dlopen("./libB.so", RTLD_LAZY);
        if (!handle) {
            std::cerr << "Cannot open libB.so: " << dlerror() << '\n';
            return -1;
        }

        SubtractFunction subtract = (SubtractFunction)dlsym(handle, "subtract");
        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol 'subtract': " << dlsym_error << '\n';
            dlclose(handle);
            return -1;
        }

        int result = subtract(a, b);
        dlclose(handle);
        return result;
    }
}


// g++ -shared -fPIC -o libB.so libB.cpp

extern "C" {
    int multiply(int a, int b) {
        return a * b;
    }

    int divide(int a, int b) {
        if (b == 0) return -1; // Simple error handling for division by zero
        return a / b;
    }

    int subtract(int a, int b) {
        return a - b;
    }
}

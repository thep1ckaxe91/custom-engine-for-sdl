#include <iostream>
using namespace std;

// Base function
void print() {
    cout << "I am empty function and I am called at last.\n";
}

// Variadic function
template <typename T, typename... Types>
void print(T var1, Types... var2) {
    cout <<  << endl;
}

int main() {
    print(1, 2, 3.14, "Pass me any number of arguments", "I will print\n");
    return 0;
}

#include <iostream>
using namespace std;
int fib(int x);

int main() {
    int result = fib(5);
    cout << "Fib of 5=" << result << endl;
    return 0;
}

int fib(int x) {
    if (x == 0)
        return 1;
    else if (x == 1)
        return 1;
    else
        return fib(x - 1) + fib(x - 2);
}

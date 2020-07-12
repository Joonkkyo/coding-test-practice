#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int factorial(int N);

int main(void)
{
    int N;
    cin >> N;
    cout << factorial(N) << endl;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

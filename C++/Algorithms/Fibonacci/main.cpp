#include <iostream>

using namespace std;

unsigned long linear_fibonacci(unsigned long n)
{
    unsigned long a = 0, b = 1, c, i;

    if (n == 0)
    {
        return a;
    }

    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

unsigned long recursive_fibonacci(unsigned long n)
{
    if (n <= 1)
    {
        return n;
    }

    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int main()
{
    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        cout << i << " " << recursive_fibonacci(i) << endl;
        cout << i << " " << linear_fibonacci(i) << endl;
    }
}
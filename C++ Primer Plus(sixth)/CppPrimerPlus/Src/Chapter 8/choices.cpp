// choices.cpp -- choosing a template
#include <iostream>
using namespace std;
template<class T>
T lesser(T a, T b)         // #1
{
	cout << "\n111111111111\n";
    return a < b ? a : b;
}

int lesser (int a, int b)  // #2
{
	cout << "\n222222222222\n";
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main()
{
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;       // use #2
    cout << lesser(x, y) << endl;       // use #1 with double
    cout << lesser<>(m, n) << endl;     // use #1 with int
    cout << lesser<int>(x, y)  << endl; // use #1 with int

    cin.get();
    return 0;
}
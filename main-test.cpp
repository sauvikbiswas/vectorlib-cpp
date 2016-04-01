#include<iostream>
#include "vector.h"

using namespace std;
int main(int argc, char *argv[]) {
    int ac = 6;
    vector a(0.1,3.5,6.7);
    vector b(9,4,6), c;
    c = a-b;
    c = a;
    cout << "Hello" << endl;
    cout << a << c << +b << endl;
    cout << (a * ac) << (c != a) << float(a) << endl;
    cout << b % a << b / 4.0 << endl;
}

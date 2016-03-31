#include <iostream>
#include <math.h>
using namespace std;
class vector {
// Data containers
    public:
    double data[3];
    vector();
    vector(double, double, double);
    vector operator- ();
    vector operator+ ();
    virtual operator float();
    virtual operator double();
    friend ostream& operator<< (ostream&, const vector);
};

// Constructor & Destructor
vector::vector() {
    for(int i=0; i<3; i++) data[i]=0.0;
}

vector::vector(double x, double y, double z) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

// Display
ostream& operator<< (ostream& os, const vector a) { 
    os << "( " << a.data[0] << ", " << a.data[1] << ", "
        << a.data[2] << " )";
    return os;
} 

// Unary Operators - typecast, abs, double, neg, pos


vector vector::operator+ () {
    vector v;
    for (int i=0; i<3; i++) v.data[i] = data[i];
    return v;
}

vector vector::operator- () {
    vector v;
    for (int i=0; i<3; i++) v.data[i] = -data[i];
    return v;
}

vector::operator double() {
    double sum;
    for (int i; i<3; i++) sum = sum + pow (data[i], 2);
    return sqrt(sum);
}

vector::operator float() {
    float sum;
    for (int i; i<3; i++) sum = sum + (float)pow(data[i], 2);
    return float(sqrt(sum));
}

// Binary Operators - add, sub, mul, rmul, mod (cross), div
vector operator+ (vector a, vector b) {
    vector c;
    for (int i=0; i<3; i++) c.data[i] = a.data[i] + b.data[i];
    return c;
}

vector operator- (vector a, vector b) {
    return a+(-b);
}

double operator* (vector a, vector b) {
    double c=0.0;
    for (int i=0; i<3; i++) c = c + (a.data[i] * b.data[i]);
    return c;
}

vector operator* (double a, vector b) {
    vector c;
    for (int i=0; i<3; i++) c.data[i] = a * b.data[i];
    return c;
}

vector operator* (float a, vector b) {
    return (double)a * b;
}

vector operator* (int a, vector b) {
    return (double)a * b;
}

vector operator* (vector a, double b) {
    return b * a;
}

vector operator* (vector a, float b) {
    return (double)b * a;
}

vector operator* (vector a, int b) {
    return (double)b * a;
}

vector operator% (vector a, vector b) {
    vector c;
    c.data[0] = a.data[1] * b.data[2] - b.data[1] * a.data[2];
    c.data[1] = a.data[2] * b.data[0] - b.data[2] * a.data[0];
    c.data[2] = a.data[0] * b.data[1] - b.data[0] * a.data[1];
    return c;
}

vector operator/ (vector a, double b) {
    return a * (1.0/b); 
}
// Comparators and boolean operators - not, <, <=, >, >=, ==, !=

bool operator== (vector a, vector b) {
    return (a.data[0] == b.data[0]) && (a.data[1] == b.data[1]) &&
            (a.data[2] == b.data[2]);
}

bool operator!= (vector a, vector b) {
    return !(a == b);
}

bool operator< (vector a, vector b) {
    return double(a) < double(b);
}

bool operator> (vector a, vector b) {
    return double(a) < double(b);
}

bool operator<= (vector a, vector b) {
    return not(double(a) > double(b));
}

bool operator>= (vector a, vector b) {
    return not(double(a) < double(b));
}
// Not implemented / not applicable


// Non native methods
// Numpy methods
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

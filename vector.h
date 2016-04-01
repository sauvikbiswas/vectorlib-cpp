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

ostream& operator<< (ostream&, const vector); 
vector operator+ (vector, vector);
vector operator- (vector, vector);
double operator* (vector, vector);
vector operator* (double, vector);
vector operator* (float, vector);
vector operator* (int, vector);
vector operator* (vector, double);
vector operator* (vector, float);
vector operator* (vector, int);
vector operator% (vector, vector);
vector operator/ (vector, double);
bool operator== (vector, vector);
bool operator!= (vector, vector);
bool operator< (vector, vector);
bool operator> (vector, vector);
bool operator<= (vector, vector);
bool operator>= (vector, vector);

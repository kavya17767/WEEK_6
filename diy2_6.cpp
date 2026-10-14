#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction {
    int num, den;

    static int gcd(int a, int b) {
        a = abs(a); b = abs(b);
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    
    void simplify() {
        if (den == 0) {
            cout << "Error: denominator cannot be zero. Setting to 0/1.\n";
            num = 0; den = 1;
            return;
        }
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        if (g > 1) { num /= g; den /= g; }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { simplify(); }   

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        if (f.den == 1) out << f.num;
        else out << f.num << "/" << f.den;
        return out;
    }

  
    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        int n, d;
        in >> n >> slash >> d;
        f = Fraction(n, d);      
        return in;
    }
};

int main() {
    Fraction f1, f2;

    cout << "Enter first fraction (a/b): ";
    cin >> f1;
    cout << "Enter second fraction (a/b): ";
    cin >> f2;

    cout << "First fraction  (simplified): " << f1 << endl;
    cout << "Second fraction (simplified): " << f2 << endl;

    Fraction f3(10, 4), f4(-6, -9), f5(3, -12);
    cout << "10/4   -> " << f3 << endl;
    cout << "-6/-9  -> " << f4 << endl;
    cout << "3/-12  -> " << f5 << endl;
    return 0;
}

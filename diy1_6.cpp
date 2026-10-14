#include <iostream>
using namespace std;

class Money {
    long long rupees;
    int paise;   

    
    void normalize() {
        long long total = rupees * 100 + paise;   
        rupees = total / 100;
        paise = total % 100;
        if (paise < 0) {                          
            paise += 100;
            rupees -= 1;
        }
    }

public:
    Money(long long r = 0, int p = 0) : rupees(r), paise(p) { normalize(); }

    Money operator+(const Money& other) const {
        return Money(rupees + other.rupees, paise + other.paise);  
    }

    Money operator-(const Money& other) const {
        return Money(rupees - other.rupees, paise - other.paise);  
    }

    void display() const {
        cout << "Rs. " << rupees << "." << (paise < 10 ? "0" : "") << paise << endl;
    }
};

int main() {
    long long r1, r2;
    int p1, p2;

    cout << "Enter first amount (rupees paise): ";
    cin >> r1 >> p1;
    cout << "Enter second amount (rupees paise): ";
    cin >> r2 >> p2;

    Money a(r1, p1), b(r2, p2);

    cout << "First  : "; a.display();
    cout << "Second : "; b.display();

    Money sum = a + b;
    Money diff = a - b;

    cout << "Sum        (a + b): "; sum.display();
    cout << "Difference (a - b): "; diff.display();
    return 0;
}

#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int* data;
    int size;

public:
    explicit SafeArray(int n = 10) : size(n) {
        if (n <= 0) throw invalid_argument("Array size must be positive");
        data = new int[size]();        
    }

   
    SafeArray(const SafeArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }

   
    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        }
        return *this;
    }

    ~SafeArray() { delete[] data; }

    
    int& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index " + to_string(index) + " is out of range (valid: 0 to " +
                               to_string(size - 1) + ")");
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size)
            throw out_of_range("Index " + to_string(index) + " is out of range (valid: 0 to " +
                               to_string(size - 1) + ")");
        return data[index];
    }

    int getSize() const { return size; }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    try {
        SafeArray arr(n);

        for (int i = 0; i < n; i++) arr[i] = (i + 1) * 10;

        cout << "Array elements: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;

        int idx;
        cout << "Enter an index to access: ";
        cin >> idx;
        cout << "arr[" << idx << "] = " << arr[idx] << endl; 
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

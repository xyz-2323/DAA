#include <iostream>
using namespace std;

int main() {
    int nterms, n1 = 0, n2 = 1, count = 0, nth;

    cout << "How many terms? ";
    cin >> nterms;

    // check if the number of terms is valid
    if (nterms <= 0) {
        cout << "Please enter a positive integer" << endl;
    } else if (nterms == 1) {
        cout << "Fibonacci sequence up to " << nterms << ": " << n1 << endl;
    } else {
        cout << "Fibonacci sequence: " << endl;
        while (count < nterms) {
            cout << n1 << " ";
            nth = n1 + n2;
            n1 = n2;
            n2 = nth;
            count++;
        }
        cout << endl;
    }

    return 0;
}












#include <iostream>
using namespace std;

int recur_fibo(int n) {
    if (n <= 1)
        return n;
    else
        return recur_fibo(n - 1) + recur_fibo(n - 2);
}

int main() {
    int nterms = 10;

    // check if the number of terms is valid
    if (nterms <= 0) {
        cout << "Please enter a positive integer" << endl;
    } else {
        cout << "Fibonacci sequence: " << endl;
        for (int i = 0; i < nterms; i++) {
            cout << recur_fibo(i) << " ";
        }
        cout << endl;
    }

    return 0;
}


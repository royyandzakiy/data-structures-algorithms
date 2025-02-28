#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int);

vector<int> generatePrimesUntil(int n) {
    vector<int> primes;

    if (n <= 1) {
        // do nothing...
    } else {
        for (int i=2; i<=n; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            } 
                
        }
    }

    return primes;
}

bool isPrime(int num) {
    cout << "Checking for " << num << endl;

    if (num <= 1) {
        // should be at least 1 and the number itself
        return false;
    } else {
        // check for divisors
        // run through i until num, if modulo exists then false, else true
        for (int i = 2; i< num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    cout << isPrime(2) << endl;
    cout << isPrime(3) << endl;
    cout << isPrime(7) << endl;
    cout << isPrime(10) << endl;
    cout << isPrime(11) << endl;

    for (auto num : generatePrimesUntil(1000)) {
        cout << num << " ";
    }

    return 0;
}
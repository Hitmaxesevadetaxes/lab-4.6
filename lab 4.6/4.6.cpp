#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;
int main() {
    double P, S;
    int n, i, k;
   
    SetConsoleOutputCP(1251);

    // Спосіб 1
    P = 1;
    n = 1;
    while (n <= 15) {
        S = 0;
        k = 1;
        while (k <= n) {
            S += 1.0 / k;
            k++;
        }
        P *= (pow(sin(n), 2) + pow(cos(n), 2) * S) / (n * n);
        n++;
    }
    cout << "Результат (while): " << P << endl;

    // Спосіб 2
    P = 1;
    n = 1;
    do {
        S = 0;
        k = 1;
        do {
            S += 1.0 / k;
            k++;
        } while (k <= n);
        P *= (pow(sin(n), 2) + pow(cos(n), 2) * S) / (n * n);
        n++;
    } while (n <= 15);
    cout << "Результат (do-while): " << P << endl;

    // Спосіб 3
    P = 1;
    for (n = 1; n <= 15; n++) {
        S = 0;
        for (k = 1; k <= n; k++) {
            S += 1.0 / k;
        }
        P *= (pow(sin(n), 2) + pow(cos(n), 2) * S) / (n * n);
    }
    cout << "Результат (for, n++): " << P << endl;

    // Спосіб 4
    P = 1;
    for (n = 15; n >= 1; n--) {
        S = 0;
        for (k = n; k >= 1; k--) {
            S += 1.0 / k;
        }
        P *= (pow(sin(n), 2) + pow(cos(n), 2) * S) / (n * n);
    }
    cout << "Результат (for, n--): " << P << endl;

    return 0;
}

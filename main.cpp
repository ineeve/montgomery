#include <iostream>
#include <algorithm>

using namespace std;

bool checkCoprime(int a, int b) {
    int minValue = min(a,b);
        for (int i = 2; i <= minValue; i++) {
            if (a % i == 0 && b % i == 0) {
                return false;
            }
        }
    
    return true;
}
/**
 * Performs T mod N, using R to fasten the computation
 * */
int montgomeryModulo(int T, int N, int R) {
    int m = T % R;
    int t = (T + m*N)/R;
    return (t >= N) ? t-N : t;
}

int main() {
    int N = 7; // choose a modulo smaller than the radix
    int R=8; // radix. should be such that computations modulo R are inexpensive to compute
    int T;
    bool areCoprime = checkCoprime(N, R);
    if (!areCoprime) {
        cout << "N and R are not coprime";
        return 1;
    } 
    cout << "Performing operations modulo " << N << endl;
    cout << "Works only for numbers less than " << N*R << endl;
    do {
        cout << "Insert a number: ";
        cin >> T;
        cout << "Computing " << T << " mod " << N << endl;
        int result = montgomeryModulo(T, N, R);
        cout << "Result: " << result << endl;
    } while(T != -1);
    
    return 0;
}
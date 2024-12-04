#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
typedef vector<double> Vector;

Vector SOR(int n, int m, const Vector& diagonal, const vector<Vector>& bands,
           const Vector& b, Vector x, int l, double omega) {

    for (int iter = 0; iter < l; iter++) {
        for (int i = 0; i < n; i++) {
            double sum = b[i];

            for (int k = 1; k <= min(m, i); k++) {
                sum -= bands[bands.size() - k][i - k] * x[i -k];
            }

            for (int k = 1; k <= min(m, n - i - 1); k++) {
                sum -= bands[bands.size() - k][i] * x[i+k];
            }

            x[i] = (1 - omega) * x[i] + (omega * sum) / diagonal[i];
        }
    }
    return x;
}

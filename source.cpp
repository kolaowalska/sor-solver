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

int main() {
    int N, M, L;
    double omega;
    cin >> N >> M;

    Vector diagonal(N), rhs(N), x0(N);
    vector<Vector> bands(M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - M + i; j++) {
            double t;
            cin >> t;
            bands[i].push_back(t);
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> diagonal[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> rhs[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> x0[i];
    }

    cin >> omega >> L;

    Vector x = SOR(N, M, diagonal, bands, rhs, x0, L, omega);

    cout << fixed << setprecision(10);
    for (double xi : x) {
        cout << scientific << xi << endl;
    }

    return 0;
}

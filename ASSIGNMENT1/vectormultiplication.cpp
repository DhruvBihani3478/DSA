#include <iostream>
#include <vector>
using namespace std;

void multiply(  vector<vector<int>> &a, vector<vector<int>> &b) {
    int m = a.size();
    int n = a[0].size();
    int p = b.size();
    int q = b[0].size();
    if (n != p) {
        cout << "Matrix multiplication not possible" << endl;
        return;
    }
    vector<vector<int>> c(m, vector<int>(q, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n, p, q;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> m >> n;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> p >> q;

    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> b(p, vector<int>(q));

    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }

    multiply(a, b);
    return 0;
}

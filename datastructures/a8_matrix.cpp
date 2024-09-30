//fmatrix multiplication
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

vector<vector<double>> matrixMultiplication(const vector<vector<double>>& a, const vector<vector<float>>& b) {
    double m = a.size();
    double n = a[0].size();
    double p = b[0].size();

    if (n != b.size()) {
        throw invalid_argument("Invalid matrix dimensions");
    }
    vector<vector<double>> c(m, vector<double>(p));


    //matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    return c;
}

//row reduction
vector<vector<double>> rowReduction(const vector<vector<double>>& a) {
    vector<vector<double>> b = a;
    double n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = b[j][i] / b[i][i];
            for (int k = 0; k < n; k++) {
                b[j][k] -= factor * b[i][k];
            }
        }
    }
    return b;
}

//determinant
double determinant(const vector<vector<double>>& a) {
    if(a.size() != a[0].size()) {
        throw invalid_argument("Invalid matrix dimensions");
    }
    vector<vector<double>> b = a;

    if (a.size() == 1) {
        return a[0][0];
    }   

    if (a.size() == 2) {
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }

    b = rowReduction(a);

    double det = 1;
    for (double i = 0; i < b.size(); i++) {
        det *= b[i][i];
    }
    return det;
}

//inverse
vector<vector<double>> inverse(const vector<vector<double>>& a) {
    if(a.size() != a[0].size()) {
        throw invalid_argument("Invalid matrix dimensions");
    }
    
    if (determinant(a) == 0) {
        throw invalid_argument("Matrix is singular");
    }

    vector<vector<double>> b = a;
    vector<vector<double>> c(a.size(), vector<double>(a.size()));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if(i == j) {
                c[i][j] = 1;
            } else {
                c[i][j] = 0;
            }
        }
    }
    //reducing the matrix into a diagonal one using column recuction
    double n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = b[j][i] / b[i][i];
            for (int k = 0; k < n; k++) {
                b[j][k] -= factor * b[i][k];
                c[j][k] -= factor * c[i][k];
            }
        }
    }
    //reducing the diagonal matrix into identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double f
            c[i][j] /= b[i][i];
        }
    }
    return c;
}

int main() {
    //first matrix
    vector<vector<double>> q = {{2, 2, 2, 2, 2}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};

    //second matrix 
    vector<vector<double>> s = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};

    //matrix multiplication
    //the 1 in the end initialises the entire matrix with it
    vector<vector<double>> t(q.size(), vector<double>(s[0].size(), 1));
    //t = matrixMultiplication(q, s);

    //row reduction
    vector<vector<double>> a = {{8, 2, -1, 2}, {-2, 1, -3, -8}, {2, -1, 7, -1}, {1, -8, 1, -2}};
    vector<vector<double>> b = rowReduction(a);
    //vector<vector<double>> b = {{8, 2, -1, 2}, {0, 1.5, -3.25, -7.5}, {0, 0, 4, -9}, {0, 0, 0, -81.188}};

    //inverse
    vector<vector<double>> c = rowReduction(a);
    //print
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c[0].size(); j++) {
            cout << c[i][j] << ", ";
        }
        cout << endl;
    }
    double det = determinant(b);
    //double x = -3897.024;
    cout << setprecision(7) << det << endl;
    return 0;

}


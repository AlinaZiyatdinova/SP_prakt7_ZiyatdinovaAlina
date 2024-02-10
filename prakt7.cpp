#include <iostream>
#include <vector>

using namespace std;

double determinant(vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return matrix[0][0];
    }

    double det = 0; // определитель
    for (int k = 0; k < n; k++) {
        vector<vector<double>> matr;
        for (int i = 1; i < n; i++) {
            vector<double> row;
            for (int j = 0; j < n; j++) {
                if (j != k) {
                    row.push_back(matrix[i][j]);
                }
            }
            matr.push_back(row);
        }

        // Вычисление определителя
        double detBk = determinant(matr);

        det += pow(-1, k + 1) * matrix[0][k] * detBk;
    }

    return det;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    //определитель матрицы
    double det = determinant(matrix);

    cout << "Определитель матрицы: " << det << endl;

    return 0;
}

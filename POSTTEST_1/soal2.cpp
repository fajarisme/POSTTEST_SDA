#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3: \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        if ((i + 1) % 2 == 0) {
            for (int j = 0; j < N; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    cout << "Jumlah elemen baris genap = " << jumlah << endl;
}
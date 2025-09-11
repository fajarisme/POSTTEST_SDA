#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan dua angka: ";
    cin >> x >> y;

    cout << "Sebelum ditukar: x = " << x << ", y = " << y << endl;
    tukar(x, y);
    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;
}
#include <iostream>
#include <cmath> // library yang dibutuhkan untuk fungsi pow()

using namespace std;

// Fungsi yang akan diintegrasikan
double f(double x) {
  return 1.0 / (7.0 + x);
}

// Fungsi Romberg untuk menghitung integrasi
// f: fungsi yang akan diintegrasikan
// a: batas bawah integrasi
// b: batas atas integrasi
// n: jumlah iterasi yang akan dilakukan
double romberg(double (*f)(double), double a, double b, int n) {
  // Inisialisasi matriks r dengan ukuran (n+1) x (n+1)
  double r[n+1][n+1];

  // Inisialisasi nilai r[0][0] dengan rumus integrasi trapesium
  r[0][0] = (b - a) * (f(a) + f(b)) / 2.0;

  // Lakukan iterasi untuk menghitung nilai integrasi dengan metode Romberg
  for (int i = 1; i <= n; i++) {
    // Hitung nilai h pada iterasi ke-i
    double h = (b - a) / pow(2, i);
    // Inisialisasi variabel sum dengan 0
    double sum = 0;
    for (int j = 1; j <= pow(2, i-1); j++) {
      // Hitung nilai sum dengan menambahkan nilai f(x) pada setiap x yang telah ditentukan
      sum += f(a + (2*j-1) * h);
    }
    // Hitung nilai r[i][0] dengan menggunakan rumus Romberg
    r[i][0] = r[i-1][0] / 2.0 + h * sum;
    for (int j = 1; j <= i; j++) {
      // Hitung nilai r[i][j] dengan menggunakan rumus Romberg
      r[i][j] = (pow(4, j) * r[i][j-1] - r[i-1][j-1]) / (pow(4, j) - 1);
    }
  }

  // Cetak tabel hasil iterasi Romberg
  for (int i = 0; i <= n; i++) {
    cout << "k = " << i << ": ";
    for (int j = 0; j <= i; j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << "\nHasil integrasi Romberg adalah: ";

  // Kembalikan hasil integrasi yaitu nilai r[n][n]
  return r[n][n];
}



int main() {
  double a = 0; // a: batas bawah integrasi
  double b = 1; // b: batas atas integrasi
  int n = 8;    // n: jumlah iterasi yang akan dilakukan

    // Tabel Integrasi Romberg
  cout << "Tabel Integrasi Romberg adalah: \n" << romberg(f, a, b, n) << endl;

  return 0;
}

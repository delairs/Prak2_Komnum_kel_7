import math # library yang dibutuhkan untuk fungsi pow()

# Fungsi yang akan diintegrasikan
def f(x):
  return 1.0 / (7.0 + x)

# Fungsi Romberg untuk menghitung integrasi
# f: fungsi yang akan diintegrasikan
# a: batas bawah integrasi
# b: batas atas integrasi
# n: jumlah iterasi yang akan dilakukan
def romberg(f, a, b, n):
  # Inisialisasi matriks r dengan ukuran (n+1) x (n+1)
  r = [[0 for j in range(n+1)] for i in range(n+1)]

  # Inisialisasi nilai r[0][0] dengan rumus integrasi trapesium
  r[0][0] = (b - a) * (f(a) + f(b)) / 2.0

  # Lakukan iterasi untuk menghitung nilai integrasi dengan metode Romberg
  for i in range(1, n+1):
    # Hitung nilai h pada iterasi ke-i
    h = (b - a) / pow(2, i)
    # Inisialisasi variabel sum dengan 0
    sum = 0
    for j in range(1, int(pow(2, i-1))+1):
      # Hitung nilai sum dengan menambahkan nilai f(x) pada setiap x yang telah ditentukan
      sum += f(a + (2*j-1) * h)
    # Hitung nilai r[i][0] dengan menggunakan rumus Romberg
    r[i][0] = r[i-1][0] / 2.0 + h * sum
    for j in range(1, i+1):
      # Hitung nilai r[i][j] dengan menggunakan rumus Romberg
      r[i][j] = (pow(4, j) * r[i][j-1] - r[i-1][j-1]) / (pow(4, j) - 1)

  # Cetak tabel hasil iterasi Romberg
  print("Tabel Integrasi Romberg adalah:")
  for i in range(n+1):
    print("k =", i, ":", end=" ")
    for j in range(i+1):
      print(r[i][j], end=" ")
    print()
  print("\nHasil integrasi Romberg adalah:", end=" ")

  # Kembalikan hasil integrasi yaitu nilai r[n][n]
  return r[n][n]

# Tabel Integrasi Romberg
a = 0 # a: batas bawah integrasi
b = 1 # b: batas atas integrasi
n = 8 # n: jumlah iterasi yang akan dilakukan

print(romberg(f, a, b, n))


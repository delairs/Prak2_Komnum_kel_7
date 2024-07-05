# P2_Komnum_B6
 
Praktikum 2 Komputasi Numerik
KomNum B
 
Kelompok  6

Anggota :
1.  M. Armand Giovani (5025211054)
2.  Fathin Muhashibi Putra (5025211229)
3.  Dafarel Fatih Wirayudha (5025211120)

## SOAL PRAKTIKUM 2 KOMPUTASI NUMERIK
<img width="422" alt="image" src="https://user-images.githubusercontent.com/103252800/208883533-65a60492-2f81-476f-ae14-a2cafe5dfa7f.png">

Pada praktikum ini, kami diminta untuk membuat sebuah program komputer untuk menjelaskan bagaimana metode Integrasi Romberg dapat mengatasi kelemahan dari metode Trapezoidal yang harus menggunakan jumlah interval yang besar untuk memperoleh akurasi yang diharapkan.

Kami menggunakan contoh soal sebagai berikut.

<img width="359" alt="image" src="https://user-images.githubusercontent.com/103252800/208886305-d55723fa-5502-4454-b224-fe42a6e50c38.png">

Maka, pertama-tama kami definisikan fungsi yang akan diintegrasikan pada soal tersebut :

```py
def f(x):
  return 1.0 / (7.0 + x)
```

Lalu, untuk proses penyelesainnya digunakan a = 0 sebagai batas bawah integrasi, b = 1  sebagai batas atas integrasi, dan n = 8 sebagai jumlah iterasi yang akan dilakukan.

```py
a = 0 # a: batas bawah integrasi
b = 1 # b: batas atas integrasi
n = 8 # n: jumlah iterasi yang akan dilakukan
```

Selanjutnya kami definisikan sebuah fungsi dengan nama "romberg" dengan parameter f (fungsi yang akan diintegrasikan) untuk menghitung fungsi integrasi pada soal tersebut. 

```py
# Fungsi Romberg untuk menghitung integrasi
# f: fungsi yang akan diintegrasikan
# a: batas bawah integrasi
# b: batas atas integrasi
# n: jumlah iterasi yang akan dilakukan

def romberg(f, a, b, n):
```

Di dalam fungsi "romberg" yang telah dibuat, dilakukan inisialisasi matriks r dengan ukuran (n+1) x (n+1)  dan inisialisasi nilai r[0][0] dengan rumus integrasi trapesium.

```py
  # Inisialisasi matriks r dengan ukuran (n+1) x (n+1)
  r = [[0 for j in range(n+1)] for i in range(n+1)]

  # Inisialisasi nilai r[0][0] dengan rumus integrasi trapesium
  r[0][0] = (b - a) * (f(a) + f(b)) / 2.0
```

Setelahnya, dilakukan suatu iterasi untuk menghitung nilai integrasi dengan metode Romberg.
```py
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
```

Dalam proses penyelesaiannya dbsetelah melakukan sebuah suatu iterasi untuk menghitung nilai integrasi dengan metode Romberg, hasil nya akan dicetak. Sehingga, mendapatkan hasil akhir penyelesaian integral menggunakan metode romberg. 

```py
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

# Cetak hasil akhir
print(romberg(f, a, b, n))
```

Berikut merupakan hasil penyelesaian yang ditampilkan oleh program.
<img width="902" alt="image" src="https://user-images.githubusercontent.com/103252800/208892807-86e43672-31b5-48a1-a72b-f18fbe9ebed6.png">

Jadi, dari soal tersebut, hasil integrasi Romberg yang didapatkan adalah 0.13353139262452263

# Kesimpulannya:
Metode Romberg adalah salah satu metode yang dapat digunakan untuk menghitung integrasi numerik dengan lebih akurat. Metode ini menggunakan teknik extrapolasi terpolarisasi yang memperbaiki hasil integrasi dengan memanfaatkan hasil integrasi yang telah diperoleh sebelumnya. Integrasi Romberg didasarkan pada ekstrapolasi Richardson, yaitu metode untuk mengkombinasikan dua perkiraan integral secara numerik untuk memperoleh nilai ketiga, yang lebih akurat. Metode Romberg dapat mengatasi kelemahan metode
trapesium dengan cara meningkatkan akurasi hasil integrasi dengan melakukan iterasi lebih banyak.

Dalam program di atas, fungsi Romberg memiliki empat parameter yaitu fungsi yang akan diintegrasikan (f), batas bawah integrasi (a), batas atas integrasi (b), dan jumlah iterasi (n). Fungsi Romberg pertama-tama akan menghitung hasil integrasi dengan menggunakan rumus integrasi trapesium yaitu dengan mengalikan jumlah panjang interval dengan jumlah nilai f(a) dan f(b) dibagi 2. Kemudian, fungsi Romberg akan melakukan iterasi sebanyak n kali untuk menghitung hasil integrasi dengan metode Romberg. Setiap iterasi akan menghitung nilai h yaitu panjang interval dibagi 2 pangkat i. Kemudian, fungsi Romberg akan menghitung nilai sum dengan menambahkan nilai f(x) pada setiap x yang telah ditentukan. Nilai r[i][0] akan dihitung dengan menggunakan rumus Romberg yaitu dengan mengalikan r[i-1][0] dibagi 2 ditambah h kali nilai sum. Setelah itu, nilai r[i][j] akan dihitung dengan menggunakan rumus Romberg yaitu dengan mengalikan 4 pangkat j kali r[i][j-1] dikurang r[i-1][j-1] dibagi 4 pangkat j dikurang 1. Setelah selesai melakukan iterasi, fungsi Romberg akan mencetak tabel hasil iterasi Romberg dan mengembalikan hasil integrasi yaitu nilai r[n][n].










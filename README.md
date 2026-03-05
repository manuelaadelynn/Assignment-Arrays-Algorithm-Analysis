# Assignment 03 – Algoritma dan Struktur Data

**Name:** Manuela Adelynn Sitompul  
**Student ID:** 24/545564/TK/60698

---

## Overview
Repositori ini berisi implementasi dan analisis untuk **Assignment 03** pada mata kuliah *Algoritma dan Struktur Data*.  
Tugas ini berfokus pada analisis algoritma, implementasi *dynamic array*, serta perbandingan algoritma pencarian dasar.

Assignment ini terdiri dari empat problem yang menggabungkan **analisis teoritis** dengan **implementasi praktis menggunakan C++**.

---

## Deskripsi Masalah

### Problem 1 – Algorithm Analysis
Pada bagian ini dilakukan analisis terhadap beberapa potongan kode (*algorithm snippets*). Untuk setiap potongan kode, ditentukan:

- *Operation cost*
- Fungsi waktu **T(n)**
- Kompleksitas waktu dalam bentuk **Big-O**
- Identifikasi operasi dominan yang memengaruhi pertumbuhan kompleksitas

Penjelasan lengkap beserta perhitungan detail disertakan pada dokumen analisis terlampir.

---

### Problem 2 – Implementasi Dynamic Array
Program ini mengimplementasikan **dynamic array dari awal menggunakan C++** dengan pendekatan prosedural.

Dynamic array direpresentasikan menggunakan sebuah `struct` yang menyimpan:

- pointer ke data (`int* data`)
- jumlah elemen saat ini (`size`)
- kapasitas total array (`capacity`)

Operasi yang diimplementasikan meliputi:

- `initArray` – menginisialisasi dynamic array
- `freeArray` – membebaskan memori yang dialokasikan
- `resize` – memperbesar kapasitas ketika array penuh
- `pushBack` – menambahkan elemen ke akhir array
- `insertAt` – menyisipkan elemen pada indeks tertentu
- `removeAt` – menghapus elemen pada indeks tertentu
- `getAt` – mengambil nilai pada suatu indeks
- `setAt` – mengubah nilai pada suatu indeks

Untuk mempermudah pemahaman perilaku program, keadaan array ditampilkan dalam **format tabel** setelah setiap operasi.  
Tabel tersebut menampilkan indeks, nilai elemen, serta ukuran (*size*) dan kapasitas (*capacity*) array saat itu.

---

### Problem 3 – Linear Search vs. Binary Search
Program ini membandingkan dua algoritma pencarian yang umum digunakan dan diimplementasikan secara iteratif:

- **Linear Search** – melakukan pencarian secara berurutan dengan kompleksitas waktu **O(n)**
- **Binary Search** – membagi ruang pencarian menjadi dua secara berulang dengan kompleksitas waktu **O(log n)**

Array yang digunakan dialokasikan secara dinamis di *heap* dan dibuat dalam keadaan **terurut**.

Pengujian dilakukan pada beberapa ukuran array (`n = 10`, `100`, dan `1000`) dengan dua skenario:

1. Mencari nilai yang **ada** di dalam array
2. Mencari nilai yang **tidak ada** di dalam array

Hasil pengujian ditampilkan dalam **tabel terformat**, yang menunjukkan:

- ukuran array
- skenario pengujian
- nilai target
- indeks yang dikembalikan oleh masing-masing algoritma
- apakah kedua algoritma memberikan hasil yang sama

Hal ini membantu memverifikasi bahwa implementasi kedua algoritma bekerja dengan benar.

---

### Problem 4 – Growth Factor dan Amortized Analysis
Pada bagian ini dianalisis bagaimana **dynamic array bertambah kapasitasnya ketika terjadi proses resize**.

Analisis mencakup:

- bagaimana proses resize memengaruhi biaya operasi penyisipan
- alasan strategi **capacity doubling** sering digunakan
- bagaimana konsep **amortized analysis** menunjukkan bahwa operasi `pushBack` memiliki biaya rata-rata **O(1)**

Selain itu, juga dibahas perbandingan beberapa *growth factor* serta dampaknya terhadap performa dan penggunaan memori.

---

## Compilation
Program dikompilasi menggunakan **g++ dengan standar C++17** serta opsi peringatan tambahan.
Karena pengujian dilakukan menggunakan **Windows PowerShell**, perintah kompilasi yang digunakan adalah:

g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3

Untuk menjalankan program di Windows PowerShell:

.\problem2
.\problem3

---

## Known Issues or Limitations
- Tidak ditemukan *memory leak* pada kedua program setelah pengujian.
- Implementasi *Binary Search* pada Problem 3 mengasumsikan bahwa array sudah terurut, yang pada program ini dipastikan oleh fungsi pembuat array (*generator*).

## Time Spent
Sekitar **8 jam** digunakan untuk menyelesaikan keseluruhan assignment, termasuk analisis algoritma, implementasi kode, pengujian, serta proses *debugging*.

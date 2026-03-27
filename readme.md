# 🚦 Traffic Light 4 Arah - Arduino Uno

## Deskripsi

Project ini dibuat untuk mensimulasikan sistem lampu lalu lintas pada persimpangan 4 arah menggunakan Arduino Uno. Tujuan utamanya adalah memahami bagaimana GPIO pada Arduino bisa digunakan untuk mengontrol beberapa LED sekaligus dengan logika tertentu.

Pada simulasi ini terdapat 4 arah:

* Utara
* Timur
* Selatan
* Barat

Masing-masing arah memiliki 3 lampu:

* Merah
* Kuning
* Hijau

Lampu akan menyala secara bergantian mengikuti arah jarum jam dan berjalan terus menerus (loop).

---

## ⚙️ Tools yang Digunakan

* Arduino Uno
* Arduino IDE
* Tinkercad (untuk simulasi rangkaian)

---

## 🔄 Cara Kerja Sistem

Secara sederhana, alurnya seperti ini:

* Awal sistem: semua lampu merah
* Salah satu arah akan aktif (hijau menyala 5 detik)
* Setelah itu lampu kuning berkedip 3 kali
* Lalu kembali ke merah
* Sistem pindah ke arah berikutnya

Urutannya:

```
Utara → Timur → Selatan → Barat → ulang lagi
```

Yang penting di sini:

* Tidak ada lebih dari satu lampu hijau yang menyala
* Sistem berjalan terus tanpa berhenti

---

## 🔌 Mapping Pin

| Arah    | Merah | Kuning | Hijau |
| ------- | ----- | ------ | ----- |
| Utara   | 2     | 3      | 4     |
| Timur   | 5     | 6      | 7     |
| Selatan | 8     | 9      | 10    |
| Barat   | 11    | 12     | 13    |

---

## 💻 Cuplikan Program

```cpp id="g3pn7x"
void loop() {
  aktifkanSimpang(merahU, kuningU, hijauU);
  aktifkanSimpang(merahT, kuningT, hijauT);
  aktifkanSimpang(merahS, kuningS, hijauS);
  aktifkanSimpang(merahB, kuningB, hijauB);
}
```

Program dibuat menggunakan fungsi supaya lebih rapi, salah satunya:

* `semuaMerah()` → memastikan semua lampu merah dulu
* `aktifkanSimpang()` → mengatur satu arah aktif

---

## 📸 Hasil Simulasi

![alt text](<Tugas 3_Rafif Surya Murtadha1.png>)

---

## 🔗 Link Project

* Tinkercad:
  https://www.tinkercad.com/things/36z2knNnZpV-tugas-3rafif-surya-murtadha

* Dokumentasi:
  https://drive.google.com/drive/folders/1pgOwei679Aq-AYLNUxDXzfmd8ulX9Ro_?usp=sharing

---


## 📊 Hasil

Dari hasil pengujian:

* Lampu sudah berjalan sesuai urutan
* Tidak ada konflik antar arah
* Timing sesuai dengan yang direncanakan
* Sistem berjalan terus (looping)
* Masih pakai `delay()` (belum optimal)

---



Rafif Surya Murtadha
H1D023008

---

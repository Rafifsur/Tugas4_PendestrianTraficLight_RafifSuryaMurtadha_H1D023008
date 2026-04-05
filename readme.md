# 🚦 Pedestrian Traffic Light - Arduino Uno

## Deskripsi

Project ini dibuat untuk mensimulasikan sistem pedestrian traffic light menggunakan Arduino Uno dengan memanfaatkan konsep interrupt. Sistem ini menggambarkan kondisi lampu lalu lintas pada satu jalur kendaraan yang dilengkapi dengan dua sisi penyeberangan.

Lampu kendaraan terdiri dari tiga warna:
- Merah  
- Kuning  
- Hijau  

Sedangkan untuk pedestrian terdiri dari:
- Merah  
- Hijau  

Pada kondisi normal, kendaraan berjalan (lampu hijau) dan pedestrian berhenti. Ketika tombol ditekan, sistem akan menghentikan kendaraan dan memberikan kesempatan bagi pejalan kaki untuk menyeberang.

---

## Tools yang Digunakan

- Arduino Uno  
- Arduino IDE  
- Tinkercad (simulasi rangkaian)

---

## Cara Kerja Sistem

Alur kerja sistem secara sederhana adalah sebagai berikut:

- Kondisi awal: kendaraan hijau, pedestrian merah  
- Ketika tombol ditekan:
  - Kendaraan berubah menjadi merah  
  - Pedestrian berubah menjadi hijau  
- Setelah beberapa detik:
  - Pedestrian kembali merah  
  - Kendaraan masuk fase kuning (kedip 3 kali)  
- Sistem kembali ke kondisi awal  

**Catatan:**
- Kedua sisi pedestrian menyala bersamaan  
- Sistem berjalan terus menerus (looping)  

---

## Mapping Pin

### 🚗 Kendaraan
| Fungsi | Pin |
|--------|-----|
| Merah  | 4   |
| Kuning | 5   |
| Hijau  | 6   |

### 🚶 Pedestrian Kanan
| Fungsi | Pin |
|--------|-----|
| Merah  | 7   |
| Hijau  | 8   |

### 🚶 Pedestrian Kiri
| Fungsi | Pin |
|--------|-----|
| Merah  | 9   |
| Hijau  | 10  |

### 🔘 Tombol
| Tombol | Pin |
|--------|-----|
| Kiri   | 2   |
| Kanan  | 3   |

---

## Cuplikan Program

```cpp
void loop() {

  // kondisi normal
  if (!ditekan) {
    digitalWrite(hijau, HIGH);
    digitalWrite(kuning, LOW);
    digitalWrite(merah, LOW);
  }

  // saat tombol ditekan
  if (ditekan) {
    digitalWrite(hijau, LOW);
    digitalWrite(merah, HIGH);
  }
}

---

Program menggunakan interrupt agar sistem dapat merespons tombol secara langsung tanpa menunggu proses loop selesai.

---

## Hasil Simulasi

dokumentasi/Tugas 4_Rafif Surya Murtadha1.png

---

## 🔗 Link Project

- Tinkercad:  
  https://www.tinkercad.com/things/1dX3K8bUF2G-pedestrian-traficlight-rafifsuryah1d023008  

- Dokumentasi:  
  https://drive.google.com/file/d/1LGKNe9Rngz_CcnvVkwCSc7eZHSg8BGzg/view?usp=sharing 

---

##  Hasil

Berdasarkan hasil pengujian:

- Sistem berjalan sesuai dengan logika yang dirancang  
- Interrupt berhasil merespons tombol dengan cepat  
- Tidak terjadi konflik antara kendaraan dan pedestrian  
- Transisi lampu berjalan dengan baik  
- Sistem masih menggunakan `delay()` sehingga belum optimal  

---


## Nama / NIM

Rafif Surya Murtadha  
H1D023008
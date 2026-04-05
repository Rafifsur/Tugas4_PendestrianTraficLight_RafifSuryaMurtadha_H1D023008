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

## Kode Program

```cpp

// PIN KENDARAAN
int merah = 4;
int kuning = 5;
int hijau = 6;

// PIN PEDESTRIAN
int ped_kanan_merah = 7;
int ped_kanan_hijau = 8;

int ped_kiri_merah = 9;
int ped_kiri_hijau = 10;

// PIN TOMBOL
int tombol_kiri = 2;
int tombol_kanan = 3;

volatile bool ditekan = false;

void setup() {
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);

  pinMode(ped_kanan_merah, OUTPUT);
  pinMode(ped_kanan_hijau, OUTPUT);
  pinMode(ped_kiri_merah, OUTPUT);
  pinMode(ped_kiri_hijau, OUTPUT);

  pinMode(tombol_kiri, INPUT_PULLUP);
  pinMode(tombol_kanan, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(tombol_kiri), ISR_tombol, FALLING);
  attachInterrupt(digitalPinToInterrupt(tombol_kanan), ISR_tombol, FALLING);

  kondisiAwal();
}

void loop() {

  // kondisi normal
  if (!ditekan) {
    digitalWrite(hijau, HIGH);
    digitalWrite(kuning, LOW);
    digitalWrite(merah, LOW);

    digitalWrite(ped_kanan_merah, HIGH);
    digitalWrite(ped_kiri_merah, HIGH);
    digitalWrite(ped_kanan_hijau, LOW);
    digitalWrite(ped_kiri_hijau, LOW);
  }

  // saat tombol ditekan
  if (ditekan) {
    ditekan = false;

    digitalWrite(hijau, LOW);
    digitalWrite(merah, HIGH);

    digitalWrite(ped_kanan_merah, LOW);
    digitalWrite(ped_kiri_merah, LOW);
    digitalWrite(ped_kanan_hijau, HIGH);
    digitalWrite(ped_kiri_hijau, HIGH);

    delay(5000);

    digitalWrite(ped_kanan_hijau, LOW);
    digitalWrite(ped_kiri_hijau, LOW);
    digitalWrite(ped_kanan_merah, HIGH);
    digitalWrite(ped_kiri_merah, HIGH);

    for (int i = 0; i < 3; i++) {
      digitalWrite(kuning, HIGH);
      delay(500);
      digitalWrite(kuning, LOW);
      delay(500);
    }

    kondisiAwal();
  }
}

void ISR_tombol() {
  ditekan = true;
}

void kondisiAwal() {
  digitalWrite(merah, LOW);
  digitalWrite(kuning, LOW);
  digitalWrite(hijau, HIGH);

  digitalWrite(ped_kanan_merah, HIGH);
  digitalWrite(ped_kiri_merah, HIGH);
  digitalWrite(ped_kanan_hijau, LOW);
  digitalWrite(ped_kiri_hijau, LOW);
}

---
```
Program menggunakan interrupt agar sistem dapat merespons tombol secara langsung tanpa menunggu proses loop selesai.

---

## Hasil Simulasi

<img width="1280" height="650" alt="Tugas 4_Rafif Surya Murtadha1" src="https://github.com/user-attachments/assets/8d5fb417-691e-4b34-b6c8-73e9ce747301" />


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

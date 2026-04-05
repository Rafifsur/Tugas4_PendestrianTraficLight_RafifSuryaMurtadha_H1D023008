// =======================
// PIN KENDARAAN
// =======================
int merah = 4;
int kuning = 5;
int hijau = 6;

// =======================
// PIN PEDESTRIAN
// =======================
int ped_kanan_merah = 7;
int ped_kanan_hijau = 8;

int ped_kiri_merah = 9;
int ped_kiri_hijau = 10;

// =======================
// PIN TOMBOL
// =======================
int tombol_kiri = 2;
int tombol_kanan = 3;

volatile bool ditekan = false;

// =======================
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

// =======================
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

    // kendaraan berhenti
    digitalWrite(hijau, LOW);
    digitalWrite(kuning, LOW);
    digitalWrite(merah, HIGH);

    // pedestrian jalan
    digitalWrite(ped_kanan_merah, LOW);
    digitalWrite(ped_kiri_merah, LOW);
    digitalWrite(ped_kanan_hijau, HIGH);
    digitalWrite(ped_kiri_hijau, HIGH);

    delay(5000);

    // pedestrian berhenti lagi
    digitalWrite(ped_kanan_hijau, LOW);
    digitalWrite(ped_kiri_hijau, LOW);
    digitalWrite(ped_kanan_merah, HIGH);
    digitalWrite(ped_kiri_merah, HIGH);

    // kuning kedip 3x
    for (int i = 0; i < 3; i++) {
      digitalWrite(kuning, HIGH);
      delay(500);
      digitalWrite(kuning, LOW);
      delay(500);
    }

    kondisiAwal();
  }
}

// =======================
void ISR_tombol() {
  ditekan = true;
}

// =======================
void kondisiAwal() {
  // kendaraan jalan
  digitalWrite(merah, LOW);
  digitalWrite(kuning, LOW);
  digitalWrite(hijau, HIGH);

  // pedestrian berhenti
  digitalWrite(ped_kanan_merah, HIGH);
  digitalWrite(ped_kiri_merah, HIGH);
  digitalWrite(ped_kanan_hijau, LOW);
  digitalWrite(ped_kiri_hijau, LOW);
}
// TRAFFIC LIGHT 4 ARAH - ARDUINO UNO

// Utara
int merahU = 2;
int kuningU = 3;
int hijauU = 4;

// Timur
int merahT = 5;
int kuningT = 6;
int hijauT = 7;

// Selatan
int merahS = 8;
int kuningS = 9;
int hijauS = 10;

// Barat
int merahB = 11;
int kuningB = 12;
int hijauB = 13;

// ===============================
// SETUP
void setup() {
  pinMode(merahU, OUTPUT);
  pinMode(kuningU, OUTPUT);
  pinMode(hijauU, OUTPUT);

  pinMode(merahT, OUTPUT);
  pinMode(kuningT, OUTPUT);
  pinMode(hijauT, OUTPUT);

  pinMode(merahS, OUTPUT);
  pinMode(kuningS, OUTPUT);
  pinMode(hijauS, OUTPUT);

  pinMode(merahB, OUTPUT);
  pinMode(kuningB, OUTPUT);
  pinMode(hijauB, OUTPUT);

  // Default: semua merah
  semuaMerah();
}

// ===============================
// LOOP UTAMA 
void loop() {
  aktifkanSimpang(merahU, kuningU, hijauU); // Utara
  aktifkanSimpang(merahT, kuningT, hijauT); // Timur
  aktifkanSimpang(merahS, kuningS, hijauS); // Selatan
  aktifkanSimpang(merahB, kuningB, hijauB); // Barat
}

// ===============================
// FUNGSI: SEMUA MERAH
void semuaMerah() {
  digitalWrite(merahU, HIGH);
  digitalWrite(merahT, HIGH);
  digitalWrite(merahS, HIGH);
  digitalWrite(merahB, HIGH);

  digitalWrite(kuningU, LOW);
  digitalWrite(kuningT, LOW);
  digitalWrite(kuningS, LOW);
  digitalWrite(kuningB, LOW);

  digitalWrite(hijauU, LOW);
  digitalWrite(hijauT, LOW);
  digitalWrite(hijauS, LOW);
  digitalWrite(hijauB, LOW);
}

// ===============================
// FUNGSI: AKTIFKAN 1 SIMPANG
void aktifkanSimpang(int merah, int kuning, int hijau) {
  // Semua merah dulu
  semuaMerah();
  delay(500);

  // HIJAU nyala 5 detik
  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  delay(5000);

  // KUNING berkedip 3x (total 2 detik)
  digitalWrite(hijau, LOW);

  for (int i = 0; i < 3; i++) {
    digitalWrite(kuning, HIGH);
    delay(333);
    digitalWrite(kuning, LOW);
    delay(333);
  }

  // Kembali ke merah
  digitalWrite(merah, HIGH);
}

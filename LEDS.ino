void playingWAVSeq() {
  while (playWav1.isPlaying()) {
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, LOW);
    delay(200);
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, HIGH);
    delay(200);
  }
  if (!playWav1.isPlaying()) {
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
  }
}  //END playingWAVSeq

void setupSeq() {
  int i, j;
  for (i = 0; i <= 2; i++) {
    for (j = 0; j < 255; j++) {
      analogWrite(ledGeneral, j);
      delay(10);

      if (j > 250) {
        for (j = 255; j > 0; j--) {
          analogWrite(ledGeneral, j);
          delay(10);
        }
        analogWrite(ledGeneral, 255);
        break;
      }
    }
  }
  digitalWrite(ledRow1, HIGH);
  digitalWrite(ledRow2, HIGH);
}

void errSeq() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledGeneral, LOW);
    delay(100);
    digitalWrite(ledGeneral, HIGH);
  }
}
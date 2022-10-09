void buttons() {
  if (digitalRead(button1) == LOW) {
    Serial.println("Button 1 pressed, playing 1.wav");
    playFile("1.wav");  // filenames are always uppercase 8.3 format
    playingWAVSeq();
  }
  if (digitalRead(button2) == LOW) {
    Serial.println("Button 1 pressed, playing 2.wav");
    playFile("2.wav");  // filenames are always uppercase 8.3 format
        playingWAVSeq();
  }
  if (digitalRead(button3) == LOW) {
    Serial.println("Button 1 pressed, playing 3.wav");
    playFile("3.wav");  // filenames are always uppercase 8.3 format
        playingWAVSeq();
  }
  if (digitalRead(button4) == LOW) {
    Serial.println("Button 1 pressed, playing 4.wav");
    playFile("4.wav");  // filenames are always uppercase 8.3 format
        playingWAVSeq();
  }
  if (digitalRead(button5) == LOW) {
    Serial.println("Button 1 pressed, playing 5.wav");
    playFile("5.wav");  // filenames are always uppercase 8.3 format
        playingWAVSeq();
  }
  if (digitalRead(button6) == LOW) {
    Serial.println("Button 1 pressed, playing 6.wav");
    playFile("6.wav");  // filenames are always uppercase 8.3 format
        playingWAVSeq();
  }
  if (digitalRead(button7) == LOW) {
    Serial.println("Button 1 pressed, playing 7.wav");
    playFile("7.wav");  // filenames are always uppercase 8.3 format
        playingWAVSeq();
  }
  if (digitalRead(button8) == LOW) {
    Serial.println("Button 1 pressed, playing 8.wav");
    playFile("8.wav");  // filenames are always uppercase 8.3 format
        playingWAVSeq();
  }
}  //END void buttons()

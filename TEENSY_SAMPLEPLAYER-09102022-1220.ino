// Simple WAV file player example
//
// Three types of output may be used, by configuring the code below.
//
//   1: Digital I2S - Normally used with the audio shield:
//         http://www.pjrc.com/store/teensy3_audio.html
//
//   2: Digital S/PDIF - Connect pin 22 to a S/PDIF transmitter
//         https://www.oshpark.com/shared_projects/KcDBKHta
//
//   3: Analog DAC - Connect the DAC pin to an amplified speaker
//         http://www.pjrc.com/teensy/gui/?info=AudioOutputAnalog
//
// To configure the output type, first uncomment one of the three
// output objects.  If not using the audio shield, comment out
// the sgtl5000_1 lines in setup(), so it does not wait forever
// trying to configure the SGTL5000 codec chip.
//
// The SD card may connect to different pins, depending on the
// hardware you are using.  Uncomment or configure the SD card
// pins to match your hardware.
//
// Data files to put on your SD card can be downloaded here:
//   http://www.pjrc.com/teensy/td_libs_AudioDataFiles.html
//
// This example code is in the public domain.

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

//AUDIO
AudioPlaySdWav playWav1;
AudioOutputI2S audioOutput;
AudioConnection patchCord1(playWav1, 0, audioOutput, 0);
AudioConnection patchCord2(playWav1, 1, audioOutput, 1);
AudioControlSGTL5000 sgtl5000_1;

//SD
#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11
#define SDCARD_MISO_PIN 12
#define SDCARD_SCK_PIN 13
bool SDcheck = false;

//BUTTONS
int button1 = 0;
int button2 = 1;
int button3 = 2;
int button4 = 3;
int button5 = 4;
int button6 = 5;
int button7 = 16;
int button8 = 17;

//LED
int ledRow1 = 14;
int ledRow2 = 22;
int ledGeneral = 9;

void setup() {
  Serial.begin(9600);

Serial.println("[[SETUP]] Started.");

  //AUDIO
  AudioMemory(512);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.1);

  //SD
  setupSD();

  File root = SD.open("/");
  printDirectory(root, 0);
  Serial.println("done!");

  //BUTTONS
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);

  //LED
  pinMode(ledRow1,OUTPUT);
  pinMode(ledRow2,OUTPUT);
  pinMode(ledGeneral,OUTPUT);

  Serial.println("[[SETUP]] End.");
  setupSeq();
}

void playFile(const char *filename) {
  if (SD.exists(filename)) {
    Serial.print(filename);
    Serial.println(" Found on SD!");
    Serial.print("Playing file: ");
    Serial.println(filename);

    // Start playing the file.  This sketch continues to
    // run while the file plays.
    playWav1.play(filename);

    // A brief delay for the library read WAV info
    delay(25);
  } else if (!SD.exists(filename)) {
    Serial.print(filename);
    Serial.println(" Not found!");
    errSeq();
  }
}


void loop() {
buttons();
}


void printDirectory(File dir, int numSpaces) {
  while (true) {
    File entry = dir.openNextFile();
    if (!entry) {
      //Serial.println("** no more files **");
      break;
    }
    printSpaces(numSpaces);
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numSpaces + 2);
    } else {
      // files have sizes, directories do not
      int n = log10f(entry.size());
      if (n < 0) n = 10;
      if (n > 10) n = 10;
      printSpaces(50 - numSpaces - strlen(entry.name()) - n);
      Serial.print("  ");
      Serial.print(entry.size(), DEC);
      DateTimeFields datetime;
      if (entry.getModifyTime(datetime)) {
        printSpaces(4);
        printTime(datetime);
      }
      Serial.println();
    }
    entry.close();
  }
}

void printSpaces(int num) {
  for (int i = 0; i < num; i++) {
    Serial.print(" ");
  }
}

void printTime(const DateTimeFields tm) {
  const char *months[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  };
  if (tm.hour < 10) Serial.print('0');
  Serial.print(tm.hour);
  Serial.print(':');
  if (tm.min < 10) Serial.print('0');
  Serial.print(tm.min);
  Serial.print("  ");
  Serial.print(tm.mon < 12 ? months[tm.mon] : "???");
  Serial.print(" ");
  Serial.print(tm.mday);
  Serial.print(", ");
  Serial.print(tm.year + 1900);
}
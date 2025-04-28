// -------------------------------------------------
// Copyright (c) 2022 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 12

int melody[] = {
  NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_E5,NOTE_D5,NOTE_B4,   //8
  NOTE_E4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_E4,                   //6
  NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,          //7
  NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_E4,NOTE_DS4,NOTE_FS4,        //7
  
  NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_E5,NOTE_D5,NOTE_B4,   //8
  NOTE_E4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_E4,                   //6
  NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,          //7
  NOTE_G4,NOTE_A4,NOTE_B4,                                            //3
  //LOOP 
  NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_E5,NOTE_D5,NOTE_B4,   //8
  NOTE_E4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_E4,                   //6
  NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,          //7
  NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_E4,NOTE_DS4,NOTE_FS4,        //7
  
  NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_E5,NOTE_D5,NOTE_B4,   //8
  NOTE_E4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_E4,                   //6
  NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,          //7
  NOTE_G4,NOTE_A4,NOTE_B4,                                            //3

  //MAIN_MELODY
  NOTE_D5,NOTE_E5,NOTE_B4,NOTE_A4,NOTE_B4,                            //5
  NOTE_A4,NOTE_B4,NOTE_D5,NOTE_E5,NOTE_B4,NOTE_A4,NOTE_B4,            //7
  NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_D4,NOTE_E4,           //7
  NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_E4,           //7

  NOTE_B4,NOTE_D5,NOTE_D5,NOTE_E5,NOTE_B4,NOTE_A4,NOTE_B4,            //7
  NOTE_A4,NOTE_B4,NOTE_D5,NOTE_E5,NOTE_B4,NOTE_A4,NOTE_B4,            //7
  NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_D4,NOTE_E4,           //7
  NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_E4,           //7
  //END
  NOTE_B4,NOTE_D5,NOTE_D5,NOTE_E5,NOTE_B4,NOTE_A4,NOTE_B4,            //7
  NOTE_A4,NOTE_B4,NOTE_D5,NOTE_E5,NOTE_B4,NOTE_A4,NOTE_B4,            //7
  NOTE_E5,NOTE_FS5,NOTE_G5,NOTE_FS5,NOTE_E5,NOTE_D5,NOTE_B4,          //7
  NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_D4,NOTE_E4,           //7


};

int durations[] = {
        //FAST
  8,8,8,8,4,8,8,4,
  4,8,8,8,8,8,
  8,8,8,4,8,8,8,
  8,8,8,8,8,8,8,

  8,8,8,8,4,8,8,4,
  4,8,8,8,8,8,
  8,8,8,4,8,8,4,
  4,4,4,
  //LOOP
  8,8,8,8,4,8,8,4,
  4,8,8,8,8,8,
  8,8,8,4,8,8,8,
  8,8,8,8,8,8,8,

  8,8,8,8,4,8,8,4,
  4,8,8,8,8,8,
  8,8,8,4,8,8,4,
  4,4,4,
  //MAIN_MELODY
  8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,

  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  //END
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,


  /*    // NOMAL
  6,6,6,6,2,6,6,2,
  2,6,6,6,6,6,
  6,6,6,2,6,6,6,
  6,6,6,6,6,6,6,

  8,8,8,8,4,8,8,4,
  4,8,8,8,8,8,
  8,8,8,4,8,8,4,
  4,4,4,
  //LOOP
  8,8,8,8,4,8,8,4,
  4,8,8,8,8,8,
  8,8,8,4,8,8,8,
  8,8,8,8,8,8,8,

  8,8,8,8,4,8,8,4,
  4,8,8,8,8,8,
  8,8,8,4,8,8,4,
  4,4,4,
  //MAIN_MELODY
  8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,

  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  //END
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,
  8,8,8,8,8,8,4,


  */
  /*    // SLOW
  4,4,4,4,2,4,4,2,
  2,4,4,4,4,4,
  4,4,4,2,4,4,4,
  4,4,4,4,4,4,4,

  4,4,4,4,2,4,4,2,
  2,4,4,4,4,4,
  4,4,4,2,4,4,2,
  2,2,2,
  //LOOP
  4,4,4,4,2,4,4,2,
  2,4,4,4,4,4,
  4,4,4,2,4,4,4,
  4,4,4,4,4,4,4,

  4,4,4,4,2,4,4,2,
  2,4,4,4,4,4,
  4,4,4,2,4,4,2,
  2,2,2,
  //MAIN_MELODY
  4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,

  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  //END
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
  4,4,4,4,4,4,2,
    */


};

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}
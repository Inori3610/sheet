// -------------------------------------------------
// Copyright (c) 2022 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 12

int melody[] = {
  // OPEN
  NOTE_G5,NOTE_E5,NOTE_G5,NOTE_B5,NOTE_A5,REST,                 //6  0:07
  NOTE_G5,NOTE_FS5,NOTE_G5,REST,                                //3
  NOTE_A5,NOTE_G5,NOTE_FS5,NOTE_E5,NOTE_D5,NOTE_FS5,            //6
  
  NOTE_G5,NOTE_E5,NOTE_G5,NOTE_B5,NOTE_A5,REST,                 //5 0:10
  NOTE_G5,NOTE_FS5,REST,NOTE_FS5,REST,                          //5
  NOTE_A5,NOTE_G5,NOTE_A5,NOTE_C6,NOTE_B5,NOTE_FS5,REST ,        //7

  NOTE_G5,NOTE_E5,NOTE_G5,NOTE_D6,NOTE_A5,REST,                 //0:15
  NOTE_G5,NOTE_FS5,REST,NOTE_FS5,REST,
  NOTE_A5,NOTE_G5,NOTE_D6,REST,

  NOTE_B5,NOTE_A5,REST,NOTE_G5,NOTE_B4,NOTE_E5,NOTE_B5,NOTE_A5, //0:17               
  REST,NOTE_G5,NOTE_FS5,REST,NOTE_FS5,REST,
  NOTE_A5,NOTE_G5,NOTE_FS5,NOTE_C6,NOTE_B5,NOTE_FS5,

  NOTE_G5,NOTE_E5,NOTE_G5,NOTE_B5,NOTE_A5,REST,                      //0:22
  NOTE_G5,NOTE_FS5,NOTE_G5,REST,
  NOTE_A5,NOTE_G5,NOTE_FS5,NOTE_E5,NOTE_D5,NOTE_FS5,

  NOTE_G5,NOTE_E5,NOTE_G5,NOTE_B5,NOTE_A5,REST,                      //0:27
  NOTE_G5,NOTE_FS5,REST,NOTE_FS5,REST,
  NOTE_A5,NOTE_G5,NOTE_A5,NOTE_C6,NOTE_B5,NOTE_FS5,REST,

  NOTE_G5,NOTE_E5,NOTE_G5,NOTE_B5,NOTE_A5,REST,                      //0:31
  NOTE_G5,NOTE_FS5,REST,NOTE_FS5,REST,
  NOTE_A5,NOTE_G5,NOTE_D6,NOTE_B5,NOTE_A5,REST,

  NOTE_G5,NOTE_B4,NOTE_E5,NOTE_B5,NOTE_A5,REST,                      //0:35
  NOTE_G5,NOTE_FS5,REST,NOTE_FS5,REST,
  NOTE_A5,NOTE_G5,NOTE_FS5,NOTE_C6,NOTE_B5,NOTE_FS5,REST,

  //  CENTER
  NOTE_G5,REST,NOTE_G5,REST,NOTE_G5,REST,NOTE_FS5,REST,                        //0:40
  NOTE_E5,REST,NOTE_E5,REST,NOTE_F5,REST,
  NOTE_FS5,NOTE_G5,NOTE_A5,REST,NOTE_A5,REST,

  NOTE_B5,REST,NOTE_C6,REST,NOTE_B5,REST,NOTE_B5,REST,                           //0:43
  NOTE_A5,REST,NOTE_A5,NOTE_F5,REST,
  NOTE_F5,REST,NOTE_F5,REST,NOTE_F5,REST,NOTE_A5,REST,
  NOTE_E5,REST,NOTE_C6,NOTE_B5,NOTE_A5,NOTE_G5,NOTE_B5,REST,NOTE_A5,REST,
  NOTE_D6,REST,NOTE_C6,NOTE_B5,REST,NOTE_B5,REST,

  NOTE_C6,NOTE_B5,NOTE_A5,NOTE_B5,NOTE_A5,NOTE_G5,REST,                         //0:55
  NOTE_E5,REST,NOTE_E5,NOTE_C6,NOTE_B5,REST,NOTE_G5,NOTE_A5,REST,NOTE_A5,REST,
  NOTE_FS5,NOTE_G5,NOTE_A5,NOTE_B5,NOTE_C6,NOTE_B5,REST,

  NOTE_G5,NOTE_FS5,REST,NOTE_G5,NOTE_A5,REST,NOTE_A5,REST,NOTE_A5,REST,NOTE_A5,REST,     //1:02
  NOTE_G5,NOTE_FS5,NOTE_G5,REST,NOTE_E5,REST,NOTE_E5,

  NOTE_C6,NOTE_B5,NOTE_A5,NOTE_G5,NOTE_A5,REST,                                //1:08
  NOTE_FS5,REST,NOTE_FS5,NOTE_G5,NOTE_A5,NOTE_B5,REST,NOTE_B5,REST,
  NOTE_G5,NOTE_FS5,REST,NOTE_G5,NOTE_A5,NOTE_B5,NOTE_A5,NOTE_C6,NOTE_B5,REST,
  //END
  NOTE_E3,NOTE_FS3,NOTE_G3,NOTE_A3,NOTE_B3,REST,
};

int durations[] = {
  //OP
  4,4,4,4,2,16,                 //ok
  8,8,2,16,
  8,8,4,4,6,4,

  4,4,4,4,2,10,                 //ok
  8,10,16,2,8,
  8,6,4,4,4,6,10,

  4,4,4,4,2,4,                  //ok
  8,16,16,2,8,
  8,16,3,16,

  4,8,4,4,4,4,4,3,                //8
  4,8,10,10,2,4,
  8,8,4,4,4,4,

  4,4,4,4,2,8,                  //ok
  8,8,3,8,
  8,8,4,4,4.5,4,

  4,4,4,4,2,8,                  //ok
  8,16,16,2,4,
  8,6,4,4,4,8,16,

  4,4,4,4,2,4,                  //ok
  8,16,16,2,4,
  8,8,2,4,8,8,

  4,4,4,4,3,4,                  //ok
  8,16,16,2,4,
  8,8,4,4,4,8,16,
  // CENTER
  3,8,3,8,3,8,3,8,              //ok
  3,8,3,8,3,8,
  4,4,3,8,3,8,

  3,8,3,8,3,8,3,8,              
  3,8,3,8,16,
  3,8,3,8,3,8,3,8,                  //ok
  3,8,3,3,4,4,3,16,3,8,
  3,16,4,8,16,3,16,

  4,4,4,4,4,6,16,
  3,8,4,4,3,8,4,8,16,2,4,
  4,4,4,4,6,3,4,

  4,5,8,4,8,16,2,8,8,16,4,16,
  4,4,6,16,2,4,4,

  4,4,4,4,3,4,
  8,8,4,4,4,8,16,3,4,
  4,3,8,4,4,2,3,3,3,8,
  //END
  4,4,4,4,2,
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
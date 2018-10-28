// Voorbeeldprogramma om met een Arduino Leonardo een keyboard te maken
// Anthony Liekens 2018 voor Team Scheire, Sputnik Media, Canvas
// Voel je vrij om deze broncode te gebruiken of te misbruiken, maar deel je opgedane kennis met anderen

#include <Keyboard.h>

#define NBUTTONS 9

// pinnen waarop 9 knoppen aangesloten kunnen worden naar GND
int inputs[ NBUTTONS ] = { 
  18, // A0
  19, // A1
  20, // A2
  21, // A3
  22, // A4
  23, // A5
  0,  // D0
  1,  // D1
  2   // D2
};

// toetsenbordcode die doorgestuurd wordt voor elk van deze pinnen of knoppen
// we sturen de knoppen van het numerieke klavier op een toetsenbord door
int outputs[ NBUTTONS ] = {
  225, // NUMERIC 1
  226, // NUMERIC 2
  227, // NUMERIC 3
  228, // NUMERIC 4
  229, // NUMERIC 5
  230, // NUMERIC 6
  231, // NUMERIC 7
  232, // NUMERIC 8
  233  // NUMERIC 9
};

// we onthouden de toestand van de knop om hem ingedrukt te kunnen houden en terug te ontdrukken
int waarden[ NBUTTONS ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void setup() {

  // we initialiseren elke pin met een interne pullup
  for ( int i = 0; i < NBUTTONS; i++ ) {
    pinMode( inputs[ i ], INPUT_PULLUP );
  }

}

void loop() {

  // we checken elke knop
  for ( int i = 0; i < NBUTTONS; i++ ) {

    // lees de waarde van de knop uit (HIGH of LOW)
    int waarde = digitalRead( inputs[ i ] );

    // als de waarde LOW is, dan zijn we verbonden met GND
    if ( waarde == LOW ) {

      // als de vorige waarde HIGH was ...
      if ( waarden[ i ] == HIGH )
      
        // ... dan drukken we de knop in
        Keyboard.press( outputs[ i ] );
      
    } else {
      
      // we doen het omgekeerde als de knop niet meer ingedrukt is
      if ( waarden[ i ] == LOW )
        Keyboard.release(outputs[i]);
      
    }

    // we onthouden de huidige waarde voor de volgende iteratie
    waarden[ i ] = waarde;

  }

  // we wachten een tiende van een seconde voor we de knoppen opnieuw uitlezen
  delay(100);

}

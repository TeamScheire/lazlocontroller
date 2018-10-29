#include <Joystick.h>

int pins[9] = { 21, 22, 23, 18, 19, 20, 0, 1, 2 };
int press_count[9] = {0,0,0,0,0,0,0,0,0};


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  32, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {

  for( int i = 0; i < 9; i++ ) {
    pinMode( pins[ i ], INPUT_PULLUP );
  }

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
}

void checkbuttons() {
    for( int i = 0; i < 9; i++ ) {
    int state = digitalRead( pins[ i ] );
    if( state == LOW ) {
      
      if( press_count[ i ] == 0 ) {
        Joystick.setButton(i,1);
      }
      press_count[ i ] += 1; 
      
      if( ( i == 4 ) && ( press_count[4] > 2 ) ) { // SHOOT AFTER AIMING FOR 500ms
        Joystick.pressButton(9);
      }
      
    } else {
      
      if( press_count[ i ] != 0 )
        Joystick.setButton(i,0);
      press_count[ i ] = 0; 

      if( i == 4 ) { // STOP SHOOTING WHEN STOPPING AIMING
        Joystick.releaseButton(9);
      }

    }
  }
  
  delay(100);

}

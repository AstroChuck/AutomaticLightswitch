#include <Servo.h>
#include <IRremote.h>

#define HOME 0
#define LIGHTOUT 180

#define IR_ONE 0xFFA25D
#define IR_TWO 0x511DBB
#define IR_THREE 0xEE886D7F
#define IR_FOUR 0xFEAC02E5
#define IR_FIVE 0xFF02FD
#define IR_SIX 0xFFC23D
#define IR_SEVEN 0xFFE01F
#define IR_EIGHT 0xFFA857
#define IR_STAR 0xFF6897
#define IR_OCTOTHORPE 0xF0C4163
#define IR_UP 0xFF18E7
#define IR_DOWN 0xFF4AB5
#define IR_LEFT 0xFF10EF
#define IR_RIGHT 0xFF5AA5
#define IR_OK 0xFF38C7

Servo lightoff; //This servo turns the lights off

IRrecv irrecv(5);
decode_results results;

void setup() {
  lightoff.attach(9);
  lightoff.write(HOME);
  lightoff.detach();
  irrecv.enableIRIn();
}

void loop() {
if(irrecv.decode(&results)){
  if(results.value == IR_ONE){
    lightoff.attach(9);
    lightoff.write(LIGHTOUT);
    delay(2000);
    lightoff.write(HOME);
    delay(2000);
    lightoff.detach();
  }
  irrecv.resume();
}

}

/* 
 * Simple 4 ELD On/Off From IR Remote - Arduino
 * PHP Tutorial - https://youtu.be/8zw6BxW2LnU
 * GitHub - https://github.com/Nexample-G/Simple-4-ELD-On-Off-From-IR-Remote-Arduino
 * Dev: Nexample info.nexample@gmail.com
 */
#include <IRremote.h>
  IRrecv irrecv(A3);
  decode_results IR;
int ELD[]= {4, 5, 6, 7};
int NOD[]= {0, 0, 0, 0};
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  for (int otp = 0; otp < 3; otp++) {
  pinMode(ELD[otp], OUTPUT);
  }
}
void loop() {
  if (irrecv.decode(&IR)) {
switch(IR.value){
  case 0x1FE50AF:  ELDS(0);break;
  case 0x1FED827:  ELDS(1);break;
  case 0x1FEF807:  ELDS(2);break;
  case 0x1FE30CF:  ELDS(3);break;
default : break;}
     irrecv.resume();
  }
}
void ELDS(int nod){
  if(NOD[nod]){
    digitalWrite(ELD[nod], LOW);
    NOD[nod]=0;
    }else{
    digitalWrite(ELD[nod], HIGH);
    NOD[nod]=1;
      }
}

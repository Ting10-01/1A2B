int Rled=3, Gled=5, Bled=6;
int R=9, G=10, B=11;
int rgb[3], my_ans[3];;
int light[3] = {0, 0, 0};
int Buzzer = 2;
int dt = 200;
void setup() {
  Serial.begin(9600);
  pinMode(Rled, OUTPUT);
  pinMode(Gled, OUTPUT);
  pinMode(Bled, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}
//793
void loop(){
  Serial.println("Please enter 3 digits from 0 to 9:");
  rgb[0] = random(10);
  rgb[1] = random(10);
  rgb[2] = random(10);
  analogWrite(R, rgb[0]*25);
  analogWrite(G, rgb[1]*25);
  analogWrite(B, rgb[2]*25);
  while(1){
    for(int i=0; i<3; i++){
      my_ans[i] = Serial.read()-48;
      if(my_ans[i] == -49)
        i--;
    }
    for(int i=0; i<3; i++){
      Serial.print(my_ans[i]);
      light[i] = 0;
    }
    Serial.println("");
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        if(my_ans[i] == rgb[j]){
          if(i == j)
            light[i] = 10;
          else
            light[i] = 1;
        }
      }
    }
    analogWrite(Rled, light[0]);
    analogWrite(Gled, light[1]);
    analogWrite(Bled, light[2]);
    if(my_ans[0]==rgb[0] &&my_ans[1]==rgb[1] && my_ans[2]==rgb[2]){
      tone(Buzzer, 700, dt);
      delay(dt);
      tone(Buzzer, 740, dt);
      delay(dt);
      tone(Buzzer, 800, dt);
      delay(dt);
      tone(Buzzer, 850, dt*3);
      delay(dt*3);
      break;
    }
    else{
      tone(Buzzer, 700, dt);
      delay(dt);
      tone(Buzzer, 500, dt*2);
      delay(dt*2);
    }
  }
}

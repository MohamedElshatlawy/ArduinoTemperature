//LED >>PIN 13
//BUTTON>> PIN 2 
//TEMP sensor >>PIN A0
int tempsenpin = A0;
int readvalue;
float writevalue;

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;


void setup() {
  pinMode(tempsenpin, INPUT);
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}


void loop() {

digitalWrite(ledPin, state);
  getTempData();
  
}
void blink(){
  state=!state;
  Serial.print("pressed :");
  if(state)
  Serial.println("ON");
  else
    Serial.println("OFF");
}
void getTempData(){
  readvalue = analogRead(tempsenpin);
  writevalue = 500./1024. * readvalue; // convert volt to temp
  Serial.println(writevalue);
  delay(3000);

  
}


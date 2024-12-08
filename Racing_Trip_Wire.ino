// C++ code
//

int lightPin = 3;
boolean prevReading = false;

int ledPin = 13;
boolean ledState = false;

void setup()
{
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  prevReading = tripWire(ledPin, lightPin, prevReading);
}


boolean tripWire(int aLedPin, int aLightPin, boolean aPrevReading){
  int read = analogRead(aLightPin);
  Serial.println(read);
  boolean currentReading = false;
  if(read <= 800){
    currentReading = true;
  }else{
    currentReading = false;
  }
 
  if(currentReading == true && aPrevReading == false){
    ledState = !ledState;
    delay(50);
  }
  digitalWrite(ledPin, ledState);
  return currentReading;
}
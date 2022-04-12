int potPin = A0; //
int potDeger = 0; //

int kirmiziPin = 9;
int yesilPin = 10;
int maviPin = 11;

int kirmiziDeger = 0;
int yesilDeger = 0;
int maviDeger = 0;

void setup() {
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);
}

void loop() {
  potDeger = analogRead(potPin);

  if(potDeger < 341){
    potDeger = (potDeger * 3) / 4;

    kirmiziDeger = 255 - potDeger;
    yesilDeger = potDeger;
    maviDeger = 0;
  }
  else if (potDeger < 682){
    potDeger = ( (potDeger - 341) * 3) / 4;

    kirmiziDeger = 0;
    yesilDeger = 255 - potDeger;
    maviDeger = potDeger;
  }
  else{
    potDeger = ( (potDeger - 683) * 3) / 4;

    kirmiziDeger = potDeger;
    yesilDeger = 0;
    maviDeger = 255 - potDeger;
  }
  analogWrite(kirmiziPin,255 - kirmiziDeger);
  analogWrite(yesilPin,255 - yesilDeger);
  analogWrite(maviPin,255 - maviDeger);
}

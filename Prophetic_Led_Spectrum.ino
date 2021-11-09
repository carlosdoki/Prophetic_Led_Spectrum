#define RED D5
#define GREEN D3
#define BLUE D2

int sensorPin = A0; // input pin for the sensor
int sensorPin2 = D1;
int led = D6;

int sensorval = 0; // variable for the value coming from the sensor
int teste =0;
int teste2 = 0;

int valMax = 0;
int valMin = 1000;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin2, INPUT);

  pinMode(led, OUTPUT);
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);

}

void loop() {
    teste = analogRead(sensorPin);
  teste2 = digitalRead(sensorPin2);
  sensorval = teste*60;
  
   if (teste2 == 1) {
    digitalWrite(led, HIGH);
    Serial.println("=============");
    Serial.println(valMin);
    Serial.println(valMax);
    Serial.println(teste);
    
    if (valMax < teste) {
      valMax = teste;
    }

    if (valMin > teste) {
      valMin = teste;
    }

    if (teste > 842 && teste < 848) {
          analogWrite(BLUE, 0);
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    } else {
    
    if (teste > 840 ) {
      analogWrite(RED, 255);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
    }

    if (teste > 825 && teste < 840 ) {
      analogWrite(GREEN, 255);
      analogWrite(BLUE, 0);
      analogWrite(RED, 0);
    }

    if (teste < 825 ) {
      analogWrite(BLUE, 255);
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
    }

    }
  } else {
    digitalWrite(led, LOW);
    analogWrite(BLUE, 0);
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
  }
}

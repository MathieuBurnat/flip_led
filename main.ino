const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

bool buttonEnable = false;
bool state = false;
void loop() {
    int keyVal = analogRead(0);

    // Get button state, I want to know when tu button is releaed
    while(keyVal > 400){
      keyVal = analogRead(0);
      // Serial.println(keyVal);

      Serial.println("Button active");
      buttonEnable = true;
    }

    if (buttonEnable){
      Serial.println("Button released");
      buttonEnable = false;
      state = !state; //button released = change the state
      Serial.println(state);
    }

    if(state == 1){
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(ledPin, LOW);
    }

    delay(200);
}



#define LED_PIN 13
#define BUTTON_PIN 12

int led_state = LOW;
int button_state = LOW;
char message[] = "{\"id\":1,\"message\":0}";

void changeLedState(int state){
  if  (led_state == state){
    return;
  }
  
  led_state = state;
 
  digitalWrite(LED_PIN, led_state);
  message[18] = 48 + led_state;
  Serial.println(message);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    int incomingByte = Serial.read();

    if (incomingByte == 48){
      changeLedState(LOW);
    }

    
    if (incomingByte == 49){
      changeLedState(HIGH);
    }
  }
  
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTON_PIN) == HIGH){
  
    if (button_state == LOW){     
      changeLedState(!led_state);
      button_state = HIGH;
      delay(100);
    }
  }
  else if (button_state == HIGH){      
      button_state = LOW;
      delay(100);
  }
}

const int MOTION_SENSOR_PIN = 6;   // Arduino pin connected to the OUTPUT pin of motion sensor
const int RELAY_PIN         = 3;   // Arduino pin connected to the IN pin of relay
const int MAXH              = 1200; // DELAY during which no movement must occur for the system to trigger again
int sensor                  = LOW; // current  state of motion sensor's pin
int motionStatePrevious     = LOW; // previous state of motion sensor's pin
int lhigh                   = 1;

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode
  pinMode(RELAY_PIN, OUTPUT);        // set arduino pin to output mode
  pinMode(LED_BUILTIN, OUTPUT);
  bootup_init();
}

void loop(){
  digitalWrite(LED_BUILTIN, digitalRead(MOTION_SENSOR_PIN));
}

void bootup_init(){
  for (int i = 0; i < 2; i++) {
    digitalWrite(RELAY_PIN, HIGH);
    delay(300);
    digitalWrite(RELAY_PIN, LOW);
    delay(300);
  }
}

void ring_test(){
  for (int i = 0; i <= 3; i++) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  }
}

void ring_real(){
  for (int i = 0; i < 3; i++) {
    digitalWrite(RELAY_PIN, HIGH);
    delay(1500);
    digitalWrite(RELAY_PIN, LOW);
    delay(1500);
  }
}

void lewp(){
  delay(500);
  sensor  = digitalRead(MOTION_SENSOR_PIN);
  if(sensor == LOW){
    if(lhigh < (MAXH + 2)){
      lhigh++;
    }    
  }else{
    if(lhigh>MAXH){
      ring_real();      
    }
    lhigh=0; // reset after each movement
  }
  

}

// --- BLYNK DEFINITIONS ---
#define BLYNK_TEMPLATE_ID "TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "TOKEN"
#define BLYNK_PRINT Serial

#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// --- PIN DEFINITIONS ---
#define IR_SENSOR_PIN D7
#define SERVO_PIN     D3
#define TRIG_PIN      D1
#define ECHO_PIN      D5
#define BUZZER_PIN    D6

// --- WIFI & BLYNK SETUP ---
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "test";
char pass[] = "PASSWORD";

// --- GLOBAL OBJECTS ---
Servo s1;
BlynkTimer timer;
long duration;
int distance;

// ===================================================================
// SETUP
// ===================================================================
void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  s1.attach(SERVO_PIN);
  s1.write(0); 

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  timer.setInterval(2000L, sendSensorData); 
}

// ===================================================================
// LOOP
// ===================================================================
void loop() {
  Blynk.run();
  timer.run();
  checkLid();
}

// ===================================================================
// FUNCTION: checkLid
// Opens lid when hand is detected
// ===================================================================
void checkLid() {
  int irValue = digitalRead(IR_SENSOR_PIN);
  if (irValue == LOW) { 
    Serial.println("Hand Detected! Opening lid.");
    s1.write(60);  
    delay(3000);    
    s1.write(0);    
    delay(1000);    
  }
}


// ===================================================================
// FUNCTION: sendSensorData
// Reads ultrasonic sensor and updates Blynk
// ===================================================================
bool binFullFlag = false;
void sendSensorData() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Blynk.virtualWrite(V0, distance);

  if (distance > 0 && distance < 8) {
        Blynk.virtualWrite(V1, "Full"); 

        if (!binFullFlag) { 
            digitalWrite(BUZZER_PIN, HIGH);
            delay(200);      
            digitalWrite(BUZZER_PIN, LOW);
            binFullFlag = true;
        }
    } else {
        Blynk.virtualWrite(V1, String(distance) + " cm"); 
        binFullFlag = false; 
    }
}

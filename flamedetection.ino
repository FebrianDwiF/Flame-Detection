#include <ESP32Servo.h>
#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

// WiFi credentials
const char* ssid = "FebrianDwi";
const char* password = "passwordeopo";

// Telegram Bot Token and Chat ID
#define BOTtoken "7462598398:AAHx1lhPkVDvkD668H20UsNdPRGMytuzieQ" // your Bot Token
#define CHAT_ID "6533119946"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int apiSensorPin1 = 27;
const int apiSensorPin2 = 26;
const int apiSensorPin3 = 25;
const int apiSensorPin4 = 33;
const int apiSensorPin5 = 32;

const int BUZZER_PIN = 14;
const int RELAY_PIN = 12;
const int SERVO_PIN = 13;

bool rightDetected = false;
bool leftDetected = false;

Servo myServo;

// Function to connect to WiFi
void connectToWiFi() {
  Serial.print("Connecting to WiFi ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" connected");
}

// Function to set time using NTP
void setupTime() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  Serial.print("Waiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" time set");
}

void setup() {
  Serial.begin(115200);
  delay(1000); // Delay to stabilize Serial Monitor

  // Connect to Wi-Fi
  connectToWiFi();

  // Set up time
  setupTime();

  client.setInsecure();

  // Initialize sensor pins
  pinMode(apiSensorPin1, INPUT);
  pinMode(apiSensorPin2, INPUT);
  pinMode(apiSensorPin3, INPUT);
  pinMode(apiSensorPin4, INPUT);
  pinMode(apiSensorPin5, INPUT);

  // Initialize buzzer and relay pins
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Ensure the buzzer and relay are off initially
  digitalWrite(BUZZER_PIN, HIGH);  
  digitalWrite(RELAY_PIN, LOW);  

  // Initialize servo
  myServo.attach(SERVO_PIN);
  myServo.write(90);  // Center the servo

  // Test Telegram connection
  if (bot.sendMessage(CHAT_ID, "Bot is connected", "")) {
    Serial.println("Telegram message sent successfully");
  } else {
    Serial.println("Failed to send Telegram message");
  }
}

void loop() {
  int api1Value = digitalRead(apiSensorPin1);
  int api2Value = digitalRead(apiSensorPin2);
  int api4Value = digitalRead(apiSensorPin4);
  int api5Value = digitalRead(apiSensorPin5);

  // Check if fire is detected on the right side
  if (api1Value == HIGH && api2Value == HIGH) {
    if (!rightDetected) {
      Serial.println("Api terdeteksi di sebelah kanan");
      Serial.println("Servo bergerak ke kanan");
      digitalWrite(BUZZER_PIN, LOW);  // Activate buzzer
      digitalWrite(RELAY_PIN, HIGH);   // Activate relay (turn on pump)

      myServo.write(45);  // Turn servo to 45 degrees to the right
      delay(200); // Give time for servo to move

      // Send notification to Telegram
      String message = "Api terdeteksi di sebelah kanan!";
      if (bot.sendMessage(CHAT_ID, message, "")) {
        Serial.println("Telegram message sent successfully");
      } else {
        Serial.println("Failed to send Telegram message");
      }

      rightDetected = true;
      leftDetected = false;
    }
  } 
  // Check if fire is detected on the left side
  else if (api4Value == HIGH && api5Value == HIGH) {
    if (!leftDetected) {
      Serial.println("Api terdeteksi di sebelah kiri");
      Serial.println("Servo bergerak ke kiri");
      digitalWrite(BUZZER_PIN, LOW);  // Activate buzzer
      digitalWrite(RELAY_PIN, HIGH);   // Activate relay (turn on pump)

      myServo.write(135);  // Turn servo to 135 degrees to the left
      delay(200); // Give time for servo to move

      // Send notification to Telegram
      String message = "Api terdeteksi di sebelah kiri!";
      if (bot.sendMessage(CHAT_ID, message, "")) {
        Serial.println("Telegram message sent successfully");
      } else {
        Serial.println("Failed to send Telegram message");
      }

      leftDetected = true;
      rightDetected = false;
    }
  } 
  // If no fire is detected on either side, turn off the buzzer and relay, and center the servo
  else {
    if (rightDetected || leftDetected) {
      Serial.println("Tidak ada api terdeteksi, servo kembali ke tengah");
    }
    digitalWrite(BUZZER_PIN, HIGH);  // Deactivate buzzer
    digitalWrite(RELAY_PIN, LOW);   // Deactivate relay
    myServo.write(90);  // Center the servo

    rightDetected = false;
    leftDetected = false;
  }

  delay(500); // Delay for reading the sensors every 500 milliseconds
}

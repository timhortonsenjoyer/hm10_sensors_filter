#include <ArduinoBLE.h>

const char* HM10address_1 = "insert address 1";
const char* HM10address_2 = "insert address 2";
const char* HM10address_3 = "insert address 3";
const char* HM10address_4= "insert address 4";
unsigned long time_on;
unsigned long start_time;
unsigned long time_on_one;
unsigned long time_on_two;
unsigned long time_on_three;
unsigned long time_on_four;
unsigned long time_on_a;
unsigned long time_on_b;
unsigned long time_on_c;
unsigned long time_on_d;
unsigned long time_end=0;
unsigned long time_on_temp=0;



void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Starting Bluetooth- Low Energy module failed!");
    while (1);
  }

  Serial.println("Scanning for HM-10s");
  BLE.scan(); 
  Serial1.begin(9600);  
  delay(100);
  start_time = millis();
}

void loop() {
  time_on_a = millis();
  connect_to_one(HM10address_1,time_on_a,time_end);
  time_on_b = millis();
  connect_to_two(HM10address_2,time_on_b,time_on_a);
  time_on_c = millis();
  connect_to_three(HM10address_3,time_on_c,time_on_b);
  time_on_d = millis();
  connect_to_four(HM10address_4,time_on_d,time_on_c);
  time_end = millis();
}
void connect_to_one(const char*address_one,unsigned long time,unsigned long time2){
  BLEDevice peripheral = BLE.available();
  if(address_one==HM10address_1){
      Serial.println(" The first HM-10 was found!");
      peripheral.connect();
      Serial.println("The time took to connect was: ");
      time_on_one = time-time2;
      Serial.print(time_on_one);
      delay(50);
      peripheral.disconnect();
    }

}
void connect_to_two(const char*address_two,unsigned long time,unsigned long time2){
  BLEDevice peripheral = BLE.available();
  if(address_two==HM10address_2){
      Serial.println(" The second HM-10 was found!");
      peripheral.connect();
      Serial.println("The time took to connect was: ");
      time_on_two = time-time2-50;
      Serial.print(time_on_two);
      delay(50);
      peripheral.disconnect();
    }

}

void connect_to_three(const char*address_three,unsigned long time,unsigned long time2){
  BLEDevice peripheral = BLE.available();
  if(address_three==HM10address_3){
      Serial.println(" The third HM-10 was found!");
      peripheral.connect();
      Serial.println("The time took to connect was: ");
      time_on_three = time-time2-50;
      Serial.print(time_on_three);
      delay(50);
      peripheral.disconnect();
    }

}

void connect_to_four(const char*address_four,unsigned long time,unsigned long time2){
  BLEDevice peripheral = BLE.available();
  if(address_four==HM10address_4){
      Serial.println(" The fourth HM-10 was found!");
      peripheral.connect();
      Serial.println("The time took to connect was: ");
      time_on_four = time-time2-50;
      Serial.print(time_on_four);
      delay(50);
      peripheral.disconnect();
    }

}

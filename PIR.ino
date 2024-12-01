#define PIR D6
#define coi D5
 #define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "fEzqZpVLGSIdWXZti1fGSzZxADnsOEJ_";

char ssid[] = "Thu Thao";  //Đổi tên Wifi
char pass[] = "917664ab";  //Đổi mật khẩu Wifi
long times;
void setup() {
  // SET Chân IO
  Serial.begin(9600);
  pinMode(PIR, INPUT_PULLUP);  //Set ngõ vào
  pinMode(coi, OUTPUT);    //Set ngõ ra
 Blynk.begin(auth, ssid, pass,"blynk-server.com",8080);
 digitalWrite(coi, HIGH);
  delay(1000);
  digitalWrite(coi, LOW);
    times = millis();
}

void loop() {
  Blynk.run();
  // put your main code here, to run repeatedly:
  if (digitalRead(PIR) == 0) { //Nếu cẩm biến xuất tín hiệu là 0 thì sau 5 phút còi ngừng kêu
    if (millis() - times > 300000) {
      digitalWrite(coi, LOW);
    }
  }
  
  if (digitalRead(PIR) == 1) {  //Nếu tín hiệu từ cảm biến là 1 thì còi sẽ kêu liên tục đến khi không có tín hiệu
    times = millis();
    digitalWrite(coi, HIGH);
    Blynk.notify("THÔNG BÁO: CÓ VẬT CẢN ĐI QUA");//Thông báo lên app
    }
}

#include <M5StickC.h>

#include <VNC_M5STICKC.h>
#include <VNC.h>

const char * vnc_ip = "192.168.XX.XX"; //VNC Server IP
const uint16_t vnc_port = 5900;
const char * vnc_pass = ""; //No password

const char* ssid = "Your WIFI SSID";
const char* password = "Your WIFI Password";

M5STICKCVNC tft = M5STICKCVNC();
arduinoVNC vnc = arduinoVNC(&tft);

void setup(void) {
    M5.begin();
    Serial.begin(115200);

    M5.Lcd.setRotation(3);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setCursor(0, 0, 1);
    M5.Lcd.println("Ready");

    Serial.setDebugOutput(true);
    Serial.println();
    Serial.println();
    Serial.println();

    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println(F("[SETUP] VNC..."));

    vnc.begin(vnc_ip, vnc_port);
    //vnc.setPassword(vnc_pass); // check for vnc server settings
}

void loop() {
    if(WiFi.status() != WL_CONNECTED) {
        vnc.reconnect();
        delay(100);
    } else {
        vnc.loop();
        if(!vnc.connected()) {
            delay(5000);
        }
    }
}

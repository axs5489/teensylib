#define p1 Serial1
#define p2 Serial2

int ind1 = 0, ind2 = 0;
String buf1 = "", buf2 = "";

void setup() {
   Serial.begin(9600);
   Serial1.begin(9600);
   Serial2.begin(9600);
   p1.begin(9600);
   p2.begin(9600);
}

void loop() {
   while(p1.available() or buf1.length())
   {
      while(p1.available()) {
         buf1 += p1.read();
      }
      ind1 = buf1.indexOf('\n');
      if(ind1 > 0) {
         Serial.print(buf1.substring(0,ind1));
         buf1 = buf1.substring(ind1);
      }
      delay(1);
   }
   
   while(p2.available() or buf2.length())
   {
      while(p2.available()) {
         buf2 += p2.read();
      }
      ind2 = buf2.indexOf('\n');
      if(ind2 > 0) {
         Serial.print(buf2.substring(0,ind2));
         buf2 = buf2.substring(ind2);
      }
      delay(1);
   }
}

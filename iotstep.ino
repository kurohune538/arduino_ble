const int LED = 13;
int rsvData = 0;
int leftOrRight,thumb,child,kakato,accelX,accelY,accelZ = 0;
byte sendData[14];
void setup()
{
//Serial.begin(9600);
  Serial1.begin(9600);
//  while (!Serial) {
//    ; // シリアルポートが開くのを待つ。
//  }
}

void loop()
{
  // 受信処理
  if(Serial1.available() > 0){
//    rsvData = Serial.read();
    rsvData = Serial1.read();
    if(rsvData == 1){ 
      digitalWrite(LED, HIGH);
    }
    else if(rsvData == 0){
      digitalWrite(LED, LOW);
    } 
  } 

  //センサー読み取り～送信
  leftOrRight = 0;
  thumb = analogRead(A0);
  child = analogRead(A1);
  kakato = analogRead(A2);
  accelX = analogRead(A3);
  accelY = analogRead(A4);
  accelZ = analogRead(A5);

  Serial1.write(leftOrRight);
  Serial1.write(thumb);
  Serial1.write(child);
  Serial1.write(kakato);
  Serial1.write(accelX);
  Serial1.write(accelY);
  Serial1.write(accelZ);
  //Serial.write(sendData,14);
//  Serial.println(leftOrRight);
//  Serial.println(thumb);
//  Serial.println(child);
//  Serial.println(kakato);
//  Serial.println(accelX);
//  Serial.println(accelY);
//  Serial.println(accelZ);
  //ウェイト

  delay(500);
}


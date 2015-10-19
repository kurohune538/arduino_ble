const int LED = 13;
int rsvData = 0;
int leftOrRight,thumb,child,kakato,accelX,accelY,accelZ,gyroX,gyroY,gyroZ,conpX,conpY,conpZ,airPress = 0;
byte sendData[14];
void setup()
{
//Serial.begin(9600);
  Serial1.begin(9600);
//  while (!Serial) {
//    ; // シリアルポートが開くのを待つ。
//  }
  pinMode(LED,OUTPUT);

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
  leftOrRight = 1;
  thumb = analogRead(A0);
  child = analogRead(A1);
  kakato = analogRead(A2);
//  sendData[0] = leftOrRight;
//  sendData[1] = thumb;
//  sendData[2] = child;
//  sendData[3] = kakato;
//  sendData[4] = accelX;
//  sendData[5] = accelY;
//  sendData[6] = accelZ;
//  sendData[7] = gyroX;
//  sendData[8] = gyroY;
//  sendData[9] = gyroZ;
//  sendData[10] = conpX;
//  sendData[11] = conpY;
//  sendData[12] = conpZ;
//  sendData[13] = airPress;
  Serial1.write(leftOrRight);
  Serial1.write(thumb);
  Serial1.write(child);
  Serial1.write(kakato);
  //Serial.write(sendData,14);
//  Serial.println(leftOrRight);
//  Serial.println(thumb);
//  Serial.println(child);
//  Serial.println(kakato);
  //ウェイト

  delay(500);
}


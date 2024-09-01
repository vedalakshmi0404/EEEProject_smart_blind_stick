const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;
const int beepDistance1 = 25; 
const int beepDistance2 = 20; 
const int beepDistance3 = 15; 
const int beepDistance4 = 10; 
const int beepDistance5 = 3; 
void playSetupMelody() 
{
 tone(buzzerPin, 523); 
 delay(150);
 noTone(buzzerPin);
 delay(50);
 
 tone(buzzerPin, 587); 
 delay(150);
 noTone(buzzerPin);
 delay(50);
 
 tone(buzzerPin, 659); 
 delay(150);
 noTone(buzzerPin);
 delay(50);
 
 tone(buzzerPin, 698); 
 delay(150);
 noTone(buzzerPin);
 delay(50);
 
 tone(buzzerPin, 784); 
 delay(150);
 noTone(buzzerPin);
 delay(50);
 
 tone(buzzerPin, 880); 
 delay(150);
 noTone(buzzerPin);
7
}
void setup() 
{
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzerPin, OUTPUT);
 playSetupMelody();
}
void loop() 
{
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 long duration = pulseIn(echoPin, HIGH);
 int distance = duration * 0.034 / 2;
 Serial.print("Distance: ");
 Serial.print(distance);
 Serial.println(" cm");
 if (distance <= beepDistance1 && distance > beepDistance2) 
{
 tone(buzzerPin, 1000); 
 delay(1000);
 noTone(buzzerPin);
 delay(200); // Wait for 200 ms
 } 
else if (distance <= beepDistance2 && distance > beepDistance3) 
{
 tone(buzzerPin, 1000); 
 delay(750);
 noTone(buzzerPin);
 delay(200); // Wait for 100 ms
 } 
else if (distance <= beepDistance3 && distance > beepDistance4) 
{
 tone(buzzerPin, 1000);
 delay(500);
 noTone(buzzerPin);
 delay(200); // Wait for 50 ms
8
 } 
else if (distance <= beepDistance4 && distance > beepDistance5) 
{
 tone(buzzerPin, 1000); 
 delay(250);
 noTone(buzzerPin);
 delay(100); // Wait for 25 ms
 } 
else if (distance <= beepDistance5 && distance > 0) 
{
 tone(buzzerPin, 1000); 
 delay(125);
 noTone(buzzerPin);
 delay(100); // Wait for 25 ms
 }
else 
{
 delay(1); 
 }
}

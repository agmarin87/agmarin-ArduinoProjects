// Traffic light for car and pedestrian.

int carRed = 12; // For the car traffic lights
int carYellow = 11;
int carGreen = 10;
int pedestrianRed = 9; // For the pedestrian traffic lights
int pedestrianGreen = 8;
int button = 2; // button pin
int crossTime = 4000; // time allowed to cross
unsigned long changeTime;

void setup() {
pinMode(carRed, OUTPUT);
pinMode(carYellow, OUTPUT);
pinMode(carGreen, OUTPUT);
pinMode(pedRed, OUTPUT);
pinMode(pedGreen, OUTPUT);
pinMode(button, INPUT);

digitalWrite(carGreen, HIGH);
digitalWrite(pedRed, HIGH);
}

void loop() {
int state = digitalRead(button);
/* Checking the button and if it was pressed over 5 seconds since last button press */
if (state == HIGH && (millis() - changeTime) > 5000) {
// Call the function to change the lights
changeLights();
}
}

void changeLights() {
delay(3000); //wait 3 seconds for the yellow light
digitalWrite(carGreen, LOW); // green off
digitalWrite(carYellow, HIGH); // yellow on
delay(2000); // wait 2 seconds
digitalWrite(carYellow, LOW); // yellow off
digitalWrite(carRed, HIGH); // red on
delay(1000); // wait 1 second till its safe for the pedestrian
digitalWrite(pedRed, LOW); // ped red off
digitalWrite(pedGreen, HIGH); // ped green on
delay(crossTime); // wait for preset time period
// flash the pedestrian green
for (int x=0; x<8; x++) {
digitalWrite(pedGreen, HIGH);
delay(250);
digitalWrite(pedGreen, LOW);
delay(250);
}
// turn ped red on
digitalWrite(pedRed, HIGH);
delay(500);
digitalWrite(carYellow, HIGH); // yellow on
digitalWrite(carRed, LOW); // red off
delay(2000);
digitalWrite(carGreen, HIGH);
digitalWrite(carYellow, LOW); // yellow off
// record the time since last change of lights
changeTime = millis();
}

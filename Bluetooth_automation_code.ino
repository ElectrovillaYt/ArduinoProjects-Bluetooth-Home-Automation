#define OUT 2 // Defining Digital Pin-2 of Arduino as Output for the Relay.

char val; // varaiable to store incoming character via Bluetooth on RX pin.

void setup() { // Setting up Output.
  pinMode(OUT, OUTPUT);

  Serial.begin(9600); // sarting serial monitor at baud-rate of 9600 to read the incoming value in the serial monitor if required!
}

void loop() {
  if (Serial.available() == 1) {  // reading incoming value if available and storing it into ( char ) variable.
    val = Serial.read();
  }

  if (val == 'A') {
    Serial.println("Out_ON");  // You can remove this line if don't want to read value on the serial monitor!
    digitalWrite(OUT, HIGH);   // if condition is true then Turn ON the Relay.
  } else if (val == 'a') {
    Serial.println("Out_OFF"); // optional as line 17!
    digitalWrite(OUT, LOW); // if upper condition is false and this condition is true then Turn OFF the Relay.
  }
}

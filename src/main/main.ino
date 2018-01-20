void setup() {
  Serial.begin(9600);
  setup_wifi();
  Serial.print("wifi ok");
}


void loop() {
  loop_wifi();
}

void setup() {
  Serial.begin(115200);
  setup_wifi();

  send_message("A1:Hello 24h du code!");
}


void loop() {
  loop_wifi();
}

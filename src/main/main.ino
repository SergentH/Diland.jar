void setup() {
  Serial.begin(115200);
  setup_wifi();

  send_message("Hello from Aspicot");
  send_message("A1:Hello 24h du code!");
}

String response;

void loop() {
  loop_wifi();
  response = return_response();
  Serial.println(response);
}

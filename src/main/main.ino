
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  follow(10);
  // put your main code here, to run repeatedly:
  //loop_nfc();
  Serial.println(loop_nfc());
}

  setup_nfc();
  Serial.begin(9600);
  setup_move();
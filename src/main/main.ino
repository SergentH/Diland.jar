void setup() {
  // put your setup code here, to run once:
  setup_move();
  for(int i=0;i<100;i++){
    move(i,i);
    delay(100);
  }
  move(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:

}

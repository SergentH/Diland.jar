
String magneton(String enonce){
  int vitesse=8;
  int porte=1;
  rot90(1);
  move(vitesse,vitesse);
  delay(3000);
  stop();
  rot90(1);
  if(havePorte()){
    Serial.println("Porte 1");
    rot90(1);
    while(ligneG()==0){
      move(vitesse,vitesse);
    }
    stop();
    rot90(1);
    porte=1;
    //return "porte"+porte;
  }else{
    rot90(1);
    delay(100);
    rot90(1);
    move(vitesse,vitesse);
    delay(3000);
    rot90(1);
    if(havePorte()){
      porte = 2;
      Serial.println("porte 2");
    }else{
      porte = 3;
      Serial.println("Porte 3");
    }
    rot90(1);
    delay(100);
    rot90(1);
    while(ligneG()==0){
      move(vitesse,vitesse);
    }
    stop();
    rot90(1);
    //return "porte"+porte;
  }
}

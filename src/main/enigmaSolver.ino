void circuit(){//A2
  
}

void dj(String strMusic){//A3 A valider
  const char* music =strMusic.c_str();
  int note;
  for (int k=0; k<strlen(music);k++){
    switch (music[k]) {
      case 'C':
      if(k < strlen(music) && music[k+1]=='#'){
        note = 277;
        k++;
      }
      else{
        note = 262;
      }
      break;
      
      case 'D':
      if(k < strlen(music) && music[k+1]=='#'){
        note = 311;
        k++;
      }
      else{
        note=294;
      }
      break;
      
      case 'E':
      note =330;
      break;
      
      case 'F':
      if(k < strlen(music) && music[k+1]=='#'){
        note = 370 ;
        k++;
      }
      else{
        note=349;
      }
      break;
      
      case 'G':
      if(k < strlen(music) && music[k+1]=='#'){
        note = 415;
        k++;
      }
      else{
        note=392;
      }
      break;
      
      case 'A':
      if(k < strlen(music) && music[k+1]=='#'){
        note = 466;
        k++;
      }
      else{
        note=440;
      }
      break;
      
      case 'B':
        note = 494;
      break;
      
      default:Serial.print("!!!!!!!!!!!!Error in note !!!!!!!!!!!!\n");
      // statements
    }
    tone(PIN_BUZZER, note,167);
    delay(187);//loose time at the last, minor problem
  }
}

void 360(){
  
}

void swipe(){
  
}

String crypto(char enonce[]){//A revoir !
  String decode;
//  for(int i=0;i<26;i++){
//    for(int j;j<strlen(enonce);j++){
//    enonce
//  }
  return decode;
}

void swipe(){
  
}

void spydj(String enonce,String key){
//crypt music

//play music
}

void ble(){
  
}

String magneton(){
  
  return "porte"+numPorte;
}

String memory(String enonce){//ultra HARDCORE
  
}

void victoire(){//here, yolo mode
  
}


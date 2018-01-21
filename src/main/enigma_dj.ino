String dj(String strMusic){//A3 A valider
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
  return strMusic;
}

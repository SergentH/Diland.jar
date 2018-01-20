#define C  262
#define C# 277
#define D  294
#define D# 311
#define E  330
#define F  349
#define F# 370
#define G  392
#define G# 415
#define A  440
#define A# 466
#define B  494


void circuit(){//A2
  
}

void dj(char music[]){//A3 A valider
  int note;
  for (int k=0; k<strlen(music);k++){
    note = null;
    note = music[k];
    if(k < strlen(music) && music[k+1]=="#"){
      note = note+"#";
      k++;
    }
    tone(PIN_BUZZER, note);
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

String memory(enonce){//ultra HARDCORE
  
}

void victoire(){//here, yolo mode
  
}


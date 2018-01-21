String spydj(String strEnonce){//A7
  Serial.println("Début enigne spyDj");
  const char* music =strEnonce.c_str();
  int note;
  int delayB = 187, timeB = 167;
  String partition;//init at the beginning
  for (int k=0; k<strlen(music);k++){
    switch (music[k]) {
      case 'P': partition+="C";
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
      break;
      
      case 'T':partition+="CC";
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
      break;
      
      case 'D':partition+="CCC";
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
      break;
      
      case 'V':partition+="CCCC";
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
      break;
      
      case 'W':partition+="CCCC";
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 262,timeB);
          delay(timeB);
      break;
      
      case 'M':partition+="D";
          tone(PIN_BUZZER, 294,timeB);
          delay(timeB);
      break;

      case 'L':partition+="DD";
          tone(PIN_BUZZER, 294,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 294,timeB);
          delay(timeB);      
      break;
      
      case 'J':partition+="DDD";
          tone(PIN_BUZZER, 294,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 294,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 294,timeB);
          delay(timeB); 
      break;

      case 'O':partition+="E";
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
      break;
      
      case 'I':partition+="EE";
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
      break;
      
      case 'F':partition+="EEE";
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
      break;
      
      case 'X':partition+="EEEE";
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 330,timeB);
          delay(timeB);
      break;
      
      case 'N':partition+="F";
          tone(PIN_BUZZER, 349,timeB);
          delay(timeB);
      break;
      
      case 'A':partition+="FF";
          tone(PIN_BUZZER, 349,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 349,timeB);
          delay(timeB);
      break;
      
      case 'Q':partition+="FFF";
          tone(PIN_BUZZER, 349,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 349,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 349,timeB);
          delay(timeB);
      break;
      
      case 'K':partition+="G";
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
      break;
      
      case 'C':partition+="GG";
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
      break;
      
      case 'G':partition+="GGG";
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
      break;  
      
      case 'Y':partition+="GGGG";
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 392,timeB);
          delay(timeB);
      break;
      
      case 'S':partition+="A";
          tone(PIN_BUZZER, 440,timeB);
          delay(timeB);
      break;
      
      case 'B':partition+="AA";
          tone(PIN_BUZZER, 440,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 440,timeB);
          delay(timeB);
      break;
      
      case 'U':partition+="AAA";
          tone(PIN_BUZZER, 440,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 440,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 440,timeB);
          delay(timeB);
      break;
      
      case 'E':partition+="B";
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
      break;
      
      case 'R':partition+="BB";
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
      break;
      
      case 'H':partition+="BBB";
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
      break;
      
      case 'Z':partition+="BBBB";
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
          tone(PIN_BUZZER, 494,timeB);
          delay(timeB);
      break;

      default:Serial.print("!!!!!!!!!!!!Error in note !!!!!!!!!!!!\n");
    }
  }
  Serial.println("Fin enigne spyDj");
  return partition;
}
//END

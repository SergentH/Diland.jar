<<<<<<< Updated upstream
String parsing(char information[]){
  String theme,id,enonce,key,porte;//key it's for the A7 SpyDj
  char[] information;
  int i=0;
  // Read each command pair 
  char* parse = strtok(information, ":");
  while (information != NULL){
   // printf ("%s\n",pch);
   if (i=0){
    theme = strtok (NULL, ":");
    i++;
   }
   else if (i=1){
    id = strtok (NULL, ":");
    i++;
   }
   else if (i=2){
    enonce = strtok (NULL, ":");
    i++;
   }
   else if (i=3){//Here, if it's A7 (spyDj)
    key = strtok (NULL, ":");
   }
   else{
    Serial.print("Information is longer than 4 data");
   }
  }
   
  if(strcmp("circuit", theme) == 0){//A2
    circuit();
    return id+":"+enonce;
  }
  if(strcmp("dj", theme) == 0){//A3
    dj();
    return id+":"+enonce;
  }
  if(strcmp("360", theme) == 0){//A4
    360();
    return id+":"+enonce;
  }
  if(strcmp("crypto", theme) == 0){//A5
    return id+":"+crypto(enonce);
  }
  if(strcmp("swipe", theme) == 0){//A6
    swipe();
    return id+":"+enonce;
  }
  if(strcmp("spydj", theme) == 0){//A7
    return id+":"+spydj(enonce, key);
  }
  if(strcmp("ble", theme) == 0){//A8
    ble();
    return id+":"+enonce;
  }
  if(strcmp("magnéton", theme) == 0){//A9
    porte = magneton();
    return id+":"+porte;
  }
  if(strcmp("memory", theme) == 0){//A10
    return id+":"+memory(enonce);
  }
  if(strcmp("victoire", theme) == 0){//11
    victoire();
  }
  default:
    Serial.print("ERROR, unknown theme!");
}

=======
String parsing(char information[]){ 
  String theme,id,enonce,key,porte;//key it's for the A7 SpyDj 
  char[] information; 
  int i=0; 
  // Read each command pair  
  char* parse = strtok(information, ":"); 
  while (information != NULL){ 
   // printf ("%s\n",pch); 
   if (i=0){ 
    theme = strtok (NULL, ":"); 
    i++; 
   } 
   else if (i=1){ 
    id = strtok (NULL, ":"); 
    i++; 
   } 
   else if (i=2){ 
    enonce = strtok (NULL, ":"); 
    i++; 
   } 
   else if (i=3){//Here, if it's A7 (spyDj) 
    key = strtok (NULL, ":"); 
   } 
   else{ 
    Serial.print("Information is longer than 4 data"); 
   } 
  } 
    
  if(strcmp("circuit", theme) == 0){//A2 
    circuit(); 
    return id+":"+enonce; 
  } 
  if(strcmp("dj", theme) == 0){//A3 
    dj(); 
    return id+":"+enonce; 
  } 
  if(strcmp("360", theme) == 0){//A4 
    360(); 
    return id+":"+enonce; 
  } 
  if(strcmp("crypto", theme) == 0){//A5 
    return id+":"+crypto(enonce); 
  } 
  if(strcmp("swipe", theme) == 0){//A6 
    swipe(); 
    return id+":"+enonce; 
  } 
  if(strcmp("spydj", theme) == 0){//A7 
    return id+":"+spydj(enonce, key); 
  } 
  if(strcmp("ble", theme) == 0){//A8 
    ble(); 
    return id+":"+enonce; 
  } 
  if(strcmp("magnéton", theme) == 0){//A9 
    porte = magneton(); 
    return id+":"+porte; 
  } 
  if(strcmp("memory", theme) == 0){//A10 
    return id+":"+memory(); 
  } 
  if(strcmp("victoire", theme) == 0){//11 
    victoire(); 
  } 
  default: 
    Serial.print("ERROR, unknown theme!"); 
} 
>>>>>>> Stashed changes

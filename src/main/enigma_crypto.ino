String crypto(String strTexte){
  Serial.println("Début enigme crypto");
  const char* texte =strTexte.c_str();
  char solution[strlen(texte)+1];
  memset(solution,'\0',strlen(texte)+1); 
  int decallage=8;
    int i;
    for(i=0 ; i<strlen(texte); i++){
        /* Si le caractere est une minuscule */
        if ('a' <= texte[i] && texte[i] <= 'z'){
            solution[i] = 'a' + ((texte[i] - 'a') + decallage)%26;
        }
        else{
            /* Si le caractere est une majuscule */
            if ('A' <= texte[i] && texte[i] <= 'Z'){
                solution[i] = 'A' + ((texte[i] - 'A') + decallage)%26;
            }
            else{
                /* Si le caractere est un chiffre */
                if ('0' <= texte[i] && texte[i] <= '9'){
                    solution[i] = '0' + ((texte[i] - '0') + decallage)%10;
                }
                else
                {
                    Serial.print("!!!!!!!Traduction is not possible, it's not a letter or a number !!!!!!!");
                }
            }
        }
    }
        Serial.print("Solution crypto :");
        Serial.println(solution);
        return solution;
}


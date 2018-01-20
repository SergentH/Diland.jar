String crypto(String strTexte){
  const char* texte =strTexte.c_str();
  int decallage=8;
    int i;
    for(i=0 ; i<strlen(texte) ; i++)
        /* Si le caractere est une minuscule */
        if ('a' <= texte[i] && texte[i] <= 'z'){
            texte[i] = 'a' + ((texte[i] - 'a') + decallage)%26;
        }
        else{
            /* Si le caractere est une majuscule */
            if ('A' <= texte[i] && texte[i] <= 'Z'){
                texte[i] = 'A' + ((texte[i] - 'A') + decallage)%26;
            }
            else{
                /* Si le caractere est un chiffre */
                if ('0' <= texte[i] && texte[i] <= '9'){
                    texte[i] = '0' + ((texte[i] - '0') + decallage)%10;
                }
                else
                {
                    Serial.print("!!!!!!!Traduction is not possible, it's not a letter or a number !!!!!!!");
                }
            }
        }
}


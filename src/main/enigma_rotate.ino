String rotate(String enonce){
  int tempsTour = 1100;
  boolean flip=true;
  int vitesse;
  int nbTour=0;
  int taille = strlen(enonce.c_str());
  const char* data = enonce.c_str();
  Serial.println(taille);
  Serial.println("Début enigme rotate");
   //Un seul coté
  if(data[1]=='C'){ //CCWn
      move(-50,50);
      Serial.print(atoi(&data[3]));
      Serial.print(" tour en CCW");
      while(nbTour<=2*atoi(&data[3])){
         if(ligneD()==false){
          flip=true;
        }
        if(ligneD() && flip){
          nbTour++;
          Serial.println(nbTour);
          flip=false;
        }
      }
      /*for(int i=0; i<atoi(&data[3]);i++){
        delay(tempsTour);
      }*/
  }else{ //CWn
      Serial.print(atoi(&data[2]));
      Serial.println(" tour en CW");
      move(50,-50);
      while(nbTour<=2*atoi(&data[2])){
        if(ligneG==false){
          flip=true;
        }
        if(ligneG() && flip){
          nbTour++;
          Serial.println(nbTour);
          flip=false;
        }
      }
      /*for(int i=0; i<atoi(&data[2]);i++){
        delay(tempsTour);
      }*/
  }
  nbTour=0;
  if(taille>=5){//double rotation
    Serial.println("Deux sens");
    if(data[taille-4]=='C'){ //CCWn
        Serial.print(atoi(&data[taille-1]));
        Serial.print(" tour en CCW");
        move(-50,50);
        while(nbTour<=2*atoi(&data[taille-1])){
           if(ligneD()==false){
            flip=true;
            }
           if(ligneD() && flip){
            nbTour++;
            Serial.println(nbTour);
            flip=false;
          }
        }
        /*for(int i=0; i<atoi(&data[taille-1]);i++){
          delay(tempsTour);
        }*/
    }else{ //CWn
        Serial.print(atoi(&data[taille-1]));
        Serial.println(" tour en CW");
        move(50,-50);
        while(nbTour<=2*atoi(&data[taille-1])){
          if(ligneG()==false){
            flip=true;
          }
          if(ligneG() && flip){
            nbTour++;
            Serial.println(nbTour);
            flip=false;
          }
        }
        /*for(int i=0; i<atoi(&data[taille-1]);i++){
          delay(tempsTour);
        }*/
    }
  }
  move(0,0);
  Serial.println("Fin tour");

  return enonce;
}

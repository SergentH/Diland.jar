/*
    Parser for the data received by the NFC reader.
*/

const char* parsing(char *rawdata){ 
    const static String sep(":");

    int i = 0;
    String args[4];
    char *token;
    String ret;

    // Parsing data
    token = strtok(rawdata, sep.c_str()); 
    do{
        args[i] = String(token);
        i++;
    }while((token = strtok(NULL, sep.c_str())));


    Serial.println("--- DEBUG(parser.ino) ---");
    Serial.println(args[0]);
    Serial.println(args[1]);
    Serial.println(args[2]);
    Serial.println(args[3]);


    // Selecting which enigma to solve
    ret = String(args[0] + sep);
    if(strcmp("circuit", args[1].c_str()) == 0){//A2 
        circuit(); 
        return ret + enonce; 
    } 
    else if(strcmp("dj", args[1].c_str()) == 0){//A3 
        dj(); 
        return ret + enonce; 
    } 
    else if(strcmp("360", args[1].c_str()) == 0){//A4 
        360(); 
        return ret + enonce; 
    } 
    else if(strcmp("crypto", args[1].c_str()) == 0){//A5 
        return ret + crypto(enonce); 
    } 
    else if(strcmp("swipe", args[1].c_str()) == 0){//A6 
        swipe(); 
        return ret + enonce; 
    } 
    else if(strcmp("spydj", args[1].c_str()) == 0){//A7 
        return ret + spydj(enonce, key); 
    } 
    else if(strcmp("ble", args[1].c_str()) == 0){//A8 
        ble(); 
        return ret + enonce; 
    } 
    else if(strcmp("magnéton", args[1].c_str()) == 0){//A9 
        porte = magneton(); 
        return ret + porte; 
    } 
    else if(strcmp("memory", args[1].c_str()) == 0){//A10 
        return ret + memory(enonce); 
    } 
    else if(strcmp("victoire", args[1].c_str()) == 0){//11 
        Serial.println("Victory!");
        victory(); /* Never returning function ? */
    } 
    else{
        Serial.println("Error: unknown enigma!");
        return NULL;
    }

    return ret.c_str();
} 

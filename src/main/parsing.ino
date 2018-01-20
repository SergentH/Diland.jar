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
        return ret + args[2]; 
    } 
    else if(strcmp("dj", args[1].c_str()) == 0){//A3 
        return ret + dj(args[2]); 
    } 
    else if(strcmp("360", args[1].c_str()) == 0){//A4 
        return ret + trisixti(args[2]); 
    } 
    else if(strcmp("crypto", args[1].c_str()) == 0){//A5 
        return ret + crypto(args[2]); 
    } 
    else if(strcmp("swipe", args[1].c_str()) == 0){//A6 
        swipe(); 
        return ret + swipe(args[2]); 
    } 
    else if(strcmp("spydj", args[1].c_str()) == 0){//A7 
        return ret + spydj(args[2], args[3]); 
    } 
    else if(strcmp("ble", args[1].c_str()) == 0){//A8 
        ble(); 
        return ret + ble(args[2]); 
    } 
    else if(strcmp("magnéton", args[1].c_str()) == 0){//A9 
        return ret + magneton(args[2]); 
    } 
    else if(strcmp("memory", args[1].c_str()) == 0){//A10 
        return ret + memory(args[2]); 
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

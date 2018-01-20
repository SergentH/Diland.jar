
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "lib_NDEF_URI.h"
#include "lib_NDEF_SMS.h"
#include "lib_NDEF_Text.h"
#include "lib_NDEF_Email.h"
#include "lib_NDEF_Geo.h"
#include "lib_95HFConfigManager.h"
#include "miscellaneous.h"
#include "lib_95HFConfigManager.h"
#include "lib_wrapper.h"
#include "lib_NDEF_URI.h"
#include "drv_spi.h"
#include "String.h"

#define SerialPort Serial

/* Exported define -----------------------------------------------------------*/
#define BULK_MAX_PACKET_SIZE            0x00000040

/******************  PICC  ******************/
/* ISO14443A */
#define PICC_TYPEA_ACConfigA            0x27  /* backscaterring */

/* ISO14443B */
#define PICC_TYPEB_ARConfigD            0x0E  /* card demodulation gain */
#define PICC_TYPEB_ACConfigA            0x17  /* backscaterring */

/* Felica */
#define PICC_TYPEF_ACConfigA            0x17  /* backscaterring */

/* Private variables ---------------------------------------------------------*/

/* TT1 (PCD only)*/
uint8_t TT1Tag[NFCT1_MAX_TAGMEMORY];

/* TT2 */
uint8_t TT2Tag[NFCT2_MAX_TAGMEMORY];

/* TT3 */
uint8_t TT3Tag[NFCT3_MAX_TAGMEMORY];
uint8_t *TT3AttribInfo = TT3Tag, *TT3NDEFfile = &TT3Tag[NFCT3_ATTRIB_INFO_SIZE];

/* TT4 */
uint8_t CardCCfile      [NFCT4_MAX_CCMEMORY];
uint8_t CardNDEFfileT4A [NFCT4_MAX_NDEFMEMORY];
uint8_t CardNDEFfileT4B [NFCT4_MAX_NDEFMEMORY];

/* TT5 (PCD only)*/
uint8_t TT5Tag[NFCT5_MAX_TAGMEMORY];

sURI_Info url; 
extern uint8_t NDEF_Buffer []; 
extern DeviceMode_t devicemode;

sRecordInfo_uri RecordStruct;
  
int8_t TagType = TRACK_NOTHING;
bool TagDetected = false;
bool terminal_msg_flag = false ;
uint8_t status = ERRORCODE_GENERIC;
static char dataOut[256];

#define X_NUCLEO_NFC03A1_LED1 A2
#define X_NUCLEO_NFC03A1_LED2 A3
#define X_NUCLEO_NFC03A1_LED3 A4
//#define X_NUCLEO_NFC03A1_LED4 D4

char* nfc_data;

boolean led2 = false;
boolean led3 = false;

void setup_nfc() {
  // 95HF HW Init
  ConfigManager_HWInit();

  // LED1
  pinMode(X_NUCLEO_NFC03A1_LED1, OUTPUT);

  // LED2
  pinMode(X_NUCLEO_NFC03A1_LED2, OUTPUT);

  // LED3
  pinMode(X_NUCLEO_NFC03A1_LED3, OUTPUT);

  // LED4
//  pinMode(X_NUCLEO_NFC03A1_LED4, OUTPUT);
  
  // Configure USB serial interface
  
  terminal_msg_flag = true;

  digitalWrite(X_NUCLEO_NFC03A1_LED1, HIGH);
}


/* Loop ----------------------------------------------------------------------*/

int statusNFC(){
  if(led3){
    return 3;
  }
  if(led2){
    return 2;
  }
  return 0;
}

void loop_nfc()
{
  devicemode = PCD;
    
  /* Scan to find if there is a tag */
  TagType = ConfigManager_TagHunting(TRACK_NFCTYPE2);
  if(TagType == TRACK_NFCTYPE2){
    digitalWrite(X_NUCLEO_NFC03A1_LED2, HIGH);
    led2 = true;
    TagDetected = true;
  }else{
    digitalWrite(X_NUCLEO_NFC03A1_LED2, LOW);
    led2 =false;
    digitalWrite(X_NUCLEO_NFC03A1_LED3, LOW);
    led3=false;
    TagDetected = false;
  }
  

  //delay(300);
    
  if (TagDetected == true)
  {       
    TagDetected = false;
      

      
    //delay(500);
      
      memset(url.Information,'\0',400); /*Clear url buffer before reading*/


      status = PCDNFCT2_ReadNDEF();
  
      if ( status == RESULTOK )
      {
        status = ERRORCODE_GENERIC;
          
        memset(NDEF_Buffer,'\0',20); /* Avoid printing useless characters */
        status = NDEF_IdentifyNDEF( &RecordStruct, NDEF_Buffer);
          
        if(status == RESULTOK && RecordStruct.TypeLength != 0)
        {
          if (NDEF_ReadURI(&RecordStruct, &url)==RESULTOK) /*---if URI read passed---*/
          {
            digitalWrite(X_NUCLEO_NFC03A1_LED3, HIGH);
            led3 = true;
            nfc_data = url.URI_Message;
          }
        }
     }
  } 
}

char* getNfcData(){
  return nfc_data;
}


    //status = NDEF_WriteURI(&url);

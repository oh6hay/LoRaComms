#ifndef LoRaComms_h
#define LoRaComms_h

#include "Arduino.h"


#define LRC_FLAG_ACK 0x80
#define LRC_FLAG_REQUEST_ACK 0x40
#define LRC_FLAG_BROADCAST 0x20

typedef enum lrc_message_type 
  {
    LOCATION_REQUEST = 1,
    LOCATION_RESPONSE,
    LOCATION_NOTIFY,
    LOCATION_STARTTRACKING_REQUEST,
    LOCATION_STARTTRACKING_RESPONSE,
    LOCATION_ENDTRACKING_REQUEST,
    LOCATION_ENDTRACKING_RESPONSE,
    LOCATION_SETINTERVAL_REQUEST,
    LOCATION_SETINTERVAL_RESPONSE,
    MESSAGE
  } lrc_message_type;


typedef struct lpkt
{
  uint8_t flags;
  uint8_t message_type;
  uint8_t srcaddr;
  uint8_t dstaddr;
  uint8_t fragmentno;
  uint8_t fragments;
  uint8_t payload_size;
  uint8_t rssi;
  uint32_t seqno;
  uint32_t padding;
  //uint8_t payload[240];
} lpkt;

typedef struct lposition 
{
  uint16_t hour;
  uint16_t minute;
  uint16_t second;
  uint16_t satellites;    // 4
  uint16_t year;
  uint16_t month;
  uint16_t day;         // 8
  uint16_t padding;
  uint32_t agemillis;  // 12
  uint32_t padding2; // vittu
  double lat;          // 20
  double lng;          // 28
  double kmph;         // 36
  double course;       // 44
  double meters;       // 52
} lposition;

typedef struct lsetinterval_request 
{
  uint8_t seconds;
}
  lsetinterval_request;


  
  

bool isAck(lpkt p);
bool requestsAck(lpkt p);
bool isBroadcast(lpkt p);


#endif


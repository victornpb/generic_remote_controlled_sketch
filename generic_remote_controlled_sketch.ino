#include <IRremote.h>
const uint8_t RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

enum Actions{
  NoAction,
  VolupAction,
  VoldownAction,
  MuteAction,
};




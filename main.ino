

void setup() {
  // put your setup code here, to run once:
  pinMode(LedBlink::pin, OUTPUT);
}

void loop() {
  
    int8_t action = processRemote();
    
    switch(action){
      
        case VolupAction:
            //increase volume
        break;
        
        case VoldownAction:
            //decrease volume
        break;
        
        case MuteAction:
            //mute or unmute
        break;
    }
   
   LedBlink::ledBlinkRoutine(millis());
    
}


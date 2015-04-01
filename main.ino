

void setup() {
  // put your setup code here, to run once:
  pinMode(LedBlink::pin, OUTPUT);
  
  
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  
    byte action = processRemote();
    
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


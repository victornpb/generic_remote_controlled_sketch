//remote control codes
enum AIWA {
    AIWA_1 = 0xE078FC8,
    AIWA_2 = 0xE078FE8,
    AIWA_3 = 0xE078FF8,
    AIWA_4 = 0xE078FD8,
    AIWA_5 = 0xE078FD2,
    AIWA_6 = 0xE078FE2,
};

const int RepeatTimeout = 300; //ms

byte processRemote(){
    
    int8_t action = NoAction;
    
    static byte lastAction;
    static long previousMillis;
    
    if(irrecv.decode(&results)) {

        unsigned long currentMillis = millis();

        unsigned long code = results.value;

        switch(code){
            case AIWA_3:
                action = VolupAction;
            break;

            case AIWA_5:
                action = VoldownAction;
            break;

            case AIWA_6:
                action = MuteAction;
            break;

            case REPEAT:
                if(currentMillis - previousMillis < RepeatTimeout){
                    if(lastAction == VolupAction || lastAction == VoldownAction){ //only enable repeat for this actions
                        action = lastAction;
                    }
                }
            break;
        }

        irrecv.resume();

        previousMillis = currentMillis;
        lastAction = action;
        
        if(action != NoAction) LedBlink::on();
    }

    return action;
}


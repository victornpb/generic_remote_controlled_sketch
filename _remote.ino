//remote control codes
enum AIWA {
    AIWA_1 = 0xE078FC8,
    AIWA_2 = 0xE078FE8,
    AIWA_3 = 0xE078FF8,
    AIWA_4 = 0xE078FD8,
    AIWA_5 = 0xE078FD2,
    AIWA_6 = 0xE078FE2,
};

enum Mp3Remote {
	Power = 0xFFA25,
	Mode = 0xFF629,
	Mute = 0xFFE21,
	Play = 0xFF22D,
	Back = 0xFF02F,
	Next = 0xFFC23,
	Eq = 0xFFE01,
	Minus = 0xFFA85,
	Plus = 0xFF906,
	D0 = 0xFF689,
	Shuffle = 0xFF986,
	Usd = 0xFFB04,
	D1 = 0xFF30C,
	D2 = 0xFF18E,
	D3 = 0xFF7A8,
	D4 = 0xFF10E,
	D5 = 0xFF38C,
	D6 = 0xFF5AA,
	D7 = 0xFF42B,
	D8 = 0xFF4AB,
	D9 = 0xFF52A,
};

const int RepeatTimeout = 300; //ms

byte processRemote(){
    
    byte action = NoAction;
    
    static byte lastAction;
    static long previousMillis;
    
    if(irrecv.decode(&results)) {

        unsigned long currentMillis = millis();

        unsigned long code = results.value;
        
       
        Serial.print(F("\nCODE:"));
        Serial.print(code, HEX);
        
        
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
            
            case Power:
                action = MuteAction;
            break;
            
            case Plus:
                action = VolupAction;
            break;

            case Minus:
                action = VoldownAction;
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


/** Led 13 blink on known command received */
namespace LedBlink{
  
  const int pin = 13;
  const unsigned int duration = 250; //hold for x ms
  
  bool enabled;
  static long ledBlinkTimeout;
  
  void on(){
      enabled = true;
      ledBlinkTimeout = millis();
      digitalWrite(pin, HIGH);
  }
  
  void ledBlinkRoutine(long currentMillis){
      if(enabled){
          if(currentMillis - ledBlinkTimeout > duration){
                enabled = false;
                digitalWrite(pin, LOW);
          }
      }
  }
  
}

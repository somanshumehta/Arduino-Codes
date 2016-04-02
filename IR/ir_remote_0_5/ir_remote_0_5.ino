     /* 
      This code can be used to decode the individual hex values of any TV remote key in general with output on the serial monitor. 
      TSOP 1728 Gnd Vcc Output (Vcc 5V)
      This code  sccessfuly ran with old hp remote
     */ 

     #include <IRremote.h>                     // IR remote control library 

     const int irReceivePin = 2;               // ARDUINO pin connected to the output of the IR 
     const int ledPin       = 13;              // LED is connected to a PWM pin 
     const int numberOfKeys = 5;               //  5 keys are learned (0 through 4) 
     long irKeyCodes[numberOfKeys];            // holds the codes for each key 
     IRrecv irrecv(irReceivePin);              // create the IR library 
     decode_results results;                   // IR data goes here 

     void setup() 
     { 
        Serial.begin(9600); 
        pinMode(irReceivePin, INPUT); 
        pinMode(ledPin, OUTPUT); 
        irrecv.enableIRIn();                   // Start the IR receiver 
        learnKeycodes();                       // learn remote control key  codes 
        Serial.println("Press a remote key"); 
     } 

     void loop() 
     { 
        long key; 
       
        if (irrecv.decode(&results)) 
        { 
          // here if data is received 
          irrecv.resume(); 
          key = convertCodeToKey(results.value); 
          
		if(key >= 0) 
          { 
            Serial.print("Got key "); 
            Serial.println(key); 
            
          } 
        } 
     } 

     /* get remote control codes  */ 
     void learnKeycodes() 
     { 
        while(irrecv.decode(&results))                      // empty the buffer 
          irrecv.resume(); 
        Serial.println("Ready to learn remote codes"); 
        long prevValue = -1; 
        int i=0; 
        while( i < numberOfKeys) 
        { 
          Serial.print("press remote key "); 
          Serial.print(i); 
          while(true) 
          { 
            if( irrecv.decode(&results) ) 
            { 
                 if(results.value != -1 && results.value != prevValue) 
                 { 
                   showReceivedData(); 
                   irKeyCodes[i] = results.value; 
                   i = i + 1; 
                   prevValue = results.value; 
                   irrecv.resume(); // Receive the next value 
                   break; 
                 } 
               irrecv.resume(); // Receive the next value 
            } 
          } 
        } 
        Serial.println("Learning complete"); 
     } 

     /* converts a remote protocol code to a logical key code (or -1 if no digit received) */ 
     int convertCodeToKey(long code) 
     { 
        for( int i=0; i < numberOfKeys; i++) 
        { 
          if( code == irKeyCodes[i]) 
          { 
            return i; // found the key so return it 

   } 
        } 
        return -1; 
      } 

     /* display the protocol type and value */ 
     void showReceivedData() 
      { 
        if (results.decode_type == UNKNOWN) 
        { 
          Serial.println("Could not decode message"); 
        } 
        else 
        { 
          if (results.decode_type == NEC) { 
             Serial.print("- decoded NEC: "); 
          } 
          else if (results.decode_type == SONY) { 
             Serial.print("- decoded SONY: "); 
          } 
          else if (results.decode_type == RC5) { 
             Serial.print("- decoded RC5: "); 
          } 
          else if (results.decode_type == RC6) { 
             Serial.print("- decoded RC6: "); 
          } 
          Serial.print("hex value = "); 
          Serial.println( results.value, HEX); 
        } 
      } 




                                                   

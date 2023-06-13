//// Please attach a potentiometer with its output pin to A0


int state;
float rate;
int dataIn;

int  targetValue;

int targetPrev;

float currentValue;
float stepDiff;


unsigned long currentMillis;
unsigned long previousMillis;
unsigned long previousWalkMillis;
unsigned long previousSafetyMillis;

void setup() {

Serial.begin(115200);

}




void loop() {

  currentMillis = millis();
  if (currentMillis - previousMillis >= 10) {  // start timed event
          
        previousMillis = currentMillis;

        rate = analogRead(A0);
        rate = map(rate,0,1023,80,1);

      
        if (state == 0) {
          targetValue = 500;
          if (currentValue <= targetValue) {
            state =1;
            targetPrev = targetValue;

          }
        }


        else if (state == 1) {
          targetValue = 2300;
         if (currentValue >= targetValue) {
            state = 0;
           targetPrev = targetValue;
            
         }
       }

        stepDiff = (targetValue - targetPrev)/(20*rate);

        currentValue = currentValue + stepDiff;

        

        Serial.print(targetValue);
        Serial.print(" , ");
        Serial.print(currentValue);
        Serial.println();
  }


  }

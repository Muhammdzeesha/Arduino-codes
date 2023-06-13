float period = 1.0;
float amplitude = 1.0; 
float phase = 0.0; 
float Shift_along_y = 0.0; ///float yShift = 0.0;


float _period;
  float _freq0;
  float _freq1;
  float _freq2;
  float _freq4;
  float _amplitude;
  float _phase;
  float y_Shifting;



  
  uint32_t _m_w = 1;
  uint32_t _m_z = 2; 
long int random();

 





void  setPeriod(float period = 1.0);




  float getPeriod() { return _period; };
  
  void  setFrequency(float freq = 1.0) { setPeriod(1/freq); };
  
  float getFrequency() { return _freq1; };
  
  void  setAmplitude(float ampl = 1.0) { _amplitude = ampl; };
  
  float getAmplitude() { return _amplitude; };
  
  void  setPhase(float phase = 180.0) { _phase = phase; };
  
  float getPhase() { return _phase; };
  
  void  setYShift(float Shift_along_y = 0.0) {  y_Shifting = Shift_along_y; };
  
  float getYShift() { return  y_Shifting; };
  
 




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

setAmplitude(50);

}

void loop() {
  // put your main code here, to run repeatedly:
float t = millis() * 0.001;
Serial.println(random_signal());







setPeriod(period);
 setAmplitude(amplitude);
 setPhase(phase);
setYShift(Shift_along_y);
}




  



void setPeriod(float period)
{
  _period = period;
  _freq1 = 1 / period;
  _freq2 = 2 * _freq1;
  _freq4 = 4 * _freq1;
  _freq0 = TWO_PI * _freq1;

  
}




float random_signal()
{
  
  float rv = y_Shifting + _amplitude * random() * 0.2328306436E-9;  // div 0xFFFFFFFF
  return rv;
}

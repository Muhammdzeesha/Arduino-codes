uint32_t _m_w = 1;
uint32_t _m_z = 2; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


}

void loop() {
  
_m_z = 36969L * (_m_z & 65535L) + (_m_z >> 16);
_m_w = 18000L * (_m_w & 65535L) + (_m_w >> 16);
 
Serial.println((_m_z << 16) + _m_w);



  
}

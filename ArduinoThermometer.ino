int thermometer = A11;             //connect di Vout of LM35  
int sensorValue = 0;               //variable for storing the value of sensor

void setup() {
  Serial.begin(9600);              //set di serial port
  pinMode(thermometer,INPUT);      //set the pin as INPUT
}

void loop() {
  sensorValue=0;
  for(int i=0;i<10;i++)            //make the arithmetci mean on 10 values
  {
      sensorValue = sensorValue + ((5*analogRead(thermometer))*100)/1024;  //equation of the sensor   
      delay(100);
  }
  
  sensorValue = sensorValue/10;
  
  Serial.print(sensorValue);      //print on serial monitor the value
  Serial.println("Â°C");

  delay(500);
}
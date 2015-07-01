void readADIS(){
  
  // Read Supply Voltage
  Serial.print("Supply: ");
  int supply = (readreg(SUPPLYBITS, SUPPLY_OUT));
  int supply_converted = supply * SUPPLYSCALE;
  Serial.print(supply_converted);
  Serial.println("V");
  
  // Read Gyro Values
  Serial.print("#Gyro: ");  //degrees per second
  float gyro = (readreg(GYROBITS, GYRO_OUT));
  float gyro2 = (twoscomptransform(GYROBITS, gyro));
  float gyro_scaled = gyro2 * GYROSCALE;
  Serial.println(gyro_scaled);
  
  // Read Accelerometer Values
  Serial.print("#Accel (X,Y,Z) (m/s^2): ");
  float accelx = (readreg(ACCBITS, XACCL_OUT));
  float accely = (readreg(ACCBITS, YACCL_OUT));
  float accelz = (readreg(ACCBITS, ZACCL_OUT));
  accelx = (twoscomptransform(ACCBITS, accelx));
  accely = (twoscomptransform(ACCBITS, accely));
  accelz = (twoscomptransform(ACCBITS, accelz));
  float accelx_scaled = accelx * ACCSCALE;
  float accely_scaled = accely * ACCSCALE;
  float accelz_scaled = accelz * ACCSCALE;
  Serial.print(accelx_scaled);  Serial.print(", ");  Serial.print(accely_scaled);  
  Serial.print(", ");     Serial.println(accelz_scaled);  
  
  // Read Temperature
  Serial.print("#Temp (C): ");
  float temp = (readreg(TEMPBITS, TEMP_OUT));
  temp = (twoscomptransform(TEMPBITS, temp));
  float temp_scaled = 25 + (temp * TEMPSCALE);
  Serial.println(temp_scaled);
 
  
  // Read Roll
  Serial.print("#Roll: ");
  float roll = (readreg(ROLLBITS, ROLL_OUT));
  roll = (twoscomptransform(ROLLBITS, roll));
  float roll_scaled = roll * ROLLSCALE;
  Serial.print(roll * ROLLSCALE);
  Serial.print(" degrees ");
  
  // Read Pitch
  Serial.print("Pitch: ");
  float pitch = (readreg(PITCHBITS, PITCH_OUT));
  pitch = (twoscomptransform(PITCHBITS, pitch));
  float pitch_scaled = pitch * PITCHSCALE;
  Serial.print(pitch_scaled);
  Serial.println(" degrees ");
  
  
}



//read register reg with number of bits nbits
unsigned int readreg(unsigned char nbits, unsigned char reg){
  unsigned char upper, lower, mask;
   digitalWrite(10, LOW);
  SPI.transfer(reg);
  SPI.transfer(0x00);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  upper = SPI.transfer(0x00);
  lower = SPI.transfer(0x00);
  digitalWrite(10, HIGH);
  mask = 0xFF >> (16 - nbits);
  
  return   ( ( upper & mask) << 8 | lower)  ;
}

//Perform two complement transformation on data
double twoscomptransform(unsigned char nbits, unsigned int num){
  unsigned int mask, padding;
  // select correct mask
  mask = 1 << (nbits -1);
  
  // if MSB is 1, then number is negative, so invert it and add one
  // if MSB is 0, then just return the number 
  return (num & mask)?( -1.0 * (~(num | 0xFF << nbits)  + 1) ):( 1.0 * num );
}

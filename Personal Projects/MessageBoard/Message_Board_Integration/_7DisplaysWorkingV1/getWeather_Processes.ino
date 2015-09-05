int writeTemp(){
  String temperature = "";
  Serial.println("Temp process initializing...");
  Process p;
  p.runShellCommand("/mnt/sda1/gettemp.py");
  while (p.available()){
    temperature = p.readString();
    p.exitValue();
  }
  p.close();
  Serial.println("Temp process complete");
  Serial.println(temperature);
  temp = temperature.toInt();
  return temp;
  }

String getCond(){
  String condition = "";
  Serial.println("Cond process initializing...");
  Process p;
  p.runShellCommand("/mnt/sda1/getcond.py");
  while (p.available()){
    condition = p.readString();
    p.exitValue();
  }
  p.close();
  Serial.println("Condition process complete");
  Serial.println(condition);
  return condition;
}

String todayfc(){
  String todayforecast = "";
  Serial.println("TodayFC process initializing...");
  Process p;
  p.runShellCommand("/mnt/sda1/todayfc.py");
  while(p.available()){
    todayforecast = p.readString();
    p.exitValue();
  }
  p.close();
  Serial.println("TodayFC process complete");
  Serial.println(todayforecast);
  return todayforecast;
  }

String tomfc(){
  String tomforecast = "";
  Serial.println("TomFC process initializing...");
  Process p;
  p.runShellCommand("/mnt/sda1/tomfc.py");
  while(p.available()){
    tomforecast = p.readString();
    p.exitValue();
  }
  p.close();
  Serial.println("TomFC process complete");
  Serial.println(tomforecast);
  return tomforecast;
  }

  




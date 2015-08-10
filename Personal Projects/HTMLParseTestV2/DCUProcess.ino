void getDCU(){
  Serial.println("DCU process initializing...");
  Process p;
  p.runShellCommand("/mnt/sda1/getDCU.py");
  while (p.running());{
    Serial.println("DCU process executing...");
  }
  while (p.available()){
    result = p.readString();
    Serial.println(result);
    p.exitValue();
  }
  p.close();
  result = "";
  Serial.println("DCU process complete");
}

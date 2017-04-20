// serial inputs
int c;
int v=0;

void serialCom(){
    // read serial-data, if available
    while (Serial.available()) {
    c = Serial.read();
    // handle digits
    if ((c >= '0') && (c <= '9')) {
      v = 10 * v + c - '0';
    }
    // handle delimiter
    else if (c == 'e') {
      for(int i=0; i<inputLength; i++){
        if(i < inputLength - 1){
          inputArray[i] = inputArray[i+1];
        }else{
          inputArray[i] = v;
        }
      }
      v = 0;




      // Find descriptive statistics
      
      //AVG
      float total=0;
      for(int i=0; i<inputLength; i++){
        total = total + inputArray[i];
      }
      inputAvg = float(total/inputLength);

      //STD
      total = 0;
      for(int i=0; i<inputLength; i++){
        total = total + sq(inputArray[i]-inputAvg);
      }
      inputSTD = total/(inputLength-1);

      //Range
      inputMax = 0;
      inputMin = 5;
      inputRange = 0;
      for(int i=0; i<inputLength; i++){
        if(inputArray[i] < inputMin){
          inputMin = inputArray[i];
        }
        if(inputArray[i] > inputMax){
          inputMax = inputArray[i];
        }
      }
      inputRange = inputMax-inputMin;
      
      

      // printouts
      Serial.println(inputArray[19]);
      Serial.println(inputArray[18]);
      Serial.println(inputArray[17]);
      Serial.println(inputArray[16]);
      Serial.println(inputArray[15]);
      Serial.println(inputArray[14]);
      Serial.println(inputArray[13]);
      Serial.println(inputArray[12]);
      Serial.println(inputArray[11]);
      Serial.println(inputArray[10]);
      Serial.println(inputArray[9]);
      Serial.println(inputArray[8]);
      Serial.println(inputArray[7]);
      Serial.println(inputArray[6]);
      Serial.println(inputArray[5]);
      Serial.println(inputArray[4]);
      Serial.println(inputArray[3]);
      Serial.println(inputArray[2]);
      Serial.println(inputArray[1]);
      
      Serial.println(inputAvg);
      Serial.println(inputSTD);
      Serial.println(inputMax);
      Serial.println(inputMin);
      Serial.println(inputRange);
    }
  }
}

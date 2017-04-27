void lightItUp(){
  // Use the variable *inputAvg* *inputSTD* *inputRange* *inputMax* *inputMin* to change the colors

  //pulse to green
  if(green && g<greenMax){
    r = r-pulseSpeed;
    g = g+pulseSpeed;
  }else{
    green = false;
    red = true;
  }
  if(red && r<redMax){
    r = r+pulseSpeed;
    g = g-pulseSpeed;
  }else{
    green = true;
    red = false;
  }
  
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r,g,b)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }

  //Wave after input
  if(wavePixel < 50){
    pixels.setPixelColor(wavePixel, pixels.Color(100,0,255));
    pixels.setPixelColor(wavePixel+1, pixels.Color(100,0,255));
    pixels.setPixelColor(wavePixel+2, pixels.Color(100,0,255));
    pixels.setPixelColor(wavePixel+3, pixels.Color(100,0,255));
    pixels.setPixelColor(wavePixel+4, pixels.Color(100,0,255));
    wavePixel = wavePixel+5;
  }
}

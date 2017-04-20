void lightItUp(){
  // Use the variable *inputAvg* *inputSTD* *inputRange* *inputMax* *inputMin* to change the colors

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(rAvg,gAvg,bAvg)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}

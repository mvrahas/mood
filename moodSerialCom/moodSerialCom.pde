//References
// Sending a numerical variable from Processing to Arduino
// mikiribes14
// December 2015
// https://forum.processing.org/two/discussion/14004/sending-a-numerical-variable-from-processing-to-arduino
// libraries
import processing.serial.*;
// serial connection
Serial port;
 
 
void setup() {
  // interface
  size(1000,600);
  
  // serial Comm
  port = new Serial(this, Serial.list()[2], 57600);
}
 
void draw() {
  // rectangles
  noStroke();
  textSize(32);
  fill(0,255,0);
  rect(0,0,width,100);
  fill(100,200,0);
  rect(0,100,width,100);
  fill(210,240,0);
  rect(0,200,width,100);
  fill(240,220,0);
  rect(0,300,width,100);
  fill(220,100,0);
  rect(0,400,width,100);
  fill(255,0,0);
  rect(0,500,width,100);
  
  // text
  fill(0);
  text("5 | Very Good", 420, 50);
  text("4 | Good", 420, 150);
  text("3 | Ok", 420, 250);
  text("2 | Meh", 420, 350);
  text("1 | Bad", 420, 450);
  text("0 | Very Bad", 420, 550);
}

void recordMood(int entry){
  // create random number
  int number = entry;
  // debug
  println("now sending number: "+number);
  // send number
  port.write(Integer.toString(number));
  // write any charcter that marks the end of a number
  port.write('e');
}

void keyPressed() {
  switch (key) {
  case '5':
    recordMood(5);
    break;
  case '4':
    recordMood(4);
    break;  
  case '3':
    recordMood(3);
    break;
  case '2':
    recordMood(2);
    break;  
  case '1':
    recordMood(1);
    break;
  case '0':
    recordMood(0);
    break;  
  }
}

// this part is executed, when serial-data is received
void serialEvent(Serial p) {
  try {
    // get message till line break (ASCII > 13)
    String message = p.readStringUntil(13);
    // just if there is data
    if (message != null) {
      println("message received: "+trim(message));
    }
  }
  catch (Exception e) {
  }
}
/*
 *    QuatTest.ino
 *    Simple test of quaternion integration and vector translation
 *    Phillip Schmidt, 2016
 */
 
 
#define SERIAL_PORT Serial

#include <Math3D.h>

Quat testQuaternion;

void setup() {
  SERIAL_PORT.begin(57600);
  delay(1000);
  SERIAL_PORT.println("Start Now");

}

void loop() {

  int steps = 100;

  Quat changeQuat;

  const Vec3 quarterTurn = Vector(0, PI / 2.0f, 0);  // 90 degree  rotation around Y-axis

  for(int i=0; i<steps; i++){
    
    // This is the function from my blog post: http://philstech.blogspot.com/2014/09/fast-quaternion-integration-for.html
    changeQuat = Quaternion(quarterTurn, 1000000UL / steps); // arguments: rotation amount and time delta in microseconds
    
    testQuaternion = Mul(testQuaternion, changeQuat); // multiply quaternions to combine rotations
    
  }

  Vec3 testResult = Rotate(Vector(1.0f, 0.0f, 0.0f), testQuaternion);  // rotate vector with quaternion

  SERIAL_PORT.print("Quaternion: ");
  display(testQuaternion);
  
  SERIAL_PORT.print("Rotated Vec: ");
  display(testResult);
  
  SERIAL_PORT.print("Vec Magnitude: ");
  SERIAL_PORT.println(Magnitude(testResult), 6);

  SERIAL_PORT.println(" ");
  delay(5000);
  
}

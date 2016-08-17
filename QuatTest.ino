#define SERIAL_PORT Serial

#include <Math3D.h>

Quat testQuaternion;

const Vec3 quarterTurn = Vector(0, PI / 2.0f, 0);  // 90 degree  rotation around Y-axis

void setup() {
  SERIAL_PORT.begin(57600);
  delay(1000);
  SERIAL_PORT.println("Start Now");

}

void loop() {

  int steps = 100;

  for(int i=0; i<steps; i++){
    
    // This is the function from my blog post: http://philstech.blogspot.com/2014/09/fast-quaternion-integration-for.html
    Quat changeQuat = Quaternion(quarterTurn, 1000000UL / steps); // for this test, this will always be the same
    
    testQuaternion = Mul(testQuaternion, changeQuat); // multiply quaternions to combine them
    
  }

  Vec3 testResult = Rotate(Vector(1.0f, 0.0f, 0.0f), testQuaternion);  // rotate vector with quaternion

  display(testQuaternion);
  display(testResult);
  SERIAL_PORT.println(Magnitude(testResult), 6);

  SERIAL_PORT.println(" ");
  delay(5000);
  
}

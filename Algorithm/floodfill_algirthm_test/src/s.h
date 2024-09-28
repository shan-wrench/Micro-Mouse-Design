#pragma once
#define model 430

float distance_cm;

// SharpIR mySensor = SharpIR(sharpl, model);

// void sharp12() {
//   float volts = analogRead(sharp1)*0.0048828125;  // value from sensor * (5/1024)
//   float distance = 13*pow(volts, -1); // worked out from datasheet graph
//   delay(1000); // slow down serial port 
  
//   if (distance <= 50.0){
//     Serial.println(distance);   // print the distance
//   }
// }

// void sharp12() {
//   // Get a distance measurement and store it as distance_cm:
//   distance_cm = mySensor.distance();

//   // Print the measured distance to the serial monitor:
//   Serial.print("Mean distance: ");
//   Serial.print(distance_cm);
//   Serial.println(" cm");

//   delay(1000);
// }

float sharp_l() {
  float volts = analogRead(sharpl)*0.0048828125;  // value from sensor * (5/1024)
  float distance = 13*pow(volts, -1); // worked out from datasheet graph
  // delay(100); // slow down serial port 
  
  // if (distance <= 500.0){
  //   Serial.print(distance);   // print the distance
  // }
  // Serial2.print("l : ");
  // Serial2.print(distance);

  return distance*10;
}

float sharp_r() {
  float volts = analogRead(sharpr)*0.0048828125;  // value from sensor * (5/1024)
  float distance = 13*pow(volts, -1); // worked out from datasheet graph
  // delay(100); // slow down serial port 
  
  // if (distance <= 500.0){
  //   Serial.print(distance);   // print the distance
  // }
  // Serial2.print("   r : ");
  // Serial2.print(distance);  
  return distance*10;
}

float sharp_c() {
  float volts = analogRead(sharpc)*0.0048828125;  // value from sensor * (5/1024)
  float distance = 13*pow(volts, -1); // worked out from datasheet graph
  // delay(100); // slow down serial port 
  
  // if (distance <= 500.0){
  //   Serial.print(distance);   // print the distance
  // }
  // Serial2.print("   c : ");
  // Serial2.print(distance);
  // Serial2.println("");
  return distance*10;
}
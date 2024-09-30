#pragma once
float shar_l() {
  int VoRaw = analogRead(sharpl);

//   float Vo = (5.0 * VoRaw) / 1024.0;

//   const float a = 48.375;
//   const float b = 0.0675;
//   float dist = 1000;
// //   if ( Vo > b ) {
// //     dist = a / (Vo - b) ;
// //   }
//   dist = a / Vo  ;
  return VoRaw; 
}

float shar_r() {
  int VoRaw = analogRead(sharpr);

//   float Vo = (5.0 * VoRaw) / 1024.0;

//   const float a = 48.375;
//   const float b = 0.0675;
//   float dist = 1000;
// //   if ( Vo > b ) {
// //     dist = a / (Vo - b);
// //   }
//   dist = a / Vo ;
  return VoRaw; 
}

float shar_c() {
  int VoRaw = analogRead(sharpc);

  // float Vo = (5.0 * VoRaw) / 1024.0;

  // const float a = 48.375;
  // const float b = 0.0675;
  // float dist = 150;
  // if ( Vo > b ) {
  //   dist = a / (Vo - b);
  // }
  return VoRaw; 
}

float shar_r_wall(){
  int VoRaw = analogRead(sharpr_wall);
  return VoRaw;
}

float shar_l_wall(){
  int VoRaw = analogRead(sharpl_wall);
  return VoRaw;
}
/* MLX90316 Rotary Position Sensor */

#include <Metro.h> //Include Metro library
#include <MLX90316.h>

byte pinSS = 5;
byte pinSCK = 3;
byte pinMOSI = 4;

int angle;

Metro mlxMetro = Metro(5); 
MLX90316 mlx_1 = MLX90316(); 

void setup(){
  Serial.begin(115200);
  mlx_1.attach(pinSS,pinSCK,pinMOSI); 
  Serial.println("MLX90316 Rotary Position Sensor");
}

void loop() {
  if (mlxMetro.check() == 1) { 
    angle = mlx_1.readAngle();
    switch (angle) {
      case -1 : Serial.println("Transmission Error"); break;
      case -2 : Serial.println("Magnetic Field Too Strong"); break;
      case -3 : Serial.println("Magnetic Field Too Weak"); break;
      default:  Serial.println((float)angle/10);
    }
  }
}

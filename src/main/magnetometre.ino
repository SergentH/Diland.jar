#include <LIS3MDLSensor.h>
#define I2C2_SCL    PB10
#define I2C2_SDA    PB11
 LIS3MDLSensor *Magneto;
TwoWire *dev_i2c;

  
void setup_magnetometre(){
  dev_i2c = new TwoWire(I2C2_SDA, I2C2_SCL);
  dev_i2c->begin();
  Magneto = new LIS3MDLSensor(dev_i2c);
  Magneto->Enable();
}

boolean havePorte(){
  int32_t magnetometer[3];
  Magneto->GetAxes(magnetometer);
    if(magnetometer[1]>200 or magnetometer[2]>200){
      return true;
  }else{
    return false;
  }
}


#include <Wire.h>
#include "LapINA219.h"
#include "LapINA219_int.h"

//
// Public functions
//

//
// Constructor
//

LapINA219::LapINA219(uint8_t addr) {
  _i2c_address = addr;
}

void LapINA219::begin() {
  begin(&Wire);
}

void LapINA219::begin(TwoWire *useWire) {
  _wire = useWire;
  _wire->begin();
  // Set device calibration to current resolution 0.1mA, max 16V, and max 400mA.
  _write(LAPINA219_CAL_REGISTER, LAPINA219_16V400MA_CAL);
  _write(LAPINA219_CONFIG_REGISTER, LAPINA219_16V400MA_CONF);
}

float LapINA219::shuntVoltage()  {
  return (float) _read(LAPINA219_VSHUNT_REGISTER) * 0.01f;
}

float LapINA219::busVoltage() {
  return (float) (_read(LAPINA219_VBUS_REGISTER)) * 0.0005f;
}

float LapINA219::shuntCurrent() {
  _write(LAPINA219_CAL_REGISTER, LAPINA219_16V400MA_CAL);
  return (float) _read(LAPINA219_ISHUNT_REGISTER) * 0.05f;
}

float LapINA219::busPower() {
  _write(LAPINA219_CAL_REGISTER, LAPINA219_16V400MA_CAL);
  return (float) _read(LAPINA219_PBUS_REGISTER) * 1.0f;
}

//
// Private functions
//

//
// Transmit 16 bits over i2c
//

void LapINA219::_write(uint8_t address, uint16_t data) {
  _wire->beginTransmission(_i2c_address);
  _wire->write(address);
  _wire->write(data >> 8);
  _wire->write(data & 0xff);
  _wire->endTransmission();
}

//
// Receive 16 bits over i2c
//

int16_t LapINA219::_read(uint8_t address) {
  uint16_t ret;
  _write(address, 0);  
  _wire->requestFrom((int) _i2c_address, (int) 2);
  ret = _wire->read() << 8;
  return ret |= _wire->read();
}

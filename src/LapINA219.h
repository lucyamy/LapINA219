#ifndef LAPCSA219_H
#define LAPCSA219_H

#include "Arduino.h"

class LapINA219 {
  public:

    LapINA219(uint8_t);
    void begin(void);
    void begin(TwoWire *);
    float shuntVoltage(void);
    float busVoltage(void);
    float shuntCurrent(void);
    float busPower(void);

  private:
  
    uint8_t _i2c_address;
    TwoWire *_wire;
    int16_t _read(uint8_t);
    void _write(uint8_t, uint16_t);
};

#endif

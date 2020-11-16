# LapINA219
This is a simple current and voltage sensing library for the INA219 high-side Current Sensor. **LapINA219** provides basic current, voltage, and power monitoring, with a current resolution 0.1mA, maximum bus voltage of 16V, and maximum bus current of 400mA. It is designed to monitor a project's power, and is small and lightweight. There are other more complex libraries available if you need more control over the setup.

The INA219 is a high-side current shunt and power monitor with an i2c interface. The INA219 monitors both shunt drop and supply voltage, with
programmable conversion times and filtering. A programmable calibration value, combined with an internal multiplier, enables direct readouts in amps. An additional multiplying register calculates power in watts. **LapINA219** only uses this chip to monitor up to 16 volts, at 400mA. The INA219 has two i2c address select pins, which allow 16 programmable addresses, as follows:

     A1  A0  SLAVE ADDRESS
    GND GND  1000000 (0x40) 
    GND VS+  1000001 (0x41)
    GND SDA  1000010 (0x42)
    GND SCL  1000011 (0x43)
    VS+ GND  1000100 (0x44)
    VS+ VS+  1000101 (0x45)
    VS+ SDA  1000110 (0x46)
    VS+ SCL  1000111 (0x47)
    SDA GND  1001000 (0x48)
    SDA VS+  1001001 (0x49)
    SDA SDA  1001010 (0x4a)
    SDA SCL  1001011 (0x4b)
    SCL GND  1001100 (0x4c)
    SCL VS+  1001101 (0x4d)
    SCL SDA  1001110 (0x4e)
    SCL SCL  1001111 (0x4f)


**Constructor**
---------------------
**LapINA219** is invoked as:

  **LapINA219(uint8_t i2cAddress);** 

The address parameter is required.

**Library functions**
---------------------

The functions provided by **LapX9C10X** are:

void begin();
-------------
This must be called before using any other function. 
Initialises the Wire library, and configures the chip.

float shuntVoltage();  
---------------------------
Returns the voltage (in millivolts) between the **V-** and **V+** pins, i.e. the voltage across the shunt resistor.  

float busVoltage();
---------------------
Returns the voltage on the bus, in volts. This is the voltage between **GND** and the **V-** pin on the INA219.  

float shuntCurrent();
----------------------
Returns the current flowing though the shunt resistor, in milliamps - which is also of course the bus current.

float busPower();
----------------------
Returns the power being used by the load on the bus, in milliwatts. 



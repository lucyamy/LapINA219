#ifndef LAPCSA219_INT_H
#define LAPCSA219_INT_H

// INA219 device registers.
#define LAPINA219_CONFIG_REGISTER    0x00  // configuration register.
#define LAPINA219_VSHUNT_REGISTER    0x01  // differential shunt voltage.
#define LAPINA219_VBUS_REGISTER      0x02  // bus voltage (wrt to system/chip GND).
#define LAPINA219_PBUS_REGISTER      0x03  // system power draw ( V_BUS * I_SHUNT).
#define LAPINA219_ISHUNT_REGISTER    0x04  // shunt current.
#define LAPINA219_CAL_REGISTER       0x05  // calibration register.

// PGA gain and range.
// Configuration register bits 11 & 12.

#define LAPINA219_CONF_GAIN_40MV              0x0000    // Gain 1, 40mV Range
// #define LAPINA219_CONF_GAIN_80MV             0x0800    // Gain 2, 80mV Range
// #define LAPINA219_CONF_GAIN_160MV            0x1000    // Gain 4, 160mV Range
// #define LAPINA219_CONF_GAIN_320MV            0x1800    // Gain 8, 320mV Range

// Bus voltage range.
// Configuration register bit 13.

#define LAPINA219_CONF_BVRANGE16V             0x0000    //  Range 0-16 volts
// #define LAPINA219_CONF_BVRANGE32V            0x2000    // Range 0-32 volts

// ADC resolution and the number of samples.
// The commented ones are not used in this library at the moment.

// Values for bus ADC resolution. Configuration register bits 7-10.
// #define LAPINA219_BADC_9BIT                  0x0000    // 9-bit bus converion time  84us.
// #define LAPINA219_BADC_10BIT                 0x0080    // 10-bit bus converion time 148us.
// #define LAPINA219_BADC_11BIT                 0x0100    // 11-bit bus converion time 2766us.
#define LAPINA219_BADC_12BIT                  0x0180    // 12-bit bus converion time 532us.
// #define LAPINA219_BADC_12BIT_2               0x0480    // 2 x 12-bit bus samples averaged converion time 1.06ms.
// #define LAPINA219_BADC_12BIT_4               0x0500    // 4 x 12-bit bus samples averaged converion time 2.13ms.
// #define LAPINA219_BADC_12BIT_8               0x0580    // 8 x 12-bit bus samples averaged converion time 4.26ms.
// #define LAPINA219_BADC_12BIT_16              0x0600    // 16 x 12-bit bus samples averaged converion time 8.51ms
// #define LAPINA219_BADC_12BIT_32              0x0680    // 32 x 12-bit bus samples averaged converion time 17.02ms.
// #define LAPINA219_BADC_12BIT_64              0x0700    // 64 x 12-bit bus samples averaged converion time 34.05ms.
// #define LAPINA219_BADC_12BIT_128             0x0780    // 128 x 12-bit bus samples averaged converion time 68.10ms.

// Values for shunt ADC resolution. Configuration register bits 3-6.
// For an explanation of each, see bus defines above
// #define LAPINA219_SADC_9BIT                  0x0000
// #define LAPINA219_SADC_10BIT                 0x0008
// #define LAPINA219_SADC_11BIT                 0x0010
#define LAPINA219_SADC_12BIT                  0x0018
// #define LAPINA219_SADC_12BIT_2               0x0048
// #define LAPINA219_SADC_12BIT_4               0x0050
// #define LAPINA219_SADC_12BIT_8               0x0058
// #define LAPINA219_SADC_12BIT_16              0x0060
// #define LAPINA219_SADC_12BIT_32              0x0068
// #define LAPINA219_SADC_12BIT_64              0x0070
// #define LAPINA219_SADC_12BIT_128             0x0078

// Selects operating mode.
// Configuration register bits 0-2.
// #define LAPINA219_MODE_POWERDOWN             0x00      // power down
// #define LAPINA219_MODE_SVOLT_TRIGGERED       0x01      // shunt voltage triggered
// #define LAPINA219_MODE_BVOLT_TRIGGERED       0x02      // bus voltage triggered
// #define LAPINA219_MODE_SANDBVOLT_TRIGGERED   0x03      // shunt and bus voltage triggered
// #define LAPINA219_MODE_ADCOFF                0x04      // ADC off
// #define LAPINA219_MODE_SVOLT_CONT            0x05      // shunt voltage continuous
// #define LAPINA219_MODE_BVOLT_CONT            0x06      // bus voltage continuous
#define LAPINA219_MODE_SBVOLT_CONT            0x07      // shunt and bus voltage continuous

#define LAPINA219_16V400MA_CONF               (LAPINA219_CONF_BVRANGE16V | LAPINA219_MODE_SBVOLT_CONT \
                                              | LAPINA219_SADC_12BIT | LAPINA219_CONF_GAIN_40MV \
                                              | LAPINA219_BADC_12BIT)
#define LAPINA219_16V400MA_CAL                0x2000

#endif

#ifndef AHT20_H
#define AHT20_H


/* ----------------* C++ detection *----------------- */

#ifdef __cplusplus
extern "C"{
#endif


/*  ----------------* Includes *-----------------  */

#include "main.h"


/*  ----------------* Defines *-----------------  */

#define AHT20_ADDRESS           0x38
#define AHT20_SOFT_RESET        0xBA
#define AHT20_TIMEOUT           1000
extern I2C_HandleTypeDef *_aht20_ui2c;


/*  ----------------* Function Prototypes *-----------------  */

void   AHT20_Init(I2C_HandleTypeDef *hi2c);    // Initializes sensor address
void   AHT20_SoftReset(void);                  // Resets sensor and measurement
void   AHT20_Measure(void);                    // Measures Temp&humid and receives data
double AHT20_Temp(void);                       // Extract temperature from data and return value (Celsius)
double AHT20_Humid(void);                      // Extract Humidity from data and return value (Percent)
#endif

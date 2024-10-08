
#include "Wire.h"
#include <cstdint>

#define TCAADDR 0x70
static void tcaselect(uint8_t i);

static void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}
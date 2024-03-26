#ifndef MKOCOT_ARDUINO_CRC8_H
#define MKOCOT_ARDUINO_CRC8_H

#include <stdint.h>

inline uint8_t calc_crc8(const uint8_t* data, uint8_t length)
{
  // NOTE: length is short, so yield is not required
  uint8_t crc = 0x00;
  while (length--) {
      crc ^= *data++;
      for (uint8_t i = 0; i < 8; i++) {
          if (crc & 0x80) {
              crc = (crc << 1) ^ 0x5D; // CRC8 polynomial: 0x5D
          } else {
              crc <<= 1;
          }
      }
  }
  return crc;
}

#endif

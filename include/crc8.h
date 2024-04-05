#ifndef MKOCOT_ARDUINO_CRC8_H
#define MKOCOT_ARDUINO_CRC8_H

#include <stdint.h>

enum CRC8_POLY : uint8_t
{
  CRC8_POLY_DVB_S2 = 0xD5,
  CRC8_POLY_OLD_DEFAULT = 0x5D,
};

inline static uint8_t crc8(const CRC8_POLY poly, const uint8_t *data, uint8_t length)
{
  // NOTE: length is short, so yield is not required
  uint8_t crc = 0x00;
  while (length--) {
    crc ^= *data++;
    for (uint8_t i = 0; i < 8; i++) {
      if (crc & 0x80) {
        crc = (crc << 1) ^ poly;
      } else {
        crc <<= 1;
      }
    }
  }
  return crc;
}

inline uint8_t crc8_dvb_s2(const uint8_t* data, uint8_t length)
{
  return crc8(CRC8_POLY_DVB_S2, data, length);
}

/* deprecated */
inline uint8_t calc_crc8(const uint8_t* data, uint8_t length)
{
  return crc8(CRC8_POLY_OLD_DEFAULT, data, length);
}

#endif


#include <stdint.h>
#include <string.h>

typedef uint8_t byte;
typedef bool boolean;

const int16_t HEIGHT = 64;
const int16_t WIDTH  = 128;
const int32_t F_CPU = 16000000;

#define B00000000  0x0
#define B00000001  0x1
#define B00000010  0x2
#define B00000100  0x4
#define B00001000  0x8
#define B00001010  0xA
#define B00001111  0xF
#define B00010000 0x10
#define B00110000 0x30
#define B00100000 0x20
#define B10010000 0x90
#define B11110000 0xF0

void delay(uint32_t ms);
long random(long howsmall, long howbig);

enum: uint8_t
{
    LEFT_BUTTON = 32,
    RIGHT_BUTTON = 64,
    UP_BUTTON = 128,
    DOWN_BUTTON = 16,
    A_BUTTON = 8,
    B_BUTTON = 4
};

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

char* ltoa_compat(long l, char * buffer, int radix);

#define pgm_read_byte *
#define pgm_read_word

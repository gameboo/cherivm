#include <stdio.h>
#include <string.h>
#define TEST_NAME "scalarmult7"
#include "cmptest.h"

unsigned char p1[32] = {
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

unsigned char p2[32] = {
    0x25,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char scalar[32];
unsigned char out1[32];
unsigned char out2[32];

int main(void)
{
  int i;

  scalar[0] = 1U;
  crypto_scalarmult_curve25519(out1, scalar, p1);
  crypto_scalarmult_curve25519(out2, scalar, p2);
  printf("%d\n", memcmp(out1, out2, sizeof out1));

  return 0;
}

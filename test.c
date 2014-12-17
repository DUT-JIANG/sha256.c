
#include <assert.h>
#include <string.h>
#include "sha256.h"
#include "tap.c/tap.h"

// "hello"
unsigned char hello_hashed[] = {
  0x2c, 0xf2, 0x4d, 0xba, 0x5f, 0xb0, 0xa3, 0x0e, 0x26, 0xe8, 0x3b, 0x2a,
  0xc5, 0xb9, 0xe2, 0x9e, 0x1b, 0x16, 0x1e, 0x5c, 0x1f, 0xa7, 0x42, 0x5e,
  0x73, 0x04, 0x33, 0x62, 0x93, 0x8b, 0x98, 0x24
};

// ""
unsigned char empty_hashed[] = {
  0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14, 0x9a, 0xfb, 0xf4, 0xc8,
  0x99, 0x6f, 0xb9, 0x24, 0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
  0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55
};

int main (void) {
  plan(1);

  unsigned char buf[32] = {0};

  sha256_hash(buf, (unsigned char*)"hello", 5);
  ok(memcmp(buf, hello_hashed, 32) == 0, "should hash correctly");

  sha256_t hash;
  sha256_init(&hash);
  sha256_update(&hash, (unsigned char*)"", 0);
  sha256_update(&hash, (unsigned char*)"", 0);
  sha256_final(&hash, buf);

  ok(memcmp(buf, empty_hashed, 32) == 0, "empty should hash correctly");

  done_testing();
}

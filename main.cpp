#include <emscripten.h>
#include <stdint.h>

uint8_t surface[320 * 200 * 4];

extern "C" {
  EMSCRIPTEN_KEEPALIVE  // This prevents the compiler from removing unused functions
  uint8_t* getSurfacePtr() { return surface; }

  EMSCRIPTEN_KEEPALIVE
  void fillCornflowerBlue() {
    for (int a=0; a < 320 * 200; a++) {
      // RGBA
      surface[a * 4] = 0x64;
      surface[a * 4 + 1] = 0x95;
      surface[a * 4 + 2] = 0xED;
      surface[a * 4 + 3] = 0xFF;
    }
  }
}
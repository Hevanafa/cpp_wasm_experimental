#include <emscripten.h>
#include <stdint.h>

#define PByte uint8_t*
#define nil nullptr

PByte surface = nil;

extern "C" {
  EMSCRIPTEN_KEEPALIVE  // This prevents the compiler from removing unused functions
  PByte getSurfacePtr() { return surface; }

  // Add more functions here
}


void fillCornflowerBlue() {
  for (int a=0; a < 320 * 200; a++) {
    // RGBA
    surface[a * 4] = 0x64;
    surface[a * 4 + 1] = 0x95;
    surface[a * 4 + 2] = 0xED;
    surface[a * 4 + 3] = 0xFF;
  }
}


void initBuffer() {
  surface = (PByte)malloc(320 * 200 * 4);
}

extern "C" EMSCRIPTEN_KEEPALIVE
void update() {}

extern "C" EMSCRIPTEN_KEEPALIVE
void draw() {
  fillCornflowerBlue();
}

EXPORT void init() {
  initBuffer();
}

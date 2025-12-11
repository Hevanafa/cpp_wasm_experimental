#include <emscripten.h>
#include <stdint.h>

// Pascal dialect of C++
#define export extern "C" EMSCRIPTEN_KEEPALIVE
#define PByte uint8_t*
#define nil nullptr
// getmem --> malloc
// freemem --> free

// Begin C++
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

export void cleanup() {
  if (surface != nil) {
    free(surface);
    surface = nil;
  }
}

export void update() {}

export void draw() {
  fillCornflowerBlue();
}

export void init() {
  initBuffer();
}

#include <emscripten.h>
#include <stdint.h>

// Pascal dialect of C++
#define export extern "C" EMSCRIPTEN_KEEPALIVE
#define PByte uint8_t*
#define nil nullptr
#define longword unsigned int
#define word unsigned short
#define shr >>
// getmem --> malloc
// freemem --> free

// Begin C++
PByte surface = nil;
const word vgaWidth = 320;
const word vgaHeight = 200;
const longword bufferSize = vgaWidth * vgaHeight * 4;

extern "C" {
  EMSCRIPTEN_KEEPALIVE  // This prevents the compiler from removing unused functions
  PByte getSurfacePtr() { return surface; }

  // Add more functions here
}


void cls(long colour) {
  char r, g, b, a;
  a = colour shr 24 & 0xff;
  r = colour shr 16 & 0xff;
  g = colour shr 8 & 0xff;
  b = colour & 0xff;

  for (int i=0; i < vgaWidth * vgaHeight; i++) {
    // RGBA
    surface[i * 4] = 0x64;
    surface[i * 4 + 1] = 0x95;
    surface[i * 4 + 2] = 0xED;
    surface[i * 4 + 3] = 0xFF;
  }
}


void initBuffer() {
  surface = (PByte)malloc(bufferSize);
}

export void cleanup() {
  if (surface != nil) {
    free(surface);
    surface = nil;
  }
}

export void update() {}

export void draw() {
  cls(0xFF6495ED);

}

export void init() {
  initBuffer();
}

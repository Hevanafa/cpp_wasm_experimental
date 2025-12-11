#include <emscripten.h>
#include <stdint.h>

// Pascal dialect of C++
#define export extern "C" EMSCRIPTEN_KEEPALIVE
#define PByte uint8_t*
#define nil nullptr
#define getmem malloc
#define freemem free
#define ne !=
#define eq ==
#define then_begin {
#define begin {
#define end }
#define procedure void

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
  surface = (PByte)getmem(320 * 200 * 4);
}

export procedure cleanup() begin
  if (surface ne nil) then_begin
    freemem(surface);
    surface = nil;
  end;
end

export void update() {}

export procedure draw() {
  fillCornflowerBlue();
}

export procedure init() {
  initBuffer();
}

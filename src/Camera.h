#pragma once

#include <cstdint>

struct Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t intensity;
};

class Camera {
public:
    static const int FB_WIDTH = 320;
    static const int FB_HEIGHT = 240;

    //static Pixel** getFrame();
    static Pixel* getLine(int line);
    //static void trashFrame(Pixel** frame);
    static void trashLine(Pixel* frame);

    static bool quadBoundary();
};

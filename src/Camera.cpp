
#include <cstdlib>
#include "E101.h"
#include "Camera.h"

/*Pixel** Camera::getFrame() {
    // Stub
    return NULL;

     Pixel** frame = new Pixel[FB_HEIGHT][FB_WIDTH];

    take_picture();
    for (int y = 0; y < FB_WIDTH; y++)
        for (int x = 0; x < FB_HEIGHT; x++) {
            frame[y][x].r = get_pixel(y, x, 0);
            frame[y][x].g = get_pixel(y, x, 1);
            frame[y][x].b = get_pixel(y, x, 2);
            frame[y][x].intensity = get_pixel(y, x, 3);
        }

    return frame;
} */

Pixel* Camera::getLine(int y) {
    Pixel* line = new Pixel[FB_WIDTH];
    if (y < 0 || y >= FB_HEIGHT) {
        return NULL;
    }
    take_picture();

    // Take picture and create pixels
    for (int x = 0; x < FB_WIDTH; x++) {
        line[x].r = get_pixel(y, x, 0);
        line[x].g = get_pixel(y, x, 1);
        line[x].b = get_pixel(y, x, 2);
        line[x].intensity = get_pixel(y, x, 3);
    }

    return line;
}

/*void Camera::trashFrame(Pixel** frame) {
    for (int i = 0; i < FB_HEIGHT; i++)
        delete[] frame[i];
    delete[] frame;
}*/

void Camera::trashLine(Pixel* line) {
    delete[] line;
}

bool Camera::quadBoundary() {
    return false;

    Pixel* line = getLine(FB_HEIGHT / 2);

    int intValue = 0;
    int greenValue = 0;
    int blueValue = 0;

    for (int i = 0; i < FB_WIDTH; i++) {
        intValue += (int)line[i].intensity;
        greenValue += (int)line[i].g;
        blueValue += (int)line[i].b;

        if(blueValue < 40 && greenValue < 40){
            return true;
        }
    }

    delete[] line;
    return false;
}

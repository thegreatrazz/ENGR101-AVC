
/**
 * Quadrant #2 code
 *
 * Follows a line
 */

#include <cstdio>
#include "E101.h"

#include "Drive.h"
#include "Camera.h"
#include "LineFollower.h"

void LineFollower::followTheLine() {
    int whiteCount = 0;
    Pixel* line = Camera::getLine(Camera::FB_HEIGHT * 2 / 3);

    bool error[Camera::FB_WIDTH];

    for (int x = 0; x < Camera::FB_WIDTH; x++) {
        auto value = line[x].intensity;
        int threshold = 70;

        error[x] = value < threshold;
        if (!error[x]) whiteCount += 1;
    }

    delete[] line;

    for (int x = 0; x < Camera::FB_WIDTH; x++) {
        printf(error[x] ? "#" : " ");
    }
    printf("\n");

    // If robot has lost line completely, reverse
    if (whiteCount >= Camera::FB_WIDTH) {
        Drive::setSpeed(-0.25);
        Drive::reverseAngle();
        return;
    }
    Drive::setSpeed(0.5);

    // Get the line
    int lineStart = -1;
    int lineLength = 0;
    for (int i = 0; i < Camera::FB_WIDTH; i++) {
        if (error[i]) {
            if (lineStart < 0) {
                lineStart = i;
                lineLength = 1;
            } else {
                lineLength++;
            }
        }
    }

    int lineCenter = lineStart + lineLength / 2;
    float angle = (float)(lineCenter - 160) / 160;

    Drive::setAngle(-angle);

    // Differential experimentation


}

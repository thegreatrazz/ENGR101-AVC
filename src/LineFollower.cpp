
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

int getLineCenter(int y) {
    // Threshold the line
    int whiteCount = 0;
    Pixel* line = Camera::getLine(y);

    bool error[Camera::FB_WIDTH];

    for (int x = 0; x < Camera::FB_WIDTH; x++) {
        auto value = line[x].intensity;
        int threshold = 70;

        error[x] = value < threshold;
        if (!error[x]) whiteCount += 1;
    }

    delete[] line;

    if (whiteCount >= Camera::FB_WIDTH) {
        return -1;
    }

    for (int x = 0; x < Camera::FB_WIDTH; x += 2) {
        printf(error[x] ? "." : " ");
    }
    printf("\n");

    // Get the line position
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

    return lineStart + lineLength / 2;
}

void LineFollower::followTheLine() {
    // Get the line
    printf("top ");
    int topLine = getLineCenter(Camera::FB_HEIGHT * 1 / 3);
    if (topLine < 0) printf("\n");
    printf("mid ");
    int midLine = getLineCenter(Camera::FB_HEIGHT / 2);
    if (midLine < 0) printf("\n");
    printf("bot ");
    int botLine = getLineCenter(Camera::FB_HEIGHT * 2 / 3);
    if (botLine < 0) printf("\n");

    int avgLine = (topLine + midLine + botLine) / 3;

    // If robot has lost line completely, reverse
    if (midLine < 0 || botLine < 0) {
        Drive::setSpeed(-0.2);
        sleep1(250);
        Drive::reverseAngle();
        return;
    }

    // Lel
    float angle = (float)(avgLine - 160) / 160;

    Drive::setSpeed(0.5);
    Drive::setAngle(-angle);
}

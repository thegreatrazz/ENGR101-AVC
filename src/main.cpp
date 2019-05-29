
// C/C++ libraries
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include <iostream>

// E101 library
#include "E101.h"

// Helper functions
#include "Drive.h"
#include "Camera.h"
#include "consts.h"

// Quad codes
#include "Gate.h"           // Quad 1
#include "LineFollower.h"   // Quad 2
#include "MazeFollower.h"   // Quad 3
#include "RubberDucky.h"    // Quad 4

int main() {
    init(0);
    open_screen_stream();

    //system("echo 'Team 4 presents'; figlet AVCBot -f slant | lolcat -a");

    int quad = 1;

    while (true) {
        switch (quad) {
        case 1:
            Gate::openSesame();
            //sleep1(1000);
            Drive::setSpeed(0.25);
            quad++;
            break;
        case 2:
            LineFollower::followTheLine();//
            break;
        case 3:
            // TBD
            break;
        case 4:
            // TBD
            break;
        default:
            printf("You messed up! Quad = %d\n", quad);
            return 1;
        }

        //update_screen();
        //if (Camera::quadBoundary()) quad += 1;
    }

    close_screen_stream();
}

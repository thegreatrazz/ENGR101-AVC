
// Project libraries
#include <cstdio>
#include "E101.h"
#include "consts.h"     // File with constants

// Our own header files
#include "Drive.h"

class Camera {
public:
    static void setAngle(int angle) {

    }

    static void getImage(){

        double whiteValMin = 130; //rough value for how much a white pixel will be
        double blackValMax = 80; //Same thing for black pixels

        int width = 320;
        int height = 240; //dimensions of image
        double image [width] [height]; //array with all pixels
        int countH = 0;
        int countW = 0; //the current count of the width and height

        //image [countW] [countH] - acccessing values in array

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                double value = get_pixel(y, x, 3);
                if (value > whiteValMin)
                    image[x][y] = 0;    //setting a white pixel in the array with value of 0
                else if (value < blackValMax)
                    image[x][y] = 1;    //setting the value of a black pixel in array to 1
            }
        }

        // Code to see how far away is the line from the middle - getting the values from only one height atm
        //Not sure if you want to make this a seperate method, will leave that up to you
        countH = 100;
        countW = 0;
        double total = 0;
        while(countW < 320){
            double var = image[countW][countH];
            int dist = countW - 160 ; // calculates the distance of the current pixel from the middle of the array
            total += (var * dist); //adds the value to the total - ideally the total should equal 0 if the line is in the middle
        }

    } //end of getImage

}; //end of class Camera

void tryPassword() {
    char ip_addr[15] = "130.195.6.196";
    unsigned short port = 1024;
    char message[] = "Please";
    char password[24];

    connect_to_server(ip_addr, port);
    send_to_server(message);
    receive_from_server(password);
    send_to_server(password);
}

int main() {
    printf("Hello world! Team 4\n");
    printf("Hello world! Perfect!\n");
    tryPassword();

    init(0);

    printf("Stop motor\n");
    Drive::setSpeed(0);
    sleep1(1000);

    for (double s = -1; s <= 1; s += 0.1) {
        printf("Speed: %f%%\n", s);
        Drive::setSpeed(s);
        for (double v = -1; v <= 1; v += 0.1) {
            printf("Direction: %f\n", v);
            Drive::setAngle(v);
        }
    }

    printf("Forwards\n");
    Drive::setSpeed(1);
        sleep1(1000);

    for (double v = -1; v <= 1; v += 0.1) {
        printf("%f\n", v);
        Drive::setAngle(v);
        sleep1(1000);
    }

    printf("Stop motor\n");
    Drive::setSpeed(0);
    sleep1(1000);

    return 0;
}

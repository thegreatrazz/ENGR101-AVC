
#include <cstdio>
#include "E101.h"

#define MOTOR_LEFT 1
#define MOTOR_RIGHT 5
#define MOTOR_CAMERA 4

#define MOTOR_DEADPOINT 48
#define MOTOR_LIMIT 12

float _speed;

class Drive {
private:
    static void setMotors(double leftPower, double rightPower) {
        set_motors(MOTOR_LEFT,  MOTOR_DEADPOINT + leftPower * MOTOR_LIMIT);
        set_motors(MOTOR_RIGHT, MOTOR_DEADPOINT - rightPower * MOTOR_LIMIT);
        hardware_exchange();
    }

public:
    static void setSpeed(float speed) {
        if (speed > 1) speed = 1;
        if (speed < -1) speed = -1;
        _speed = speed;

        Drive::setMotors(speed, speed);
    }

    static void setAngle(float direction) {
        if (direction == 0) {
            Drive::setMotors(_speed, _speed);
        } else if (direction < 0) {
            Drive::setMotors((direction + 1) * _speed, _speed);
        } else if (direction > 0) {
            Drive::setMotors(_speed, (1 - direction) * _speed);
        }
    }
};

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
    char id_addr[15] = "130.135.6.196";
    unsigned short port = 1024;
    char message[24] = "Please";

    connect_to_server(id_addr, port);
    send_to_server(message);
    receive_from_server(message);
    send_to_server(message);
}

int main() {
    printf("Hello world! Team 4\n");
    printf("Hello world! Perfect!\n");
    //tryPassword();

    init(0);

    printf("Stop motor\n");
    Drive::setSpeed(0);
    sleep1(1000);

    printf("Backwards\n");
    Drive::setSpeed(-1);
        sleep1(1000);

    for (double v = -1; v <= 1; v += 0.1) {
        printf("%f\n", v);
        Drive::setAngle(v);
        sleep1(1000);
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

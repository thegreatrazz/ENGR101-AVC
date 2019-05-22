
// Project libraries
#include <cstdio>
#include "E101.h"
#include "consts.h"     // File with constants

// Our own header files

#include "Drive.h"
//Chucked these in for debugging, i couldnt rememeber which one printed stuff out
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <math.h>
#include <stdlib.h>
#include <iostream>
int debug = 2;
double kp = 1.0/10000.0; // This value probably too big, needs to be even smaller, needs testing
int quad = 2;
class Camera {
public:
   // static void setAngle(int angle) { - dont think we need this

    //}

    static void getImage(){
        int whiteC = 0; //white count total - needed to see if robot lost line
        double whiteValMin = 80; //rough value for how much a white pixel will be - could make this one variable
        double blackValMax = 80; //Same thing for black pixels
         int width = 320;
        int height = 240; //dimensions of image
        double image [width] [height]; //array with all pixels


//----------------------------------QUAD 2-------------------------------------
        if(quad == 2){



            int countH = 0;
            int countW = 0; //the current count of the width and height

            //image [countW] [countH] - acccessing values in array

            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) { //getting values for all pixels - should change just for one row
                    double value = get_pixel(y, x, 3);

                    double greenValue = get_pixel(y,x,1); //Need to check if hit red marker
                    double blueValue = get_pixel(y, x, 2); //get blue value
                    if(blueValue < 40 && greenValue < 40){
                        quad += 1;// Call something when reached next quadrant
                        return;
                    }


                    if (value > whiteValMin)
                        image[x][y] = 0;    //setting a white pixel in the array with value of 0
                        whiteC += 1;
                    else if (value < blackValMax)
                        image[x][y] = 1;    //setting the value of a black pixel in array to 1
                }
            }

            if(whiteC >= width*height){ // If robot has lost line completely, reverse
                Drive::setSpeed(-0.5);

            } else{ //if line is present follow it

                // Code to see how far away is the line from the middle - getting the values from only one height atm
                //Not sure if you want to make this a seperate method, will leave that up to you
                countH = 100;
                countW = 0;
                double total = 0;
                while(countW < 320){
                    double var = image[countW][countH];
                    int dist = countW - 160 ; // calculates the distance of the current pixel from the middle of the array
                    total += (var * dist); //adds the value to the total - ideally the total should equal 0 if the line is in the middle
                    countW += 1;

                }
                double angle = total * kp;
                if(total <= 3 && total >= -3){ //robot go straight relatively

                    Drive::setAngle(angle);
                    Drive::setSpeed(0.8);
                }else if(total < -3){  //robot needs to turn left
                    Drive::setAngle(angle);
                    Drive::setSpeed(0.2);
                } else{
                    Drive::setAngle(angle); //Could change this to make it only 2 if statements in this since its the same as above
                    Drive::setSpeed(0.2);
                }
            }




//-------------------------------QUAD 3 Code-------------------------------------
        } else if(quad == 3){ //code for quadrant 3

            double leftTot = 0;
            double rightTot = 0; // The totals of value for each level
            double topTot = 0;
            double botTot = 0;
            int rCount = 0; // amount of red pixels

            int x = 20; //Checking Left line of image - vertical
            for(int y = 0; y < height; y++){
                double leftValue = get_pixel(y, x, 3);
                if( leftValue > blackValMax){
                    leftValue = 0;
                } else{
                    leftValue = 1;
                }
                leftTot += leftValue;
            }

            x = 300;
            for(int y = 0; y < height; y++){ // checking right line of image vertical
                double rightValue = get_pixel(y, x, 3);
                if( rightValue > blackValMax){
                    rightValue = 0;
                } else{
                    rightValue = 1;
                }
                rightTot += rightValue;
            }

            int y = 20;
            for(int x = 0; x<width; x++){ //Checking top horizontal line
                double topValue = get_pixel(y,x, 3);
                double greenVal = get_pixel(y,x, 1);
                double blueVal = get_pixel(y,x, 2);

                if(greenVal < 30 && blueVal < 30){ //Found a red pixel;
                    rCount += 1;
                    if( rCount > 5){ // Sufficient amount of red pixels found
                        quad += 1;
                         return;
                    }

                }

                if(topValue > blackValMax){
                    topValue = 0;
                } else{
                    topValue = 1;
                }
                topTot += topValue;
            }

            y = 200;
            for(int x = 0; x< width; x++){ //Checking bottom horizontal line - This is essentially checking to make sure robot is following line still in quadrant 3
                double botValue = get_pixel(y,x, 3);
                if(botValue > blackValMax){
                    botValue = 0;
                } else {
                    botValue = 1;
                }
                double distance = 160 - x;
                botTot += distance * botValue;

            }



            if( leftTot > 6){ // Turn left making decision
                Drive::setAngle (-1); // Not sure if this will make it turn 90 degrees
                Drive::setSpeed(0.3);


            } else if( topTot == 0 && botTot == 0 && leftTot == 0 && rightTot == 0){ // lost the line which is likely to happen if we always turn left (look at track) turn around by turning left
                Drive::setAngle(-1); //not sure if this will make it turn around
                Drive::setSpeed(0.6);

            } else if( topTot > 5 && rightTot > 5 && leftTot < 2){ // has option to go right or straight - go straight
                Drive::setAngle(0);
                Drive::setSpeed(1); //go straight and as fast as possible

            }

             else { // Go straight (Don't make decision)
                double angle = botTot * kp;
                if(botTot <= 3 && botTot >= -3){ //robot go straight relatively
                    Drive::setAngle(angle);
                    Drive::setSpeed(0.8);
                }else if(botTot < -3){  //robot needs to turn left
                    Drive::setAngle(angle);
                    Drive::setSpeed(0.2);
                } else{
                    Drive::setAngle(angle); //Could change this to make it only 2 if statements in this - Might not need this since lines are straight
                    Drive::setSpeed(0.2);
                }
            }

        } //end of quad 3
//------------------------------QUAD 4---------------------------------------
            else{ //Code for quadrant 4



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

    //tryPassword();
    init(0);



//-------------------------------DEBUG-----------------------------------------
    if(debug == 1){ //Check motors are working, when debug variable set to 1
        printf("Hello world! Team 4\n");
        printf("Hello world! Perfect!\n");


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

    } else if(debug == 2){ // Checking for camera values - Stopped working for some reason after a couple of tries - good threshold value around 70


        //int height = 240;
        int width = 320;
        int whiteValMin = 70; // pretty good value for black
        int blackValMax = 70;
        double image [width];

                for (int x = 0; x < width; x++) { //getting values for all pixels - should change just for one row
                    double value = get_pixel(120, x, 3);
                    //printf("Value of white %d", value); not sure if this printf works
                    //std :: cout << " Value of whiteness " <<value << std :: endl ;
                    //sleep1(300);
                    double greenValue = get_pixel(120,x,1); //Need to check if hit red marker
                    double blueValue = get_pixel(120, x, 2); //get blue value
                    if(blueValue < 40 && greenValue < 40){
                        quad += 1;// Call something when reached next quadrant

                    }


                    if (value > whiteValMin)
                        image[x] = 0;    //setting a white pixel in the array with value of 0
                    else if (value < blackValMax){
                        image[x] = 1;    //setting the value of a black pixel in array to 1
                        //sleep1(300);
                }
                 //printf("Value of pixel %d", image[x]); not sure if this printf works
                //std :: cout << " Value of pixel " <<image[x]<< std :: endl ;
                //sleep1(300);
            }
    //close_screen_stream();
    }
//-----------------------------------------------------------------------------



    while(true){ // actual code

        if(quad == 2){ //Code for quadrant 2 - following the line
            Camera::getImage();
        }

        else if(quad == 3){ //code for quadrant 3 - making decisions
            Camera::getImage();

        }

        else{ //code for quadrant 4 - going to cylinders
            //Add camera motor to move up
            //Implent code

        }



    }






    return 0;
}

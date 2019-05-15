
#include "E101.h"
#include "Drive.h"

double _Drive_speed = 0;
double _Drive_angle = 0;

void Drive::setMotors(double leftPower, double rightPower) {
    set_motors(MOTOR_LEFT,  MOTOR_DEADPOINT + leftPower * MOTOR_LIMIT);
    set_motors(MOTOR_RIGHT, MOTOR_DEADPOINT - rightPower * MOTOR_LIMIT);
    hardware_exchange();
}

void Drive::setSpeed(float speed) {
    if (speed > 1) speed = 1;
    if (speed < -1) speed = -1;
    _Drive_speed = speed;

    Drive::setAngle(_Drive_angle);
}

void Drive::setAngle(float direction) {
    if (direction == 0) {
        Drive::setMotors(_Drive_speed, _Drive_speed);
    } else if (direction < 0) {
        Drive::setMotors((direction + 1) * _Drive_speed, _Drive_speed);
    } else if (direction > 0) {
        Drive::setMotors(_Drive_speed, (1 - direction) * _Drive_speed);
    }
}

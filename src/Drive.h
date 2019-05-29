#pragma once

#define MOTOR_LEFT 1
#define MOTOR_RIGHT 5
#define MOTOR_CAMERA 3

#define MOTOR_DEADPOINT 48
#define MOTOR_LIMIT 12

class Drive {
private:
    static void setMotors(double leftPower, double rightPower);

public:
    static void setSpeed(float speed);
    static void setAngle(float direction);
    static void reverseAngle();
};

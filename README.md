# Autonomous Vechicle Challenge

This is the GitLab project for **\<\<TEAM NAME HERE>>**'s AVC robot.

## Useful links

The rest of the README is information detailing the source code and whatnot.
Here are some useful links if you're not looking for the code.

* [Project wiki - Please put documentation here](https://gitlab.ecs.vuw.ac.nz/nistorrare/engr-101-avc/wikis/home)
* [Snippers - Paste text not meant to be in Git](https://gitlab.ecs.vuw.ac.nz/nistorrare/engr-101-avc/snippets)
* [Issues - Document errors here](https://gitlab.ecs.vuw.ac.nz/nistorrare/engr-101-avc/issues)
* [Boards - Kanban-style boards](https://gitlab.ecs.vuw.ac.nz/nistorrare/engr-101-avc/boards)
* [Milestones - Project goals](https://gitlab.ecs.vuw.ac.nz/nistorrare/engr-101-avc/milestones)
* [Messenger Chat - General talk and planning](https://www.messenger.com/t/1011231269000788)

### Important documents

* [Project plan](docs/plan.md)

## Building

### On the Raspberry Pi

If you need to compile this on a Raspberry Pi. Make sure `meson` and
`g++` are installed, and then run the following.

```bash
meson build     # Create build structure
cd build
ninja           # You only need to run ninja to build now
./avcbot        # Start the bot program
```

This is way shorter than typing
`g++ -Wall -Wextra -le101 -o build/avcbot src/main.c` just to compile every time
you make a change.

### On a school machine (or your laptop running Linux or Mac)

Long story short, you can use Geany to make life easier for everyone. The Geany
project included with the code includes some scripts which will automatically
connect and upload the code to the Raspberry Pi and run it.

You can use it by going to **Project → Open…** in Geany and selecting
`AVCProject.geany`.

Just make sure you have [Geany](https://www.geany.org/), `ssh`, `rsync` and
`bash` installed. On macOS, all but Geany should already be on your computer.

### On Windows

All I can really say here is... [Good luck!](https://www.cygwin.com/)

## Writing code

### Geany

The Geany project allows you to more easily work, upload, compile and test the
project straight from a computer, without plugging in the Raspberry Pi between
code tweaks.

Here are the key maps:

* `F8` - **Set up Meson (Compile)** \
  Sets up the compiler on the Raspberry Pi and... well... *compiles*.
* `F9` - **Build** \
  Builds the program on the Raspberry Pi.
* `F5` - **Execute** \
  Runs the program on the Raspberry Pi and report output here.
* `Shift`+`F9` - **Upload code** \
  Uploads the latest revision of code to the Raspberry Pi.

Just remember, to build and run, you can just do `Shift`+`F9` → `F9` → `F5`.

### Code style

Please keep the code somewhat tidy and to the same sort of style. Here's what I
mean:

```cpp

#include <iostream>
#include "Motor.h"

class Motor {
    int pin;
    int angle;
    int speed;

public:
    Motor(int pin);
    ~Motor();

    void set_angle(int angle);
    void set_speed(int speed);

    int get_angle();
    int get_speed();
}

/** Entry point */
int main() {
    // This is an android with an arm connected to motor 3
    Motor* arm = new Motor(3);
    while (true) {
        // Wave it back and forth to say hi!
        arm.set_angle(45);
        sleep(500);
        arm.set_angle(135);
        sleep(500);
    }
}
```

Don't forget to comment. Humans still can't read each others' minds.

# Autonomous Vechicle Challenge

This is the GitLab project for Team 4's AVC robot.

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

## Managing Git

### Download anew
```bash
git clone https://gitlab.ecs.vuw.ac.nz/nistorrare/engr-101-avc.git
```

### Making your progress
```bash
git add .		# Add all the changes made
git commit -m "Message"	# Save them
git push		# Upload the code to GitLab
```

### Getting changes
```bash
git pull
```

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

### Project layout

The bulk of the source code is in the [`src`](src/) folder and
documentation meant for submission, like the [project plan](docs/plan.md)
are in the [`docs`](docs/) folder.

The `meson.build`, `pi.conf` and `AVCProject.geany` are support files meant
to make working on this project easier.

Please don't commit an PDFs, Word documents, the `build` folder and things
that could better be kept in snippets or the wiki.

### Geany

The Geany project allows you to more easily work, upload, compile and test the
project straight from a computer, without plugging in the Raspberry Pi between
code tweaks.

Here are the key maps:

* `F8` - **Build (_Compile_ in toolbar)** \
  Builds the code already uploaded to the Pi.
* `F9` - **Upload and Build (_Build_ in toolbar)** \
  Uploads the code to the Pi and builds it.
* `F5` - **Execute** \
  Runs the program on the Raspberry Pi and report output here.
* `Shift`+`F9` - **Upload** \
  Uploads the latest revision of code to the Raspberry Pi.
* `Ctrl`+`Shift`+`F9` - **Configure** \
  **Don't use it unless you know what you're doing.** It configures the project.

Just remember, to build and run, you can just do `F9` → `F5`.

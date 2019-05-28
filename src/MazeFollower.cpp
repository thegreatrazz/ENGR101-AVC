

//Get data for 3 lines - We also need to define how much black makes a line and also how much to turn for 90 degrees and 180 degrees


// One vertical on far left

// One vertical on far right

// And then the normal line from linefollower - to make sure the robot follows the line ( top horizontal)



//We want the robot to always turn left, if not keep going straight, and if not, follow the line, otherwise we'll have to turn around



//If the robot sees a line on left and right, turn left

//If the robot can keep going straight, go straight ( if there is a line ahead and a line right, go straight)

//If there is no additional lines, follow the line

//If there is nothing, turn around by turning to left (don't think we can reverse here cause robot will be facing wrong way)



//Check for quadrant boundary



//Decisions for the robot has to make during this quadrant - at other times there is only one line to follow

//Turn left with line on right
//Turn left with line on all sides
//Turn left with line on right
//Turn around 180 degrees
//Go straight even with line on right

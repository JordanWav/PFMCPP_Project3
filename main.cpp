/*
Project 3 - Part 1d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3. 
Part1 will be broken up into 5 separate steps 
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/

/*
Thing 1) House
5 properties:
    1) number of rooms (int)
    2) number of windows (int)
    3) name of owner(s) (std::string)
    4) number of doors (int)
    5) number of beds (int)
3 things it can do:
    1) furnish house
    2) open front door
    3) close window
 */

/*
Thing 2) Xbox
5 properties:
    1) amount of space (float)
    2) number of games downloaded (int)
    3) number of controllers (int)
    4) name of profile (std::string)
    5) number of friends online (int)
3 things it can do:
    1) open game
    2) download game
    3) turn on Xbox
 */

/*
Thing 3) Logic Pro
5 properties:
    1) project sample rate (float)
    2) name of input device (std::string)
    3) name of project (std::string)
    4) number of tracks (int)
    5) tempo (double)
3 things it can do:
    1) create a new instrument track
    2) insert plugin
    3) record performance
 */

/*
Thing 4) Computer Monitor
5 properties:
    1) number of default modes (int)
    2) brightness value (int)
    3) speaker volume (int)
    4) number of possible inputs (int)
    5) number of user profiles (int)

3 things it can do:
    1) increase monitor brightness
    2) change profiles
    3) switch to HDMI input
 */

/*
 Thing 5) workbench
5 properties:
    1) number of tools (int)
    2) name of tool brand (std::string)
    3) height of workbench (float)
    4) weight of hammer (float)
    5) number of broken tools (int)
3 things it can do:
    1) open toolbox
    2) repair an item
    3) put away tools
 */

/*
Thing 6) exercise equipment
5 properties:
    1) weight of dumbbell (float)
    2) number of dumbbells (int)
    3) value of equipment (float, dollars)
    4) type of workout (std::string)
    5) type of equipment (std::string)
3 things it can do:
    1) lift dumbbells
    2) add weight to benchpress
    3) move equipment
 */

/*
Thing 7) storage containers
5 properties:
    1) number of boxes (int)
    2) weight of selected box (float)
    3) category of box (std::string)
    4) label on box (char)
    5) weight of all boxes (float)
3 things it can do:
    1) label a box
    2) pick up a box
    3) fill a box
 */

/*
Thing 8) cars
5 properties:
    1) car type (std::string, electric or gas)
    2) car brand (std::string)
    3) number of wheels (int)
    4) number of doors
    5) owner of car (std::string, name)
3 things it can do:
    1) open car door
    2) park car
    3) drive car
 */

/*
Thing 9) shelves
5 properties: 
    1) name of object (std::string)
    2) category of object (char)
    3) number of shelves (int)
    4) number of items on a specific shelf (int)
    5) weight of items on a specific shelf (float)
3 things it can do:
    1) store object on shelf
    2) sort items on shelf
    3) grab an item off the shelf
 */

 /*
Thing 10) Garage
5 properties:
    1) workbench
    2) exercise equipment
    3) storage containers
    4) cars
    5) shelves
3 things it can do:
    1) open garage door
    2) use workbench
    3) park car in garage
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
      
    std::cout << "good to go!" << std::endl;
}

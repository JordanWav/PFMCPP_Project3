 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
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
 struct House 
 {
    // number of rooms (int)
    int numRooms = 6;
    // number of windows (int)
    int numWindows = 12;
    // name of owner(s) (std::string)
    std::string ownerName = "James";
    // number of doors (int)
    int numDoors = 6;
    // number of beds (int)
    int numBeds = 2;

    struct Kitchen 
    {
        // number of knives in kitchen (int)
        int numKnives = 5;
        // number of plates in kitchen (int)
        int numPlates = 8;
        // name of toaster brand (std::string)
        std::string toasterBrand = "GE";
        // number of doors on fridge (int)
        int numFridgeDoors = 1;
        // number of shelves in kitchen (int)
        int numShelves = 4;

        void microwaveChicken(float microwaveTime = 60.f);  
        bool madeSalad(std::string lettuceBrand, bool includeTomatoes = true, std::string dressing = "Italian");
        int preheatOven(float ovenTemperature);
    };
    // furnish house
    bool furnishHouse(House myHouse);
    // open front door
    void openFrontDoor(std::string door = "front door");
    // close window
    bool closeWindow(House::Kitchen myKitchen);
};

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

struct Xbox
{
    // amount of space (float)
    float amountOfSpace = 500.f;
    // number of games downloaded (int)
    int numGamesDownloaded = 10;
    // number of controllers (int)
    int numControllers = 1;
    // name of profile (std::string)
    std::string profileName = "Profile1";
    // number of friends online (int)
    int numFriendsOnline = 8;

    struct Game
    {
        // size of game (float)
        float sizeOfGame = 55.5f;
        // category of game (std::string)
        std::string gameCategory = "RPG";
        // rating of game (char)
        char gameRating = 'M';
        // hours of game played (float)
        float timePlayed = 15.2f;
        // number of achievements completed (int)
        int numCompletedAchievements = 5;

        bool openGame(std::string gameName);
        bool completeAchievement(std::string achievementName, int numPoints = 5);
        void changeMenu(char buttonPressed = 'b', std::string currentMenu = "Main menu");
    };
    // open game
    bool openGame(Xbox::Game skyrim);
    // download game
    bool downloadGame(Xbox::Game haloInfinite);
    // turn on Xbox
    void turnOnXbox(Xbox myXbox);
};

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

struct LogicPro
{
    // project sample rate (float)
    float sampleRate = 48000.f;
    // name of input device (std::string)
    std::string nameOfInputDevice = "SSL 2+";
    // name of project (std::string)
    std::string nameOfProject = "my project";
    // number of tracks (int)
    int numTracks = 12;
    // tempo (double)
    double tempo = 99.9;

    // create a new instrument track
    std::string createInstrumentTrack(LogicPro trackA);
    // insert plugin
    std::string insertPlugin(LogicPro trackA);
    // record performance
    int recordPerformance(LogicPro trackB);
};

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

 struct ComputerMonitor
 {    
    // number of default modes (int)
    int numDefaultModes = 8;
    // brightness value (int)
    int brightnessValue = 50;
    // speaker volume (int)
    int speakerVolume = 0;
    // number of possible inputs (int)
    int numPossibleInputs = 3;
    // number of user profiles (int)
    int numUserProfiles = 3;

     // increase monitor brightness
    int increaseBrightness(ComputerMonitor myMonitor);
    // change profiles
    std::string changeProfiles(ComputerMonitor myMonitor);
    // switch to HDMI input
    bool toHDMIInput(ComputerMonitor myMonitor);
};

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

struct Workbench
{    
    // number of tools (int)
    int numTools = 15;
    // name of tool brand (std::string)
    std::string toolBrand = "craftsman";
    // height of workbench (float)
    float workbenchHeight = 36;
    // weight of hammer (float)
    float hammerWeight = 1.5f;
    // number of broken tools (int)
    int numBrokenTools = 0;    

    // open toolbox
    bool openToolbox(Workbench myWorkbench);
    // repair an item
    bool repairItem(Workbench myWorkbench);
    // put away tools
    int putAwayTools(Workbench myWorkbench);
};

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

struct ExerciseEquipment
{
    // weight of dumbbell (float)
    float dumbbellWeight = 12.f;
    // number of dumbbells (int)
    int numDumbbells = 4;
    // value of equipment (float, dollars)
    float equipmentValue = 200.35f;
    // type of workout (std::string)
    std::string workoutType = "endurance";
    // type of equipment (std::string)
    std::string equipmentType = "benchpress";

    // lift dumbbells
    int liftDumbbell(ExerciseEquipment dumbbell);
    // add weight to benchpress
    float addWeight(ExerciseEquipment benchpress);
    // move equipment
    bool moveEquipment(ExerciseEquipment equipment);
};



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

struct StorageContainers
{
    // number of boxes (int)
    int numBoxes = 10;
    // weight of selected box (float)
    float weightOfBox = 12.5f;
    // category of box (std::string)
    std::string boxCategory = "books";
    // label on box (char)
    char boxLabel = 'b';
    // weight of all boxes (float)
    float allBoxesWeight = 115.23f;
    
    // label a box
    char labelBox(StorageContainers boxA);
    // pick up a box
    std::string pickUpBox(StorageContainers boxD);
    // fill a box
    int fillBox(StorageContainers emptyBoxA);
};

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

struct Cars
{
    // car type (std::string, electric or gas)
    std::string carType = "gas";
    // car brand (std::string)
    std::string carBrand = "Ford";
    // number of wheels (int)
    int numWheels = 4;
    // number of doors
    int numDoors = 4;
    // owner of car (std::string, name)
    std::string ownerOfCar = "Jason";

    // open car door
    void openCarDoor(Cars carA);
    // park car
    bool parkCar(Cars carB);
    // drive car
    bool driveCar(Cars carA);
};

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

struct Shelves
{
    // name of object (std::string)
    std::string objectName = "shovel";
    // category of object (char)
    char objectCategory = 'w';
    // number of shelves (int)
    int numShelves = 8;
    // number of items on a specific shelf (int)
    int numItemsOnShelf = 5;
    // weight of items on a specific shelf (float)
    float weightOfItemsOnShelf = 15.5f;

     // store object on shelf
    bool storeObjectOnShelf(Shelves shelfA);
    // sort items on shelf
    void sortShelfItems(std::string item, int numItems, bool alphabetical = true);
    // grab an item off the shelf
    std::string grabItem(Shelves shelfB);
};


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

struct Garage 
{
    Workbench workbench;
    ExerciseEquipment equipment;
    StorageContainers container;
    Cars car;
    Shelves shelf;

    bool openGarageDoor(Garage myGarage);
    void useWorkbench(Workbench myWorkbench);
    bool parkCarInGarage(Cars myCar);
};


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

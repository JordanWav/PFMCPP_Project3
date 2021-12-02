/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




 struct House 
 {
    int numRooms = 6;
    int numWindows = 12;
    std::string ownerName = "James";
    int numDoors = 6;
    int numBeds = 2;

    struct Kitchen 
    {
        int numKnives = 5;
        int numPlates = 8;
        std::string toasterBrand = "GE";
        int numFridgeDoors = 1;
        int numShelves = 4;

        void microwaveChicken(float microwaveTime = 60.f);  
        bool madeSalad(std::string lettuceBrand, bool includeTomatoes = true, std::string dressing = "Italian");
        float preheatOven(float ovenTemperature);
    };
    bool furnishHouse(House myHouse);
    void openFrontDoor(std::string door = "front door");
    bool closeWindow(House::Kitchen myKitchen);
};

void House::Kitchen::microwaveChicken( float microwaveTime)
{
    float instructions = 45.f;
    microwaveTime = instructions;    
    
    if( microwaveTime >= 45.f )
    {
        std::cout << "Ready!" << std::endl;
    }
    else
    {
        std::cout << "Not Ready!" << std::endl;
    }
}

bool House::Kitchen::madeSalad( std::string lettuceBrand, bool includeTomatoes, std::string dressing)
{
    lettuceBrand = "Good Lettuce";

    if( includeTomatoes == true && dressing == "Italian" )
    {
        return true;
    }
    else
    {
        return false;
    }
}

float House::Kitchen::preheatOven(float ovenTemperature)
{
    ovenTemperature = 350.f;
    if (ovenTemperature > 0.f)
    {
        return ovenTemperature;
    }
    else
    {
        return 0.f;
    }
}

bool House::furnishHouse(House myHouse)
{   
    return myHouse.numBeds == 0;
}

void House::openFrontDoor(std::string door)
{
    if ( door == "front door" )
    {
        std::cout << "Need to open front door" << std::endl;
    }
    else
    {
        std::cout << "Not the front door" << std::endl;
    }
}

bool House::closeWindow(House::Kitchen myKitchen)
{
    return myKitchen.numShelves > 1;
}

struct Xbox
{
    float amountOfSpace = 500.f;
    int numGamesDownloaded = 10;
    int numControllers = 1;
    std::string profileName = "Profile1";
    int numFriendsOnline = 8;

    struct Game
    {
        float sizeOfGame = 55.5f;
        std::string gameCategory = "RPG";
        char gameRating = 'M';
        float timePlayed = 15.2f;
        int numCompletedAchievements = 5;

        bool openGame(std::string gameName);
        bool completeAchievement(std::string achievementName, int numPoints = 5);
        void changeMenu(char buttonPressed = 'b', std::string currentMenu = "Main menu");
    };
    bool openGame(Xbox::Game skyrim);
    bool downloadGame(Xbox::Game haloInfinite);
    void turnOnXbox(Xbox myXbox);
};


bool Xbox::Game::openGame(std::string gameName)
{
    return gameName == "Valid";
}

bool Xbox::Game::completeAchievement(std::string achievementName, int numPoints)
{
    if ( achievementName == "Valid" )
    {
        numPoints += 5;
        return true;
    }
    return false;
}

void Xbox::Game::changeMenu(char buttonPressed, std::string currentMenu)
{
    if ( buttonPressed == 'b' )
    {
        currentMenu = "Main menu";
    }

}

bool Xbox::openGame(Xbox::Game skyrim)
{
    return skyrim.gameCategory == "RPG";
}

bool Xbox::downloadGame(Xbox::Game haloInfinite)
{
    return Xbox::amountOfSpace >= haloInfinite.sizeOfGame;
}

void Xbox::turnOnXbox(Xbox myXbox)
{
    myXbox.profileName = "My Profile";   
}


struct LogicPro
{
    float sampleRate = 48000.f;
    std::string nameOfInputDevice = "SSL 2+";
    std::string nameOfProject = "my project";
    int numTracks = 12;
    double tempo = 99.9;

    std::string createInstrumentTrack(LogicPro trackA);
    std::string insertPlugin(LogicPro trackA);
    int recordPerformance(LogicPro trackB);
};

std::string LogicPro::createInstrumentTrack(LogicPro trackA)
{
    if ( trackA.numTracks < 1000 )
    {
        return "new track";
    }
    std::cout << "could not make a new track" << std::endl;
    return "!";
}

std::string LogicPro::insertPlugin(LogicPro trackA)
{
    if ( trackA.nameOfProject == "my project" )
    {
        return "FabFilter Pro-Q 3";
    }
    return "no plugin";
}

int LogicPro::recordPerformance(LogicPro trackB)
{
    if ( trackB.nameOfInputDevice == "SSL 2+")
    {
        return 0;
    }
    if ( trackB.nameOfInputDevice == "Focusrite Scarlett 2i2")
    {
        std::cout << "Wrong Input Device Selected" << std::endl;
        return 1; 
    }
    if ( trackB.numTracks == 0 )
    {
        std::cout << "Please Create a New Track" << std::endl;
        return 2;
    }
    std::cout << "Something Went Wrong... Please Try Again" << std::endl;
    return 3;
}


 struct ComputerMonitor
 {    
    int numDefaultModes = 8;
    int brightnessValue = 50;
    int speakerVolume = 0;
    int numPossibleInputs = 3;
    int numUserProfiles = 3;

    int increaseBrightness(ComputerMonitor myMonitor);
    std::string changeProfiles(ComputerMonitor myMonitor);
    bool toHDMIInput(ComputerMonitor myMonitor);
};

int ComputerMonitor::increaseBrightness(ComputerMonitor myMonitor)
{
    while ( myMonitor.brightnessValue < 30 )
    {
        myMonitor.brightnessValue += 1;
    }
    return myMonitor.brightnessValue;
}

std::string ComputerMonitor::changeProfiles(ComputerMonitor myMonitor)
{
    if ( myMonitor.numUserProfiles == 2 )
    {
        return "Profile 2";
    }
    return "Profile 1";
}

bool ComputerMonitor::toHDMIInput(ComputerMonitor myMonitor)
{
    if ( myMonitor.numPossibleInputs >= 2)
    {
        return true;
    }
    std::cout << "no HDMI input available" << std::endl;
    return false;
}

struct Workbench
{    
    int numTools = 15;
    std::string toolBrand = "craftsman";
    float workbenchHeight = 36;
    float hammerWeight = 1.5f;
    int numBrokenTools = 0;    

    bool openToolbox(Workbench myWorkbench);
    bool repairItem(Workbench myWorkbench);
    int putAwayTools(Workbench myWorkbench);
};

bool Workbench::openToolbox(Workbench myWorkbench)
{
    return myWorkbench.numTools > 0;
}

bool Workbench::repairItem(Workbench myWorkbench)
{
    return myWorkbench.numBrokenTools > 0;
}

int Workbench::putAwayTools(Workbench myWorkbench)
{
    return myWorkbench.numTools;
}



struct ExerciseEquipment
{
    float dumbbellWeight = 12.f;
    int numDumbbells = 4;
    float equipmentValue = 200.35f;
    std::string workoutType = "endurance";
    std::string equipmentType = "benchpress";

    int liftDumbbell(ExerciseEquipment dumbbell);
    float addWeight(ExerciseEquipment benchpress);
    bool moveEquipment(ExerciseEquipment equipment);
};

int ExerciseEquipment::liftDumbbell(ExerciseEquipment dumbbell)
{
    if ( dumbbell.numDumbbells > 1 )
    {
        return 2;
    }
    return 0;
}

float ExerciseEquipment::addWeight(ExerciseEquipment benchpress)
{
    if ( benchpress.workoutType == "strength training")
    {
        return 20.f;
    }
    return 0.f;
}

bool ExerciseEquipment::moveEquipment(ExerciseEquipment equipment)
{
    return equipment.equipmentType != "pullup bar";
}

struct StorageContainers
{
    int numBoxes = 10;
    float weightOfBox = 12.5f;
    std::string boxCategory = "books";
    char boxLabel = 'b';
    float allBoxesWeight = 115.23f;

    char labelBox(StorageContainers boxA);
    std::string pickUpBox(StorageContainers boxD);
    int fillBox(StorageContainers emptyBoxA);
};

char StorageContainers::labelBox(StorageContainers boxA)
{   
    if ( boxA.boxLabel != 'A')
    {
        boxA.boxLabel = 'A';
    }
    return boxA.boxLabel;
}

std::string StorageContainers::pickUpBox(StorageContainers boxD)
{
    return boxD.boxCategory;
}

int StorageContainers::fillBox(StorageContainers emptyBoxA)
{
    if ( emptyBoxA.weightOfBox < 1.f )
    {
        emptyBoxA.numBoxes += 1;
        return emptyBoxA.numBoxes;
    }
    return 0;
}

struct Cars
{
    std::string carType = "gas";
    std::string carBrand = "Ford";
    int numWheels = 4;
    int numDoors = 4;
    std::string ownerOfCar = "Jason";

    void openCarDoor(Cars carA);
    bool parkCar(Cars carB);
    bool driveCar(Cars carA);
};

void Cars::openCarDoor(Cars carA)
{
    if ( carA.ownerOfCar == "Me" )
    {
        std::cout << "My Car" << std::endl;
    }

    else
    {
        std::cout << "Not My Car... don't open"  << std::endl;
    }

}

bool Cars::parkCar(Cars carB)
{
    return carB.numWheels > 1;
}

bool Cars::driveCar(Cars carA)
{
    return carA.ownerOfCar == "Me" || carA.ownerOfCar == "Jason";
}

struct Shelves
{
    std::string objectName = "shovel";
    char objectCategory = 'w';
    int numShelves = 8;
    int numItemsOnShelf = 5;
    float weightOfItemsOnShelf = 15.5f;

    bool storeObjectOnShelf(Shelves shelfA);
    void sortShelfItems(std::string item, int numItems, bool alphabetical = true);
    std::string grabItem(Shelves shelfB);
};

bool Shelves::storeObjectOnShelf(Shelves shelfA)
{
    return shelfA.numItemsOnShelf < 10;
}

void Shelves::sortShelfItems(std::string item, int numItems, bool alphabetical)
{
    while ( alphabetical == false && numItems > 0 && item == "unsorted")
    {
        numItems -= 1;
        item = "sorted";

        if ( numItems == 0 )
        {
            alphabetical = true;
        }
    }
}

std::string Shelves::grabItem(Shelves shelfB)
{
    return shelfB.objectName;
}

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

bool Garage::openGarageDoor(Garage myGarage)
{
    Garage myGarageOpened;
    myGarage = myGarageOpened;
    return true;
}

void Garage::useWorkbench(Workbench myWorkbench)
{
    if ( myWorkbench.numTools > 0 )
    {
        std::cout << "Using Workbench" << std::endl;
    }
}

bool Garage::parkCarInGarage(Cars myCar)
{
    return myCar.carType == "Ford";
}



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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}

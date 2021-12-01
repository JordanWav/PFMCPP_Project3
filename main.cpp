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

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run( int howFast, bool startWithLeftFoot);

    struct Foot
    {
        int stepSize()
        {
            int size = 5;
            return size;
        }
        void stepForward()
        {
        
        }
    };

    Foot leftFoot;
    Foot rightFoot;
};

void Person::run( int howFast, bool startWithLeftFoot)
{
    howFast = 10;
    
    if( startWithLeftFoot == true )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }

    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}




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
    bool ready;
    
    if( microwaveTime >= 45.f )
    {
        ready = true;
    }

    else
    {
        ready = false;
    }

    if( ready == true )
    {
        std::cout << "Ready!" << std::endl;
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
    
    if( myHouse.numBeds == 0 )
    {
        return true; // furnish the house
    }

    else
    {
        return false; // don't furnish the house
    }
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
    if ( myKitchen.numShelves > 1 )
    {
        return true; 
    }

    else
    {
        return false;
    }

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
    if ( gameName == "Valid" )
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Xbox::Game::completeAchievement(std::string achievementName, int numPoints)
{
    if ( achievementName == "Valid" )
    {
        numPoints += 5;
        return true;
    }

    else
    {
        numPoints += 0;
        return false;
    }
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
    if ( skyrim.gameCategory == "RPG" )
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Xbox::downloadGame(Xbox::Game haloInfinite)
{
    Xbox myXbox;
    
    if ( myXbox.amountOfSpace >= haloInfinite.sizeOfGame )
    {
        return true;
    }

    else
    {
        return false;
    }
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

    else
    {
        std::cout << "could not make a new track" << std::endl;
    }
    return "";
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

    else
    {
        std::cout << "Something Went Wrong... Please Try Again" << std::endl;
        return 3;
    }
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

    else
    {
        return "Profile 1";
    }
}

bool ComputerMonitor::toHDMIInput(ComputerMonitor myMonitor)
{
    if ( myMonitor.numPossibleInputs >= 2)
    {
        return true;
    }

    else
    {
        std::cout << "no HDMI input available" << std::endl;
        return false;
    }
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
    if ( myWorkbench.numTools > 0 )
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Workbench::repairItem(Workbench myWorkbench)
{
    if ( myWorkbench.numBrokenTools > 0 )
    {
        return true;
    }

    else
    {
        return false;
    }
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

    else
    {
        return 0;
    }
}

float ExerciseEquipment::addWeight(ExerciseEquipment benchpress)
{
    if ( benchpress.workoutType == "strength training")
    {
        return 20.f;
    }

    else
    {
        return 0.f;
    }
}

bool ExerciseEquipment::moveEquipment(ExerciseEquipment equipment)
{
    if ( equipment.equipmentType != "pullup bar")
    {
        return true;
    }
    
    else
    {
        return false;
    }

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

    else
    {
        return 0;
    }
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
    if ( carB.numWheels > 1 )
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Cars::driveCar(Cars carA)
{
    if ( carA.ownerOfCar == "Me" || carA.ownerOfCar == "Jason")
    {
        return true;
    }

    else
    {
        return false;
    }
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
    if ( shelfA.numItemsOnShelf < 10 )
    {
        return true;
    }

    else
    {
        return false;
    }
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
    if ( myCar.carType == "Ford" )
    {
        return true;
    }

    else
    {
        return false;
    }
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
      
    std::cout << "good to go!" << std::endl;
}

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
    House();
    int numRooms = 6;
    int numWindows = 12;
    std::string ownerName = "James";
    int numDoors = 6;
    int numBeds = 2;

    struct Kitchen 
    {
        Kitchen();
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

House::House()
{
    std::cout << "House Constructed" << std::endl;
    std::cout << std::endl;
}

House::Kitchen::Kitchen()
{
    numKnives = 10;
    std::cout << "Kitchen Constructed" << std::endl;
    std::cout << std::endl;
}

void House::Kitchen::microwaveChicken( float microwaveTime)
{
    if( microwaveTime >= 45.f )
    {
        std::cout << "Cooked for " << microwaveTime << " seconds:" << " Chicken cooked!" << std::endl;
    }
    else
    {
        std::cout << "Cooked for " << microwaveTime << " seconds:" << " Chicken not finished cooking!" << std::endl;
    }
}

bool House::Kitchen::madeSalad(std::string lettuceBrand, bool includeTomatoes, std::string dressing)
{
    if( includeTomatoes == true && dressing == "Italian" && lettuceBrand == "Lettuce!" )
    {
        std::cout << "Made salad!" << std::endl;
        return true;
    }
    std::cout << "Didn't make salad" << std::endl;
    return false;
}

float House::Kitchen::preheatOven(float ovenTemperature)
{
    if (ovenTemperature > 0.f)
    {
        std::cout << "Oven preheated to: " << ovenTemperature << std::endl;
        return ovenTemperature;
    }
    return 0.f;
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
    Xbox();
    float amountOfSpace = 500.f;
    int numGamesDownloaded = 10;
    int numControllers = 1;
    std::string profileName = "Profile1";
    int numFriendsOnline = 8;

    struct Game
    {
        Game();
        float sizeOfGame = 55.5f;
        std::string gameCategory = "RPG";
        char gameRating = 'M';
        float timePlayed = 15.2f;
        int numCompletedAchievements = 5;

        bool isGame(std::string gameName);
        bool completeAchievement(std::string achievementName, int numPoints = 5);
        void changeMenu(char buttonPressed = 'b', std::string currentMenu = "Main menu");
    };
    bool openGame(Xbox::Game skyrim);
    bool downloadGame(Xbox::Game haloInfinite);
    void turnOnXbox(Xbox myXbox);
};

Xbox::Xbox()
{
    std::cout << "Xbox Constructed" << std::endl;
    amountOfSpace = 1000.f;
    std::cout << std::endl;
}

Xbox::Game::Game()
{
    std::cout << "Game Constructed" << std::endl;
    std::cout << std::endl;
}


bool Xbox::Game::isGame(std::string gameName)
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
    std::cout << "No achievements!" << std::endl;
    return false;
}

void Xbox::Game::changeMenu(char buttonPressed, std::string currentMenu)
{
    if ( buttonPressed == 'b' )
    {
        currentMenu = "main menu";
        std::cout << "You are now at the main menu" << std::endl;
    }
    if ( buttonPressed == 'a' )
    {
        currentMenu = "start menu";
        std::cout << "You are now at the start menu" << std::endl;
    }

}

bool Xbox::openGame(Xbox::Game skyrim)
{
    if( skyrim.gameCategory == "RPG" )
    {
        std::cout << "Game Opened!" << std::endl;
        return true;
    }
    return false;
}

bool Xbox::downloadGame(Xbox::Game haloInfinite)
{
    if( Xbox::amountOfSpace >= haloInfinite.sizeOfGame )
    {
        std::cout << "Game Downloaded!" << std::endl;
        return true;
    }
    return false;
}

void Xbox::turnOnXbox(Xbox myXbox)
{
    std::cout << "Xbox On!" << std::endl;
    myXbox.profileName = "My Profile";   
}


struct LogicPro
{
    LogicPro();
    float sampleRate = 48000.f;
    std::string nameOfInputDevice = "SSL 2+";
    std::string nameOfProject = "my project";
    int numTracks = 12;
    double tempo = 99.9;

    std::string createInstrumentTrack(LogicPro trackA);
    std::string insertPlugin(LogicPro trackA);
    int recordPerformance(LogicPro trackB);
};

LogicPro::LogicPro()
{
    nameOfProject = "Project 1";
    std::cout << "LogicPro Constructed" << std::endl;
    std::cout << std::endl;
}

std::string LogicPro::createInstrumentTrack(LogicPro trackA)
{
    if ( trackA.numTracks < 1000 )
    {
        std::cout << "New track created!" << std::endl;
        return "new track";
    }
    std::cout << "Could not make a new track" << std::endl;
    return "!";
}

std::string LogicPro::insertPlugin(LogicPro trackA)
{
    if ( trackA.nameOfProject == "my project" )
    {
        std::cout << "Plugin inserted!" << std::endl;
        return "FabFilter Pro-Q 3";
    }
    std::cout << "Plugin could not be inserted!" << std::endl;
    return "no plugin";
}

int LogicPro::recordPerformance(LogicPro trackB)
{
    if ( trackB.nameOfInputDevice == "SSL 2+")
    {
        std::cout << "Input device: " << trackB.nameOfInputDevice << std::endl;
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
    ComputerMonitor();
    int numDefaultModes = 8;
    int brightnessValue = 50;
    int speakerVolume = 0;
    int numPossibleInputs = 3;
    int numUserProfiles = 3;

    int increaseBrightness(ComputerMonitor myMonitor);
    std::string changeProfiles(ComputerMonitor myMonitor);
    bool toHDMIInput(ComputerMonitor myMonitor);
};

ComputerMonitor::ComputerMonitor()
{
    brightnessValue = 30;
    std::cout << "ComputerMonitor Constructed" << std::endl;
    std::cout << std::endl;
}

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
        std::cout << "Switched to 'Profile 2'" << std::endl;
        return "Profile 2";
    }
    std::cout << "Couldn't change profiles!" << std::endl;
    return "Profile 1";
}

bool ComputerMonitor::toHDMIInput(ComputerMonitor myMonitor)
{
    if ( myMonitor.numPossibleInputs >= 2)
    {
        std::cout << "Changed input to HDMI" << std::endl;
        return true;
    }
    std::cout << "No HDMI input available" << std::endl;
    return false;
}

struct Workbench
{    
    Workbench();
    int numTools = 15;
    std::string toolBrand = "craftsman";
    float workbenchHeight = 36;
    float hammerWeight = 1.5f;
    int numBrokenTools = 0;    

    bool openToolbox(Workbench myWorkbench);
    bool repairItem(Workbench myWorkbench);
    int putAwayTools(Workbench myWorkbench);
};

Workbench::Workbench()
{
    std::cout << "Workbench Constructed" << std::endl;
    std::cout << std::endl;
}


bool Workbench::openToolbox(Workbench myWorkbench)
{
    std::cout << "Number of tools: " << myWorkbench.numTools << std::endl;
    return myWorkbench.numTools > 0;
}

bool Workbench::repairItem(Workbench myWorkbench)
{
    if( myWorkbench.numBrokenTools > 0 )
    {
        std::cout << myWorkbench.numBrokenTools << " items repaired!" << std::endl;
        return true;
    }
    return false;
}

int Workbench::putAwayTools(Workbench myWorkbench)
{
    return myWorkbench.numTools;
}

struct ExerciseEquipment
{
    ExerciseEquipment();
    float dumbbellWeight = 12.f;
    int numDumbbells = 4;
    float equipmentValue = 200.35f;
    std::string workoutType = "endurance";
    std::string equipmentType = "benchpress";

    int liftDumbbell(ExerciseEquipment dumbbell);
    float addWeight(ExerciseEquipment benchpress);
    bool moveEquipment(ExerciseEquipment equipment);
};

ExerciseEquipment::ExerciseEquipment()
{
    std::cout << "ExerciseEquipment Constructed" << std::endl;
    std::cout << std::endl;
}

int ExerciseEquipment::liftDumbbell(ExerciseEquipment dumbbell)
{
    if ( dumbbell.numDumbbells > 1 )
    {
        std::cout << "Lifting dumbbells!" << std::endl;
        return 2;
    }
    return 0;
}

float ExerciseEquipment::addWeight(ExerciseEquipment benchpress)
{
    if ( benchpress.workoutType == "strength training")
    {
        std::cout << "Added weight!" << std::endl;
        return 20.f;
    }
    std::cout << "Didn't add any weight" << std::endl;
    return 0.f;
}

bool ExerciseEquipment::moveEquipment(ExerciseEquipment equipment)
{
    return equipment.equipmentType != "pullup bar";
}

struct StorageContainers
{
    StorageContainers();
    int numBoxes = 10;
    float weightOfBox = 12.5f;
    std::string boxCategory = "books";
    char boxLabel = 'b';
    float allBoxesWeight = 115.23f;

    char labelBox(StorageContainers boxA);
    std::string pickUpBox(StorageContainers boxD);
    int fillBox(StorageContainers emptyBoxA);
};

StorageContainers::StorageContainers()
{
    std::cout << "StorageContainers Constructed" << std::endl;
    std::cout << std::endl;
}

char StorageContainers::labelBox(StorageContainers boxA)
{   
    if ( boxA.boxLabel != 'A')
    {
        std::cout << "Box label changed to 'A'" << std::endl;
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
    std::cout << "Boxes filled!" << std::endl;
    return 0;
}

struct Cars
{
    Cars();
    std::string carType = "gas";
    std::string carBrand = "Ford";
    int numWheels = 4;
    int numDoors = 4;
    std::string ownerOfCar = "Jason";

    void openCarDoor(Cars carA);
    bool parkCar(Cars carB);
    bool driveCar(Cars carA);
};

Cars::Cars()
{
    carType = "electric";
    std::cout << "Cars Constructed" << std::endl;
    std::cout << std::endl;
}

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
    
    if( carB.numWheels > 1 )
    {
        std::cout << "Car parked!" << std::endl;
        return true;
    }
    std::cout << "Couldn't park car!" << std::endl;
    return false;
}

bool Cars::driveCar(Cars carA)
{
    std::cout << "Car owner: " << carA.ownerOfCar << std::endl;
    return carA.ownerOfCar == "Me" || carA.ownerOfCar == "Jason";
}

struct Shelves
{
    Shelves();
    std::string objectName = "shovel";
    char objectCategory = 'w';
    int numShelves = 8;
    int numItemsOnShelf = 5;
    float weightOfItemsOnShelf = 15.5f;

    bool storeObjectOnShelf(Shelves shelfA);
    void sortShelfItems(std::string item, int numItems, bool alphabetical = true);
    std::string grabItem(Shelves shelfB);
};

Shelves::Shelves()
{
    std::cout << "Shelves Constructed" << std::endl;
    std::cout << std::endl;
}

bool Shelves::storeObjectOnShelf(Shelves shelfA)
{
    if( shelfA.numItemsOnShelf < 10 )
    {
        std::cout << "Stored items on shelf" << std::endl;
        return true;
    }
    return false;
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
    std::cout << "Items sorted!" << std::endl;
}

std::string Shelves::grabItem(Shelves shelfB)
{
    return shelfB.objectName;
}

struct Garage 
{
    Garage();
    Workbench workbench;
    ExerciseEquipment equipment;
    StorageContainers container;
    Cars car;
    Shelves shelf;

    bool openGarageDoor(Garage myGarage);
    void useWorkbench(Workbench myWorkbench);
    bool parkCarInGarage(Cars myCar);
};

Garage::Garage()
{
    std::cout << "Garage Constructed" << std::endl;
    std::cout << std::endl;
}

bool Garage::openGarageDoor(Garage myGarage)
{
    Garage myGarageOpened;
    myGarage = myGarageOpened;
    std::cout << "Garage door opened" << std::endl;
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

    std::cout << std::endl;
    
    House home;
    House::Kitchen homeKitchen;

    std::cout << "How many rooms are in my home? " << home.numRooms << std::endl;

    home.furnishHouse(home);
    home.openFrontDoor("front door");
    home.closeWindow(homeKitchen);

    std::cout << "----------------------------------" << std::endl;
    
    std::cout << "Kitchen A:" << std::endl;
    House::Kitchen kitchenA;
    
    std::cout << "How many knives are in Kitchen A? " << kitchenA.numKnives << std::endl;

    kitchenA.microwaveChicken(300.f);
    kitchenA.madeSalad("Great Lettuce", false, "French");
    kitchenA.preheatOven(450.f);

    std::cout << std::endl;

    std::cout << "Kitchen B:" << std::endl;
    House::Kitchen kitchenB;

    kitchenB.numKnives -= 5;
    std::cout << "How many knives are in Kitchen B? " << kitchenB.numKnives << std::endl;

    kitchenB.microwaveChicken(10.f);
    kitchenB.madeSalad("Lettuce!", true, "Italian");
    kitchenB.preheatOven(400.f);
    
    std::cout << "----------------------------------" << std::endl;

    Xbox myXbox;
    Xbox::Game oblivion;

    std::cout << "Does my Xbox have more than 550 gigabytes of space? " << (myXbox.amountOfSpace > 550.f ? "Yes" : "No") << std::endl;

    myXbox.openGame(oblivion);
    myXbox.downloadGame(oblivion);
    myXbox.turnOnXbox(myXbox);

    std::cout << "----------------------------------" << std::endl;

    Xbox::Game morrowind;
    morrowind.isGame("morrowind");
    morrowind.completeAchievement("none", 0);
    morrowind.changeMenu('a', "Start menu");


    std::cout << "----------------------------------" << std::endl;

    LogicPro sessionA;

    std::cout << "Name of project: " << sessionA.nameOfProject << std::endl;

    sessionA.createInstrumentTrack(sessionA);
    sessionA.insertPlugin(sessionA);
    sessionA.recordPerformance(sessionA);

    std::cout << "----------------------------------" << std::endl;

    ComputerMonitor mainMonitor;

    std::cout << "How bright is my monitor? " << mainMonitor.brightnessValue << std::endl;

    mainMonitor.increaseBrightness(mainMonitor);
    mainMonitor.changeProfiles(mainMonitor);
    mainMonitor.toHDMIInput(mainMonitor);

    std::cout << "----------------------------------" << std::endl;

    Workbench myWorkbench;
    myWorkbench.openToolbox(myWorkbench);
    myWorkbench.repairItem(myWorkbench);
    myWorkbench.putAwayTools(myWorkbench);

    std::cout << "----------------------------------" << std::endl;

    ExerciseEquipment myEquipment;
    myEquipment.liftDumbbell(myEquipment);
    myEquipment.addWeight(myEquipment);
    myEquipment.moveEquipment(myEquipment);

    std::cout << "----------------------------------" << std::endl;

    StorageContainers containerA;
    containerA.labelBox(containerA);
    containerA.pickUpBox(containerA);
    containerA.fillBox(containerA);

    std::cout << "----------------------------------" << std::endl;

    Cars carA;

    std::cout << "Is this an electric car? " << (carA.carType == "electric" ? "Yes" : "No") << std::endl;

    carA.openCarDoor(carA);
    carA.parkCar(carA);
    carA.driveCar(carA);

    std::cout << "----------------------------------" << std::endl;

    Shelves topShelf;

    std::cout << "Is there room on this shelf? " << (topShelf.numItemsOnShelf < 10 ? "Yes" : "No") << std::endl;

    topShelf.storeObjectOnShelf(topShelf);
    topShelf.sortShelfItems("trophy", 3, false);
    topShelf.grabItem(topShelf);

    std::cout << "----------------------------------" << std::endl;

    Garage garageA;
    garageA.openGarageDoor(garageA);
    garageA.useWorkbench(myWorkbench);
    garageA.parkCarInGarage(carA);
   
    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}

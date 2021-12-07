/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





 struct House 
 {
    House();
    int numRooms;
    int numWindows;
    std::string ownerName;
    int numDoors;
    int numBeds;

    struct Kitchen 
    {
        int numKnives;
        int numPlates;
        std::string toasterBrand;
        int numFridgeDoors;
        int numShelves;
        Kitchen();

        void microwaveChicken(float microwaveTime = 60.f);  
        bool madeSalad(std::string lettuceBrand, bool includeTomatoes = true, std::string dressing = "Italian");
        float preheatOven(float ovenTemperature);
        bool tableSet(int numPlacesToSet, int placesSet);
    };
    bool furnishHouse(House myHouse);
    void openFrontDoor(std::string door = "front door");
    bool closeWindow(House::Kitchen myKitchen);
    void openWindows(int openedWindows);
};

House::House() : numRooms(4), numWindows(10), ownerName("Viktor"), numDoors(5), numBeds(2)
{
    std::cout << "House Constructed" << std::endl;
    std::cout << std::endl;
}

House::Kitchen::Kitchen() : numKnives(10), numPlates(10), toasterBrand("GE"), numFridgeDoors(2), numShelves(4)
{
    std::cout << "Kitchen Constructed" << std::endl;
    std::cout << std::endl;
}

void House::Kitchen::microwaveChicken( float microwaveTime)
{
    if( microwaveTime >= 45.f )
    {
        std::cout << "Cooked for " << microwaveTime << " seconds:" << " Chicken cooked!" << std::endl;

        if( numPlates > 0 )
        {
            std::cout << "Put chicken on plate" << std::endl;
        }
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

bool House::Kitchen::tableSet(int numPlacesToSet, int placesSet)
{
    if( numPlates < numPlacesToSet )
    {
        std::cout << "Not enough plates, need " << numPlacesToSet - numPlates << " more plates to set the table!" << std::endl; 
        return false;
    }     
    for( int i = 0; i < numPlacesToSet; ++i )
    {
        placesSet += 1;
        if( placesSet == numPlacesToSet )
        {
            std::cout << "Table set!" << std::endl;
            return true;
        }
    }
    return false; 
}

bool House::furnishHouse(House myHouse)
{   
    if( myHouse.numBeds == 0 )
    {
        return true;
    }
    std::cout << "No need to buy more beds, I already have " << myHouse.numBeds << std::endl;
    return false;
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

void House::openWindows(int openedWindows)
{
    std::cout << std::endl;
    std::cout << "Opening windows" << std::endl;
    std::cout << "Windows opened: ";
    for( int i = 1; i <= numWindows; ++i )
    {
        openedWindows = i;
        std::cout << openedWindows;
        if( openedWindows != numWindows)
        {
            std::cout << ", ";
        }
        if( openedWindows == numWindows )
        {
            std::cout << std::endl;
            std::cout << "All " << numWindows << " windows have been opened" << std::endl;
        }    
    }
}

bool House::closeWindow(House::Kitchen myKitchen)
{
    return myKitchen.numShelves > 1;
}

struct Xbox
{
    float amountOfSpace;
    int numGamesDownloaded;
    int numControllers;
    std::string profileName;
    int numFriendsOnline;

    Xbox() : amountOfSpace(500.f), numGamesDownloaded(10), numControllers(2), profileName("Profile2"), numFriendsOnline(10)
    {
        std::cout << "Xbox Constructed" << std::endl; 
        std::cout << std::endl; 
        std::cout << "Xbox info: " << std::endl;
        std::cout << std::endl; 
        std::cout << "Space: " << amountOfSpace << std::endl; 
        std::cout << "Number of games downloaded: " << numGamesDownloaded << std::endl;
        std::cout << "Number of controllers owned: " << numControllers << std::endl;       
        std::cout << "Current profile: " << profileName << std::endl;
        std::cout << std::endl;
    }

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
        int totalAchievementPoints(int achievementsGained, int achievementPoints);
    };
    bool openGame(Xbox::Game skyrim);
    bool downloadGame(Xbox::Game haloInfinite);
    void turnOnXbox(Xbox myXbox);
    int deleteAllGames(int gamesDeleted);
};

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

int Xbox::Game::totalAchievementPoints(int achievementsGained, int achievementPoints)
{    
    int currentTotal = numCompletedAchievements * achievementPoints;
    for( int i = 0; i < achievementsGained; ++i )
    {
        currentTotal += achievementPoints;
        std::cout << "New achievement points total: " << currentTotal << std::endl;
    }
    return currentTotal;
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

int Xbox::deleteAllGames(int gamesDeleted)
{
    gamesDeleted = 0;
    while( gamesDeleted < numGamesDownloaded )
    {
        ++gamesDeleted;
        --numGamesDownloaded;
        amountOfSpace += 30.f;
        std::cout << "Games deleted: " << gamesDeleted << " New total space = " << amountOfSpace << std::endl;
    }
    return numGamesDownloaded;
}

struct LogicPro
{
    LogicPro();
    float sampleRate;
    std::string nameOfInputDevice;
    std::string nameOfProject;
    int numTracks;
    double tempo;

    std::string createInstrumentTrack(LogicPro trackA);
    std::string insertPlugin(LogicPro trackA);
    int recordPerformance(LogicPro trackB);
    int addTracks(int numTracksNeeded);
};

LogicPro::LogicPro() : sampleRate(44100.f), nameOfInputDevice("Scarlett 2i4"), nameOfProject("My Song"), numTracks(25), tempo(135)
{
    std::cout << "LogicPro Constructed" << std::endl;
    std::cout << std::endl;

    std::cout << "Number of tracks in session: " << numTracks << 
    std::endl;

    std::cout << "Session tempo: " << tempo << " BPM" <<
    std::endl;

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

int LogicPro::addTracks(int numTracksNeeded)
{
    for( int i = 1; i <= numTracksNeeded; ++i )
    {
        numTracks += 1;
        std::cout << "Track " << numTracks << " created" << std::endl;
    }
    std::cout << "New total number of tracks: " << numTracks << std::endl;
    return numTracks;
}

 struct ComputerMonitor
 {    
    int numDefaultModes;
    int brightnessValue;
    int speakerVolume;
    int numPossibleInputs;
    int numUserProfiles;

    ComputerMonitor() : numDefaultModes(10), brightnessValue(30), speakerVolume(20), numPossibleInputs(2), numUserProfiles(5) 
    {
        std::cout << "ComputerMonitor Constructed" << std::endl;
        std::cout << std::endl;
    }

    int increaseBrightness(ComputerMonitor myMonitor);
    std::string changeProfiles(ComputerMonitor myMonitor);
    bool toHDMIInput(ComputerMonitor myMonitor);
    void cycleThroughInputs(int currentInput);
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
    std::cout << "Number of profiles: " << numUserProfiles << std::endl;
    
    if ( myMonitor.numUserProfiles >= 2 )
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

void ComputerMonitor::cycleThroughInputs(int currentInput)
{
    for( int i = 0; i < numPossibleInputs; ++i )
    {
        currentInput += 1;
        if( currentInput > numPossibleInputs )
        {
            currentInput = 1;
        }
        std::cout << "Now on input: " << currentInput << std::endl;
    }
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
    int addingTools(int numToolsBought);
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

int Workbench::addingTools(int numToolsBought)
{
    for( int i = 0; i < numToolsBought; ++i )
    {
        numTools += 1;
        std::cout << "Bought a new tool" << std::endl;
    }
    std::cout << "New number of tools: " << numTools << std::endl;
    return numTools;
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
    void repsCounter(int numReps);
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

void ExerciseEquipment::repsCounter(int numReps)
{
    for( int i = 1; i <= numReps; ++i )
    {
        std::cout << i << "!" << std::endl;
    }
    std::cout << "Completed reps" << std::endl;
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
    int addBoxes(int numBoxesToAdd);
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

int StorageContainers::addBoxes(int numBoxesToAdd)
{
    for( int i = 0; i < numBoxesToAdd; ++i )
    {
        std::cout << "Box added" << std::endl;
        numBoxes += 1;
    }
    std::cout << "New total number of boxes: " << numBoxes << std::endl;
    return numBoxes;
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
    void driveToStore(int distanceToStore);
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

void Cars::driveToStore(int distanceToStore)
{
    int newDistance;
    for( int i = 0; i < distanceToStore; ++i )
    {
        newDistance = distanceToStore - i;
        if( newDistance == 1 )
        {
            std::cout << newDistance << " mile away" << std::endl;
        }       
        else
        {
            std::cout << newDistance << " miles away" << std::endl;
        }
    }
    std::cout << "Arrived at store!" << std::endl;
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
    bool clearedShelf();
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

bool Shelves::clearedShelf()
{
    if( numItemsOnShelf == 0 )
    {
        std::cout << "Shelf already empty!" << std::endl;
        return false;
    }

    int newTotal = numItemsOnShelf;
    for( int i = 0; i < numItemsOnShelf; ++i )
    {
        newTotal -= 1;
        if( newTotal + 1 == 1 )
        {
            std::cout << newTotal + 1 << " item left on shelf" << std::endl;
        }
        else
        {
            std::cout << newTotal + 1 << " items left on shelf" << std::endl;
        }
    }
    std::cout << "Shelf cleared!" << std::endl;
    return true;
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
    void moveOldBoxes(int numOldBoxes);
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

void Garage::moveOldBoxes(int numOldBoxes)
{
    for( int i = 1; i <= numOldBoxes; ++i )
    {
        if( i == 1 )
        {
            std::cout << i << " old box moved" << std::endl;
        }
        else
        {
            std::cout << i << " old boxes moved" << std::endl;
        }
    }
    std::cout << "All old boxes moved!" << std::endl;
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
    home.openWindows(0);

    std::cout << "----------------------------------" << std::endl;
    
    std::cout << "Kitchen A:" << std::endl;
    House::Kitchen kitchenA;
    
    std::cout << "How many knives are in Kitchen A? " << kitchenA.numKnives << std::endl;

    kitchenA.microwaveChicken(300.f);
    kitchenA.madeSalad("Great Lettuce", false, "French");
    kitchenA.preheatOven(450.f);

    kitchenA.tableSet(7, 0);

    std::cout << std::endl;

    std::cout << "Kitchen B:" << std::endl;
    House::Kitchen kitchenB;

    kitchenB.numKnives -= 5;
    std::cout << "How many knives are in Kitchen B? " << kitchenB.numKnives << std::endl;

    kitchenB.microwaveChicken(10.f);
    kitchenB.madeSalad("Lettuce!", true, "Italian");
    kitchenB.preheatOven(400.f);

    kitchenB.numPlates = 2;
    kitchenB.tableSet(5, 0);
    
    std::cout << "----------------------------------" << std::endl;

    Xbox myXbox;
    Xbox::Game oblivion;

    std::cout << "Does my Xbox have more than 550 gigabytes of space? " << (myXbox.amountOfSpace > 550.f ? "Yes" : "No") << std::endl;

    myXbox.openGame(oblivion);
    myXbox.downloadGame(oblivion);
    myXbox.turnOnXbox(myXbox);
    myXbox.deleteAllGames(0);

    std::cout << "----------------------------------" << std::endl;

    Xbox::Game morrowind;
    morrowind.isGame("morrowind");
    morrowind.completeAchievement("none", 0);
    morrowind.changeMenu('a', "Start menu");

    Xbox::Game skyrim;
    skyrim.numCompletedAchievements = 10;
    skyrim.totalAchievementPoints(5, 10);

    std::cout << "----------------------------------" << std::endl;

    LogicPro sessionA;

    std::cout << "Name of project: " << sessionA.nameOfProject << std::endl;

    sessionA.createInstrumentTrack(sessionA);
    sessionA.insertPlugin(sessionA);
    sessionA.recordPerformance(sessionA);
    sessionA.addTracks(15);

    std::cout << "----------------------------------" << std::endl;

    ComputerMonitor mainMonitor;

    std::cout << "How bright is my monitor? " << mainMonitor.brightnessValue << std::endl;

    mainMonitor.numPossibleInputs = 6;
    mainMonitor.increaseBrightness(mainMonitor);
    mainMonitor.changeProfiles(mainMonitor);
    mainMonitor.toHDMIInput(mainMonitor);
    mainMonitor.cycleThroughInputs(2);

    std::cout << "----------------------------------" << std::endl;

    Workbench myWorkbench;
    myWorkbench.openToolbox(myWorkbench);
    myWorkbench.repairItem(myWorkbench);
    myWorkbench.putAwayTools(myWorkbench);
    myWorkbench.addingTools(3);

    std::cout << "----------------------------------" << std::endl;

    ExerciseEquipment myEquipment;
    myEquipment.liftDumbbell(myEquipment);
    myEquipment.addWeight(myEquipment);
    myEquipment.moveEquipment(myEquipment);
    myEquipment.repsCounter(10);

    std::cout << "----------------------------------" << std::endl;

    StorageContainers containerA;
    containerA.labelBox(containerA);
    containerA.pickUpBox(containerA);
    containerA.fillBox(containerA);
    containerA.addBoxes(7);

    std::cout << "----------------------------------" << std::endl;

    Cars carA;

    std::cout << "Is this an electric car? " << (carA.carType == "electric" ? "Yes" : "No") << std::endl;

    carA.openCarDoor(carA);
    carA.parkCar(carA);
    carA.driveCar(carA);
    carA.driveToStore(9);

    std::cout << "----------------------------------" << std::endl;

    Shelves topShelf;

    std::cout << "Is there room on this shelf? " << (topShelf.numItemsOnShelf < 10 ? "Yes" : "No") << std::endl;

    topShelf.storeObjectOnShelf(topShelf);
    topShelf.sortShelfItems("trophy", 3, false);
    topShelf.grabItem(topShelf);
    topShelf.clearedShelf();

    std::cout << "----------------------------------" << std::endl;

    Garage garageA;
    garageA.openGarageDoor(garageA);
    garageA.useWorkbench(myWorkbench);
    garageA.parkCarInGarage(carA);
    garageA.moveOldBoxes(4);
   
    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}

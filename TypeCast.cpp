//Petie Deveer & Adrian Burke
//Orion Lawlor CS 301 @ UAF
//TypeCast optimization project

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <string>
#include <chrono>

// Generate a random float in a given range
static inline float generateRandom(float min, float max) {
    return min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

// Represents a species of fish with stat ranges
struct FishSpecies {
    std::string name;
    float minWeight;
    float maxWeight;
    float minLength;
    float maxLength;

    // Constructor
    FishSpecies(std::string n, float minW, float maxW, float minL, float maxL)
        : name(n), minWeight(minW), maxWeight(maxW), minLength(minL), maxLength(maxL) {
        // Init code
    }
};

// Represents an instance of a caught fish with randomized stats represented as floats (get it, float?)
struct Fish {
    std::string name = "unnamed fish";
    float weight;
    float length;

    // Constructor using a FishSpecies
    Fish(const FishSpecies& species)
        : name(species.name), weight(generateRandom(species.minWeight, species.maxWeight)),
          length(generateRandom(species.minLength, species.maxLength)) {
        // Init code
    }
};

//clear the console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//prints the time (in nanoseconds) that has elapsed since a given time_point
void printDurationSinceTime(std::chrono::time_point<std::chrono::system_clock> timeStart) {
    std::cout << std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - timeStart)).count() << " ns\n";
}

int main() {
    std::cout << "program started\n";
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //set a time point to benchmark array declaration
    std::chrono::time_point<std::chrono::system_clock> debugTimeProgramStart = std::chrono::system_clock::now();

    // initialize array of fish species
    std::array<FishSpecies,38> fishes{ {
        {"King Salmon", 12, 30, 5, 36},
        {"Marlin", 18, 120, 300, 1000},
        {"Oarfish", 120, 432, 50, 600},
        {"Trout", 6, 12, 0.5f, 8},
        {"Bass", 3, 10, 0.3f, 5},
        {"Tuna", 24, 48, 20, 300},
        {"Swordfish", 18, 30, 15, 200},
        {"Guppy", 0.5f, 2, 0.01f, 0.1f},
        {"Cod", 9, 18, 1, 15},
        {"Catfish", 5, 14, 0.6f, 8},
        {"Angelfish", 3, 6, 0.02f, 0.2f},
        {"Piranha", 4, 8, 0.3f, 2},
        {"Clownfish", 2, 5, 0.05f, 0.3f},
        {"Sturgeon", 12, 60, 10, 300},
        {"Halibut", 18, 36, 10, 150},
        {"Mahi Mahi", 10, 20, 5, 40},
        {"Pufferfish", 4, 8, 0.1f, 1},
        {"Walleye", 1, 30, 2, 20},
        {"Perch", 0.5f, 12, 0.3f, 1.5f},
        {"Bluegill", 0.2f, 8, 3, 10},
        {"Snapper", 1.2f, 18, 2, 15},
        {"Carp", 1.5f, 36, 5, 30},
        {"Rockfish", 1, 14, 0.8f, 3},
        {"Flounder", 0.4f, 12, 0.5f, 2},
        {"Haddock", 1.2f, 22, 1.5f, 10},
        {"Redfish", 0.8f, 20, 1, 6},
        {"Archerfish", 0.3f, 10, 2, 8},
        {"Blue Whale", 1000, 100000, 200000, 200000},
        {"Magikarp", 0.2f, 12, 0.02f, 0.5},
        {"Humuhumunukunukuapua'a", 0.15f, 5, 1, 12},
        {"O'opu Alamo'o", 0.05f, 0.15f, 0.75f, 2.8f},
        {"Patagonian Toothfish", 10, 200, 9, 90},
        {"Tiger Shark", 400, 2000, 72, 198},
        {"Dugong", 400, 2240, 72, 160},
        {"Plecostomus", 0.1f, 1.5f, 1.5f, 12},
        {"Manta Ray", 200, 2950, 60, 276},
        {"Bumblebee", 0.0002f, 0.0004f, 0.4f, 0.9f},
        {"Blobfish", 6, 20, 10, 40}
    } };

    //benchmark array initialization time
    std::cout << "array initialized by: ";
    printDurationSinceTime(debugTimeProgramStart);

    // Game loop
    std::string userInput;
    while (userInput != "no") {
        // Print the "title screen"
        std::cout << "\nWelcome to the game! Press Enter to start...\n";

        // Wait for the user to press Enter
        std::cin.get();
        clearScreen();

        // Ask the user if they want to go fishing
        std::cout << "Want to go fishing? Type the word \"cast\"!\n";
        std::cin >> userInput;

        // Check if the user typed "cast"
        if (userInput == "cast") {
            // Generate a random index to select a fish species from the vector
            int randomIndex = std::rand() % fishes.size();

            //set debug timepoint
            std::chrono::time_point<std::chrono::system_clock> debugTimeFishAccessStart = std::chrono::system_clock::now();

            // Create an instance of CaughtFish based on the selected fish species
            Fish caughtFish(fishes[randomIndex]);

            //print access time
            std::cout << "fish access time: ";
            printDurationSinceTime(debugTimeFishAccessStart);
            // Print the details of the caught fish
            std::cout << "You've got a \033[1m" << caughtFish.name << "\033[0m on the hook!\n";
            std::cout << "Type its name to reel it in!\n";

            //set the time up
            float secondsToCatch = caughtFish.name.length() * 0.5f;
            std::chrono::time_point<std::chrono::system_clock> hookTime = std::chrono::system_clock::now();
            std::cin >> userInput;

            // Check if the user entered the correct fish name
            if (userInput == caughtFish.name) {
                if (std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - hookTime)).count() <= secondsToCatch) {
                    std::cout << "You caught a \033[1m" << caughtFish.name << "\033[0m!\n";
                    std::cout << "Weight: " << caughtFish.weight << " lbs, Length: " << caughtFish.length << " inches\n";
                }
                else {
                    std::cout << "Too slow! The fish got off the hook.\n";
                }
            } else {
                std::cout << "The line snapped! Your fish got away!\n";
            }

            // Ask if the player wants to play again. if yes, game loop will restart. If no, game loop will exit. Else, ask again.
            while (userInput != "yes" && userInput != "no") {
                std::cout << "Do you want to play again? (yes/no): ";
                std::cin >> userInput;
            }
        }
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}

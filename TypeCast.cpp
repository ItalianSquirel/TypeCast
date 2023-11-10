#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>

// Represents a species of fish with arbitrary (but functional) default values
struct FishSpecies {
    std::string name = "unnamed fish";
    float minWeight = 0.5f;
    float maxWeight = 25;
    float minLength = 4;
    float maxLength = 64;

    // Constructor
    FishSpecies(std::string n, float minW, float maxW, float minL, float maxL)
        : name(n), minWeight(minW), maxWeight(maxW), minLength(minL), maxLength(maxL) {
        // Init code
    }
};

// Represents an instance of a caught fish with calculated stats
struct Fish {
    std::string name = "unnamed fish";
    float weight = 0.0f;
    float length = 0.0f;

    // Constructor using a FishSpecies
    Fish(const FishSpecies& species)
        : name(species.name), weight(generateRandom(species.minWeight, species.maxWeight)),
          length(generateRandom(species.minLength, species.maxLength)) {
        // Init code
    }

    // Function to generate a random float in a given range
    static float generateRandom(float min, float max) {
        return min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max - min)));
    }
};

// Function to clear the console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Sample fish species
    std::vector<FishSpecies> fishSpecies;
    fishSpecies.push_back(FishSpecies("Salmon", 12, 30, 5, 36));
    fishSpecies.push_back(FishSpecies("Marlin", 18, 120, 300, 1000));
    fishSpecies.push_back(FishSpecies("Oarfish", 120, 432, 50, 600));
    fishSpecies.push_back(FishSpecies("Trout", 6, 12, 0.5f, 8));
    fishSpecies.push_back(FishSpecies("Bass", 3, 10, 0.3f, 5));
    fishSpecies.push_back(FishSpecies("Tuna", 24, 48, 20, 300));
    fishSpecies.push_back(FishSpecies("Swordfish", 18, 30, 15, 200));
    fishSpecies.push_back(FishSpecies("Guppy", 0.5f, 2, 0.01f, 0.1));
    fishSpecies.push_back(FishSpecies("Cod", 9, 18, 1, 15));
    fishSpecies.push_back(FishSpecies("Catfish", 5, 14, 0.6f, 8));
    fishSpecies.push_back(FishSpecies("Angelfish", 3, 6, 0.02f, 0.2));
    fishSpecies.push_back(FishSpecies("Piranha", 4, 8, 0.3f, 2));
    fishSpecies.push_back(FishSpecies("Clownfish", 2, 5, 0.05f, 0.3));
    fishSpecies.push_back(FishSpecies("Sturgeon", 12, 60, 10, 300));
    fishSpecies.push_back(FishSpecies("Halibut", 18, 36, 10, 150));
    fishSpecies.push_back(FishSpecies("Mahi Mahi", 10, 20, 5, 40));
    fishSpecies.push_back(FishSpecies("Pufferfish", 4, 8, 0.1f, 1));
    fishSpecies.push_back(FishSpecies("Walleye", 1, 30, 2, 20));
    fishSpecies.push_back(FishSpecies("Perch", 0.5f, 12, 0.3f, 1.5));
    fishSpecies.push_back(FishSpecies("Bluegill", 0.2f, 8, 0.1f, 0.5));
    fishSpecies.push_back(FishSpecies("Snapper", 1.2f, 18, 2, 15));
    fishSpecies.push_back(FishSpecies("Carp", 1.5f, 36, 5, 30));
    fishSpecies.push_back(FishSpecies("Rockfish", 1, 14, 0.8f, 3));
    fishSpecies.push_back(FishSpecies("Flounder", 0.4f, 12, 0.5f, 2));
    fishSpecies.push_back(FishSpecies("Haddock", 1.2f, 22, 1.5f, 10));
    fishSpecies.push_back(FishSpecies("Redfish", 0.8f, 20, 1, 6));
    fishSpecies.push_back(FishSpecies("Archerfish", 0.3f, 10, 0.05f, 0.2));
    fishSpecies.push_back(FishSpecies("Blue Whale", 1000, 100000, 200000, 200000));
    fishSpecies.push_back(FishSpecies("Magikarp", 0.2f, 12, 0.02f, 0.5));

    // Game loop
    while (true) {
        // Print the "title screen"
        std::cout << "\nWelcome to the game! Press Enter to start...\n";

        // Wait for the user to press Enter
        std::cin.get();

        // Clear the screen
        clearScreen();

        // Ask the user if they want to go fishing
        std::cout << "Want to go fishing? Type the word \"cast\"!\n";

        std::string userInput;
        std::cin >> userInput;

        // Check if the user typed "cast"
        if (userInput == "cast") {
            // Generate a random index to select a fish species from the vector
            int randomIndex = std::rand() % fishSpecies.size();

            // Create an instance of CaughtFish based on the selected fish species
            Fish caughtFish(fishSpecies[randomIndex]);

            // Print the details of the caught fish
            std::cout << "You've got a " << caughtFish.name << " on the hook!\n";
            std::cout << "Type its name to reel it in!\n";

            //set the time up
            float secondsToCatch = caughtFish.name.length() * 0.5f;
            std::chrono::time_point<std::chrono::system_clock> hookTime = std::chrono::system_clock::now();
            std::cin >> userInput;

            // Check if the user entered the correct fish name
            if (userInput == caughtFish.name) {
                if (std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - hookTime)).count() <= secondsToCatch) {
                    std::cout << "You caught a "\033[1m << caughtFish.name << \033[1m"!\n";
                    std::cout << "Weight: " << caughtFish.weight << " lbs, Length: " << caughtFish.length << " inches\n";
                }
                else {
                    std::cout << "Too slow! The fish got off the hook.\n";
                }
            } else {
                std::cout << "The line snapped! Your fish got away!\n";
            }

            // Ask if the player wants to play again
            std::cout << "Do you want to play again? (yes/no): ";
            std::cin >> userInput;

            // Check if the user wants to play again
            if (userInput != "yes") {
                break; // Exit the game loop
            }
        } else {
            std::cout << "Invalid input. Game over.\n";
            break; // Exit the game loop
        }
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}


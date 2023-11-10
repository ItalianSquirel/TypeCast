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
    fishSpecies.push_back(FishSpecies("Salmon", 1, 25, 1, 36));
    fishSpecies.push_back(FishSpecies("Marlin", 0.2f, 14, 8, 1000));
    fishSpecies.push_back(FishSpecies("Oarfish", 120, 4320, 50, 600));

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
                    std::cout << "You caught a " << caughtFish.name << "!\n";
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


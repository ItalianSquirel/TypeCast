#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

//represents a species of fish with arbitrary (but functional) default values
struct Fish {
    std::string name = "unnamed fish";
    float minWeight = 0.5f;
    float maxWeight = 25;
    float minLength = 4;
    float maxLength = 64;

    //constructor
    Fish(std::string n, int minW, int maxW, int minL, int maxL) : name(n), minWeight(minW), maxWeight(maxW), minLength(minL), maxLength(maxL) {
        //init code
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

    // Sample fish names
    std::vector<Fish*> fishes; //this would be a memory leak but it's ok because there is a fixed number of fish
    fishes.push_back(new Fish("Salmon", 1, 25, 8, 36));

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
            // Generate a random index to select a fish from the vector
            int randomIndex = std::rand() % fishes.size();

            // Print the selected fish
            std::cout << "You caught a " << fishes[randomIndex]->name << "!\n";

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
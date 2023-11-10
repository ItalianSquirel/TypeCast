#include <iostream>
#include <cstdlib>
#include <ctime>  // Include this header for seed initialization
#include <vector>
#include <string>

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
    std::vector<std::string> fishNames = {"Trout", "Bass", "Salmon"};

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
        int randomIndex = std::rand() % fishNames.size();

        // Print the selected fish
        std::cout << "You caught a " << fishNames[randomIndex] << "!\n";

        // Add the fishing game logic here
    } else {
        std::cout << "Invalid input. Game over.\n";
    }

    return 0;
}

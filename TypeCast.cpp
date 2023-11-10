// TypeCast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

// Function to clear the console screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
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
        std::cout << "Let's go fishing!\n";
        // Add the fishing game logic here
    } else {
        std::cout << "Invalid input. Game over.\n";
    }

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

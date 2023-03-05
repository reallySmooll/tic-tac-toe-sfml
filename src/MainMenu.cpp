#include "EventLoop.hpp"

// Function creates the main menu which is basically three text functions.
void EventLoop::mainMenu(sf::RenderWindow& window, sf::Font& font)
{
    textX(window, font, "Tic Tac Toe in SFML", 42, 100.f);
    textX(window, font, "Press SPACE to Start", 32, 300.f);
    textX(window, font, "Press ESCAPE to Quit", 32, 450.f);
}

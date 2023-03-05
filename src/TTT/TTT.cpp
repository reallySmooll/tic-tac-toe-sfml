#include "TTT.hpp"

namespace TTT
{
    // If this is true, the showFPS function will be enabled on startup.
    // If this is false, the showFPS function will require the F3 key to be pressed to startup.
    bool TTT::toggleFPS = false;

    // If this is true, the log function will be able to show debug logs of the library.
    // If this is false, the log function will not be able to show debug logs of the library.
    bool TTT::verbose = false;

    TTT::TTT(int windowWidth, int windowHeight, const sf::String& windowTitle, uint32_t windowStyle, const sf::ContextSettings& windowContextSettings)
        : window(sf::VideoMode(windowWidth, windowHeight), windowTitle, windowStyle, windowContextSettings) {}

    TTT::~TTT() {}

    void TTT::log(std::string message)
    {
        if (verbose)
            std::cout << "TTT: " << message << std::endl;
    }
}

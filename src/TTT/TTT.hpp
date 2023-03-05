#pragma once

#include <iostream>
#include <cstdint>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

namespace TTT
{
    // Class creates window.
    class TTT
    {
        public:
            TTT(int windowWidth, int windowHeight, const sf::String& windowTitle="TTT", uint32_t windowStyle=sf::Style::Default, const sf::ContextSettings& windowContextSettings=sf::ContextSettings());
            ~TTT();

            void log(std::string message);

            // Getter function for toggleFPS variable so it's possible to display the FPS counter on program start.
            static bool get_toggleFPS() { return toggleFPS; }

            sf::RenderWindow window;

            static bool verbose;
        private:
            int windowWidth;
            int windowHeight;

            sf::String windowTitle;

            uint32_t windowStyle;

            sf::ContextSettings windowContextSettings;

            static bool toggleFPS;
    };

    // Utilities class for misc functions like the showFPS one.
    class Utils
    {
        public:
            static void showFPS(sf::RenderWindow& window, sf::Font& font, unsigned int fontSize, sf::Color color=sf::Color::White);
            static sf::Font createFont(std::string filename);
            static sf::Sprite createSprite(sf::Texture& texture, std::string filename);
    };
}

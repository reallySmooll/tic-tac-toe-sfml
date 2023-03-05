#include "TTT.hpp"

namespace TTT
{
    sf::Clock clock;
    sf::Text fpsText;
    std::stringstream ss;
    bool toggleFPS = TTT::get_toggleFPS();

    // Function to calculate FPS.
    void calculateFPS(sf::RenderWindow& window, sf::Font& font, unsigned int fontSize, sf::Color color)
    {
        int frameCount = 0;

        frameCount++;
        const float elapsedTime = clock.getElapsedTime().asSeconds();

        if (elapsedTime >= 0.1f)
        {
            const float fps = static_cast<int>(frameCount) / elapsedTime;
            ss.str("");
            ss << "FPS: " << std::floor(fps);
            fpsText.setString(ss.str());
            frameCount = 0;
            clock.restart();
        }

        if (toggleFPS)
        {
            fpsText.setFont(font);
            fpsText.setFillColor(color);
            fpsText.setCharacterSize(fontSize);
            fpsText.setPosition(10.f, 10.f);
            window.draw(fpsText);
        }
    }

    // Function to update the FPS counter in-game.
    void updateFPS(sf::RenderWindow& window)
    {
        bool isKeyPressed = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
        {
            if (!isKeyPressed)
            {
                toggleFPS = !toggleFPS;
                isKeyPressed = true;
            }
        }
        else
        {
            isKeyPressed = false;
        }

        if (toggleFPS)
        {
            window.draw(fpsText);
        }
    }

    // Function combines both the calculateFPS and updateFPS functions so the user only has to use one instead of both.
    void Utils::showFPS(sf::RenderWindow& window, sf::Font& font, unsigned int fontSize, sf::Color color)
    {
        calculateFPS(window, font, fontSize, color);
        updateFPS(window);
    }

    // Function to create a font and load it. Shortens the amount of code that has to be written.
    sf::Font Utils::createFont(std::string filename)
    {
        sf::Font font;

        if (!font.loadFromFile(filename))
            throw std::runtime_error("SFML: Failed to load font!");

        return font;
    }

    // Function to create and load a texture to a sprite. Shortens the amound of code that has to be written.
    // Texture variable has to be created manually and passed as a paramter to the function because the sprites
    // act weird when the texture is created in the function.
    sf::Sprite Utils::createSprite(sf::Texture& texture, std::string filename)
    {
        sf::Sprite sprite;

        if (!texture.loadFromFile(filename))
            throw std::runtime_error("SFML: Failed to load texture!");

        sprite.setTexture(texture);

        return sprite;
    }
}

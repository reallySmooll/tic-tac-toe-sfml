#pragma once

#include "TTT/TTT.hpp"

// Positions for X's and O's.
#define X_LEFT 237.5 / 2 + 19
#define X_MIDD 402.5 / 2 + 116
#define X_RIGH 567.5 / 2 + 214

#define Y_TOP 137.5 / 2 - 10
#define Y_MID 302.5 / 2 + 90
#define Y_BOT 467.5 / 2 + 185

class EventLoop
{
    public:
        EventLoop(sf::RenderWindow& window);
        ~EventLoop();
    private:
        void mainMenu(sf::RenderWindow& window, sf::Font& font);
        void game(sf::RenderWindow& window, sf::Font& font);
        bool checkWinningPositions(bool positions[]);
        sf::Text textX(sf::RenderWindow& window, sf::Font& font, std::string message, unsigned int fontSize, float y, sf::Color color=sf::Color::White);
        sf::Text textY(sf::RenderWindow& window, sf::Font& font, std::string message, unsigned int fontSize, float x, sf::Color color=sf::Color::White);

        // Variables that are initialized at the creation of the event loop.
        sf::Vector2f winSize;

        bool mainMenuToggle;
        bool draw;

        int gameOverTurns;

        unsigned int fontSize;

        sf::Texture xTexture;
        sf::Texture oTexture;

        // Variables pre-initialized(?).
        std::string xFilepath    = "resources/sprites/x.png";
        std::string oFilepath    = "resources/sprites/o.png";

        // Create the sprites.
        sf::Sprite xSprite = TTT::Utils::createSprite(xTexture, xFilepath);
        sf::Sprite oSprite = TTT::Utils::createSprite(oTexture, oFilepath);

        // Create a 3x3 array of rects that will be the background.
        sf::RectangleShape background[3][3];

        // All positions on the play area.
        const sf::Vector2f positions[9] = {
            { X_LEFT, Y_TOP },
            { X_MIDD, Y_TOP },
            { X_RIGH, Y_TOP },
            { X_LEFT, Y_MID },
            { X_MIDD, Y_MID },
            { X_RIGH, Y_MID },
            { X_LEFT, Y_BOT },
            { X_MIDD, Y_BOT },
            { X_RIGH, Y_BOT }
        };

        // These arrays will allow for the X's and O's to be placed on the play area (background).
        bool xPositions[9] = { false };
        bool oPositions[9] = { false };

        bool xTurn = true;
        bool oTurn = false;

        int xTurns = 6;
        int oTurns = 6;

        int xDrawTurns = 1;
        int oDrawTurns = 2;

        float textUpPosition   = 5.f;
        float textDownPosition = 570.f;
};

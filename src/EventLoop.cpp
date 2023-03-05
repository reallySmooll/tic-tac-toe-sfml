#include "EventLoop.hpp"

//#define DEBUG_OUTPUT

std::string fontFilepath = "resources/fonts/04B_30__.TTF";

EventLoop::EventLoop(sf::RenderWindow& window)
    : winSize(window.getSize().x, window.getSize().y),
      mainMenuToggle(true),
      draw(false),
      gameOverTurns(-1),
      fontSize(24)
{
    sf::Font font = TTT::Utils::createFont(fontFilepath);

    // Set scale of X's and O's cause initial size is 2.5 times too small.
    xSprite.setScale(2.5f, 2.5f);
    oSprite.setScale(2.5f, 2.5f);

    // Set position of X's and O's so they don't show on initial game start.
    xSprite.setPosition(-200, -200);
    oSprite.setPosition(-200, -200);

    // Background variables (size, padding between all 9 rects and origin).
    sf::Vector2f backgroundSize(165.f, 165.f);
    sf::Vector2f backgroundPadding(15.f, 15.f);
    sf::Vector2f backgroundOrigin(backgroundSize.x / 2.f, backgroundSize.y / 2.f);

    float backgroundSPX = (backgroundSize.x + backgroundPadding.x);
    float backgroundSPY = (backgroundSize.y + backgroundPadding.y);

    // Center background (play area).
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            sf::Vector2f backgroundPosition((winSize.x - backgroundSPX) / 2.f + backgroundPadding.x + x * backgroundSPX - 20,
                                            (winSize.y - backgroundSPY) / 2.f + backgroundPadding.y + y * backgroundSPY - 20);

            background[x][y].setSize(backgroundSize);
            background[x][y].setOrigin(backgroundOrigin);
            background[x][y].setPosition(backgroundPosition);
            background[x][y].move(-backgroundOrigin);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        // Check if it's in the main menu or not. If it is, close the game on next esc press and if not, return to the main menu.
                        if (mainMenuToggle)
                            window.close();
                        else
                            mainMenuToggle = true;
                    else if (event.key.code == sf::Keyboard::Space)
                    {
                        // Start the game if space was pressed or restart if not in the main menu.
                        mainMenuToggle = false;

                        for (int i = 0; i < 9; i++)
                        {
                            xPositions[i] = false;
                            oPositions[i] = false;
                        }

                        xTurn = true;
                        oTurn = false;

                        xTurns = 6;
                        oTurns = 6;

                        draw = false;

                        xSprite.setPosition(-200, -200);
                        oSprite.setPosition(-200, -200);
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Check position of mouse at click.
                        sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);

                        for (int x = 0; x < 3; x++)
                        {
                            for (int y = 0; y < 3; y++)
                            {
                                // Get the global bounds of all rects so it doesn't place an X or O if you click outside the play area.
                                sf::FloatRect backgroundBounds = background[x][y].getGlobalBounds();

                                // Current rect.
                                int index = y * 3 + x;

                                // Check if the mouse clicked on one of the rects.
                                if (backgroundBounds.contains(mousePosition))
                                {
                                    // If there are no X's and/or O's on clicked rect go to the next turn.
                                    if (!xPositions[index] && !oPositions[index])
                                    {
                                        if (xTurn && xTurns > xDrawTurns)
                                        {
                                            xPositions[index] = true;
                                            xTurns--;
                                            oTurn = true;
                                            xTurn = false;
                                        }
                                        else if (oTurn && oTurns > oDrawTurns)
                                        {
                                            oPositions[index] = true;
                                            oTurns--;
                                            xTurn = true;
                                            oTurn = false;
                                        }
                                    }
                                }
#ifdef DEBUG_OUTPUT
                                std::cout << "Turn: " << xTurn << " (x) | " << oTurn << " (o)" << std::endl;
                                std::cout << "Turns remaining: " << xTurns << " (x) | " << oTurns << " (o)" << std::endl;
                                std::cout << "Who won: " << checkWinningPositions(xPositions) << " (x), " << checkWinningPositions(oPositions) << " (o), " << draw << " (draw)" << std::endl;
                                std::cout << std::endl;
#endif
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear();

        game(window, font);

        TTT::Utils::showFPS(window, font, fontSize);

        window.display();
    }
}

EventLoop::~EventLoop() {}

// Functions for placing text in the center of an axis.

sf::Text EventLoop::textX(sf::RenderWindow& window, sf::Font& font, std::string message, unsigned int fontSize, float y, sf::Color color)
{
    sf::Text text;

    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setString(message);
    text.setFillColor(color);
    text.setPosition((winSize.x / 2.f) - (text.getGlobalBounds().width / 2.f), y);

    window.draw(text);

    return text;
}

sf::Text EventLoop::textY(sf::RenderWindow& window, sf::Font& font, std::string message, unsigned int fontSize, float x, sf::Color color)
{
    sf::Text text;

    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setString(message);
    text.setFillColor(color);
    text.setPosition(x, (winSize.y / 2.f) - (text.getGlobalBounds().height / 2.f));

    window.draw(text);

    return text;
}

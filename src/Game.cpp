#include "EventLoop.hpp"

void EventLoop::game(sf::RenderWindow& window, sf::Font& font)
{
    // Check if mainMenuToggle is true, if it is show the main menu, if not, progress with the game loop.
    if (mainMenuToggle)
        mainMenu(window, font);
    else
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                // Current rect.
                int index = y * 3 + x;

                // Draw background (each of the 9 rects).
                window.draw(background[x][y]);

                // If the (x/o)Positions array does not have one of the winning combinations
                // and the turns of each player are equal to the turns needed for a draw to happen,
                // flip the draw flag to true.
                if ((!checkWinningPositions(xPositions) && xTurns == xDrawTurns) && (!checkWinningPositions(oPositions) && oTurns == oDrawTurns))
                    draw = true;

                // If it's not a draw, progress with the game loop.
                if (!draw)
                {
                    // If the xPositions array does not have one of the winning combinations,
                    // check which position is the x on and set it's position before drawing.
                    if (!checkWinningPositions(xPositions))
                    {
                        if (xPositions[index])
                            xSprite.setPosition(positions[index]);
                    }
                    else
                    {
                        // Else, check which position is the x on and set it's position before drawing,
                        // change each turn number to the game over turn number and draw a text saying "X Wins!".
                        if (xPositions[index])
                        {
                            xSprite.setPosition(positions[index]);
                            xTurns = gameOverTurns;
                            oTurns = gameOverTurns;
                            textX(window, font, "X Wins!", fontSize, textUpPosition, sf::Color::Yellow);
                        }
                    }

                    // The same as x above.
                    if (!checkWinningPositions(oPositions))
                    {
                        if (oPositions[index])
                            oSprite.setPosition(positions[index]);
                    }
                    else
                    {
                        if (oPositions[index])
                        {
                            oSprite.setPosition(positions[index]);
                            oTurns = gameOverTurns;
                            xTurns = gameOverTurns;
                            textX(window, font, "O Wins!", fontSize, textUpPosition, sf::Color::Yellow);
                        }
                    }
                }
                else
                {
                    // If it is a draw, check which position is the x/o on and set it's position before drawing,
                    // as well as draw some text on the screen saying "Draw!".
                    if (xPositions[index])
                        xSprite.setPosition(positions[index]);
                    else if (oPositions[index])
                        oSprite.setPosition(positions[index]);

                    textX(window, font, "Draw!", fontSize, textUpPosition);
                }

                // Draw the sprites.
                window.draw(xSprite);
                window.draw(oSprite);
            }
        }

        // If it's X's turn, it's turns are not equal to the game over turns and it's not a draw,
        // Draw some red-colored text on the screen saying "X's Turn"
        if (xTurn && xTurns != gameOverTurns && !draw)
            textX(window, font, "X's Turn", fontSize, textUpPosition, sf::Color::Red);

        // The same as x above.
        if (oTurn && oTurns != gameOverTurns && !draw)
            textX(window, font, "O's Turn", fontSize, textUpPosition, sf::Color::Green);

        // If either X or O won the game, draw some text on the screen saying "Press SPACE to Restart".
        if (checkWinningPositions(xPositions) || checkWinningPositions(oPositions) || draw)
            textX(window, font, "Press SPACE to Restart", fontSize, textDownPosition);
    }
}

bool EventLoop::checkWinningPositions(bool positions[])
{
    /* Check for all possible winning positions,
     * for example, | X | X | X |
     *
     * Or,          | X |   |   |
     *              |   | X |   |
     *              |   |   | X | */
    if (positions[0] && positions[1] && positions[2])
        return true;
    else if (positions[3] && positions[4] && positions[5])
        return true;
    else if (positions[6] && positions[7] && positions[8])
        return true;
    else if (positions[0] && positions[3] && positions[6])
        return true;
    else if (positions[1] && positions[4] && positions[7])
        return true;
    else if (positions[2] && positions[5] && positions[8])
        return true;
    else if (positions[0] && positions[4] && positions[8])
        return true;
    else if (positions[2] && positions[4] && positions[6])
        return true;

    return false;
}

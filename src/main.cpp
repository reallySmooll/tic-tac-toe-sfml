#include "EventLoop.hpp"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE  "Tic Tac Toe in SFML"

int main()
{
    TTT::TTT ttt(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, sf::Style::Fullscreen);

    ttt.window.setFramerateLimit(61);

    EventLoop eventLoop(ttt.window);

    return 0;
}

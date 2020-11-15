#include <SFML/Graphics.hpp>

#define WIDTH 1200
#define HEIGHT 800

int main() {
    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Window",
            sf::Style::Titlebar);
    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Green);

    while (win.isOpen()) {
        sf::Event ev;
        while (win.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                win.close();
            }
        }
        win.clear();
        win.draw(shape);
        win.display();
    }
    return 0;
}

#include "SFML/Graphics.hpp"

# define WINDOW_WIDTH  800
# define WINDOW_HEIGHT 600
# define WINDOW_DIM    {WINDOW_WIDTH, WINDOW_HEIGHT}

static bool windowShouldClose(sf::RenderWindow *window);
using v2f = sf::Vector2<float>;

sf::Font font; 
sf::Text text( const char* content, unsigned int size = 24,
    sf::Vector2f position = {0, 0}, sf::Font = font,
    sf::Color color = sf::Color::White,
    sf::Uint32 style = sf::Text::Regular) {
  sf::Text t(content, font);
  t.setCharacterSize(size); t.setPosition(position);
  t.setFillColor(color);    t.setStyle(style);
  return (t);
}

int main(void) {
  sf::RenderWindow W(sf::VideoMode(WINDOW_DIM), "Hello");
  font.loadFromFile("DelaGothicOne-Regular.ttf");
  sf::Text WeDidIt = text("We did it!", 100, {125, 225});

  while (!windowShouldClose(&W)) {
    W.clear(sf::Color::Black);
    W.draw(WeDidIt);
    W.display();
  }
}

static bool windowShouldClose(sf::RenderWindow *window) {
  sf::Event event;
  window->pollEvent(event);
  return (event.type == sf::Event::Closed
      || (event.type == sf::Event::KeyPressed
        && event.key.code == sf::Keyboard::Escape));
}

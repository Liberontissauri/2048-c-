#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>

void draw_game_container(sf::RenderWindow& window) {
    const float window_width = window.getSize().x;
    const float window_height = window.getSize().y;
    sf::RectangleShape game_container_shape;
    game_container_shape.setOrigin (sf::Vector2<float>(window_height*0.4, window_height*0.4));
    game_container_shape.setSize(sf::Vector2<float>(window_height*0.8, window_height*0.8));
    game_container_shape.setPosition (
        window.mapPixelToCoords (sf::Vector2<int>(window_width / 2, window_height / 2))
    );
    
    window.draw(game_container_shape);
}
void draw_block(sf::RenderWindow& window, sf::Vector2<int> grid_position, std::string text) {
    sf::Font font;
    font.loadFromFile("Roboto-Regular.ttf");
    const float window_width = window.getSize().x;
    const float window_height = window.getSize().y;
    sf::RectangleShape block_shape;
    
    block_shape.setFillColor (sf::Color (255, 0, 0));
    block_shape.setSize(sf::Vector2<float>(window_height*0.2, window_height*0.2));
    block_shape.setPosition (
        window.mapPixelToCoords (sf::Vector2<int>(
            ((window_width / 2) - window_height*0.4) + window_height * 0.2 * grid_position.x,
            ((window_height / 2) - window_height*0.4) + window_height * 0.2 * grid_position.y
            )
        )
    );
    window.draw(block_shape);

    sf::Text label(text, font);
    label.setCharacterSize(window_height * 0.13);
    label.setFillColor(sf::Color (255, 255, 255));
    label.setPosition (sf::Vector2<float>(0,0));

    auto center = label.getGlobalBounds().getSize() / 2.f;
    auto origin = center + label.getLocalBounds().getPosition();
    label.setOrigin(origin);
    
    label.setPosition(
        window.mapPixelToCoords (sf::Vector2<int>(
            ((window_width / 2) - window_height*0.4) + window_height * 0.2 * grid_position.x + (window_height * 0.2)/2,
            ((window_height / 2) - window_height*0.4) + window_height * 0.2 * grid_position.y + (window_height * 0.2)/2
            )
        )
    );
    
    window.draw(label);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");

    window.setTitle ("Heyheyy");
    sf::View window_view = window.getDefaultView();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
            // resize my view
                window_view.setSize({
                        static_cast<float>(event.size.width),
                        static_cast<float>(event.size.height)
                    });
                window.setView(window_view);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        draw_game_container(window);
        draw_block(window, sf::Vector2<int>(1, 0), "8");
        window.display();
    }

    return 0;
}
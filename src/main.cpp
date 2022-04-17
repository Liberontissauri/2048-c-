#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Game.hpp"

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
void draw_blocks_from_2d_array(sf::RenderWindow& window, int board[4][4]) {
    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            if(board[x][y] == 0) continue;
            draw_block(window, sf::Vector2<int>(x, y), std::to_string(board[x][y]));
        }
    }
}

int main()
{
    Game mygame;
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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                mygame.push_to_left();
                mygame.generate_new_block();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                mygame.push_to_right();
                mygame.generate_new_block();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                mygame.push_to_up();
                mygame.generate_new_block();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                mygame.push_to_down();
                mygame.generate_new_block();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        draw_game_container(window);
        draw_blocks_from_2d_array(window, mygame.board);
        window.display();
    }

    return 0;
}
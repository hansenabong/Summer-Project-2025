#include <SFML/Graphics.hpp>

int main()
{
    //------------------------INITIALIZATION-------------------------
    
    sf::RenderWindow window(sf::VideoMode({ 1024, 1024 }), "SFML window");
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 9;
    sf::CircleShape shape(50.0f);
    sf::CircleShape shape2(50.0f);
    //define a 120x50 rectangle
    //sf::RectangleShape rectangle({ 800.0f, 2.0f});
    sf::RectangleShape box({ 120.f, 50.f });
    box.setPosition(sf::Vector2f(400, 350));
    shape.setPosition({ 700, 300 });
    shape2.setPosition({ 0, 300 });
    box.setRotation(sf::degrees(30));
    box.setOrigin(sf::Vector2f(box.getSize() / 2.0f));

    sf::Angle rotation = box.getRotation();
    sf::Vector2f velocity(0.05f, 0.f);
    sf::Vector2f point = {3.0f, 2.0f};  
    sf::Texture texture("assets/player/textures/lizard.png");
    sf::Sprite playerSprite(texture);
    playerSprite.setTextureRect(sf::IntRect({ 0, 0 }, { 340, 1024}));
    playerSprite.setScale(sf::Vector2f{ 0.25f, 0.25f });
    
    

    //------------------------INITIALIZATION-------------------------
    // Limit the framerate to 60 frames per second (this step is optional)
    //window.setFramerateLimit(60);
    
    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {
        //--------------------UPDATE----------------------
        // Event processing(click drag close minimize etc)
        while (const std::optional event = window.pollEvent())
        {

            /*
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::D)
                {
                    sf::Vector2f playerPosition = playerSprite.getPosition();
                    playerSprite.setPosition(playerPosition + sf::Vector2f{ 30,0 });
                }
                if (keyPressed->scancode == sf::Keyboard::Scan::A)
                {
                    sf::Vector2f playerPosition = playerSprite.getPosition();
                    playerSprite.setPosition(playerPosition + sf::Vector2f{ -30,0 });
                }
                if (keyPressed->scancode == sf::Keyboard::Scan::S)
                {
                    sf::Vector2f playerPosition = playerSprite.getPosition();
                    playerSprite.setPosition(playerPosition + sf::Vector2f{ 0,30 });
                }
                if (keyPressed->scancode == sf::Keyboard::Scan::W)
                {
                    sf::Vector2f playerPosition = playerSprite.getPosition();
                    playerSprite.setPosition(playerPosition + sf::Vector2f{ 0,-30 });
                }
            }
            */

          

        
            // Request for closing the window(press x on the title bar)
            if (event->is<sf::Event::Closed>())
                window.close();
            
        }
        sf::Vector2f playerPosition = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
            
            playerSprite.setPosition(playerPosition + sf::Vector2f{ 0.2f,0 });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
            playerSprite.setPosition(playerPosition + sf::Vector2f{ -0.2f,0 });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
            playerSprite.setPosition(playerPosition + sf::Vector2f{ 0,0.2f });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
            playerSprite.setPosition(playerPosition + sf::Vector2f{ 0, -0.2f });
        }
        //--------------------UPDATE----------------------
        
        sf::FloatRect leftCircleBounds = shape2.getGlobalBounds();
        sf::FloatRect rightCircleBounds = shape.getGlobalBounds();

        
        //box.rotate(sf::degrees(0.03f));
        box.move(velocity);
        sf::FloatRect boxBounds = box.getGlobalBounds();
        if (boxBounds.findIntersection(leftCircleBounds) || boxBounds.findIntersection(rightCircleBounds)) {
            velocity.x *= -1.f; // bounce!
        }
        // Clear the whole window before rendering a new frame
        //---------------------DRAW-----------------------
        window.clear();
        /*window.draw(shape2);
        window.draw(box);
        window.draw(shape);*/
        window.draw(playerSprite);
        window.display();
        //---------------------DRAW-----------------------
    }
}
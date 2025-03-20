#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Timer.h"
using namespace sf;
using namespace std;

/*
    This version of the SFML "hello world" is statically linked, you may wish to try the dynamically linked version as well.
*/
int WinMain()
{
    RenderWindow window(VideoMode({ 800, 800 }), "SFML works!");
    CircleShape shape(100.f, 9);
    shape.setFillColor(Color::Magenta);
    RectangleShape rectangle({ 50.f, 50.f });
    rectangle.setFillColor(Color::Blue);
    rectangle.setSize({ 100.f, 100.f });
    rectangle.setPosition({250.f, 100.f});
    CircleShape circle(50.f);
    circle.setPointCount(100);
    circle.setPosition({ 0.f, 250.f });
    const Texture metalTex("metal.JPG");
    circle.setTexture(&metalTex);
    circle.setTextureRect(IntRect({ 10, 10 }, { 100, 100 }));

    Character player;
    Timer timer;

    while (window.isOpen())
    {
<<<<<<< Updated upstream
        // Event polling section of code - this must be done in the thread which created the window
        // we will talk about threading later, but essentially this must be done here
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }

=======
        timer.UpdateTimer(currentTime, deltaTime, lastTime, timeSincePhysicsStep, physicsTimeStep, totalTimeFixed,
                          timeSinceTick, tickLength, window, totalTimeTicked, totalTimeFree);
        
>>>>>>> Stashed changes
        player.moveChar(circle);

        window.clear();
        window.draw(shape);
        window.draw(rectangle);
        window.draw(circle);
        window.display();
    }
}
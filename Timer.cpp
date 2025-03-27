#include "Timer.h"

float Timer::UpdateTimer(chrono::steady_clock::time_point currentTime, float deltaTime,
      chrono::steady_clock::time_point lastTime, float timeSincePhysicsStep,
      float physicsTimeStep, int totalTimeFixed, int timeSinceTick, float tickLength,
      RenderWindow & window, int totalTimeTicked, int totalTimeFree)
{
    //Time stuff in loop
    currentTime = chrono::steady_clock::now(); //This frame
    deltaTime = chrono::duration_cast<chrono::microseconds>(currentTime - lastTime).count();
    lastTime = currentTime;

    //Physics
    timeSincePhysicsStep += deltaTime;
    while (timeSincePhysicsStep > physicsTimeStep)
    {
        totalTimeFixed += 1;
        timeSincePhysicsStep -= physicsTimeStep;
    }

    if (timeSinceTick < tickLength)
    {
        timeSinceTick += deltaTime;
    }
    else
    {
        // Event polling section of code - this must be done in the thread which created the window
        // we will talk about threading later, but essentially this must be done here
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }
        totalTimeTicked += 1;
        timeSinceTick = 0.0f;

    }
    totalTimeFree += 1;
    return 0;
}


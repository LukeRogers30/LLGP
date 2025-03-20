#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Timer
{

    //Functions
public:
    float UpdateTimer(chrono::steady_clock::time_point currentTime, float deltaTime,
        chrono::steady_clock::time_point lastTime, float timeSincePhysicsStep,
        float physicsTimeStep, int totalTimeFixed, int timeSinceTick, float tickLength,
        RenderWindow window, int totalTimeTicked, int totalTimeFree);

    // Time Stuff
    int totalTimeFixed = 0;
    int totalTimeTicked = 0;
    int totalTimeFree = 0;

    chrono::steady_clock::time_point lastTime = chrono::steady_clock::now();
    chrono::steady_clock::time_point currentTime;

    float deltaTime = 0.0f;
    float physicsTimeStep = 20000.0f;
    float tickLength = 10000.0f;
    float timeSincePhysicsStep = 0.0f;
    float timeSinceTick = 0.0f;





};


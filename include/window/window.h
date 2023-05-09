#pragma once
#ifndef MAIN_WINDOW_HEADER_H
#define MAIN_WINDOW_HEADER_H

#include "structs/holder.h"
#include "celestialObject.h"
#include <iostream>
#include <functional>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define U_P std::unique_ptr

class MainWindowClass
{
private:
    struct ImageToBeDrawn
    {
        sf::Sprite SPRITE;
        sf::Texture TEXTURE;
    };

    std::string WindowTitle;
    
    std::unique_ptr<ImageToBeDrawn> BackGround;
    sf::Font GlobalWindowFont;
    sf::Text GreetingText;
    ImageToBeDrawn MenuBox1, MenuBox2, MenuBox3;
    std::unique_ptr<ImageToBeDrawn> WindowTitleTextbox;

    std::vector<CelestialObject *> objectsToBeDrawn;

    // Variables related to the main window
    std::shared_ptr<sf::RenderWindow> WindowPointer;
    std::shared_ptr<sf::Thread> MainWindowThread;
    std::shared_ptr<sf::VideoMode> MainWindowVideo;
    sf::Int32 WWidth;
    sf::Int32 WHeight;
    // std::thread* STDMainWindowThread;

    // Variables related to the textures and design elements
    // Private constructor for singleton pattern
    MainWindowClass(const std::string &TITLE, int W, int H) : WindowTitle(TITLE), MainWindowVideo(new sf::VideoMode(W, H)),
                                                              WWidth(static_cast<int>(W)), WHeight(static_cast<int>(H))
    {
        // Create window and set active
        WindowPointer = std::make_unique<sf::RenderWindow>(*MainWindowVideo, WindowTitle, sf::Style::Titlebar | sf::Style::Close); // Create the window
        WindowPointer->setActive(false);

    };

    ~MainWindowClass()
    { // Auto deallocate smart pointers

        for (int i = 0; i < (int)objectsToBeDrawn.size(); ++i)
        {
            delete objectsToBeDrawn[i];
        }
    }
public:
    
    MainWindowClass(const MainWindowClass&) = delete;
    MainWindowClass& operator=(const MainWindowClass&) = delete;

    static MainWindowClass& get_app(const std::string &TITLE, int W, int H) {
        static MainWindowClass app(TITLE, W, H);
        return app;
    }

    void WinStartRendering();
    void MainWindowThreadExecution(TripleItemHolder<sf::RenderWindow, sf::Thread, MainWindowClass> &ITEM_HOLDER);
    void DrawInsideMainWindow(sf::RenderWindow *Window);
    // void RenderTextures(DoubleItemHolder<sf::RenderWindow, MainWindowClass> ITEM_HOLDER);

    void setWindow(sf::RenderWindow *Window);

    std::vector<CelestialObject*> &getObjectsToBeDrawn();
    void setObjectsToBeDrawn(std::vector<CelestialObject *> &objectsToBeDrawn);
    sf::RenderWindow *getWindow() const;
};

#endif
#pragma once
#ifndef MAIN_WINDOW_HEADER_H
#define MAIN_WINDOW_HEADER_H

#include "structs/holder.h"
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
protected:
    struct ImageToBeDrawn
    {
        sf::Sprite SPRITE;
        sf::Texture TEXTURE;
    };

    sf::Int32 WWidth;
    sf::Int32 WHeight;
    const std::string WindowTitle;

    std::unique_ptr<ImageToBeDrawn> BackGround;
    sf::Font GlobalWindowFont;
    sf::Text GreetingText;
    ImageToBeDrawn MenuBox1, MenuBox2, MenuBox3;
    std::unique_ptr<ImageToBeDrawn> WindowTitleTextbox;

    // Variables related to the main window
    sf::RenderWindow *WindowPointer = NULL;
    sf::Thread *MainWindowThread;
    sf::VideoMode *MainWindowVideo;
    // std::thread* STDMainWindowThread;

    // Variables related to the textures and design elements
public:
    MainWindowClass(const std::string& TITLE, int W, int H) : WindowTitle(TITLE), MainWindowVideo(new sf::VideoMode(W, H)),
                                                             WWidth(static_cast<int>(W)), WHeight(static_cast<int>(H))
    {
        // MainWindowThread = new sf::Thread(std::bind(&MainWindowClass::MainWindowThreadExecution,this, *TripleHolder));
        MainWindowThread = new sf::Thread([&]() -> void
                                          {
					// Create window and set active
					MainWindowClass::WindowPointer = new sf::RenderWindow(*MainWindowVideo, WindowTitle, sf::Style::Titlebar | sf::Style::Close); // Create the window
					WindowPointer->setActive(false);

					std::unique_ptr<TripleItemHolder<sf::RenderWindow, sf::Thread, MainWindowClass>> TripleHolder = std::make_unique<TripleItemHolder
						<sf::RenderWindow, sf::Thread, MainWindowClass>>(WindowPointer, MainWindowThread, this);
					
					MainWindowClass::MainWindowThreadExecution(*TripleHolder); });
        // Create and launch the window thread
        MainWindowThread->launch();
    };
    ~MainWindowClass()
    { // Auto deallocate smart pointers
        delete WindowPointer;
        delete MainWindowThread;
        delete MainWindowVideo;
    }

    void MainWindowThreadExecution(TripleItemHolder<sf::RenderWindow, sf::Thread, MainWindowClass> &ITEM_HOLDER);
    void DrawInsideMainWindow(sf::RenderWindow *Window);
    // void RenderTextures(DoubleItemHolder<sf::RenderWindow, MainWindowClass> ITEM_HOLDER);

    void setWindow(sf::RenderWindow *Window);
    sf::RenderWindow *getWindow() const;
};

#endif
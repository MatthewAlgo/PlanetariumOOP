#include "window/window.h"
#include "except/exceptions.h"

void MainWindowClass::MainWindowThreadExecution(TripleItemHolder<sf::RenderWindow, sf::Thread, MainWindowClass>& ITEM_HOLDER) {
	// sf::WindowHandle handle = ITEM_HOLDER.getA()->getSystemHandle(); // Use the handle with OS specific functions -> Function not used
	// Main Window Settings
	ITEM_HOLDER.getA()->setActive(true);
	ITEM_HOLDER.getA()->setVerticalSyncEnabled(true);
	ITEM_HOLDER.getA()->setFramerateLimit(60);
	
	std::unique_ptr<DoubleItemHolder<sf::RenderWindow, MainWindowClass>> CurrentHolder = std::make_unique<DoubleItemHolder<sf::RenderWindow, MainWindowClass>>(WindowPointer, this);
	// RenderTextures(*CurrentHolder.get());

	// Display main Window
	while (ITEM_HOLDER.getA()->isOpen()) {
		sf::Event* Event = new sf::Event();
		while (ITEM_HOLDER.getA()->pollEvent(*Event)) {
			if (Event->type == sf::Event::Closed) {
				ITEM_HOLDER.getA()->close();
				break;
			}
			else if (Event->type == sf::Event::MouseButtonReleased) {
				std::cout << "Mouse button clicked\n";
				std::unique_ptr<sf::Mouse> MyMouse = std::make_unique<sf::Mouse>();
				std::cout << "XPos: " << MyMouse.get()->getPosition(*WindowPointer).x << " ; YPos: "
					<< MyMouse.get()->getPosition(*WindowPointer).y << "\n";
				// 630-250 - BR first button | 340-150 - TL first button
				if (MyMouse.get()->getPosition(*WindowPointer).x >= 340 && MyMouse.get()->getPosition(*WindowPointer).x <= 630 
						&& MyMouse.get()->getPosition(*WindowPointer).y >= 150 && MyMouse.get()->getPosition(*WindowPointer).y <= 250) {
					std::cout << "First Button Pressed\n";
				}
				// 630-380 - BR second button | 340-280 - TL first button
				if (MyMouse.get()->getPosition(*WindowPointer).x >= 340 && MyMouse.get()->getPosition(*WindowPointer).x <= 630
					&& MyMouse.get()->getPosition(*WindowPointer).y >= 280 && MyMouse.get()->getPosition(*WindowPointer).y <= 380) {
					std::cout << "Second Button Pressed\n";
				}

			}
			else if (Event->type == sf::Event::KeyPressed) {
				if (Event->key.code == sf::Keyboard::Escape) { // Exits on ESC pressed
					ITEM_HOLDER.getA()->close();
					break;
				}
			}
			else if (Event->type == sf::Event::TextEntered){
				if (Event->text.unicode < 128)
					std::cout << "ASCII character typed: " << static_cast<char>(Event->text.unicode) << std::endl;
					break;
			}
		}
		std::free(Event);
        // Draws the window
		MainWindowClass::DrawInsideMainWindow(ITEM_HOLDER.getA());
	}
}
/* Window draw - draws the window with elements */

void MainWindowClass::DrawInsideMainWindow(sf::RenderWindow* Window) {
	Window->clear(sf::Color::Black);
	
    // Draw objects here

	Window->display();
}

/*(Render textures - unused function)*/

/*
void MainWindowClass::RenderTextures(DoubleItemHolder<sf::RenderWindow, MainWindowClass> ITEM_HOLDER) {
	// Inside a separate thread -> Background
	BackGround = std::make_unique<ImageToBeDrawn>();
	BackGround->TEXTURE.loadFromFile("res/greenwallpaper.jpeg");
	BackGround->SPRITE.setTexture(BackGround->TEXTURE);
	BackGround->SPRITE.setScale(0.5, 0.5);

	// Inside a separate thread -> Menu Button
	// First Button
	MenuBox1.TEXTURE.loadFromFile("res/greenpill.png");
	MenuBox1.SPRITE.setTexture(MenuBox1.TEXTURE);
	MenuBox1.SPRITE.setPosition(WWidth / 3, WHeight / 15);
	MenuBox1.SPRITE.setScale(0.5, 0.5);

	// Second Button
	MenuBox2.TEXTURE.loadFromFile("res/greenpill.png");
	MenuBox2.SPRITE.setTexture(MenuBox2.TEXTURE);
	MenuBox2.SPRITE.setPosition(WWidth / 3, WHeight / 3);
	MenuBox2.SPRITE.setScale(0.5, 0.5);

	// Render Font for text
	GlobalWindowFont.loadFromFile("res/google_fonts/ProductSans-Bold.ttf");
	GreetingText.setFont(GlobalWindowFont);
	GreetingText.setString("My Application");
	GreetingText.setCharacterSize(24);
	GreetingText.setFillColor(sf::Color::Yellow);
	GreetingText.setStyle(sf::Text::Bold);
	GreetingText.setPosition(WWidth / 2.35, WHeight / 100);

} */

void MainWindowClass::setWindow(sf::RenderWindow* Window) {
	WindowPointer = Window;
}

// Get window pointer with throw
sf::RenderWindow* MainWindowClass::getWindow() const {
	if (WindowPointer == nullptr) {
		throw WindowNotFoundException("Window not found");
	}
	return WindowPointer;
}
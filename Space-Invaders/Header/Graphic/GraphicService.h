#pragma once
#include<SFML/Graphics.hpp>

namespace Graphic {
	
	class GraphicService {

	private:
		const std::string game_window_title = " Space Impact ";

		const int game_window_width = 1920;
		const int game_window_height = 1080;

		const sf::Color window_color = sf::Color::Blue;
		const int frame_rate = 60;

		sf::VideoMode* video_mode; //pointer to the video mode
		sf::RenderWindow* game_window; //pointer to RenderWindow

		void setVideoMode(); //Method to setting our video mode
		void onDestroy();  //Method to run when window is deleated

	public:
		GraphicService();
		~GraphicService(); //clean up

		//Method for creating the game window . returns a pointer to an instance of the game window
		sf::RenderWindow* creatGameWindow();

		void initialize(); //lifecycle function
		void update(); // 
		void render();
		bool isGameWindowOpen(); //check if the window is open

		sf::RenderWindow* getGameWindow(); // getter for the game window instance
		sf::Color getWindowColor(); //get the color

	};
}
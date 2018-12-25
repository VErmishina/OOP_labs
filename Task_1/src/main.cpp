#include "cell.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
	if (argc != 3){
		std::cout << "Please, enter all arguments" << std::endl;
		return 1;
	}

	std::ifstream input_file(argv[1], std::ios::in);
	int32_t iter = atoi(argv[2]);

	Cells curr;
	input_file >> curr;

	sf::RenderWindow window (sf::VideoMode(window_width, window_height), "Game");


	if (iter > 0){
		for (int i = 0; i < iter; i++){
			curr = curr.next_gen();
		}
	}

	while(window.isOpen()) {
		sf::Event event;		
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			
			if(iter == 0
			   && event.type == sf::Event::KeyPressed
			   && event.key.code == sf::Keyboard::Return) {
				
			   curr = curr.next_gen();
			}
		}

		window.clear();
		Draw(window, curr);	
		window.display();
	}

}
#include <iostream>
#include <memory>
#include <fstream>

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

void someFunction()
{
std::cout << std::endl; 
}
	
int main(int argc, char* argv[]){

	//window size
	const int wWidth = 1280;
	const int wHeight = 720;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight),"SFML works!");
	window.setFramerateLimit(60); //set framerate to 60 fps
	
	ImGui::SFML::Init(window);
	sf::Clock deltaClock;


	//scale imgui ui and text size by 2
	ImGui::GetStyle().ScaleAllSizes(2.0f);
	ImGui::GetIO().FontGlobalScale = 2.0f;

	while(window.isOpen()){
		

		sf::Event event;
		while(window.pollEvent(event)){
			
			ImGui::SFML::ProcessEvent(window, event);
			
			if(event.type == sf::Event::Closed){
				window.close();
			}

			if(event.type == sf::Event::KeyPressed){
				std::cout << "Key pressed with code = " << event.key.code << std::endl;
			

			}
			
		}
	}
}



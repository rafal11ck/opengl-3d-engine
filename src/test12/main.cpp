/**
 *@file
 *@brief
 *custom event handler  */

#include "engine.hpp"
#include <iostream>

Engine &engine{Engine::getInstance()};

int main() {

  engine.setEventHandler(
      Engine::Event::MouseButtonPressed, [](const Engine::Event &ev) {
        std::cout << "Custom event handler Mouse button press "
                  << ev.mouseButton.button << '\t' << ev.mouseButton.x << '\t'
                  << ev.mouseButton.y << "\n";
      });

  engine.loop();
}

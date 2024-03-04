#include "cube.hpp"
#include "drawable.hpp"
#include "engine.hpp"
#include "light.hpp"
#include "log.hpp"
#include "shape.hpp"
#include "time.h"
#include "torus.hpp"
#include <cstdlib>
#include <glm/fwd.hpp>
#include <iostream>
#include <random>

Engine &engine{Engine::getInstance()};

constexpr int paczekcount{15};
constexpr float paczekRotationSpeed{15};

constexpr float rotationChangeIntervalSeconds{2};

void init() {
  engine.setProjectionType(Engine::ProjectionType::perspective);
  engine.setCameraHandlingKeyboard(true);
  engine.setCameraHandlingMouse(true);
  engine.getWindow().setMouseCursorGrabbed(true);
  engine.getWindow().setMouseCursorVisible(false);

  engine.setEventHandler(Engine::Event::KeyReleased, [](sf::Event ev) {
    static bool wireOn{false};
    if (ev.key.code == sf::Keyboard::Key::M) {
      LOGINFO << "Switching wireframe mode " << wireOn << '\n';
      engine.setWireframeMode(wireOn = !wireOn);
    }
  });
}

int main() {
  init();

  Light *light{new Light{}};
  engine.addLight(light);

  light->setAmbient(glm::vec3{0.2});
  light->setDiffuse(glm::vec3{0.3});
  light->setSpecular(glm::vec3{0.2});

  Cube *lightBox{new Cube};
  engine.addDrawable(lightBox);

  light->setPosition({0, 0, 0});
  lightBox->setPosition({0, 0, 0});
  lightBox->setScale(glm::vec3{0.1});

  std::vector<Shape *> paczki;

  for (int i{}; i < paczekcount; ++i) {
    Shape *tmp{new Torus{static_cast<float>(0.1),
                         static_cast<float>(0.5 + 0.2 * (i * 2))}};
    paczki.push_back(tmp);
    engine.addDrawable(tmp);
  }

  srand(time(0));

  std::random_device rd;
  std::default_random_engine randEng(rd());
  std::uniform_real_distribution<float> dist(0, 1);

  glm::vec3 rotationVector[paczekcount];

  for (glm::vec3 &i : rotationVector) {
    i = {dist(rd), dist(rd), dist(rd)};
  }

  float dt{};

  engine.setLoopFunction([&]() {
    engine.moveMouseToCenterOfWindow();

    dt += engine.getLastFrameDuration().asSeconds();
    if (dt > rotationChangeIntervalSeconds) {
      dt = 0;
      for (glm::vec3 &i : rotationVector) {
        i = {dist(rd), dist(rd), dist(rd)};
      }
    }
    for (int i{}; i < paczekcount; ++i) {
      paczki[i]->rotate(glm::radians((paczekcount - i + 1) *
                                     engine.getLastFrameDuration().asSeconds() *
                                     paczekRotationSpeed),
                        glm::vec3{rotationVector[i]});
    }
  });

  engine.loop();
}


/**
 *@file
 *@brief Camera example.
 **/

#include "shape.hpp"
#define TRACE
#include "log.hpp"

#include "basicMesh.hpp"
#include "engine.hpp"
#include <vector>

Engine &engine{Engine::getInstance()};

std::vector<Vertex> verticies{
    {glm::vec3{1.f, 1.f, 0.0f}},   // top right
    {glm::vec3{1.f, -1.f, 0.0f}},  // bottom right
    {glm::vec3{-1.f, -1.f, 0.0f}}, // bottom left
    {glm::vec3{-1.f, 1.f, 0.0f}}   // top left
};

std::vector<GLuint> indicies{0, 1, 3, 1, 2, 3};

int main() {
  engine.setMaxFps(75);
  engine.setCameraHandlingKeyboard(true);
  engine.setCameraHandlingMouse(true);

  engine.setLoopFunction([]() { engine.moveMouseToCenterOfWindow(); });

  engine.getWindow().setMouseCursorGrabbed(true);
  engine.getWindow().setMouseCursorVisible(false);

  engine.setProjectionType(Engine::ProjectionType::perspective);

  Shape *moveRectangle{new Shape{verticies, indicies}};
  moveRectangle->rotate(glm::radians(-30.f), {0, 1, 1});

  moveRectangle->setPosition(0.7, 0.7, -5);
  engine.addDrawable(moveRectangle);

  moveRectangle->setScale(0.2);

  Shape *projectionRect{new Shape{verticies, indicies}};
  engine.addDrawable(projectionRect);

  projectionRect->setPosition(0, 0, -10);
  projectionRect->setScale(0.2);

  engine.loop();

  delete moveRectangle;
}

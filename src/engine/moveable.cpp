#include "moveable.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/matrix.hpp>

void Movable::setPosition(GLfloat x, GLfloat y, GLfloat z) {
  setPosition({x, y, z});
};

void Movable::setPosition(glm::vec3 position) { m_position = position; };

glm::vec3 Movable::getPosition() const { return m_position; };

glm::mat4 Movable::getModelMatrix() {
  return glm::translate(glm::mat4{1}, getPosition());
}
Movable::~Movable() {}

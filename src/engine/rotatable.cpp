#include "rotatable.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>

void Rotatable::rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
  rotate(angle, glm::vec3(x, y, z));
}

void Rotatable::rotate(GLfloat angle, glm::vec3 origin) {
  m_rotationMatrix = glm::rotate(m_rotationMatrix, angle, origin);
}
const glm::mat4 &Rotatable::getRotationMatrix() const {
  return m_rotationMatrix;
}

#include "scaleable.hpp"

#include "transformable.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>

void Scalable::setScale(GLfloat scaleFactor) {
  m_scale = glm::vec3{scaleFactor};
};

void Scalable::setScale(GLfloat x, GLfloat y, GLfloat z) {
  setScale({x, y, z});
};

void Scalable::setScale(glm::vec3 scale) { m_scale = scale; }

glm::vec3 Scalable::getScale() const { return m_scale; };

Scalable::~Scalable(){};

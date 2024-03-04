#include "elementBuffer.hpp"
#include "log.hpp"

ElementBuffer::ElementBuffer() {
  LOGTRACEN;
  glGenBuffers(1, &m_EBO);
};

void ElementBuffer::bind() {
  LOGTRACEN;
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
};

void ElementBuffer::setData(std::vector<GLuint> inicies) {
  bind();
  LOGTRACEN;
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, inicies.size() * sizeof(GLint),
               inicies.data(), GL_STATIC_DRAW);
}

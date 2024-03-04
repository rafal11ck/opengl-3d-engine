#include "vertexArray.hpp"
#include "log.hpp"
#include "vertex.hpp"

VertexArray::VertexArray() {
  LOGTRACEN;
  glGenVertexArrays(1, &m_VAOid);
}

void VertexArray::bind() { glBindVertexArray(m_VAOid); };

void VertexArray::unBind() { glBindVertexArray(0); };

void VertexArray::setAttribPointer(GLuint layout, GLuint size, GLuint offset) {
  bind();
  glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        reinterpret_cast<void *>(offset));
  glEnableVertexAttribArray(layout);
}

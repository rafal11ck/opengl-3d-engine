#include "include/vertexBuffer.hpp"
#include "log.hpp"

VertexBuffer::VertexBuffer() {
  LOGTRACEN;
  glGenBuffers(1, &m_VBO);
};

void VertexBuffer::bind() {
  LOGTRACEN;
  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}

void VertexBuffer::setData(std::vector<Vertex> verticies) {
  LOGTRACEN;
  bind();
  glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(Vertex),
               verticies.data(), GL_STATIC_DRAW);
}

#include "texture.hpp"
#define TRACE
#include "log.hpp"

#include "basicMesh.hpp"

void BasicMesh::initialize(verticies_t veritices, indicies_t indicies) {
  LOGTRACEN;
  if (veritices.empty()) {
    LOGWARN << "Empty verticies";
  }
  m_verticies = veritices;

  if (indicies.empty()) {
    LOGWARN << "Empty indicies";
  }
  m_indicies = indicies;

  m_VAO = new VertexArray{};

  m_VBO = new VertexBuffer{};
  m_EBO = new ElementBuffer{};

  m_VAO->bind();

  m_VBO->setData(m_verticies);
  m_EBO->setData(m_indicies);

  // setup attrib pointers
  // position
  m_VAO->setAttribPointer(0, 3, offsetof(Vertex, m_position));
  // normal vector
  m_VAO->setAttribPointer(1, 3, offsetof(Vertex, m_normal));
  // texture cordinate
  m_VAO->setAttribPointer(2, 2, offsetof(Vertex, m_texCord));
}

BasicMesh::BasicMesh(){};

BasicMesh::BasicMesh(verticies_t veritices, indicies_t indicies) {
  LOGTRACEN;
  initialize(veritices, indicies);
}

BasicMesh::~BasicMesh() { delete m_VAO; }

void BasicMesh::draw(Shader &shader) {
  LOGTRACEN;
  shader.use();
  shader.setInt("material.diffuse", 0);
  shader.setInt("material.specular", 1);
  shader.setFloat("material.shininess", m_shininess);

  m_VAO->bind();
  glDrawElements(GL_TRIANGLES, m_indicies.size(), GL_UNSIGNED_INT, 0);
  m_VAO->unBind();
}

void BasicMesh::setShininess(float shininess) { m_shininess = shininess; };

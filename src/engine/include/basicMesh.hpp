

#ifndef BASICMESH_HPP_
#define BASICMESH_HPP_

#include "drawable.hpp"
#include "elementBuffer.hpp"
#include "log.hpp"
#include "moveable.hpp"
#include "rotatable.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "vertexArray.hpp"
#include "vertexBuffer.hpp"
#include <GL/glew.h>
#include <netdb.h>
/// @brief Basic Mesh Class 
class BasicMesh : public Drawable {
  /// @brief no copy operations
  BasicMesh(BasicMesh &) = delete;
  /// @brief no move operations
  BasicMesh(BasicMesh &&) = delete;

public:
  /// @brief Vertex alias
  using verticies_t = std::vector<Vertex>;
  /// @brief Index alias
  using indicies_t = std::vector<GLuint>;

protected:
  /// @brief Vertex array object.
  VertexArray *m_VAO{nullptr};

private:
  /// @brief Vertex buffer object.
  VertexBuffer *m_VBO{nullptr};
  /// @brief Element buffer object.
  ElementBuffer *m_EBO{nullptr};
  /// @brief Vericies collection.
  verticies_t m_verticies;
  /// @brief Elements  inidcies collection.
  indicies_t m_indicies;

  /// @brief The shininess of the material
  float m_shininess{0.5};

protected:
  /**
   *@brief
   *
   * Because openGL vertex attrib pointers are set all shaders have to use same
   * layout.
   * */
  void initialize(verticies_t veritices, indicies_t indicies);

public:
  /// @brief Constructor
  BasicMesh();
  /// @brief Constructor
  BasicMesh(verticies_t veritices, indicies_t indicies);
  
  /// @brief Destructor
  ~BasicMesh();

  /// @brief Draws mesh with shader
  virtual void draw(Shader &shader) override;

  /// @brief Shininess setter
  void setShininess(float shininess);
};
#endif // BASICMESH_HPP_

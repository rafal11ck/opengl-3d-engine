#ifndef VERTEXBUFFER_HPP_
#define VERTEXBUFFER_HPP_

#include "vertex.hpp"
#include <GL/glew.h>
#include <vector>

/// @brief Vertex Buffer class
class VertexBuffer {
  /// @brief Vertex buffer object id
  GLuint m_VBO;

public:
  /// @brief Constructor
  VertexBuffer();

  /// @brief Binds buffer to id
  void bind();

  /// @brief Data setter
  /// @param verticies vector of veritcies for the buffer
  void setData(std::vector<Vertex> verticies);
};

#endif // VERTEXBUFFER_HPP_

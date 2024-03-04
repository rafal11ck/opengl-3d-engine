#ifndef ELEMENTBUFFER_HPP_
#define ELEMENTBUFFER_HPP_

#include <GL/glew.h>
#include <vector>

/// @brief Element buffer class
class ElementBuffer {
  /// @brief Element buffer object id
  GLuint m_EBO;

public:
  /// @brief Constructor
  ElementBuffer();

  /// @brief Binds buffer to id
  void bind();

  /// @brief Indices setter
  void setData(std::vector<GLuint> inicies);
};

#endif // ELEMENTBUFFER_HPP_

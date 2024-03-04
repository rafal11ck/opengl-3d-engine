#ifndef VERTEXARRAY_HPP_
#define VERTEXARRAY_HPP_

#include <GL/glew.h>

/// @brief Vertex Array class
class VertexArray {
  /// @brief Vertex array id;
  GLuint m_VAOid{};

public:
  /// @brief Constructor
  VertexArray();

  /// @brief Binds vertex array to id
  void bind();

  /// @brief Unbinds vertex array from id
  static void unBind();

  /**
   *@param layout layout number that shader uses to access data.
   *@param size How many values are in one struct ex. (*3* floats).
   *@param offset offset in values count. (use offsetof())
   **/
  void setAttribPointer(GLuint layout, GLuint size, GLuint offset = 0);
};
#endif // VERTEXARRAY_HPP_

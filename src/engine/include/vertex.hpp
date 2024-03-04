#ifndef VERTEX_HPP_
#define VERTEX_HPP_

#include <glm/glm.hpp>

/// @brief Vertex struct
struct Vertex {
  /// @brief Position of vertex
  glm::vec3 m_position{0.f};
  /// @brief Vertex normal
  glm::vec3 m_normal{0.f};
  /// @brief Texture coordinates
  glm::vec2 m_texCord{0.f};
};

#endif // VERTEX_HPP_

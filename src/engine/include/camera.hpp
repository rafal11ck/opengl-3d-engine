#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>



//  An abstract camera class that processes input and calculates the
//  corresponding Euler Angles, Vectors and Matrices for use in OpenGL
///@brief Represents a camera in 3D space
class Camera {

public:
  enum Camera_Movement { FORWARD, BACKWARD, LEFT, RIGHT };

  // Default camera values
  static constexpr float YAW = -90.0f;
  static constexpr float PITCH = 0.0f;
  static constexpr float SPEED = 2.5f;
  static constexpr float SENSITIVITY = 0.1f;
  static constexpr float ZOOM = 45.0f;

private:
  // camera Attributes
  ///@brief Camera position vector
  glm::vec3 m_position;
  /// @brief Camera front vector
  glm::vec3 m_front;
  /// @brief Camera up vector
  glm::vec3 m_up;
  /// @brief Camera right vector
  glm::vec3 m_right;
  /// @brief World's up direction vector
  glm::vec3 m_worldUp;

  // euler Angles
  ///@brief Camera yaw
  float m_yaw;
  /// @brief Camera pitch
  float m_pitch;
  // camera options
  ///@brief Camera movement speed
  float m_movementSpeed;
  /// @brief Camera mouse sensitivity
  float m_mouseSensitivity;
  /// @brief Camera zoom
  float m_zoom;

public:
  ///@brief constructor with vectors
  Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW,
         float pitch = PITCH);

  ///@brief constructor with scalar values
  Camera(float posX, float posY, float posZ, float upX, float upY, float upZ,
         float yaw, float pitch);

  ///@brief returns the view matrix calculated using Euler Angles and the LookAt Matrix
  glm::mat4 getViewMatrix();

  /**
   * @brief
   * processes input received from any keyboard-like input system. Accepts input
   * parameter in the form of camera defined ENUM (to abstract it from windowing 
   * systems)
  */
  void processKeyboard(Camera_Movement direction, float deltaTime);

  /**
   * @brief
   * processes input received from a mouse input system. Expects the offset
   * value in both the x and y direction
  */
  void processMouseMovement(float xoffset, float yoffset,
                            GLboolean constrainPitch = true);

  /**
   * @brief
   * processes input received from a mouse scroll-wheel event. Only requires
   * input on the vertical wheel-axis
  */
  void processMouseScroll(float yoffset);

  ///@brief calculates the front vector from the Camera's (updated) Euler Angles
  void updateCameraVectors();

  /// @brief Camera zoom getter 
  float getZoom() const;

  /// @brief Camera position getter 
  glm::vec3 getPosition() const;

  /// @brief Camera speed setter
  void setSpeed(float speed);
};

#endif // CAMERA_HPP_

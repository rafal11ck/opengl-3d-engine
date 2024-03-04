#include "camera.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(SPEED),
      m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM) {
  m_position = position;
  m_worldUp = up;
  m_yaw = yaw;
  m_pitch = pitch;
  updateCameraVectors();
}

// constructor with scalar values
Camera::Camera(float posX, float posY, float posZ, float upX, float upY,
               float upZ, float yaw, float pitch)
    : m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(SPEED),
      m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM) {
  m_position = glm::vec3(posX, posY, posZ);
  m_worldUp = glm::vec3(upX, upY, upZ);
  m_yaw = yaw;
  m_pitch = pitch;
  updateCameraVectors();
}

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 Camera::getViewMatrix() {
  return glm::lookAt(m_position, m_position + m_front, m_up);
}

// processes input received from any keyboard-like input system. Accepts input
// parameter in the form of camera defined ENUM (to abstract it from windowing
// systems)
void Camera::processKeyboard(Camera_Movement direction, float deltaTime) {
  float velocity = m_movementSpeed * deltaTime;
  if (direction == FORWARD)
    m_position += m_front * velocity;
  if (direction == BACKWARD)
    m_position -= m_front * velocity;
  if (direction == LEFT)
    m_position -= m_right * velocity;
  if (direction == RIGHT)
    m_position += m_right * velocity;
}

// processes input received from a mouse input system. Expects the offset
// value in both the x and y direction.
void Camera::processMouseMovement(float xoffset, float yoffset,
                                  GLboolean constrainPitch) {
  xoffset *= m_mouseSensitivity;
  yoffset *= m_mouseSensitivity;

  m_yaw -= xoffset;
  m_pitch -= yoffset;

  // make sure that when pitch is out of bounds, screen doesn't get flipped
  if (constrainPitch) {
    if (m_pitch > 89.0f)
      m_pitch = 89.0f;
    if (m_pitch < -89.0f)
      m_pitch = -89.0f;
  }

  // update Front, Right and Up Vectors using the updated Euler angles
  updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires
// input on the vertical wheel-axis
void Camera::processMouseScroll(float yoffset) {
  m_zoom -= (float)yoffset;
  if (m_zoom < 1.0f)
    m_zoom = 1.0f;
  if (m_zoom > 45.0f)
    m_zoom = 45.0f;
}

// calculates the front vector from the Camera's (updated) Euler Angles
void Camera::updateCameraVectors() {
  // calculate the new Front vector
  glm::vec3 front;
  front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
  front.y = sin(glm::radians(m_pitch));
  front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
  m_front = glm::normalize(front);
  // also re-calculate the Right and Up vector
  m_right = glm::normalize(glm::cross(
      m_front, m_worldUp)); // normalize the vectors, because their length
                            // gets closer to 0 the more you look up or down
                            // which results in slower movement.
  m_up = glm::normalize(glm::cross(m_right, m_front));
}

float Camera::getZoom() const { return m_zoom; };
glm::vec3 Camera::getPosition() const { return m_position; };

void Camera::setSpeed(float speed) { m_movementSpeed = speed; };

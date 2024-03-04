#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "SFML/System/Clock.hpp"
#include "SFML/Window.hpp"
#include "SFML/Window/ContextSettings.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Window.hpp"
#include "camera.hpp"
#include "drawable.hpp"
#include "light.hpp"
#include "resources.hpp"
#include "shader.hpp"
#include <functional>
#include <set>
#include <string_view>

/**
 *@brief Singleton Engine class
 **/
class Engine {

public:
  /// @brief Alias for sfml Time
  using Time = sf::Time;
  /// @brief Alias for sfml Event
  using Event = sf::Event;
  /// @brief Event handler alias
  using eventHandler_t = std::function<void(const Event &)>;

  /// @brief Enum for projection types
  enum class ProjectionType { orthogonal, perspective, max_ProjectionType };

  /**
   *@brief Distance to near clipping plane from camera.*/
  static constexpr float s_clippingPlaneNear{0.1};

  /**
   *@brief Distance to far clipping plane from camera.*/
  static constexpr float s_clippingPlaneFar{100};

  /// @brief Default path to shader directory
  static const std::string s_defaultShaderDir;

  /// @brief Default path to vertex shader code
  static const std::string s_defaultShaderPathVertex;
  /// @brief Default path to fragment shader code
  static const std::string s_defaultShaderPathFragment;

  /// @brief Maximum number of lights handled by the engine
  static const unsigned int s_maxlightcount;

  /// @brief Engine instance getter 
  static Engine &getInstance();

  /// @brief Last frame duration getter
  /// @return returns the time elapsed
  Time getLastFrameDuration() const;

  /** @brief Set function that is invoked in the main loop.
   *  @param function Function that will be called in loop.
   * */
  Engine &setLoopFunction(std::function<void()> function) {
    m_loopFunction = function;
    return *this;
  };

  /**
   * @brief Set custom event handler.
   * @param eventType Type of event that handler receives.
   * @param handler Function handling the event.
   **/
  Engine &setEventHandler(Event::EventType eventType, eventHandler_t handler);

  /**
   * @brief The main loop.
   */
  void loop();

  /// @brief Window getter
  /// @return returns current window object
  const sf::Window &getWindow() const;
  /// @brief Window getter
  /// @return returns current window object
  sf::Window &getWindow();

  /// @brief Sets the fps limit for the engine
  /// @param fps fps limit
  /// @return returns reference to engine instance
  Engine &setMaxFps(int fps);

  /**
   *@brief Add drawable to be drawn by engine.
   *
   *Added dawables will be rendered.
   *
   *@note Added object has to outlive Engine object in which case it will be
   *desroyed by ~Engine() or be removed via removeDrawable().
   *
   *@see removeDrawable()
   **/
  void addDrawable(Drawable *drawable);

  /**
   *@brief Add drawable to be drawn by engine.
   *
   *Removes drawable from engine collection.
   *
   *@warning This does not delete object.
   *
   *@see addDrawable
   **/
  void removeDrawable(Drawable *const drawable);

  /// @brief Adds light
  /// @param light Light to be added
  void addLight(Light *const light);

  /// @brief Removes light
  /// @param light Light to be removed
  void removeLight(Light *const light);

  /// @brief Camera getter
  /// @return returrns camera instance
  Camera &getCamera();
  /// @brief aspect ratio getter
  /// @return retuurns the aspect ratio of window
  float getAspectRatio() const;

  /**
   *@brief Compute projection matix.
   *
   *It is based on m_camera zoom and m_window aspect ratio.
   *
   *@warning It only computes is.
   **/
  glm::mat4 computeProjectionMatrix() const;

  /**
   *@brief Set if engine should change camera angles on mouse move within it's
   *widnow.
   **/
  void setCameraHandlingMouse(bool enbaled);

  /**
   *@brief Set if engine should change camera positon on mouse move within
   *it's widnow.
   **/
  void setCameraHandlingKeyboard(bool enbaled);

  /// @brief Projection type setter
  /// @param projectionType projection type to be set
  void setProjectionType(ProjectionType projectionType);


  /// @brief Moves mouse to the center of the window
  void moveMouseToCenterOfWindow();
  
  /// @brief WireframeMode setter
  /// @param enabled true or false
  void setWireframeMode(bool enabled);

private:
  /// @brief Engine instance pointer
  static Engine *s_instance;

  /// @brief Loop boolean
  bool isLoopRunning{false};

  /// @brief time elapsed since last frame
  sf::Time m_lastFrameDuration{};
  /// @brief the clock instance
  sf::Clock m_clockFrame{};

  /// @brief the window instance
  sf::Window m_window{};

  /** @brief custom function fired in the main loop.
   * */
  std::function<void()> m_loopFunction{[]() {}};

  /**
   *@brief Custom functions handling events.
   **/
  std::array<eventHandler_t, Event::Count> m_eventHandlers;

  /**
   *@brief Shader for drawing objects.
   *
   **/
  Shader *m_defaultShader{nullptr};

  /**
   *@brief Collection of drawables drawn by engine.
   **/
  std::set<Drawable *> m_drawables{};

  /**
   *@brief Collection of lights.
   **/
  std::set<Light *> m_lights{};

  /// @brief Camera
  Camera m_camera{};

  /**
   *@brief Does engine change camrea angle o mouse move
   **/
  bool m_engineHandleCameraOnMouseMove{false};

  /**
   *@brief Does engine change camrea position o mouse move.
   **/
  bool m_cameraHandlingKeyboard{false};

  /// @brief Projection type
  ProjectionType m_projectionType{ProjectionType::orthogonal};

private:
  /// @brief Constructor
  Engine();
  /// @brief Destructor
  ~Engine();

  /// @brief Event handler
  void handleEvents();

  /// @brief Renders shaders
  void render();

  /** @brief Builds the window with openGl context
   */
  Engine &buildWindow(sf::ContextSettings settings = sf::ContextSettings{
                          24, 8, 4, 3, 3, sf::ContextSettings::Core});
  /**
   *@brief Builtin camera handler.
   *
   *Handles mouse movement event.
   *
   **/
  void handleCameraMouseMove(const sf::Event ev);

  /**
   *@brief Builtin camera handler.
   *
   *Used in main loop.
   **/
  void handleCameraKeyboard();

  /// @brief Updates Lights with Shader
  /// @param shader shader to update lights with
  void updateShaderLights(Shader &shader) const;
};

#endif // ENGINE_HPP_

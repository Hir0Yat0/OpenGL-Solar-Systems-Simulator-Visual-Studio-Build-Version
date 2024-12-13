#ifndef GLWINDOW_HPP
#define GLWINDOW_HPP

#include"glad/glad.h"
#include"GLFW/glfw3.h"

#include<vector>
#include<optional>
#include<memory>

#include "Shader.hpp"
#include "Shape.hpp"
#include "Texture.hpp"
#include "ShapeSurface.hpp"

#include "RenderGroup3D.hpp"
#include "RenderGroup3DManager.hpp"

#include "FrameManager.hpp"
#include "glmlib.hpp"
#include "Camera.hpp"

#include "DebugLevel.hpp"
class GLDrawWindow
{
private:
    /* data */
    GLFWwindow * window;
    const int SCR_WIDTH;
    const int SCR_HEIGHT;
    bool polygonFillMode;
    static void framebuffer_size_callback(GLFWwindow * window, int width, int height);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
    void setCallbacks(void);
public:
    static inline Camera camera{};
    int initSuccess;
    GLDrawWindow(/* args */);
    ~GLDrawWindow();

    /* this makes -Werror=effc++ compiles for GLFWwindow * window; */
    /* https://stackoverflow.com/a/53892135 */

    GLDrawWindow(const GLDrawWindow&) = delete;              // copy ctor
    GLDrawWindow(GLDrawWindow&&) = delete;                   // move ctor
    GLDrawWindow& operator=(const GLDrawWindow&) = delete;   // copy assignment
    GLDrawWindow& operator=(GLDrawWindow&&) = delete;        // move assignment


    int drawWindow(Shader &shaderProgram, Shape & shape,const std::optional<Texture> & texture);
    int drawWindow(Shader &shaderProgram, std::vector<Shape> & shapes,const std::optional<Texture> & texture);
    // int drawWindow(Shader &shaderProgram, std::vector<ShapeSurface> & shapeSurfaces)    ;
    int drawWindow(std::unique_ptr<RenderGroup3D> renderGroup3D);
    int drawWindow(std::unique_ptr<RenderGroup3DManager> renderGroup3DManager);
    void togglePolygonFillMode();
    void processInput();
    int initGLFWWindow();
};


#endif // GLWINDOW_HPP

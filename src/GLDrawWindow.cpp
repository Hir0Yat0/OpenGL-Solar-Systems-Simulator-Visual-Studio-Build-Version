#include "GLDrawWindow.hpp"
#include <chrono>

GLDrawWindow::GLDrawWindow(/* args */)
: window{nullptr}, SCR_WIDTH{800}, SCR_HEIGHT{600}, polygonFillMode{true}, initSuccess{0}
{
    this->initSuccess = this->initGLFWWindow() == 0;
}

GLDrawWindow::~GLDrawWindow()
{
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

void GLDrawWindow::togglePolygonFillMode(){
    if (this->polygonFillMode){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    this->polygonFillMode = !this->polygonFillMode;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void GLDrawWindow::processInput()
{
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(this->window, true);
    }
    if (glfwGetKey(this->window, GLFW_KEY_F) == GLFW_PRESS){
        this->togglePolygonFillMode();
    }
    // camera movements

    const bool isShiftPressed = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        camera.ProcessKeyboard(this->camera.FORWARD, FrameManager::deltaTimeSeconds, isShiftPressed);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        camera.ProcessKeyboard(this->camera.BACKWARD, FrameManager::deltaTimeSeconds, isShiftPressed);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        camera.ProcessKeyboard(this->camera.LEFT, FrameManager::deltaTimeSeconds, isShiftPressed);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        camera.ProcessKeyboard(this->camera.RIGHT, FrameManager::deltaTimeSeconds, isShiftPressed);
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        camera.ProcessKeyboard(this->camera.UP, FrameManager::deltaTimeSeconds, isShiftPressed);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS){
        camera.ProcessKeyboard(this->camera.DOWN, FrameManager::deltaTimeSeconds, isShiftPressed);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        FrameManager::increaseGameSpeed();
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        FrameManager::decreaseGameSpeed();
    }

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void GLDrawWindow::framebuffer_size_callback([[maybe_unused]]GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void GLDrawWindow::mouse_callback([[maybe_unused]]GLFWwindow * window, double xposIn, double yposIn)
{
    const float xpos{static_cast<float>(xposIn)};
    const float ypos {static_cast<float>(yposIn)};

    if ( GLDrawWindow::camera.firstMouse)
    {
        GLDrawWindow::camera.prevPosX = xpos;
        GLDrawWindow::camera.prevPosY = ypos;
        GLDrawWindow::camera.firstMouse = false;
    }

    const float xoffset = xpos - GLDrawWindow::camera.prevPosX;
    const float yoffset = GLDrawWindow::camera.prevPosY - ypos; // reversed since y-coordinates go from bottom to top

    GLDrawWindow::camera.prevPosX = xpos;
    GLDrawWindow::camera.prevPosY = ypos;


    GLDrawWindow::camera.ProcessMouseMovement(xoffset,yoffset,true);
}

void GLDrawWindow::setCallbacks(void) {
    glfwSetFramebufferSizeCallback(this->window, this->framebuffer_size_callback);
    glfwSetCursorPosCallback(this->window,this->mouse_callback);
    glfwSetScrollCallback(this->window,this->scroll_callback);

}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void GLDrawWindow::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    GLDrawWindow::camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

int GLDrawWindow::initGLFWWindow(){
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    // --------------------
    this->window = glfwCreateWindow(this->SCR_WIDTH, this->SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (this->window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << "\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(this->window);
    this->setCallbacks();

    // capture mouse to windows
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to initialize GLAD" << "\n";
        glfwTerminate();
        return -1;
    }
    return 0;
}

int GLDrawWindow::drawWindow(Shader &shaderProgram, Shape & shape,const std::optional<Texture> & texture){    

    glEnable(GL_DEPTH_TEST);

    std::cerr << "Starting Rendering!" << "\n";

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    const auto startTime = std::chrono::system_clock::now();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        // std::cerr << "Processing Input" << "\n";
        // processInput(window);
        this->processInput();

        // render
        // ------
        // std::cerr << "Clearing Color" << "\n";
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // std::cerr << "Clearing Color" << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.use();
        shaderProgram.setFloat("time",std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() / 1000.0);
        
        if (texture.has_value()){
            texture.value().use();
        }
        shape.use(); 
        shape.draw();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        // std::cout << "Swapping Buffers" << std::endl;
        glfwSwapBuffers(window);
        // std::cout << "Polling Events" << std::endl;
        glfwPollEvents();
    }

    std::cerr << "Done Rendering!" << "\n";

    /* Clean Ups Done In Deconstructors */
    
    return 0;
}

int GLDrawWindow::drawWindow(Shader &shaderProgram, std::vector<Shape> & shapes,const std::optional<Texture> & texture){    

    glEnable(GL_DEPTH_TEST);

    std::cerr << "Starting Rendering!" << "\n";

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    const auto startTime = std::chrono::system_clock::now();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        // std::cerr << "Processing Input" << "\n";
        // processInput(window);
        this->processInput();

        // render
        // ------
        // std::cerr << "Clearing Color" << "\n";
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // std::cerr << "Clearing Color" << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // std::cerr << "Using Shader Program" << "\n";
        shaderProgram.use();
        shaderProgram.setFloat("time",std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() / 1000.0);
        
        if (texture.has_value()){
            texture.value().use();
        }
        for (auto &shape : shapes){
            shape.use();
            shape.draw();
        }
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        // std::cerr << "Swapping Buffers" << "\n";
        glfwSwapBuffers(window);
        // std::cerr << "Polling Events" << "\n";
        glfwPollEvents();
    }

    std::cerr << "Done Rendering!" << "\n";

    /* Clean Ups Done In Deconstructors */

    return 0;
}

// int GLDrawWindow::drawWindow(Shader &shaderProgram, std::vector<ShapeSurface> & shapeSurfaces){    

//     glEnable(GL_DEPTH_TEST);

//     std::cerr << "Starting Rendering!" << "\n";

//     // uncomment this call to draw in wireframe polygons.
//     // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//     const auto startTime = std::chrono::system_clock::now();

//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(window))
//     {
//         // input
//         // -----
//         // std::cerr << "Processing Input" << "\n";
//         // processInput(window);
//         this->processInput();

//         // render
//         // ------
//         // std::cerr << "Clearing Color" << "\n";
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         // std::cerr << "Clearing Color" << "\n";
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         shaderProgram.use();
//         shaderProgram.setFloat("time",std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() / 1000.0);
//         for (auto &shapeSurface : shapeSurfaces){
//             // shapeSurface.texture.use();
//             // shapeSurface.shape.use();
//             // shapeSurface.shape.draw();
//             shapeSurface.use();
//             shapeSurface.draw();
//         }
//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         // std::cerr << "Swapping Buffers" << "\n";
//         glfwSwapBuffers(window);
//         // std::cerr << "Polling Events" << "\n";
//         glfwPollEvents();
//     }

//     std::cerr << "Done Rendering!" << "\n";

//     /* Clean Ups Done In Deconstructors */

//     return 0;
// }

int GLDrawWindow::drawWindow(std::unique_ptr<RenderGroup3D> renderGroup3D){

    glEnable(GL_DEPTH_TEST);

    std::cerr << "Starting Rendering!" << "\n";

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    FrameManager::init();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        FrameManager::updateFrame();

        // input
        // -----
        // std::cerr << "Processing Input" << "\n";
        // processInput(window);
        this->processInput();

        // render
        // ------
        // std::cerr << "Clearing Color" << "\n";
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // std::cerr << "Clearing Color" << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        /* set model, view, and projection matrices */

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), static_cast<float>(SCR_WIDTH) / static_cast<float>(SCR_HEIGHT), 0.1f, 100.0f);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();

        // update objects

        Object3D::updateAllObjects();

        // render objects

        (*renderGroup3D).render(projection,view, this->camera.Position);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        // std::cerr << "Swapping Buffers" << "\n";
        glfwSwapBuffers(window);
        // std::cerr << "Polling Events" << "\n";
        glfwPollEvents();
    }

    std::cerr << "Done Rendering!" << "\n";

    /* Clean Ups Done In Deconstructors */

    return 0;

}

int GLDrawWindow::drawWindow(std::unique_ptr<RenderGroup3DManager> renderGroup3DManager){
    glEnable(GL_DEPTH_TEST);

    std::cerr << "Starting Rendering!" << "\n";

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    FrameManager::init();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        FrameManager::updateFrame();

        // input
        // -----
        // std::cerr << "Processing Input" << "\n";
        // processInput(window);
        this->processInput();

        // render
        // ------
        // std::cerr << "Clearing Color" << "\n";
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // std::cerr << "Clearing Color" << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        /* set model, view, and projection matrices */

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), static_cast<float>(SCR_WIDTH) / static_cast<float>(SCR_HEIGHT), 0.1f, this->camera.renderDistance);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();

        // update objects

        Object3D::updateAllObjects();

        // render objects

        (*renderGroup3DManager).renderAll(projection,view, this->camera.Position);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        // std::cerr << "Swapping Buffers" << "\n";
        glfwSwapBuffers(window);
        // std::cerr << "Polling Events" << "\n";
        glfwPollEvents();
    }

    std::cerr << "Done Rendering!" << "\n";

    /* Clean Ups Done In Deconstructors */

    return 0;
}

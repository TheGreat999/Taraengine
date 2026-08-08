#pragma once

#include <GLFW/glfw3.h>
#include <glad.h>
#include <iostream>

using std::cout, std::endl, std::cerr;



int init(){
    

    return 0;

}

class Window {
private:
    int WIDTH;
    int HEIGHT=600;
    GLFWwindow* winObj =nullptr;

    // get called when size of the window changes
    static void framebuffer_size_callback(GLFWwindow* winObj, int newWidth, int newHeight){
        Window* self = static_cast<Window*>(glfwGetWindowUserPointer(winObj));
        self->WIDTH = newHeight;
        self->HEIGHT = newHeight;
        glViewport(0, 0, newWidth, newHeight);
        // cout<<width<<' '<<height<<endl;
    }

public:
    Window(int w, int h, const char* title){
        WIDTH = w;
        HEIGHT = h;
        
        glfwInit();
        //glfwWIndowHint is the settings functions 
        //where the first arg is the name of the setting and second is the value
        // here the OpenGL version 3.3 CORE is selected
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

        // Creating window object
        winObj = glfwCreateWindow(WIDTH,HEIGHT,title,NULL,NULL);
        if(winObj==NULL){
            cout<<"GLFW failed to create a window"<<endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(winObj);

        //Intiate glad
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { 
            cout << "Failed to initialize GLAD" << endl;
            // return -1;
        }
        // this function trigger when ever the size of the window changes
        // and it calls the function to change the size of the window object of OpenGL
        glfwSetWindowUserPointer(winObj, this);
        glfwSetFramebufferSizeCallback(winObj, framebuffer_size_callback);
    }



    void inputProccesing(GLFWwindow* winObj){
        if(glfwGetKey(winObj,GLFW_KEY_ESCAPE)==GLFW_PRESS){
            glfwSetWindowShouldClose(winObj,true);
        }

    }
};


class Engine {
private:
    Window window;

public:
    /*
    This is the syntax of initializing obj B before init of obj A
    */
    Engine() : window(800, 600, "Window Title")
    {
        
    }


};

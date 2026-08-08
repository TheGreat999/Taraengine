#include "../include/camera/camera.hpp"

Camera::Camera(){
    //origin of the camera
    eye=glm::vec3(0.0f);
    //the direction the camera is looking at
    viewDir=glm::vec3(0.0f,0.0f,1.0f);
    //the direction which we defined to be up
    UP=glm::vec3(0.0f,1.0f,0.0f);;
}

glm::mat4 Camera::getViewMatrix() const{
    return glm::lookAt(eye, viewDir, UP);
}

void Camera::moveForward(float speed){
    eye.z+=speed;
}
void Camera::moveBackward(float speed){
    eye.z-=speed;

};
void Camera::moveLeft(float speed){
    eye.x+=speed;
};
void Camera::moveRight(float speed){
    eye.x-=speed;

};


void Camera::mouseMotion(float x , float y){
    viewDir=glm::rotate(viewDir, glm::radians(x), UP);
}

// void Camera::correctViewDir(){
//     viewDir=glm::vec3(eye.x,eye.y,eye.z+1);
// }


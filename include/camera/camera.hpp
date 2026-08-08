#pragma once

#define GLM_ENABLE_EXPERIMENTAL// used for glm experimental features
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtx/rotate_vector.hpp"


class Camera{
private:
    glm::vec3 eye;
    glm::vec3 viewDir;
    glm::vec3 UP;

public:

    Camera();

    glm::mat4 getViewMatrix() const;
    void correctViewDir();
    
    void moveForward(float speed);
    void moveBackward(float speed);
    void moveLeft(float speed);
    void moveRight(float speed);

    void mouseMotion(float x , float y);
};
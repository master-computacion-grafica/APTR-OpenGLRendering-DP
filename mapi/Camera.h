#pragma once

#include "common.h"
#include "Entity.h"

static enum projectionType_e
{
    KEYBOARD, FPS
};

class Camera : public Entity
{
protected:

    // ATTRIBUTES //
    
    glm::mat4 view;
    glm::mat4 projection;
    glm::vec3 up;
    glm::vec3 lookAt;

    projectionType_e type;

    float fovY;
    float near;
    float far;
    float aspectRatio;

    
public:

    // CONSTRUCTOR //

    Camera(projectionType_e type, glm::vec3 position, glm::vec3 lookAt, glm::vec3 up)
    {
        this->type = type;
        this->position = glm::vec4(position, 1.0f);
        this->lookAt = lookAt;
        this->up = up;
    }

    
    // GETTERS && SETTERS //

    glm::mat4 getView() { return this->view; }
    glm::mat4 getProjection() { return this->projection; }
    glm::vec3 getUp() { return this->up; }
    glm::vec3 getLookAt() { return this->lookAt; }
    projectionType_e getType() { return this->type; }
    float getFovy() { return this->fovY; }
    float getNear() { return this->near; }
    float getFar() { return this->far; }
    float getAspectRatio() { return this->aspectRatio; }
    
    void setView(glm::mat4 newView) { this->view = newView; }
    void setProjection(glm::mat4 newProjection) { this->projection = newProjection; }
    void setUp(glm::vec3 newUp) { this->up = newUp; }
    void setLookAt(glm::vec3 newLookAt) { this->lookAt = newLookAt; }
    void setType(projectionType_e newType) { this->type = newType; }
    void setFovy(float newFovy) { this->fovY = newFovy; }
    void setNear(float newNear) { this->near = newNear; }
    void setFar(float newFar) { this->far = newFar; }
    void setAspectRatio(float newAspectRatio) { this->aspectRatio = newAspectRatio; }
    

    // METHODS && FUNCTIONS //

    void computeProjectionMatrix();

    void computeViewMatrix();
    
    virtual void step(float timeStep) = 0;
    void step(double deltaTime) override;
};

//     glm::vec4  pos;
//     glm::vec4  rot;
//
//     glm::vec4 lookAt;
//
//     double fovy=90.0; //angulo de apertura en grados
//     double aspectRatio=4.0/3.0; //4:3
//
//     glm::mat4 cameraModel = glm::mat4(1);
//
//     glm::mat4 cameraView = glm::mat4(1);
//     glm::mat4 cameraProjection= glm::mat4(1);
//
//     Camera() {};
//     
//     Camera(glm::vec4  pos, glm::vec4  lookAt, double fovy=90.0f, double aspectRatio=4.0/3.0 );
//
//     void step(float timeStep);
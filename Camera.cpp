#include "Camera.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtx/euler_angles.hpp>


namespace gps {

    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        this->cameraUpDirection = cameraUp;

        //TODO - Update the rest of camera parameters
        
        //v = (c - l) / || c - l || = normalize(c - l), unde c este pozitia camerei, iar l este punctul spre care priveste(camera target)
        // calcul -v => cameraFrontDirection, deci cameraFrontDirection = (l - c) / || l - c ||
        this->cameraFrontDirection = glm::normalize(this->cameraTarget - this->cameraPosition);

        //u = v X r (cross product)
        this->cameraUpDirection = glm::cross(- this->cameraFrontDirection, this->cameraRightDirection); // - (-v) deoarece cameraFrontDirection = -v

        //r = - (v x u') / || v x u' ||, unde u' = (0.0f, 1.0f, 0.0f), adica axa y
        this->cameraRightDirection = -glm::normalize(glm::cross(-this->cameraFrontDirection, glm::vec3(0.0f, 1.0f, 0.0f)));// - (- v) deoarece cameraFrontDirection = -v

    }

    //return the view matrix, using the glm::lookAt() function
    glm::mat4 Camera::getViewMatrix() {
        return glm::lookAt(cameraPosition, cameraTarget, cameraUpDirection);
    }

    //update the camera internal parameters following a camera move event
    void Camera::move(MOVE_DIRECTION direction, float speed) {
        //TODO
        if (direction == MOVE_FORWARD) {
            this->cameraPosition = this->cameraPosition + speed * this->cameraFrontDirection; //cameraFrontDirection = -v
        }
        if (direction == MOVE_BACKWARD) {
            this->cameraPosition = this->cameraPosition - speed * this->cameraFrontDirection; //pt ca cameraFrontDirection = -v => scriu - (-v)
        }
        if (direction == MOVE_RIGHT) {
            this->cameraPosition = this->cameraPosition + speed * this->cameraRightDirection;
        }
        if (direction == MOVE_LEFT) {
            this->cameraPosition = this->cameraPosition - speed * this->cameraRightDirection;
        }

        //actualizez cameraTarget
        this->cameraTarget = this->cameraPosition + this->cameraFrontDirection;
    }

    //update the camera internal parameters following a camera rotate event
    //yaw - camera rotation around the y axis
    //pitch - camera rotation around the x axis
    void Camera::rotate(float pitch, float yaw) {
        //TODO
        //pt rotate se va modifica doar cameraFrontDirection, pozitia camerei ramanand la fel
        //(atunci cand rotesc camera, pozitia camerei nu se modifica, ramane pe loc, se roteste doar directia spre care privesc)

        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        this->cameraFrontDirection = glm::normalize(front);
        
        //cameraRightDirection si cameraUpDirection raman la fel ca si in constructor
        this->cameraRightDirection = -glm::normalize(glm::cross(-this->cameraFrontDirection, glm::vec3(0.0f, 1.0f, 0.0f)));
        this->cameraUpDirection = glm::cross(-this->cameraFrontDirection, this->cameraRightDirection);

        //actualizez cameraTarget
        this->cameraTarget = this->cameraPosition + this->cameraFrontDirection;
    }
}
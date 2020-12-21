// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include <stdio.h>
//Please implement the following functions:
#include <glm/glm.hpp>


// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
  /*                                             0   -nz  ny
   * R(n,a)= cos(a)I + (1-cos(a))nn.t() + sin(a)(nz  0   -nx)
   *                                             -ny  nx  0
   */
    float radians = degrees * M_PI / 180.0f;  // Converts degrees to radians
    mat3 identMat(1.0);
    mat3 r1 = mat3(axis.x*axis.x, axis.x*axis.y, axis.x*axis.z,
                   axis.x*axis.y, axis.y*axis.y, axis.y*axis.z, axis.x*axis.z, axis.y*axis.z, axis.z*axis.z);
    mat3 r2 = mat3(0.0, axis.z, -axis.y, -axis.z, 0.0, axis.x, axis.y, -axis.x, 0.0);
    mat3 R = cos(radians)*identMat + (1.0-cos(radians))*r1 + sin(radians)*r2;
    return R;
}


// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
    eye = rotate(degrees, vec3(0,1,0)) * eye;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE

    vec3 z = glm::cross(eye, up);
    z = glm::normalize(z);
    mat3 r = rotate(degrees, z);
    up = r * up;
    eye = r * eye;

}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE
  vec3 w = glm::normalize(eye);
  vec3 u = glm::normalize(glm::cross(up,w));
  vec3 v = glm::normalize(glm::cross(w,u));
  mat4 rot = mat4(u.x,u.y,u.z,0,v.x,v.y,v.z,0,w.x,w.y,w.z,0,0,0,0,1);
  rot = glm::transpose(rot);
  mat4 traslate = glm::mat4(1,0,0,-eye.x,0,1,0,-eye.y,0,0,1,-eye.z,0,0,0,1);
  traslate = glm::transpose(traslate);
  glm::mat4 returnmat = rot*traslate;
  // You will change this return call
  return returnmat;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}

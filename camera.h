#pragma once

#include "linalg.h"

namespace renderer {

class Camera {
 private:
  Vector3 position_;
  Vector3 target_;
  Vector3 up_;
  float fovY_;
  float aspect_;
  float nearClip_;
  float farClip_;
  Matrix4 viewMatrix_;
  Matrix4 projectionMatrix_;
  static Matrix4 viewMatrix(const Vector3& position, const Vector3& target, const Vector3& up);
  static Matrix4 projectionMatrix(float fovY, float aspect, float nearClip, float farClip);
  void moveAroundTarget(const Vector3& axis, float angle);

 public:
  Camera(int screenWidth, int screenHeight);
  Matrix4 viewProjectionMatrix() const;
  Matrix4 viewMatrix() const;

  void moveForward(float distance);
  void moveBackward(float distance);
  void moveLeft(float distance);
  void moveRight(float distance);

  void rotateLeft(float angle);
  void rotateRight(float angle);
  void rotateUp(float angle);
  void rotateDown(float angle);
};

}  // namespace renderer

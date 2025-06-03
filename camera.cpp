#include "camera.h"

#include <cmath>

namespace renderer {

Camera::Camera(int screenWidth, int screenHeight)
    : position_(0.0f, 0.0f, 40.0f),
      target_(0.0f, 0.0f, 0.0f),
      up_(0.0f, 1.0f, 0.0f),
      fovY_(20.0f * M_PI / 180.0f),
      aspect_(static_cast<float>(screenWidth) / static_cast<float>(screenHeight)),
      nearClip_(0.1f),
      farClip_(100.0f),
      viewMatrix_(viewMatrix(position_, target_, up_)),
      projectionMatrix_(projectionMatrix(fovY_, aspect_, nearClip_, farClip_)) {
}

Matrix4 Camera::viewMatrix(const Vector3& position, const Vector3& target, const Vector3& up) {
  Vector3 f = (target - position).normalized();
  Vector3 r = f.cross(up).normalized();
  Vector3 u = r.cross(f);

  Matrix4 view = Matrix4::Identity();
  view.block<1, 3>(0, 0) = r.transpose();
  view.block<1, 3>(1, 0) = u.transpose();
  view.block<1, 3>(2, 0) = -f.transpose();
  view(0, 3) = -r.dot(position);
  view(1, 3) = -u.dot(position);
  view(2, 3) = f.dot(position);

  return view;
}

Matrix4 Camera::projectionMatrix(float fovY, float aspect, float nearClip, float farClip) {
  float f = 1.0f / std::tan(fovY / 2.0f);

  Matrix4 projection = Matrix4::Zero();
  projection(0, 0) = f / aspect;
  projection(1, 1) = f;
  projection(2, 2) = (farClip + nearClip) / (nearClip - farClip);
  projection(2, 3) = (2 * farClip * nearClip) / (nearClip - farClip);
  projection(3, 2) = -1.0f;

  return projection;
}

void Camera::moveAroundTarget(const Vector3& axis, float angle) {
  Eigen::AngleAxisf rotation(angle, axis.normalized());
  Vector3 v = rotation * (position_ - target_);
  position_ = target_ + v;
  up_ = rotation * up_;
  viewMatrix_ = viewMatrix(position_, target_, up_);
}

Matrix4 Camera::viewProjectionMatrix() const {
  return projectionMatrix_ * viewMatrix_;
}

Matrix4 Camera::viewMatrix() const {
  return viewMatrix_;
}

void Camera::moveForward(float distance) {
  Vector3 forward = (target_ - position_).normalized();
  position_ += forward * distance;
  viewMatrix_ = viewMatrix(position_, target_, up_);
}

void Camera::moveBackward(float distance) {
  Vector3 forward = (target_ - position_).normalized();
  position_ -= forward * distance;
  viewMatrix_ = viewMatrix(position_, target_, up_);
}

void Camera::moveLeft(float distance) {
  Vector3 forward = (target_ - position_).normalized();
  Vector3 right = forward.cross(up_).normalized();
  position_ -= right * distance;
  target_ -= right * distance;
  viewMatrix_ = viewMatrix(position_, target_, up_);
}

void Camera::moveRight(float distance) {
  Vector3 forward = (target_ - position_).normalized();
  Vector3 right = forward.cross(up_).normalized();
  position_ += right * distance;
  target_ += right * distance;
  viewMatrix_ = viewMatrix(position_, target_, up_);
}

void Camera::rotateLeft(float angle) {
  moveAroundTarget(up_, angle);
}

void Camera::rotateRight(float angle) {
  moveAroundTarget(up_, -angle);
}

void Camera::rotateUp(float angle) {
  Vector3 right = (target_ - position_).cross(up_).normalized();
  moveAroundTarget(right, angle);
}

void Camera::rotateDown(float angle) {
  Vector3 right = (target_ - position_).cross(up_).normalized();
  moveAroundTarget(right, -angle);
}

}  // namespace renderer

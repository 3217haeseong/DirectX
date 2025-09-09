#include "Camera.h"

using namespace DirectX;

Camera::Camera()
    : position(XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f)),
    yaw(0.0f), pitch(0.0f),
    up(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f))
{
    UpdateVectors();
}

void Camera::SetPosition(float x, float y, float z) {
    position = XMVectorSet(x, y, z, 1.0f);
}

void Camera::MoveForward(float speed) {
    position = XMVectorAdd(position, XMVectorScale(forward, speed));
}

void Camera::MoveRight(float speed) {
    XMVECTOR right = XMVector3Cross(up, forward);
    position = XMVectorAdd(position, XMVectorScale(right, speed));
}

void Camera::MoveUp(float speed) {
    position = XMVectorAdd(position, XMVectorScale(up, speed));
}

void Camera::Rotate(float dyaw, float dpitch) {
    yaw += dyaw;
    pitch += dpitch;

    // Clamp pitch to prevent flipping
    if (pitch > XM_PIDIV2 - 0.01f) pitch = XM_PIDIV2 - 0.01f;
    if (pitch < -XM_PIDIV2 + 0.01f) pitch = -XM_PIDIV2 + 0.01f;

    UpdateVectors();
}

void Camera::UpdateVectors() {
    forward = XMVectorSet(
        cosf(pitch) * sinf(yaw),
        sinf(pitch),
        cosf(pitch) * cosf(yaw),
        0.0f
    );
    forward = XMVector3Normalize(forward);
}

XMMATRIX Camera::GetViewMatrix() const {
    return XMMatrixLookToLH(position, forward, up);
}

#pragma once
#include <DirectXMath.h>

class Camera {
public:
    Camera();
    void SetPosition(float x, float y, float z);
    void MoveForward(float speed);
    void MoveRight(float speed);
    void MoveUp(float speed);
    void Rotate(float yaw, float pitch);

    DirectX::XMMATRIX GetViewMatrix() const;

private:
    DirectX::XMVECTOR position;
    DirectX::XMVECTOR forward;
    DirectX::XMVECTOR up;
    float yaw, pitch;
    void UpdateVectors();
};

//CAMERA

Vertice2D cameraPos;
bool PlayerInteracting = false;
#define MaxRight 500
#define MinLeft -500

class Camera : public RigidBody2D
{
private:
    const float Speed = 1;
public:
    Vertice2D offset;
    Camera();
    void update_dynamic(RigidBody2D body);
    void update_static(RigidBody2D body);
};

Camera::Camera()
{
    Gravity = 0;
    Friction = 0.1;
    AirResistance = 0.1;
    offset.y = -70;
    sf::View camera(sf::FloatRect(std::round((-ScreenWidth*0.5) + position.x), std::round((-ScreenHeight*0.5) + position.y), ScreenWidth, ScreenHeight));
    window.setView(camera);
}

void Camera::update_dynamic(RigidBody2D body)
{
    if (position.x < body.position.x - 16)
    {
        acceleration.x = Speed;
    }
    else if (position.x > body.position.x + 16)
    {
        acceleration.x = -Speed;
    }
    else
    {
        acceleration.x = 0;
    }
    if (position.y < body.position.y - 16)
    {
        acceleration.y = Speed;
    }
    else if (position.y > body.position.y + 16)
    {
        acceleration.y = -Speed;
    }
    else
    {
        acceleration.y = 0;
    }
    update_vel();
    apply_vel();
    sf::View camera(sf::FloatRect(std::round((-ScreenWidth*0.5) + position.x), std::round((-ScreenHeight*0.5) + position.y), ScreenWidth, ScreenHeight));
    window.setView(camera);
    if (position.x >= MaxRight) {
        position.x = MaxRight;
    }
    if (position.x <= MinLeft) {
        position.x = MinLeft;
    }
}

void Camera::update_static(RigidBody2D body)
{
    position.x = body.position.x + offset.x;
    position.y = body.position.y + offset.y;
    sf::View camera(sf::FloatRect(std::round((-ScreenWidth*0.5) + position.x), std::round((-ScreenHeight*0.5) + position.y), ScreenWidth, ScreenHeight));
    window.setView(camera);
}

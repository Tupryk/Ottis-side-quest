#ifndef PARTICLES
#define PARTICLES

struct Particle : RigidBody2D
{
	int ColorIntensity = 0;
	bool OnScreen = true;
};

class BloodParticles : StaticBody2D
{
	public:
		void init(Vertice2D position);
		void update(Vertice2D position);
		void draw();
		const int ParticlesAmount = 50;
	private:
		Particle particles[50];
		int ParticlesOnScreen = 50;

		sf::Image image;
		sf::Texture texture;
		sf::Sprite Particles;
		sf::Clock UpdateTimer;
};

#endif
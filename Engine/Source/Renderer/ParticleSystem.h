#pragma once
#include "Particles.h"
#include<vector>

class ParticleSystem {
public:
	ParticleSystem(int maxSize = 2500) {
		m_particles.resize(maxSize);
	}

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddParticle(const Particle::Data& data);

private:
	Particle* GetFreeParticle();
private:
	std::vector<Particle> m_particles;
};
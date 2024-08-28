#pragma once
#include "Core/EAssert.h"
#include "Core/EFile.h"
#include "Core/ETime.h"
#include "Core/json.h"
#include "Core/Factory.h"
#include "Core/EString.h"

#include "Renderer/Renderer.h"
#include "Renderer/Particles.h"
#include "Renderer/Model.h"
#include "Renderer/ParticleSystem.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Texture.h"

#include "Input/Input.h"

#include "Audio/Audio.h"

#include "Math/Vector2.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/Rect.h"

#include "Components/TextureComp.h"
#include "Components/TextureAnimationComponent.h"
#include "Components/EnginePhyComp.h"
#include "Components/TextComp.h"

#include "Framework/Actor.h"
#include "Framework/Scene.h"

#include "Resources/Resource.h"
#include "Resources/ResourceManager.h"

#include "Physics/Physics.h"

#include "Event/EventSystem.h"

#include <SDL.h>
#include <fmod.hpp>


class Engine {
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	ParticleSystem& GetPS() { return *m_particleSystem; }

	Physics& GetPhysics() { return *m_physics; }
	std::unique_ptr<Physics> m_physics;

	Time& GetTime() { return *m_time; }

	bool IsQuit() { return quit; }

private:
	bool quit{ false };

	std::unique_ptr<Time> m_time{ nullptr };
	std::unique_ptr<Renderer> m_renderer{nullptr};
	std::unique_ptr<Input> m_input{ nullptr };
	std::unique_ptr<Audio> m_audio{ nullptr };

	std::unique_ptr<ParticleSystem> m_particleSystem;
};


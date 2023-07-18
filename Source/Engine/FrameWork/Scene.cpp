#include "Scene.h"

namespace kiko {
	void Scene::upDate(float dt)
	{
		for (auto actor : m_actors) {
			actor->Update(dt);
		}
	}
	void Scene::Draw(Renderer& ren)
	{
		for (auto actor : m_actors) {
			actor->Draw(ren);
		}
	}
	void Scene::addActor(Actor* actor)
	{
		m_actors.push_back(actor);
	}
	void Scene::removeActor(Actor* actor)
	{
		m_actors.remove(actor);
	}
	void Scene::removeAll()
	{
		m_actors.clear();
	}
}
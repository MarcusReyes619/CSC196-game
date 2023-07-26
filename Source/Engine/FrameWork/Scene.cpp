#include "Scene.h"

namespace kiko {
	void Scene::Update(float dt)
	{
		auto iter = m_actors.begin();
		while (iter != m_actors.end())
		{
			(*iter)->Update(dt);
			((*iter)->m_destroyed) ? iter = m_actors.erase(iter) : iter++;
		}

			//check collisions
			for (auto iter1 = m_actors.begin(); iter1 != m_actors.end(); iter1++) {

				for (auto iter2 = std::next(iter1, 1); iter2 != m_actors.end(); iter2++) {
					float distance = ((*iter1)->m_transform.position.Distances((*iter2)->m_transform.position));
					float raduis = (*iter1)->GetRadius() + (*iter2)->GetRadius();

					if (distance <= raduis) {
						//boom

						(*iter1)->OnCollision(iter2->get());
						(*iter2)->OnCollision(iter1->get());
					}

				} 
			}
	}
	void Scene::Draw(Renderer& ren)
	{
		for (auto& actor : m_actors) {
			actor->Draw(ren);
		}
	}
	void Scene::addActor(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this;
		m_actors.push_back(std::move(actor));
	}
	/*void Scene::removeActor(std::unique_ptr<Actor> actor)
	{
		m_actors.remove(actor);
	}*/
	void Scene::removeAll()
	{
		m_actors.clear();
	}
}
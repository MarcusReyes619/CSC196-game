#include "modelManager.h"

namespace kiko {

	ModelManager g_manger;

	std::shared_ptr<Modle> ModelManager::Get(const std::string& filename)
	{
		if (m_models.find(filename) == m_models.end()) {
			std::shared_ptr<Modle>modele = std::make_shared<Modle>();
			modele->Load(filename);

			m_models[filename] = modele;
		}
		return m_models[filename];

	}

}
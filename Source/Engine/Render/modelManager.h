#pragma once
#include<string>
#include <map>
#include <memory>
#include "Modle.h"
namespace kiko{

	class ModelManager {
	public:
		std::shared_ptr<Modle>Get(const std::string& filename);

	private:
		std::map<std::string, std::shared_ptr<Modle>>m_models;

};
	extern ModelManager g_manger;

}
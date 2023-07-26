#include "fileIO.h"
#include <fstream>

namespace kiko {

	std::string kiko::getFilePath() {
		return  std::filesystem::current_path().string();
	}

	bool kiko::setFilePath(const std::filesystem::path& path)
	{
		std::error_code ec;
		std::filesystem::current_path(path);

		return ec.value() == 0;
	}

	bool kiko::fileExists(const std::filesystem::path& path)
	{
		return std::filesystem::exists(path);
	}

	bool kiko::getFileSize(const std::filesystem::path& path, size_t& size)
	{
		std::error_code ec;
		size = std::filesystem::file_size(path, ec);

		return ec.value() == 0;
	}

	bool kiko::readFile(const std::filesystem::path& path, std::string& buffer)
	{
		if (!fileExists(path)) return false;

		size_t size;
		if (!getFileSize(path, size)) return false;

		buffer.resize(size);
		std::ifstream stream(path);
		stream.read(buffer.data(), size);
		stream.close();

		return true;
	}

}
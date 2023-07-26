#include "Modle.h"
#include <sstream>

namespace kiko {

	void Modle::Draw(kiko::Renderer& renderer, const vec2& position,float rotation, float scale) {

		if (m_points.empty()) return;


		//renderer.SetColor(Color::toInt(m_color.r), Color::toInt(m_color.g), Color::toInt(m_color.b), Color::toInt(m_color.a));
		renderer.SetColor(255, 255, 255, 255);
		for (int i = 0; i < m_points.size() - 1; i++) {
			vec2 p1 = (m_points[i] * scale).Rotate(rotation) + position;
			vec2 p2 = (m_points[i + 1 ] *scale).Rotate(rotation) + position;

			 renderer.DrawLine(p1.x, p1.y, p2.x,p2.y );
		}

		

	}
	bool Modle::Load(const std::string& filename) {

		std::string buffer;
		kiko::readFile(filename, buffer);

		std::istringstream stream(buffer);

		//read color
		stream >> m_color;

		std::string line;
		std::getline(stream, line);

		int numPoints = std::stoi(line);
		for (int i = 0; i < numPoints; i++) {

			vec2 point;
			stream >> point;
			m_points.push_back(point);

		}


		return true;

	}
	void Modle::Draw(kiko::Renderer& renderer, const Transform& transform) {

		Draw(renderer, transform.position, transform.rotations, transform.scale);


	}

	float Modle::getRadius(){
		if (m_raduis) return m_raduis;

		for (auto points : m_points) {

			float length = points.Length();
			m_raduis = max(m_raduis, length);

		}

		return m_raduis;
	}

}
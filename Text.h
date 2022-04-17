#pragma once
#include "Solid.h"
#include "Vector3D.h"
#include <string>
#include <iostream>


using namespace std;

class Text: public Solid
{
private:

	string text;
	float m_size{};
public:
		

		/*Text(string t = "default"):Solid(), text(t) {
			text = t;
		}*/
		//Text(const Text& c): Solid(c), text(c.text){}



		Text(string t = "hola", Vector3D position = Vector3D(0.0, 0.0, 0.0),
			Vector3D orientation = Vector3D(0.0, 0.0, 0.0),
			Color    rgb = Color(0.0, 0.0, 0.0),
			Vector3D vectorRotacion = Vector3D(0.0, 0.0, 0.0),
			Vector3D vectorDesplazamiento = Vector3D(0.0, 0.0, 0.0),
			float size = 4.0)
			:Solid(), m_size{ size }, text(t){}



		

		//Text(string t = "texto"): Solid(), text(t){}
		//Text(const Text& c): Solid(c), text(c.text){}

		inline string getText() { return text; }
		inline void setText(string t) { text = t; }

		inline float getSize() const { return this->m_size; }
		inline void setSize(const  float& sizeToSet) { this->m_size = sizeToSet; }

		//inline void setSize(const  float& sizeToSet) { this->m_size = sizeToSet; }

		//Vector3D operator+(const Vector3D& vector);
		//Vector3D Product(const float& value);
		//Text operato(ostream& os, const Text& v);

		//friend std::ostream& operator<<(std::ostream& os, const Text& v);

		/*inline std::ostream& operator<<(std::ostream& os, const Text& c) {

			os << static_cast<const Solid&>(c);
			os << ", text=" << c.text;
			return os;
		}*/

		void Render();
};


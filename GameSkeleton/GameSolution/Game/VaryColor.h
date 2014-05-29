#ifndef COLOR_H
#define COLOR_H

#include "Core.h"
#include "MyRandomNumber.h"

namespace Util{
	class Colors{

	public:
		static Core::RGB VeryColor(Core::RGB color, float variance);
		static Core::RGB Brightness (Core::RGB color, float brightValue);
		static float Util::Colors::RandomFloat();
		static float Util::Colors::RandomInRange(float min, float max);
	};
}

#endif // !COLOR_H

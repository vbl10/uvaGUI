#pragma once
#include <string>
#include "uva_coord.h"

namespace uva
{
	class Graphics
	{
	public:
		enum COLORS
		{
			WHITE			= 0xffffff,
			BLACK			= 0x000000,
			GREY			= 0x7f7f7f,
			DARK_GREY		= 0x3f3f3f,
			LIGHT_GREY		= 0xbebebe,
			RED				= 0xff0000,
			GREEN			= 0x00ff00,
			BLUE			= 0x0000ff,
			YELLOW			= 0xffff00,
			ORANGE			= 0xff7f00,
			PURPLE			= 0x7f00ff
		};

		virtual void SetFont(const std::wstring& font, float size) = 0;
		
		virtual dimension<float> GetStringDimension(const std::wstring& str) const = 0;
		virtual dimension<float> GetSize() const = 0;

		virtual void DrawString(const std::wstring& str, const coord<float>& top_left, int color = WHITE) = 0;
		virtual void DrawRect(coord<float> top_left, coord<float> bottom_right, float thickness = 1.0f, int color = WHITE) = 0;
		virtual void FillRect(coord<float> top_left, coord<float> bottom_right, int color = WHITE) = 0;
	};
};


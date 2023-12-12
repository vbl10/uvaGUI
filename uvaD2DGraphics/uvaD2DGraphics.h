#pragma once
#include <uva_Graphics.h>
#include <ext_d2d1.h>

class uvaD2DGraphics : public uva::Graphics
{
private:
	ext::D2DGraphics& gfx;
	std::wstring font;
	float font_size;
public:
	uvaD2DGraphics(ext::D2DGraphics& gfx, std::wstring font = L"Consolas", float font_size = 16.0f);

	void SetFont(const std::wstring& font, float font_size) override;

	uva::dimension<float> GetStringDimension(const std::wstring& str) const override;
	uva::dimension<float> GetSize() const override;

	void DrawString(const std::wstring& str, const uva::coord<float>& top_left, int color = WHITE) override;
	void DrawRect(uva::coord<float> top_left, uva::coord<float> bottom_right, float thickness = 1.0f, int color = WHITE) override;
	void FillRect(uva::coord<float> top_left, uva::coord<float> bottom_right, int color = WHITE) override;
};


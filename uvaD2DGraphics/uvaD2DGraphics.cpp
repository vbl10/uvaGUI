#include "uvaD2DGraphics.h"

uvaD2DGraphics::uvaD2DGraphics(ext::D2DGraphics& gfx, std::wstring font, float font_size)
	:gfx(gfx), font(font), font_size(font_size)
{
}

void uvaD2DGraphics::SetFont(const std::wstring& font, float font_size)
{
	this->font = font;
	this->font_size = font_size;
}

uva::dimension<float> uvaD2DGraphics::GetStringDimension(const std::wstring& str) const
{
	ext::TextFormat format(font, font_size);
	auto layout = format(str);
	DWRITE_TEXT_METRICS dwm = { 0 };
	layout->GetMetrics(&dwm);
	return { dwm.width,dwm.height };
}

uva::dimension<float> uvaD2DGraphics::GetSize() const
{
	auto size = gfx.pRenderTarget->GetPixelSize();
	return { (float)size.width,(float)size.height };
}

void uvaD2DGraphics::DrawString(const std::wstring& str, const uva::coord<float>& top_left, int color)
{
	ext::TextFormat format(font, font_size);
	gfx.pSolidBrush->SetColor(D2D1::ColorF(color));
	gfx.pRenderTarget->DrawTextLayout(
		D2D1::Point2F(top_left.x, top_left.y),
		format(str),
		gfx.pSolidBrush
	);
}

void uvaD2DGraphics::DrawRect(uva::coord<float> top_left, uva::coord<float> bottom_right, float thickness, int color)
{
	gfx.pSolidBrush->SetColor(D2D1::ColorF(color));
	gfx.pRenderTarget->DrawRectangle(
		D2D1::RectF(
			top_left.x, top_left.y,
			bottom_right.x, bottom_right.y
		),
		gfx.pSolidBrush,
		thickness
	);
}

void uvaD2DGraphics::FillRect(uva::coord<float> top_left, uva::coord<float> bottom_right, int color)
{
	gfx.pSolidBrush->SetColor(D2D1::ColorF(color));
	gfx.pRenderTarget->FillRectangle(
		D2D1::RectF(
			top_left.x, top_left.y,
			bottom_right.x, bottom_right.y
		),
		gfx.pSolidBrush
	);
}

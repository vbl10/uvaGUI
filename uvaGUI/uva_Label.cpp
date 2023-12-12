#include "uva_Label.h"
#include "uva_GUI.h"

uva::Label::Label(const std::wstring& text)
	:text(text)
{
}

void uva::Label::Draw(Graphics& gfx)
{
	Element::Draw(gfx);
	gfx.DrawString(text, GetPos());
}

void uva::Label::SetText(const std::wstring& new_text)
{
	text = new_text;
}

uva::coord<float> uva::Label::GetDefaultMinSize() const
{
	return GetRoot()->gfx.GetStringDimension(text);
}

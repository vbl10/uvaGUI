#pragma once
#include "uva_Element.h"
#include <string>

namespace uva
{
	class Label : public Element
	{
	private:
		std::wstring text;
	public:
		Label(const std::wstring& text = L"");
		void Draw(Graphics& gfx) override;
		void SetText(const std::wstring& new_text);
		coord<float> GetDefaultMinSize() const override;
	};
};


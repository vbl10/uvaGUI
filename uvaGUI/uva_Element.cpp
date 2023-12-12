#include "uva_Element.h"
#include <utility>

uva::GUI* uva::Element::GetRoot()
{
	auto p = parent;
	while (p != nullptr && p->parent != nullptr) 
		p = p->parent;
	return (GUI*)p;
}

const uva::GUI* uva::Element::GetRoot() const
{
	auto p = parent;
	while (p != nullptr && p->parent != nullptr)
		p = p->parent;
	return (const GUI*)p;
}

void uva::Element::SetSize(const coord<float>& new_size)
{
	auto def = GetMinSize();
	size.x = std::max(new_size.x, def.x);
	size.y = std::max(new_size.y, def.y);
}

uva::coord<float> uva::Element::GetSize() const
{
	auto def = GetMinSize();
	return
	{
		std::max(size.x, def.x),
		std::max(size.y, def.y)
	};
}

uva::coord<float> uva::Element::GetMinSize() const
{
	auto def = GetDefaultMinSize();
	return 
	{
		std::max(min_size.x, def.x),
		std::max(min_size.y, def.y)
	};
}

void uva::Element::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos, pos + size, 1.0f, Graphics::RED);
}

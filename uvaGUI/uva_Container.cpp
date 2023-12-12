#include "uva_Container.h"

void uva::Container::Draw(Graphics& gfx)
{
	for (auto i : display_order)
		contents[i].element->Draw(gfx);
}

uva::Container::ContentManipulator uva::Container::At(const std::wstring& content_name)
{
	if (!contents_map.count(content_name))
		throw std::exception("Content name does not exist");
	return ContentManipulator(*this, contents_map[content_name]);
}
uva::Container::ContentManipulator uva::Container::Add(const std::wstring& name, std::shared_ptr<Element> element)
{
	contents.push_back({ element });
	contents_map[name] = contents.size() - 1;
	display_order.push_back(contents.size() - 1);
	return ContentManipulator(*this, contents.size() - 1);
}

void uva::Container::SetSize(const coord<float>& new_size)
{
	Element::SetSize(new_size);
	for (auto& c : contents)
	{
		if (c.container_flags & SET_SIZE)
		{
			c.element->SetSize(GetSize() * c.size_rcs);
		}
		else
		{
			c.element->SetSize(c.element->GetSize());
		}
	}
}

void uva::Container::SetPos(const coord<float>& new_pos)
{
	for (auto& c : contents)
	{
		if (c.container_flags & SET_POS)
		{
			auto _GetPos = GetPos();
			auto _GetSize = GetSize();
			auto _element_GetSize = c.element->GetSize();
			auto aux = GetPos() + c.offset + c.pos_rcs * GetSize() - c.origin_res * c.element->GetSize();
			c.element->SetPos(GetPos() + c.offset + c.pos_rcs * GetSize() - c.origin_res * c.element->GetSize());
		}
	}
}

void uva::Container::SetParent(Element* parent)
{
	Element::SetParent(parent);
	for (auto& c : contents)
		c.element->SetParent(parent);
}

uva::Container::ContentManipulator& uva::Container::ContentManipulator::Forefront()
{
	container.display_order.remove(index);
	container.display_order.push_back(index);
	return *this;
}
uva::Container::ContentManipulator& uva::Container::ContentManipulator::SetRelativePos(const coord<float>& new_relative_pos)
{
	container.contents[index].container_flags |= SET_POS;
	container.contents[index].pos_rcs = new_relative_pos;
	return *this;
}
uva::Container::ContentManipulator& uva::Container::ContentManipulator::SetRelativeOrigin(const coord<float>& new_relative_origin)
{
	container.contents[index].container_flags |= SET_POS;
	container.contents[index].origin_res = new_relative_origin;
	return *this;
}
uva::Container::ContentManipulator& uva::Container::ContentManipulator::SetRelativeSize(const coord<float>& new_relative_size)
{
	container.contents[index].container_flags |= SET_SIZE;
	container.contents[index].size_rcs = new_relative_size;
	return *this;
}
uva::Container::ContentManipulator& uva::Container::ContentManipulator::SetOffset(const coord<float>& new_offset)
{
	container.contents[index].container_flags |= SET_POS;
	container.contents[index].offset = new_offset;
	return *this;
}

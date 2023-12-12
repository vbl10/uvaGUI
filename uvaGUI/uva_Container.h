#pragma once
#include "uva_Element.h"
#include <map>
#include <list>
#include <vector>
#include <memory>

namespace uva
{
	class Container : public Element
	{
	public:
		enum FLAGS
		{
			SET_POS  = 0b01,
			SET_SIZE = 0b10
		};
	private:
		struct Content
		{
			std::shared_ptr<Element> element;
			coord<float> 
				pos_rcs		= { 0 }, //relative to container's size
				origin_res	= { 0 }, //relative to element's size
				size_rcs	= { 0 }, //relative to container's size
				offset		= { 0 }; //absolute offset in pixels
			uint8_t container_flags = 0;
		};
		std::vector<Content> contents;
		std::list<int> display_order;
		std::map<std::wstring, int> contents_map;
	public:
		void Draw(Graphics& gfx) override;

	private:
		class ContentManipulator
		{
		private:
			Container& container;
			const int index;
		public:
			ContentManipulator(Container& container, int index) :container(container), index(index) {};
			ContentManipulator& Forefront();
			ContentManipulator& SetRelativePos(const coord<float>& new_relative_pos);
			ContentManipulator& SetRelativeOrigin(const coord<float>& new_relative_origin);
			ContentManipulator& SetRelativeSize(const coord<float>& new_relative_size);
			ContentManipulator& SetOffset(const coord<float>& new_offset);
		};
	public:
		ContentManipulator At(const std::wstring& content_name);
		ContentManipulator Add(const std::wstring& name, std::shared_ptr<Element> element);

		void SetSize(const coord<float>& new_size) override;
		void SetPos(const coord<float>& new_pos) override;
		void SetParent(Element* parent) override;
	};
};


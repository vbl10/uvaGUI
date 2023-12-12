#pragma once
#include "uva_Graphics.h"
#include "uva_coord.h"

namespace uva
{
	class GUI;
	class Element
	{
	private:
		//absolute values
		coord<float>
			pos = { 0 },
			size = { 0 },
			min_size = { 0 };
		Element* parent = nullptr;
	public:
		virtual void SetParent(Element* parent) { this->parent = parent; };
	protected:
		Element* GetParent() { return parent; }
		GUI* GetRoot();
		const Element* GetParent() const { return parent; }
		const GUI* GetRoot() const;
	public:
		virtual void SetPos(const coord<float>& new_pos) { pos = new_pos; }
		virtual void SetSize(const coord<float>& new_size);
		void SetMinSize(const coord<float>& new_min_size) { min_size = new_min_size; }

		coord<float> GetPos() const { return pos; }
		coord<float> GetSize() const;
		coord<float> GetMinSize() const;
		virtual coord<float> GetDefaultMinSize() const { return { 0.0f,0.0f }; }

		virtual void Draw(Graphics& gfx);
	};
};


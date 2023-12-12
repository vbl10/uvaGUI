#pragma once
#include "uva_Graphics.h"
#include "uva_Keyboard.h"
#include "uva_Mouse.h"
#include "uva_Element.h"
#include <memory>

namespace uva
{
	class GUI : private Element
	{
	public:
		Graphics& gfx;
		Mouse& mouse;
		Keyboard& kbd;
	private:
		float fTime = 0.0f;
		std::shared_ptr<Element> content;
	public:
		GUI(Graphics& gfx, Mouse& mouse, Keyboard& kbd);
		void SetContent(std::shared_ptr<Element> content);
		void Update();
		void Draw();
		void Reshuffle();
	};
};
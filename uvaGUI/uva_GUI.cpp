#include "uva_GUI.h"
#include <chrono>

uva::GUI::GUI(Graphics& gfx, Mouse& mouse, Keyboard& kbd)
	:gfx(gfx), mouse(mouse), kbd(kbd)
{
    SetSize(gfx.GetSize());
}

void uva::GUI::SetContent(std::shared_ptr<Element> content)
{
    this->content = content;
    content->SetParent(this);
    Reshuffle();
}

void uva::GUI::Update()
{
    static std::chrono::steady_clock::time_point tp1, tp2;
    static float fElapsedTime = 0.0f;

    if (tp1.time_since_epoch().count() == 0)
    {
        tp1 = std::chrono::steady_clock::now();
    }

    //update stuff...
    fTime += fElapsedTime;

    tp2 = std::chrono::steady_clock::now();
    fElapsedTime = std::chrono::duration<float>(tp2 - tp1).count();
    tp1 = std::chrono::steady_clock::now();
}

void uva::GUI::Draw()
{
    content->Draw(gfx);
}

void uva::GUI::Reshuffle()
{
    content->SetSize(GetSize());
    content->SetPos({ 0.0f,0.0f });
}

#pragma once
#include <ext_win32.h>
#include <ext_d2d1.h>

class MainWindow : public ext::Window, public ext::D2DGraphics
{
public:
    MainWindow();
private:
    LRESULT AppProc(HWND, UINT msg, WPARAM wParam, LPARAM lParam) override;
};

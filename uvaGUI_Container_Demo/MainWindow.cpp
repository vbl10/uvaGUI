#include "MainWindow.h"

MainWindow::MainWindow()
    :Window(L"uvaGUI - demo", { 600,600 }), D2DGraphics(hWnd)
{
    ShowWindow(hWnd, SW_SHOW);
}

LRESULT MainWindow::AppProc(HWND, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}
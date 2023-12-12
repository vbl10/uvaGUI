#include "MainWindow.h"
#include <uvaD2DGraphics.h>
#include <uva_GUI.h>
#include <uva_Label.h>
#include <uva_Container.h>

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    MainWindow wnd;
    uvaD2DGraphics gfx(wnd, L"Azaret Mono", 20.0f);
    uva::Mouse mouse;
    uva::Keyboard kbd;
    uva::GUI gui(gfx, mouse, kbd);

    auto ctnMain = std::make_shared<uva::Container>();
    ctnMain->Add(L"top-left", std::make_shared<uva::Label>(L"top-left"))
        .SetRelativePos({ 0.0f,0.0f });
    ctnMain->Add(L"top-middle", std::make_shared<uva::Label>(L"top-middle"))
        .SetRelativePos({ 0.5f,0.0f })
        .SetRelativeOrigin({ 0.5f,0.0f });
    ctnMain->Add(L"top-right", std::make_shared<uva::Label>(L"top-right"))
        .SetRelativePos({ 1.0f,0.0f })
        .SetRelativeOrigin({ 1.0f,0.0f });
    ctnMain->Add(L"middle-left", std::make_shared<uva::Label>(L"middle-left"))
        .SetRelativePos({ 0.0f,0.5f })
        .SetRelativeOrigin({ 0.0f,0.5f });
    ctnMain->Add(L"middle-middle", std::make_shared<uva::Label>(L"middle-middle"))
        .SetRelativePos({ 0.5f,0.5f })
        .SetRelativeOrigin({ 0.5f,0.5f });
    ctnMain->Add(L"middle-right", std::make_shared<uva::Label>(L"middle-right"))
        .SetRelativePos({ 1.0f,0.5f })
        .SetRelativeOrigin({ 1.0f,0.5f });
    ctnMain->Add(L"bottom-left", std::make_shared<uva::Label>(L"bottom-left"))
        .SetRelativePos({ 0.0f,1.0f })
        .SetRelativeOrigin({ 0.0f,1.0f });
    ctnMain->Add(L"bottom-middle", std::make_shared<uva::Label>(L"bottom-middle"))
        .SetRelativePos({ 0.5f,1.0f })
        .SetRelativeOrigin({ 0.5f,1.0f });
    ctnMain->Add(L"bottom-right", std::make_shared<uva::Label>(L"bottom-right"))
        .SetRelativePos({ 1.0f,1.0f })
        .SetRelativeOrigin({ 1.0f,1.0f });

    gui.SetContent(ctnMain);

    MSG msg;
    // Loop de mensagem principal:
    while (true)
    {
        if (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
            if (msg.message == WM_QUIT)
                break;
        }

        gui.Update();

        wnd.pRenderTarget->BeginDraw();
        wnd.pRenderTarget->Clear();
        
        gui.Draw();

        wnd.pRenderTarget->EndDraw();
    }

    return 0;
}
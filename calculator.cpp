#include <windows.h>
#include <string>
#include <sstream>

// Function to handle button clicks
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static std::string display = "";
    static HWND hEdit;

    switch (uMsg) {
        case WM_CREATE: {
            // Create the edit control for the display
            hEdit = CreateWindowEx(
                0, "EDIT", "",
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT | ES_READONLY,
                10, 10, 280, 40,
                hwnd, (HMENU)100, nullptr, nullptr);

            // Create buttons
            const char* buttonLabels[] = {
                "7", "8", "9", "+",
                "4", "5", "6", "-",
                "1", "2", "3", "*",
                "C", "0", "=", "/"
            };

            for (int i = 0; i < 16; ++i) {
                CreateWindowEx(
                    0, "BUTTON", buttonLabels[i],
                    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                    10 + (i % 4) * 70, 60 + (i / 4) * 50, 60, 40,
                    hwnd, (HMENU)(200 + i), nullptr, nullptr);
            }
            break;
        }
        case WM_COMMAND: {
            int buttonId = LOWORD(wParam);
            if (buttonId >= 200 && buttonId < 216) {
                const char* buttonLabel = "";
                switch (buttonId) {
                    case 200: buttonLabel = "7"; break;
                    case 201: buttonLabel = "8"; break;
                    case 202: buttonLabel = "9"; break;
                    case 203: buttonLabel = "+"; break;
                    case 204: buttonLabel = "4"; break;
                    case 205: buttonLabel = "5"; break;
                    case 206: buttonLabel = "6"; break;
                    case 207: buttonLabel = "-"; break;
                    case 208: buttonLabel = "1"; break;
                    case 209: buttonLabel = "2"; break;
                    case 210: buttonLabel = "3"; break;
                    case 211: buttonLabel = "*"; break;
                    case 212: buttonLabel = "C"; break;
                    case 213: buttonLabel = "0"; break;
                    case 214: buttonLabel = "="; break;
                    case 215: buttonLabel = "/"; break;
                }

                if (strcmp(buttonLabel, "C") == 0) {
                    display = "";
                } else if (strcmp(buttonLabel, "=") == 0) {
                    //Basic evaluation. For serious calculations, use a proper parser.
                    //This code is for demonstration, and has very limited error handling.
                    //It only support simple +,-,*,/ operations with 2 numbers
                    std::stringstream ss(display);
                    double num1, num2, result;
                    char op;

                    if (ss >> num1 >> op >> num2) {
                        switch (op) {
                            case '+': result = num1 + num2; break;
                            case '-': result = num1 - num2; break;
                            case '*': result = num1 * num2; break;
                            case '/':
                                if(num2 != 0){
                                    result = num1 / num2;
                                } else {
                                    display = "Error";
                                    SetWindowText(hEdit, display.c_str());
                                    return 0;
                                }
                                break;
                            default: display = "Error";
                                SetWindowText(hEdit, display.c_str());
                                return 0;
                        }
                        std::stringstream resultStream;
                        resultStream << result;
                        display = resultStream.str();

                    } else{
                        display = "Error";
                    }

                } else {
                    display += buttonLabel;
                }
                SetWindowText(hEdit, display.c_str());
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "CalculatorWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Calculator By Saad Arshad",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 310, 300,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <Commdlg.h>
#include <locale>
#include <codecvt>

#include "SoundButtons.h"
#include "Texts.h"
#include "Background.h"



using namespace std;
using namespace sf;


void RegisterKeys() {

    if (RegisterHotKey(NULL, 9, NULL, 0x69))
    {
        std::cout << "Hotkey 'Numpad9' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }

    if (RegisterHotKey(NULL, 8, NULL, 0x68))
    {
        std::cout << "Hotkey 'Numpad8' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }

    if (RegisterHotKey(NULL, 7, NULL, 0x67))
    {
        std::cout << "Hotkey 'Numpad7' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }
    if (RegisterHotKey(NULL, 6, NULL, 0x66))
    {
        std::cout << "Hotkey 'Numpad6' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }

    if (RegisterHotKey(NULL, 5, NULL, 0x65))
    {
        std::cout << "Hotkey 'Numpad5' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }
    if (RegisterHotKey(NULL, 4, NULL, 0x64))
    {
        std::cout << "Hotkey 'Numpad4' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }
    if (RegisterHotKey(NULL, 3, NULL, 0x63))
    {
        std::cout << "Hotkey 'Numpad3' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }
    if (RegisterHotKey(NULL, 2, NULL, 0x62))
    {
        std::cout << "Hotkey 'Numpad2' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }
    if (RegisterHotKey(NULL, 1, NULL, 0x61))
    {
        std::cout << "Hotkey 'Numpad1' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }



}

std::string path_converter(wchar_t* w_str) {

    std::wstring string_to_convert;
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    std::string str = converter.to_bytes(w_str);

    return str;
}

void initialize_ofns(OPENFILENAME* ofns, wchar_t char_buffs[][100]) {

    for (int i = 0; i < 9; i++) {

        ZeroMemory(&ofns[i], sizeof(ofns[i]));
        ofns[i].lStructSize = sizeof(ofns[i]);
        ofns[i].hwndOwner = NULL;
        ofns[i].lpstrFile = char_buffs[i];
        ofns[i].lpstrFile[0] = '\0';
        ofns[i].nMaxFile = sizeof(char_buffs[i]);
        //ofns[i].lpstrFilter = "All Files\0*.*\0\0";
        ofns[i].nFilterIndex = 1;
        ofns[i].lpstrFileTitle = NULL;
        ofns[i].nMaxFileTitle = 0;
        ofns[i].lpstrInitialDir = NULL;
        ofns[i].Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    }
}

int main(void)
{

    sf::RenderWindow window(sf::VideoMode(480, 480), "Load Files");

    //Initialize file and sound buffers
    SoundBuffer sound_buffs[9];
    OPENFILENAME f_names[9];
    wchar_t char_buffs[9][100];
    initialize_ofns(f_names, char_buffs);


    //Loading widow display
    Background backg;
    backg.Load();

    Sprite b[10];
    Soundbuttons sound_buttons;
    sound_buttons.Load(b);

    Text ta[10];
    Texts texts;
    texts.Load(ta);

    while (window.isOpen()) {

        Event e;

        Vector2i pos = Mouse::getPosition(window);


        while (window.pollEvent(e)) {

            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::MouseButtonPressed) {
                if (e.key.code == Mouse::Left) {

                    for (int i = 0; i < 10; i++) {

                        if (b[i].getGlobalBounds().contains(pos.x, pos.y)) {

                            if(i == 0) {
                                window.close();
                            }

                            else {


                                if (!GetOpenFileName(&f_names[i - 1])) {

                                    std::cout << "Error code " << GetLastError();
                                }
                                string fp = path_converter(char_buffs[i-1]);
                                sound_buffs[i - 1].loadFromFile(fp);

                            }
                        }

                    }

                }

            }

        }

        window.clear();

        backg.Draw(window);
        sound_buttons.Draw(window, b);
        texts.Draw(window, ta);

        window.display();

    }


    Sound sound1;

    RegisterKeys();


    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {

            int x = msg.wParam;

            switch (x) {

            case 1:
                std::cout << "playing Numpad1\n";

                sound1.setBuffer(sound_buffs[0]);
                sound1.play();
                break;

            case 2:
                std::cout << "playing Numpad2\n";

                sound1.setBuffer(sound_buffs[1]);
                sound1.play();
                break;

            case 3:
                std::cout << "playing Numpad3\n";

                sound1.setBuffer(sound_buffs[2]);
                sound1.play();
                break;

            case 4:
                std::cout << "playing Numpad4\n";

                sound1.setBuffer(sound_buffs[3]);
                sound1.play();
                break;

            case 5:
                std::cout << "playing Numpad5\n";

                sound1.setBuffer(sound_buffs[4]);
                sound1.play();
                break;

            case 6:
                std::cout << "playing Numpad6\n";

                sound1.setBuffer(sound_buffs[5]);
                sound1.play();
                break;
            case 7:
                std::cout << "playing Numpad7\n";

                sound1.setBuffer(sound_buffs[6]);
                sound1.play();
                break;
            case 8:
                std::cout << "playing Numpad8\n";

                sound1.setBuffer(sound_buffs[7]);
                sound1.play();
                break;
            case 9:
                std::cout << "playing Numpad9\n";

                sound1.setBuffer(sound_buffs[8]);
                sound1.play();
                break;




            }
        }
    }


    return 0;
}
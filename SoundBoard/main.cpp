#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>;


using namespace std;
using namespace sf;

int main(void)
{
    SoundBuffer sound_buff;
    sound_buff.loadFromFile("Audio_Clips/ahaha.wav");

    Sound sound;
    sound.setBuffer(sound_buff);

    if (RegisterHotKey(NULL, 1, NULL, 0x69))
    {
        std::cout << "Hotkey 'Numpad9' is registered\n";
    }
    else
    {
        std::cout << "Error code " << GetLastError();
    }

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            std::cout << msg.wParam;

            std::cout << "playing Numpad9\n";

            sound.play();
        }
    }

    while (TRUE) {

    }

    /*
    *
    *     sf::RenderWindow window(sf::VideoMode(600, 800), "window");

    while (window.isOpen()) {

        Event e;

        while (window.pollEvent(e)) {

            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::KeyPressed) {

                if (e.key.code == Keyboard::BackSpace) {

                    sound.play();

                    cout << "play" << endl;
                }
            }
        }

    }
    */

    return 0;
}
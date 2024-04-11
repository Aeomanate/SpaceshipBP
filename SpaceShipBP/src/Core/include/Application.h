

#include <unordered_map>
#include <SFML/Graphics.hpp>

class Application
{
public:
    explicit Application();

    void startLoop();

private:
    void handleInput();
    void initSfmlEventHandler();

    void handleProgramClose(const sf::Event&);
    void handlePressedKeyKeyboard(const sf::Event& e);
    void handlePressedKeyMouse(const sf::Event& e);

    void update();

    void draw();

private:
    bool isApplicationWork = true;

    using WindowEventHandlerFunc = decltype(&Application::handleProgramClose);
    std::unordered_map<sf::Event::EventType, WindowEventHandlerFunc> sfmlEventHandlerMap;

    sf::RenderWindow window;
};

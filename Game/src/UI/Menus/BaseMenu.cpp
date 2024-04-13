#include "BaseMenu.h"


void BaseMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

BaseMenu::BaseMenu()
{

}

void BaseMenu::OnKeyPressed(const sf::Event::KeyEvent& key)
{
    if(key.code == sf::Keyboard::Key::Backspace)
    {
        emitterCloseRequest.Emit();
    }
}

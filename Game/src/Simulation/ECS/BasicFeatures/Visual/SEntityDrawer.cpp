#include "SEntityDrawer.h"

void SEntityDrawer::Update(float)
{
    renderTarget;
}

SEntityDrawer::SEntityDrawer(sf::RenderTarget* renderTarget)
: renderTarget { renderTarget }
{

}

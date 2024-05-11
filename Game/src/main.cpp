#include "Core/Application/Application.h"



int main()
{
    Application::GetInstance().Init();
    Application::GetInstance().Run();
}

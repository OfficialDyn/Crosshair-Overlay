#include <Windows.h>
#include <string>

struct
{
#define Font_CALIBRI			(1 << 3)
#define Font_ARIAL			(1 << 4)
#define Font_COURIER			(1 << 5)
#define Font_GABRIOLA			(1 << 6)
#define Font_IMPACT			(1 << 7)
}fonts;

#define FOREGROUND	(1 << 0)

void OverlaySetOption(DWORD option);
typedef void(*DirectOverlayCallback)(int width, int height);
void InitializeOverlay(DirectOverlayCallback callbackFunction, HWND targetWindow);
void RenderLine(float x1, float y1, float x2, float y2, float thickness, float r, float g, float b, float a);
void RenderCheckmark(float x, float y, float r, float g, float b, float a);
void RenderCross(float x, float y, float r, float g, float b, float a);
void RenderBox(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);
void RenderCircle(float x, float y, float radius, float thickness, float r, float g, float b, float a, bool filled);
void RenderEllipse(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);
void RenderText(std::string str, float fontSize, float x, float y, float r, float g, float b, float a);
void RenderShadowText(std::string str, float fontSize, float x, float y, float r, float g, float b, float a);
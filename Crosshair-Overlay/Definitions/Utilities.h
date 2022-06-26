struct keystate
{
	DWORD time_started;
	bool is_pressed;
}

KeyStatus[256];

class utils_
{
public:
	__forceinline string randomstring(size_t length)
	{
		string string, chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		random_device random_device;
		mt19937 generator(random_device());
		uniform_int_distribution<> randomization(0, chars.size() - 1);
		for (size_t i = 0; i < length; ++i)
		{
			string += chars[randomization(generator)];
		}
		return string;
	}
	__forceinline bool __stdcall IsKeyPressed(int key, int var)
	{
		if (HIWORD(GetKeyState(key)))
		{
			if (!KeyStatus[key].is_pressed || (KeyStatus[key].time_started && (KeyStatus[key].time_started + var) <= GetTickCount()))
			{
				KeyStatus[key].is_pressed = TRUE;
				if (var > NULL)
					KeyStatus[key].time_started = GetTickCount();
				return TRUE;
			}
		}
		else
			KeyStatus[key].is_pressed = FALSE;
		return false;
	}
	__forceinline void create_thread(LPTHREAD_START_ROUTINE IpStartAddress)
	{
		HANDLE handle = CreateThread(NULL, NULL, IpStartAddress, NULL, NULL, NULL); CloseHandle(handle);
	}
	__forceinline void render_crosshair(int center_width, int center_height)
	{
		if (functions.render_crosshair)
		{
			if (functions.render_outline)
			{
				RenderLine(center_width - style->crosshair_length - 1, center_height, center_width - style->crosshair_gap + 1, center_height, style->crosshair_thickness + 1, 0, 0, 0, 255);
				RenderLine(center_width + style->crosshair_gap - 1, center_height, center_width + style->crosshair_length + 1, center_height, style->crosshair_thickness + 1, 0, 0, 0, 255);
				RenderLine(center_width, center_height - style->crosshair_length - 1, center_width, center_height - style->crosshair_gap + 1, style->crosshair_thickness + 1, 0, 0, 0, 255);
				RenderLine(center_width, center_height + style->crosshair_length + 1, center_width, center_height + style->crosshair_gap - 1, style->crosshair_thickness + 1, 0, 0, 0, 255);
			}

			RenderLine(center_width - style->crosshair_length, center_height, center_width - style->crosshair_gap, center_height, style->crosshair_thickness, style->color.red, style->color.green, style->color.blue, style->color.alpha);
			RenderLine(center_width + style->crosshair_gap, center_height, center_width + style->crosshair_length, center_height, style->crosshair_thickness, style->color.red, style->color.green, style->color.blue, style->color.alpha);
			RenderLine(center_width, center_height - style->crosshair_length, center_width, center_height - style->crosshair_gap, style->crosshair_thickness, style->color.red, style->color.green, style->color.blue, style->color.alpha);
			RenderLine(center_width, center_height + style->crosshair_length, center_width, center_height + style->crosshair_gap, style->crosshair_thickness, style->color.red, style->color.green, style->color.blue, style->color.alpha);


			if (functions.render_outline && functions.render_crosshair_centerdot)
				RenderCircle(center_width, center_height, 4, 1, 0, 0, 0, 255, true);
			if (functions.render_crosshair_centerdot)
				RenderCircle(center_width, center_height, 3, 1, style->color.red, style->color.green, style->color.blue, style->color.alpha, true);

		}
	}

}; inline static utils_* utils = new utils_;
DWORD keybinds(LPVOID in)
{
	while (1)
	{
		if (utils->IsKeyPressed(VK_RSHIFT, 0x800))
			functions.render_menu = !functions.render_menu;

		if (functions.render_menu)
		{
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				selection_indicator_pos -= 20;
				if (selection_indicator_pos <= 0) selection_indicator_pos = 0;
			}
			if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				selection_indicator_pos += 20;
				if (selection_indicator_pos >= 540) selection_indicator_pos = 540;
			}

			if (selection_indicator_pos == 0 && utils->IsKeyPressed(VK_RETURN, 0x800))
				functions.render_crosshair = !functions.render_crosshair;

			if (selection_indicator_pos == 20 && utils->IsKeyPressed(VK_RETURN, 0x800))
				functions.render_outline = !functions.render_outline;

			if (selection_indicator_pos == 40 && utils->IsKeyPressed(VK_RETURN, 0x800))
				functions.render_crosshair_centerdot = !functions.render_crosshair_centerdot;

			if (selection_indicator_pos == 60)
			{
				if (GetAsyncKeyState(VK_LEFT) & 1)
					style->crosshair_length -= 1;
				if (GetAsyncKeyState(VK_RIGHT) & 1)
					style->crosshair_length += 1;

				if (style->crosshair_length <= 1) style->crosshair_length = 1;
				if (style->crosshair_length >= 16) style->crosshair_length = 16;
			}

			if (selection_indicator_pos == 80)
			{
				if (GetAsyncKeyState(VK_LEFT) & 1)
					style->crosshair_gap -= 1;
				if (GetAsyncKeyState(VK_RIGHT) & 1)
					style->crosshair_gap += 1;

				if (style->crosshair_gap <= 1) style->crosshair_gap = 1;
				if (style->crosshair_gap >= 16) style->crosshair_gap = 16;
				if (style->crosshair_gap >= style->crosshair_length - 1) style->crosshair_gap = style->crosshair_length - 1;
			}

			if (selection_indicator_pos == 100)
			{
				if (GetAsyncKeyState(VK_LEFT) & 1)
					style->crosshair_thickness -= 2;
				if (GetAsyncKeyState(VK_RIGHT) & 1)
					style->crosshair_thickness += 2;

				if (style->crosshair_thickness <= 2) style->crosshair_thickness = 2;
				if (style->crosshair_thickness >= 8) style->crosshair_thickness = 8;				
			}

			if (selection_indicator_pos == 120)
			{
				if (GetAsyncKeyState(VK_LEFT) & 1)
					style->color.red -= 2;
				if (GetAsyncKeyState(VK_RIGHT) & 1)
					style->color.red += 2;

				if (style->color.red <= 0) style->color.red = 0;
				if (style->color.red >= 255) style->color.red = 255;
			}

			if (selection_indicator_pos == 140)
			{
				if (GetAsyncKeyState(VK_LEFT) & 1)
					style->color.green -= 2;
				if (GetAsyncKeyState(VK_RIGHT) & 1)
					style->color.green += 2;

				if (style->color.green <= 0) style->color.green = 0;
				if (style->color.green >= 255) style->color.green = 255;
			}

			if (selection_indicator_pos == 160)
			{
				if (GetAsyncKeyState(VK_LEFT) & 1)
					style->color.blue -= 2;
				if (GetAsyncKeyState(VK_RIGHT) & 1)
					style->color.blue += 2;

				if (style->color.blue <= 0) style->color.blue = 0;
				if (style->color.blue >= 255) style->color.blue = 255;
			}

			if (selection_indicator_pos == 180)
			{
				if (GetAsyncKeyState(VK_LEFT) & 1)
					style->color.alpha -= 2;
				if (GetAsyncKeyState(VK_RIGHT) & 1)
					style->color.alpha += 2;

				if (style->color.alpha <= 0) style->color.alpha = 0;
				if (style->color.alpha >= 255) style->color.alpha = 255;
			}

			if (utils->IsKeyPressed(VK_F3, 0x800))
			{
				ExitProcess(0);
			}
		}
	}
}
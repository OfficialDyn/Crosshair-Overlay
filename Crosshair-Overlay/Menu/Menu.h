void Menu(int width, int height)
{
	int x = width - 270;
	int y = 20;
	if (functions.render_menu)
	{
		RenderBox(x, y, 250, 600, 1, 20, 20, 20, 255, true);
		RenderBox(x, y, 250, 30, 1, 42, 108, 189, 255, true);
		RenderBox(x, y, 250, 600, 1, 42, 108, 189, 255, false);
		RenderShadowText("Crosshair Overlay", 16, x + 63, y + 4, 255, 255, 255, 255);
		RenderBox(x, y + 30 + selection_indicator_pos, 250, 20, 1, 42, 108, 189, 255, false);
		
		RenderText("Render Crosshair", 14, x + 5, y + 30, 255, 255, 255, 255);
		if (functions.render_crosshair)
			RenderCheckmark(x + 240, y + 41, 0, 255, 0, 255);
		else
			RenderCross(x + 240, y + 40, 255, 0, 0, 255);

		RenderText("Render Outline", 14, x + 5, y + 50, 255, 255, 255, 255);
		if (functions.render_outline)
			RenderCheckmark(x + 240, y + 61, 0, 255, 0, 255);
		else
			RenderCross(x + 240, y + 60, 255, 0, 0, 255);

		RenderText("Render Center Dot", 14, x + 5, y + 70, 255, 255, 255, 255);
		if (functions.render_crosshair_centerdot)
			RenderCheckmark(x + 240, y + 81, 0, 255, 0, 255);
		else
			RenderCross(x + 240, y + 80, 255, 0, 0, 255);

		RenderText("Length", 14, x + 5, y + 90, 255, 255, 255, 255);
		if(style->crosshair_length < 10) RenderText(std::to_string(style->crosshair_length), 14, x + 237, y + 90, 255, 255, 255, 255);
		else RenderText(std::to_string(style->crosshair_length), 14, x + 232, y + 90, 255, 255, 255, 255);

		RenderText("Gap", 14, x + 5, y + 110, 255, 255, 255, 255);
		if (style->crosshair_gap < 10) RenderText(std::to_string(style->crosshair_gap), 14, x + 237, y + 110, 255, 255, 255, 255);
		else RenderText(std::to_string(style->crosshair_gap), 14, x + 232, y + 110, 255, 255, 255, 255);

		RenderText("Thickness", 14, x + 5, y + 130, 255, 255, 255, 255);
		RenderText(std::to_string(style->crosshair_thickness / 2), 14, x + 237, y + 130, 255, 255, 255, 255);

		RenderText("Red", 14, x + 5, y + 150, 255, 255, 255, 255);
		if (style->color.red < 10) RenderText(std::to_string(style->color.red), 14, x + 237, y + 150, 255, 255, 255, 255);
		if (style->color.red >= 10 && style->color.red <= 99) RenderText(std::to_string(style->color.red), 14, x + 232, y + 150, 255, 255, 255, 255);
		if (style->color.red >= 100 ) RenderText(std::to_string(style->color.red), 14, x + 225, y + 150, 255, 255, 255, 255);

		RenderText("Green", 14, x + 5, y + 170, 255, 255, 255, 255);
		if (style->color.green < 10) RenderText(std::to_string(style->color.green), 14, x + 237, y + 170, 255, 255, 255, 255);
		if (style->color.green >= 10 && style->color.green <= 99) RenderText(std::to_string(style->color.green), 14, x + 232, y + 170, 255, 255, 255, 255);
		if (style->color.green >= 100) RenderText(std::to_string(style->color.green), 14, x + 225, y + 170, 255, 255, 255, 255);

		RenderText("Blue", 14, x + 5, y + 190, 255, 255, 255, 255);
		if (style->color.blue < 10) RenderText(std::to_string(style->color.blue), 14, x + 237, y + 190, 255, 255, 255, 255);
		if (style->color.blue >= 10 && style->color.blue <= 99) RenderText(std::to_string(style->color.blue), 14, x + 232, y + 190, 255, 255, 255, 255);
		if (style->color.blue >= 100) RenderText(std::to_string(style->color.blue), 14, x + 225, y + 190, 255, 255, 255, 255);

		RenderText("Alpha", 14, x + 5, y + 210, 255, 255, 255, 255);
		if (style->color.alpha < 10) RenderText(std::to_string(style->color.alpha), 14, x + 237, y + 210, 255, 255, 255, 255);
		if (style->color.alpha >= 10 && style->color.alpha <= 99) RenderText(std::to_string(style->color.alpha), 14, x + 232, y + 210, 255, 255, 255, 255);
		if (style->color.alpha >= 100) RenderText(std::to_string(style->color.alpha), 14, x + 225, y + 210, 255, 255, 255, 255);
	}
	utils->render_crosshair(width / 2, height / 2);
}
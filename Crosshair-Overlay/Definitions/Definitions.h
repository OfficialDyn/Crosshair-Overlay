using namespace std;
struct
{
	inline static bool render_menu = 1;
	inline static bool render_crosshair = 1;
	inline static bool render_outline = 1;
	inline static bool render_crosshair_centerdot = 0;
}functions;

inline static int selection_indicator_pos = 0;

class style_
{
public:
	struct
	{
		inline static int red = 255;
		inline static int blue = 0;
		inline static int green = 0;
		inline static int alpha = 255;
	}color;
	inline static int crosshair_length = 8;
	inline static int crosshair_gap = 2;
	inline static int crosshair_thickness = 2;
}; inline static style_* style = new style_;
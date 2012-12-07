package TestDriver;

public class Generator {
	public static String[] ALL_COLORS =
		{"Black",		"White",		"Red",			"Blue",
		 "Green",		"Yellow",		"Brown",		"Purple",
		 "Viridian",	"Pewter",		"Cerulean",		"Vermilion",
		 "Lavender",	"Celadon",		"Fuchsia",		"Saffron",
		 "Orange",		"Apricot",		"Gold",			"Gray",
		 "Magenta",		"Salmon",		"Silver",		"Copper",
		 "Sepia",		"Teal",			"Scarlet",		"Indigo",
		 "Pine",		"Plum",			"Maroon",		"Orchid",
		 "Peach",		"Olive",		"Tan",			"Sienna",
		 "Mauvelous",	"Razzmatazz",	"Manatee",		"Beaver"	//these are real colors, according to Crayola: http://en.wikipedia.org/wiki/List_of_Crayola_crayon_colors
		};
	
	public int _numPegs, _numColors;
	public String[] _colorSpace;
	
	public Generator(int numPegs, int numColors) {
		this._numPegs = numPegs;
		this._numColors = numColors;
		this._colorSpace = new String[numColors];
		for(int color_index = 0; color_index < numColors; color_index++)
			this._colorSpace[color_index] = ALL_COLORS[color_index];
	}
	
	public Generator(int numPegs, String[] colorSpace) {
		this._numPegs = numPegs;
		this._numColors = colorSpace.length;
		this._colorSpace = colorSpace;
	}
	
	//just generates a dumb, all-random code
	public Code generate() {
		Code returnval = new Code(_colorSpace, _numPegs, true);
		return returnval;
	}
}

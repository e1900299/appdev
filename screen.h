// usually in a header file we have 2 parts:
// 1. function declarations
// 2. constant definitions

//constant definitions
#define ESC 0x1B	// or using 27
// make enumeration for fg colors
enum FG {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10) // this is called Marco definition

#define UNICODE
#define BAR "\u2590"
#define REC "\u2588"

#define DEBUG
// the following is the information of cursor position, this information will be decored by an escape sequence ESC[6n, and query
// reply should be a string consisting row and col numbers of the cursor.
typedef struct{
	int row;
	int col;
} Position;
// making a constant in a name will make your program more meaningful or readable
// now we can use color names in function setfgcolor()

//function declarations
#define UNICODE	// for conditional compilation

void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolors(void);
void clearscreen(void);
void gotoXY(int, int);
void drawbar(int, int);
void drawrect(int, int, int, int);
Position getscreensize(void);	// this function returns a compound data ( 2 ints)

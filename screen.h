// Usually in a header file, following information are included
// 1. Function declarations
// 2. Constant definitions
// 3. Conditional compilation

// Constant definitions
#define ESC 0x1B
//#define BLACK 30, instead of using define, it's betetr to use enumeration
enum FG{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10)	//marco definition

#define UNICODE		//This is for conditional compilation
#define BAR "\u2590"

//#define DEBUG	//for conditional compilation
typedef struct{	//for this struct we will define a compound data, which consists of the number of rows
	int row;	//and the number of columns of our screen
	int col;
}Position;

// Function declarations

void clearscreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolors(void);
void gotoXY(int, int);
void drawbar(int, int);
void drawrect(int, int, int, int);
Position getscreensize(void);

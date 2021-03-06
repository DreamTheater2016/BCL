#include <tui.h>

WINDOW *create_new_win(int startx, int starty, int width, int height)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

WINDOW *simple_create_new_win(int startx, int starty, int width, int height)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	wrefresh(local_win);

	return local_win;
}


void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}

void init_colors()
{
	start_color();

	init_pair(COLOR_DEFAULT, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_COMMENT, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_INCLUDE, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_STDLIB, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_TODO, COLOR_WHITE, COLOR_YELLOW);
	init_pair(COLOR_DATA, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_CTL, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_BOOL, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_JUMP, COLOR_MAGENTA, COLOR_BLACK);
}

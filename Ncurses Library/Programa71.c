#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>

WINDOW *crearVentana(int alto, int ancho, int y, int x){
    WINDOW *win;
    win = newwin(alto,ancho,y,x);

 
    return win;
}

void eliminarVentana(WINDOW *win){
  
    wrefresh(win);
    delwin(win);
    
}

void opcion1(WINDOW *win){
   

    start_color();                    /*  Initialize colours  */

    /*  Make sure we are able to do what we want. If
	has_colors() returns FALSE, we cannot use colours.
	COLOR_PAIRS is the maximum number of colour pairs
	we can use. We use 13 in this program, so we check
	to make sure we have enough available.               */

    if ( has_colors() && COLOR_PAIRS >= 13 ) {

	int n = 1;


	/*  Initialize a bunch of colour pairs, where:

	        init_pair(pair number, foreground, background);

	    specifies the pair.                                  */

	init_pair(1,  COLOR_RED,     COLOR_BLACK);
	init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
	init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
	init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
	init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
	init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
	init_pair(8,  COLOR_WHITE,   COLOR_RED);
	init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
	init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
	init_pair(11, COLOR_WHITE,   COLOR_BLUE);
	init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
	init_pair(13, COLOR_BLACK,   COLOR_CYAN);


	/*  Use them to print of bunch of "Hello, world!"s  */

	while ( n <= 13 ) {
	    color_set(n, NULL);
	    mvaddstr(10 + n, 20+n, " Prueba");
	    n++;
	}
    while(n>=0){
        color_set(n, NULL);
        mvaddstr(10+n, 20-n, " Prueba");
        n--;
    }
    
    }


    /*  Refresh the screen and sleep for a
	while to get the full screen effect  */

    refresh();

   
    

    /*  Clean up after ourselves  */

}
void opcion2(WINDOW *win){


    start_color();                    /*  Initialize colours  */

    /*  Make sure we are able to do what we want. If
	has_colors() returns FALSE, we cannot use colours.
	COLOR_PAIRS is the maximum number of colour pairs
	we can use. We use 13 in this program, so we check
	to make sure we have enough available.               */

    if ( has_colors() && COLOR_PAIRS >= 13 ) {

	int n = 1;


	/*  Initialize a bunch of colour pairs, where:

	        init_pair(pair number, foreground, background);

	    specifies the pair.                                  */

	init_pair(1,  COLOR_RED,     COLOR_BLACK);
	init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
	init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
	init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
	init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
	init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
	init_pair(8,  COLOR_WHITE,   COLOR_RED);
	init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
	init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
	init_pair(11, COLOR_WHITE,   COLOR_BLUE);
	init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
	init_pair(13, COLOR_BLACK,   COLOR_CYAN);


	/*  Use them to print of bunch of "Hello, world!"s  */

	while ( n <= 13 ) {
	    color_set(n, NULL);
	    mvaddstr(10 + n, 25+n, " Prueba");
	    n++;
	}
    while(n>=0){
        color_set(n, NULL);
        mvaddstr(10+n, 25-n, " Prueba");
        n--;
    }
    
    }


    /*  Refresh the screen and sleep for a
	while to get the full screen effect  */

    refresh();
  

   
    

    /*  Clean up after ourselves  */

}
void opcion3(WINDOW *win){
    start_color();                    /*  Initialize colours  */

    /*  Make sure we are able to do what we want. If
	has_colors() returns FALSE, we cannot use colours.
	COLOR_PAIRS is the maximum number of colour pairs
	we can use. We use 13 in this program, so we check
	to make sure we have enough available.               */

    if ( has_colors() && COLOR_PAIRS >= 13 ) {

	int n = 1;


	/*  Initialize a bunch of colour pairs, where:

	        init_pair(pair number, foreground, background);

	    specifies the pair.                                  */

	init_pair(1,  COLOR_RED,     COLOR_BLACK);
	init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
	init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
	init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
	init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
	init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
	init_pair(8,  COLOR_WHITE,   COLOR_RED);
	init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
	init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
	init_pair(11, COLOR_WHITE,   COLOR_BLUE);
	init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
	init_pair(13, COLOR_BLACK,   COLOR_CYAN);


	/*  Use them to print of bunch of "Hello, world!"s  */

	while ( n <= 13 ) {
	    color_set(n, NULL);
	    mvaddstr(n, 25+n, " Prueba");
	    n++;
	}
    while(n>=0){
        color_set(n, NULL);
        mvaddstr(n, 25-n, " Prueba");
        n--;
    }
    
    }


    /*  Refresh the screen and sleep for a
	while to get the full screen effect  */

    refresh();
  

   
    

    /*  Clean up after ourselves  */
    
}
void opcion4(WINDOW *win){
    
}
int main() {

    WINDOW *win;
    int alto = 30, ancho=30;
    int x = (COLS - ancho) / 2;
    int y = (LINES - alto) / 2;

    int res; //variable para elegir opción del menu

    /*  Initialize ncurses  */

    if ( (win = initscr()) == NULL ) {
	fprintf(stderr, "Error initialising ncurses.\n");
	exit(-1);
    }
    raw();
    noecho();
   
 
    keypad(win,true);
    printw("Opciones del programa\n");
    printw("Presiona F1 para opcion 1\n");
    printw("Presiona F2 para opcion 2\n");
    printw("Presiona F3 para opcion 3\n");
    printw("Presiona F4 para opcion 4\n");
    printw("Presiona F5 para salir\n");
    

    refresh();

    win = crearVentana(alto, ancho, y, x);
  

    while((res = getch()) != KEY_F(5)){
        
        switch (res)
        {
        case KEY_F(1):
        
            eliminarVentana(win);
            win = crearVentana(alto, ancho, y , x);
            opcion1(win);
            break;

        case KEY_F(2):

            eliminarVentana(win);
            win = crearVentana(alto, ancho, y , x);
            opcion2(win);
     
            break;

        case KEY_F(3):
            eliminarVentana(win);
            win = crearVentana(alto, ancho, y , x);
            opcion3(win);
            break;

        case KEY_F(4):
            eliminarVentana(win);
            win = crearVentana(alto, ancho, y , x);
            opcion4(win);
            break;
        case KEY_F(5):
            break;
        }
    }
    

    endwin();
    return 0;
}


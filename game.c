#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <signal.h>
int h,w;
int playerposx,playerposy;
char grapharray[30][30];
struct projectile{
  int velocity;
  int direction;
  int cols;
  int rows;
}projectile1, projectile2, projectile3;

void setplayerpos(){
 playerposx=rand()%30;
 playerposy=rand()%30;
 
}
int  assign_graph(int a, int b){
  for(int i=1;i<30;i++){
    for(int j=1;j<30;j++){
      grapharray[i][j]='#';
    }
  }
 grapharray[projectile1.cols][projectile1.rows]='>'; 
 grapharray[playerposx][playerposy]='o';
 if(playerposx>=28){
  playerposx=28;
 }
 if(playerposx<2){
  playerposx=2;
 }
 if(playerposy>=28){
  playerposy=28;
 }
 if(playerposy<2){
  playerposy=2;
 }
}
void drawgraph(){
  for(int i=1;i<=30;i++){
    for(int j=1;j<=30;j++){
      if(i==playerposx && j==playerposy){
        printf("\033[01;33m");
        printf("%c ",grapharray[i][j]);
        printf("\033[0m");
      }else{
        printf("\033[0;31m");
        printf("%c ",grapharray[i][j]);
      }
      if(i==projectile1.cols && j==projectile1.rows){
        printf("\033[0;32m");
        printf("%c",grapharray[i][j]);
        printf("\033[0m");
      }
    }
    printf("\n\r");
  }
}
//void* resizeHandler(int);
int main(){
  // signal(SIGWINCH, resizeHandler);
  initscr();
 // start_color();
  WINDOW *win = newwin(100,100,300,300);
  noecho();
  wattron(win, COLOR_PAIR(2));
  whline(win,ACS_HLINE, 40);
  keypad(stdscr,TRUE);
  srand(time(NULL));
  setplayerpos();
  bool condition = 1;
//  projectile1.direction=rand()%4;
//  projectile1.cols= rand()%25;
//  projectile1.rows= rand()%25;
//  projectile1.velocity= 1;
  while(condition){
    wrefresh(stdscr);
    assign_graph(playerposy,playerposx);
    drawgraph();
  int keyinput =getch();
  wmove(win,30 ,30);
  switch (keyinput) {
       case KEY_RIGHT:
          playerposy+=1;
          clear();
          break;  
       case KEY_UP:  
          playerposx-=1;
          clear();
          break; 
       case KEY_DOWN: 
          playerposx=playerposx+1;
          clear();
          break;
       case KEY_LEFT:
          playerposy-=1;
          clear();
          break;
       case KEY_BACKSPACE:
          delwin(win);
          condition = 0;
          break;
  }
  assign_graph(playerposy,playerposx);
  }
  endwin();
}

/*void* resizeHandler(int sig){
  int nh,nw;
  getmaxyx(stdscr, nh, nw);
}*/

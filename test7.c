#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<sys/time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include<stdlib.h>
#include<SDL2/SDL_mixer.h>

#define WINDOW_WIDTH (1000)
#define WINDOW_HEIGHT (700)
#define SPEED (600)

int main(void)
{    
     
     int hsc;
     double m=7.0;
     double m1=7.0;
     double m2=7.0;
     int life=1;
     int life1=1;
     int life2=1;
     int flag=0;
     int pause=0;
     int g=2;
     int k=1;
     int last,copy,prsc;
     int score=0;
     int t1,t2,p1,p2;
     srand(time(0));
     TTF_Init();
     int k1=2;
     int k2=2;
     int close_requested = 0;
    int up1 = 0;
    int down1 = 0;
    int left1 = 0;
    int right1 = 0;

    int up2 = 0;
    int down2 = 0;
    int left2 = 0;
    int right2 = 0;
    char sc[3];
   for(int i=0;i<3;i++)
    sc[i]='0';  
   char hs[3];
   for(int i=0;i<3;i++)
    hs[i]='0';   
    FILE *fp; 
   fp=fopen("integer","r");
   hsc=getw(fp);
   fclose(fp);
 copy=hsc;
       while(copy!=0)
       {
       last=copy%10;
       copy=copy/10;
       switch(last)
       { 
        case 0:
        hs[g]='0';
        break;
        case 1:
        hs[g]='1';
        break;
        case 2:
        hs[g]='2';
        break;
        case 3:
        hs[g]='3';
        break;
        case 4:
        hs[g]='4';
        break;
        case 5:
        hs[g]='5';
        break;
        case 6:
        hs[g]='6';
        break;
        case 7:
        hs[g]='7';
        break;
        case 8:
        hs[g]='8';
        break;
        case 9:
        hs[g]='9';
        break;
     }
     g--;
}
 g=2;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("VBall",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_WIDTH, WINDOW_HEIGHT,0);
   
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Surface *front=IMG_Load("resources/COD.jpg");
    SDL_Texture* tfr= SDL_CreateTextureFromSurface(rend,front);
    SDL_FreeSurface(front);
    SDL_Rect dfr;
    SDL_QueryTexture(tfr, NULL, NULL, &dfr.w, &dfr.h);
    dfr.x=0;
    dfr.y=0;
    dfr.w=WINDOW_WIDTH;
    dfr.h=WINDOW_HEIGHT;
    SDL_RenderCopy(rend, tfr, NULL, &dfr);
     SDL_RenderPresent(rend);
    SDL_Delay(2000);

  Mix_Music* music;
  Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
  music=Mix_LoadMUS("resources/ChillingMusic.wav");
Mix_PlayMusic(music,-1);

 TTF_Font *fonth = TTF_OpenFont("resources/OpenSans-Bold.ttf", 80);
 SDL_Color colorhigh = { 0, 255, 0};
 SDL_Color colorhs = {255,0,255};
  SDL_Surface * surfhigh = TTF_RenderText_Solid(fonth,"HIGH-SCORE", colorhigh);

 SDL_Texture * texhigh = SDL_CreateTextureFromSurface(rend,
  surfhigh);

SDL_Rect desthigh;
 SDL_QueryTexture(texhigh, NULL, NULL, &desthigh.w, &desthigh.h);
   desthigh.x=WINDOW_WIDTH/2;
   desthigh.y=WINDOW_HEIGHT/2;

  SDL_Surface * surfhscr = TTF_RenderText_Solid(fonth,hs, colorhs);

 SDL_Texture * texhscr = SDL_CreateTextureFromSurface(rend,
  surfhscr);

SDL_Rect desthscr;
 SDL_QueryTexture(texhscr, NULL, NULL, &desthscr.w, &desthscr.h);
   desthscr.x=WINDOW_WIDTH/2;
   desthscr.y=WINDOW_HEIGHT/2+desthigh.h;

    SDL_Surface *sinstr=IMG_Load("resources/instr.jpg");
    SDL_Texture* tinstr= SDL_CreateTextureFromSurface(rend,sinstr);
    SDL_FreeSurface(sinstr);
    SDL_Rect dinstr;
    SDL_QueryTexture(tinstr, NULL, NULL, &dinstr.w, &dinstr.h);
    dinstr.x=0;
    dinstr.y=0;
    dinstr.w=WINDOW_WIDTH;
    dinstr.h=WINDOW_HEIGHT;
    SDL_Surface *slvl1=IMG_Load("resources/lvl1.jpg");
    SDL_Texture* tlvl1= SDL_CreateTextureFromSurface(rend,slvl1);
    SDL_FreeSurface(slvl1);
    SDL_Rect dlvl1;
    SDL_QueryTexture(tlvl1, NULL, NULL, &dlvl1.w, &dlvl1.h);
    dlvl1.x=0;
    dlvl1.y=0;
    dlvl1.w=WINDOW_WIDTH;
    dlvl1.h=WINDOW_HEIGHT;
    SDL_Surface *slvl2=IMG_Load("resources/lvl2.jpg");
    SDL_Texture* tlvl2= SDL_CreateTextureFromSurface(rend,slvl2);
    SDL_FreeSurface(slvl2);
    SDL_Rect dlvl2;
    SDL_QueryTexture(tlvl2, NULL, NULL, &dlvl2.w, &dlvl2.h);
    dlvl2.x=0;
    dlvl2.y=0;
    dlvl2.w=WINDOW_WIDTH;
    dlvl2.h=WINDOW_HEIGHT;
    SDL_Surface *slvl3=IMG_Load("resources/lvl3.jpg");
    SDL_Texture* tlvl3= SDL_CreateTextureFromSurface(rend,slvl3);
    SDL_FreeSurface(slvl3);
    SDL_Rect dlvl3;
    SDL_QueryTexture(tlvl3, NULL, NULL, &dlvl3.w, &dlvl3.h);
    dlvl3.x=0;
    dlvl3.y=0;
    dlvl3.w=WINDOW_WIDTH;
    dlvl3.h=WINDOW_HEIGHT; 
    SDL_Surface* surfplays = IMG_Load("resources/plays.jpg");
    SDL_Texture* texplays = SDL_CreateTextureFromSurface(rend, surfplays);
    SDL_FreeSurface(surfplays);
    SDL_Rect destplays;
    SDL_QueryTexture(texplays, NULL, NULL, &destplays.w, &destplays.h);
    destplays.x=0;
    destplays.y=0;
    destplays.w=WINDOW_WIDTH;
    destplays.h=WINDOW_HEIGHT;
    SDL_Surface* surfplaym = IMG_Load("resources/playm.jpg");
    SDL_Texture* texplaym = SDL_CreateTextureFromSurface(rend, surfplaym);
    SDL_FreeSurface(surfplaym);
    SDL_Rect destplaym;
    SDL_QueryTexture(texplaym, NULL, NULL, &destplaym.w, &destplaym.h);
    destplaym.x=0;
    destplaym.y=0;
    destplaym.w=WINDOW_WIDTH;
    destplaym.h=WINDOW_HEIGHT;
    SDL_Surface* surfhelp = IMG_Load("resources/help.jpg");
    SDL_Texture* texhelp = SDL_CreateTextureFromSurface(rend, surfhelp);
    SDL_FreeSurface(surfhelp);
    SDL_Rect desthelp;
    SDL_QueryTexture(texhelp, NULL, NULL, &desthelp.w, &desthelp.h);
    desthelp.x=0;
    desthelp.y=0;
    desthelp.w=WINDOW_WIDTH;
    desthelp.h=WINDOW_HEIGHT;
    SDL_Surface* surfhighscore = IMG_Load("resources/highscore.jpg");
    SDL_Texture* texhighscore = SDL_CreateTextureFromSurface(rend, surfhighscore);
    SDL_FreeSurface(surfhighscore);
    SDL_Rect desthighscore;
    SDL_QueryTexture(texhighscore, NULL, NULL, &desthighscore.w, &desthighscore.h);
    desthighscore.x=0;
    desthighscore.y=0;
    desthighscore.w=WINDOW_WIDTH;
    desthighscore.h=WINDOW_HEIGHT;
    SDL_Surface* surfexit = IMG_Load("resources/exit.jpg");
    SDL_Texture* texexit = SDL_CreateTextureFromSurface(rend, surfexit);
    SDL_FreeSurface(surfexit);
    SDL_Rect destexit;
    SDL_QueryTexture(texexit, NULL, NULL, &destexit.w, &destexit.h);
    destexit.x=0;
    destexit.y=0;
    destexit.w=WINDOW_WIDTH;
    destexit.h=WINDOW_HEIGHT;
    
    SDL_Surface* surfp1r = IMG_Load("resources/rball.png");
    SDL_Texture* texp1r = SDL_CreateTextureFromSurface(rend, surfp1r);
    SDL_FreeSurface(surfp1r);
    SDL_Surface* surfp1b = IMG_Load("resources/bball.jpg");
    SDL_Texture* texp1b = SDL_CreateTextureFromSurface(rend, surfp1b);
    SDL_FreeSurface(surfp1b);
    SDL_Rect destp1r;
    SDL_Rect destp1b;
    SDL_QueryTexture(texp1r, NULL, NULL, &destp1r.w, &destp1r.h);
    SDL_QueryTexture(texp1b, NULL, NULL, &destp1b.w, &destp1b.h);
     destp1r.w =60;
     destp1r.h =60;
     destp1b.w =60;
     destp1b.h =60;
     
    SDL_Surface* surfp2r = IMG_Load("resources/rball.png");
    SDL_Texture* texp2r = SDL_CreateTextureFromSurface(rend, surfp2r);
    SDL_FreeSurface(surfp2r);
    SDL_Surface* surfp2b = IMG_Load("resources/bball.jpg");
    SDL_Texture* texp2b = SDL_CreateTextureFromSurface(rend, surfp2b);
    SDL_FreeSurface(surfp2b);
    SDL_Rect destp2r;
    SDL_Rect destp2b;
    SDL_QueryTexture(texp2r, NULL, NULL, &destp2r.w, &destp2r.h);
    SDL_QueryTexture(texp2b, NULL, NULL, &destp2b.w, &destp2b.h);
     destp2r.w =60;
     destp2r.h =60;
     destp2b.w =60;
     destp2b.h =60;

    float x_posp1 = (WINDOW_WIDTH - destp1r.w) /2;
    float y_posp1 = WINDOW_HEIGHT;
    float x_posp2 = (WINDOW_WIDTH - destp2r.w) /2;
    float y_posp2 = WINDOW_HEIGHT;
    float x_vel1 = 0;
    float y_vel1 = 0;   
    float x_vel = 0;
    float y_vel = 0; 
    
    SDL_Surface* surface2 = IMG_Load("resources/white.jpg");
    SDL_Texture* tex2= SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);
     SDL_Surface* surface3 = IMG_Load("resources/red.jpg");
    SDL_Texture* tex3= SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);
    SDL_Surface* surface4 = IMG_Load("resources/blue.jpg");
    SDL_Texture* tex4= SDL_CreateTextureFromSurface(rend, surface4);
    SDL_FreeSurface(surface4);
    SDL_Rect dest2;
    SDL_Rect dest3;
    SDL_Rect dest4;
    dest2.w=174;
    dest2.h=59;
    dest3.w=174;
    dest3.h=59;
    dest4.w=174;
    dest4.h=59;
    int u=WINDOW_WIDTH-dest2.w;
    
      SDL_QueryTexture(tex2, NULL, NULL, &dest2.w, &dest2.h);
      SDL_QueryTexture(tex3, NULL, NULL, &dest3.w, &dest3.h);
      SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
 
    
    float x_pos2 = rand()%(u+1);
    float y_pos2 = 0;
     float x_pos3 = 0;
    float y_pos3 = WINDOW_HEIGHT + dest3.h;  
    float x_pos4 = 0;
    float y_pos4 = WINDOW_HEIGHT + dest4.h; 
    float x_vel2 = SPEED/2;
    float y_vel2 = SPEED/2;
    TTF_Font *font = TTF_OpenFont("resources/OpenSans-Bold.ttf", 70);
 SDL_Color colorgo = { 0, 255, 0};
 SDL_Color colorpw = {255,0,255};
 SDL_Color colorscr = { 255, 153, 51};
 SDL_Color colorhscr = {255,255,0};
 SDL_Surface * surfgo = TTF_RenderText_Solid(font,"GAME OVER", colorgo);
 SDL_Texture * texgo = SDL_CreateTextureFromSurface(rend,
  surfgo);
SDL_Rect destgo;
SDL_QueryTexture(texgo, NULL, NULL, &destgo.w, &destgo.h);
   destgo.x=WINDOW_WIDTH/2;
   destgo.y=WINDOW_HEIGHT/2;
   
 SDL_Surface * surfpw1 = TTF_RenderText_Solid(font,"PLAYER WITH SPACE WINS", colorpw);
 SDL_Texture * texpw1 = SDL_CreateTextureFromSurface(rend,
  surfpw1);
SDL_Rect destpw1;
 SDL_QueryTexture(texpw1, NULL, NULL, &destpw1.w, &destpw1.h);
   destpw1.x=WINDOW_WIDTH/2;
   destpw1.y=WINDOW_HEIGHT/2+destgo.h;
   destpw1.w/=2;
   destpw1.h/=2;
  SDL_Surface * surfpw2 = TTF_RenderText_Solid(font,"PLAYER WITH TAB WINS", colorpw);
 SDL_Texture * texpw2 = SDL_CreateTextureFromSurface(rend,
  surfpw2);
 SDL_Rect destpw2;
SDL_QueryTexture(texpw2, NULL, NULL, &destpw2.w, &destpw2.h);
   destpw2.x=WINDOW_WIDTH/2;
   destpw2.y=WINDOW_HEIGHT/2+destgo.h;
   destpw2.w/=2;
   destpw2.h/=2;

   SDL_Surface * surfpscr = TTF_RenderText_Solid(font,"SCORE :", colorpw);
 SDL_Texture * texpscr = SDL_CreateTextureFromSurface(rend,
  surfpscr);
 SDL_Rect destpscr;
SDL_QueryTexture(texpscr, NULL, NULL, &destpscr.w, &destpscr.h);
   destpscr.x=WINDOW_WIDTH/2;
   destpscr.y=WINDOW_HEIGHT/2+destgo.h;
    SDL_Surface * surfphscr = TTF_RenderText_Solid(font,"NEW HIGH-SCORE", colorhscr);
 SDL_Texture * texphscr = SDL_CreateTextureFromSurface(rend,
  surfphscr);
 SDL_Rect destphscr;
SDL_QueryTexture(texphscr, NULL, NULL, &destphscr.w, &destphscr.h);
   destphscr.x=WINDOW_WIDTH/2;
   destphscr.y=WINDOW_HEIGHT/2+destgo.h+destpscr.h;
   destphscr.w/=2;
   destphscr.h/=2;
   destp1b.x=WINDOW_WIDTH+200;
   destp1b.y=WINDOW_HEIGHT+200;

   destp2b.x=WINDOW_WIDTH+200;
   destp2b.y=WINDOW_HEIGHT+200;


   SDL_Surface* surfps = IMG_Load("resources/pause.png");
    SDL_Texture * texps = SDL_CreateTextureFromSurface(rend,
  surfps);
  SDL_Rect destps;
 SDL_QueryTexture(texps, NULL, NULL, &destps.w, &destps.h);
   destps.x=WINDOW_WIDTH+100;
   destps.y=WINDOW_HEIGHT+100;
   destps.w /=2;
   destps.h /=2;

   SDL_Surface* slife1 = IMG_Load("resources/heart.png");
    SDL_Texture * tlife1 = SDL_CreateTextureFromSurface(rend,
  slife1);
  SDL_Rect dlife1;
 SDL_QueryTexture(tlife1, NULL, NULL, &dlife1.w, &dlife1.h);
   dlife1.w /=12;
   dlife1.h /=12;
   dlife1.x=WINDOW_WIDTH+101;
   dlife1.y=WINDOW_HEIGHT+101; 
   
  SDL_Surface* slife2 = IMG_Load("resources/heart.png");
    SDL_Texture * tlife2 = SDL_CreateTextureFromSurface(rend,
  slife2);
  SDL_Rect dlife2;
 SDL_QueryTexture(tlife2, NULL, NULL, &dlife2.w, &dlife2.h);
   dlife2.w /=12;
   dlife2.h /=12;
   dlife2.x=WINDOW_WIDTH+101;
   dlife2.y=WINDOW_HEIGHT+101; 
   
  SDL_Surface* slife3 = IMG_Load("resources/heart.png");
    SDL_Texture * tlife3 = SDL_CreateTextureFromSurface(rend,
  slife3);
  SDL_Rect dlife3;
 SDL_QueryTexture(tlife3, NULL, NULL, &dlife3.w, &dlife3.h);
   dlife3.w /=12;
   dlife3.h /=12;
   dlife3.x=WINDOW_WIDTH+101;
   dlife3.y=WINDOW_HEIGHT+101; 
   
   SDL_Surface* slife = IMG_Load("resources/heart.png");
    SDL_Texture * tlife = SDL_CreateTextureFromSurface(rend,
  slife);
  SDL_Rect dlife;
 SDL_QueryTexture(tlife, NULL, NULL, &dlife.w, &dlife.h);
   dlife.w /=8;
   dlife.h /=8;
   dlife.x=WINDOW_WIDTH+101;
   dlife.y=WINDOW_HEIGHT+101; 
 
  SDL_Surface* slife1m = IMG_Load("resources/heart.png");
    SDL_Texture * tlife1m = SDL_CreateTextureFromSurface(rend,
  slife1m);
  SDL_Rect dlife1m;
 SDL_QueryTexture(tlife1m, NULL, NULL, &dlife1m.w, &dlife1m.h);
   dlife1m.w /=12;
   dlife1m.h /=12;
   dlife1m.x=WINDOW_WIDTH+101;
   dlife1m.y=WINDOW_HEIGHT+101; 
   
  SDL_Surface* slife2m = IMG_Load("resources/heart.png");
    SDL_Texture * tlife2m = SDL_CreateTextureFromSurface(rend,
  slife2m);
  SDL_Rect dlife2m;
 SDL_QueryTexture(tlife2m, NULL, NULL, &dlife2m.w, &dlife2m.h);
   dlife2m.w /=12;
   dlife2m.h /=12;
   dlife2m.x=WINDOW_WIDTH+101;
   dlife2m.y=WINDOW_HEIGHT+101; 
   
  SDL_Surface* slife3m = IMG_Load("resources/heart.png");
    SDL_Texture * tlife3m = SDL_CreateTextureFromSurface(rend,
  slife3m);
  SDL_Rect dlife3m;
 SDL_QueryTexture(tlife3m, NULL, NULL, &dlife3m.w, &dlife3m.h);
   dlife3m.w /=12;
   dlife3m.h /=12;
   dlife3m.x=WINDOW_WIDTH+101;
   dlife3m.y=WINDOW_HEIGHT+101; 
   
   SDL_Surface* skill = IMG_Load("resources/kill.jpg");
    SDL_Texture * tkill = SDL_CreateTextureFromSurface(rend,
  skill);
  SDL_Rect dkill;
 SDL_QueryTexture(tkill, NULL, NULL, &dkill.w, &dkill.h);
   dkill.w /=6;
   dkill.h /=6;
   dkill.x=WINDOW_WIDTH+101;
   dkill.y=WINDOW_HEIGHT+101;
 while(!close_requested)
    {
    SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
             if (ev.type==SDL_KEYDOWN)
            {
            switch(ev.key.keysym.scancode)
            {
             case SDL_SCANCODE_UP:
             flag=0;
             k--;
             break;
             case SDL_SCANCODE_DOWN:
             flag=0;
             k++;
             break;
             case SDL_SCANCODE_SPACE:
             flag=1;
            }
           }
          if(ev.type==SDL_QUIT)
           {
      close_requested=1;
            break; 
            }
         if(k<1)
         k=5;
         if(k>5)
         k=1;
        }
    if(k==1)
    {
     SDL_RenderClear(rend);
      SDL_RenderCopy(rend, texplays, NULL, &destplays);
      SDL_RenderPresent(rend);
     }
    if(k==2)
    {
     SDL_RenderClear(rend);
      SDL_RenderCopy(rend, texplaym, NULL, &destplaym);
      SDL_RenderPresent(rend);
     }
    if(k==3 && flag==0)
    { SDL_RenderClear(rend);
      SDL_RenderCopy(rend, texhighscore, NULL, &desthighscore);
      SDL_RenderPresent(rend);
    }
    if(k==4 && flag==0)
    { SDL_RenderClear(rend);
      SDL_RenderCopy(rend, texhelp, NULL, &desthelp);
      SDL_RenderPresent(rend);
    }
    if(k==5)
    { SDL_RenderClear(rend);
      SDL_RenderCopy(rend, texexit, NULL, &destexit);
      SDL_RenderPresent(rend);
    }
    if(flag==1 &&k==5)
           close_requested=1;
    if(flag==1 &&k==1)
     {
     close_requested=1;
        }
    if(flag==1 &&k==2)
     {
     close_requested=1;
        }
     if(flag==1 &&k==4)
     {
     SDL_RenderClear(rend);
     SDL_RenderCopy(rend, tinstr, NULL, &dinstr);
     SDL_RenderPresent(rend);
        }
      if(flag==1 &&k==3)
     {
     SDL_RenderClear(rend);
      SDL_RenderCopy(rend, texhscr, NULL, &desthscr);
      SDL_RenderCopy(rend, texhigh, NULL, &desthigh);
      SDL_RenderPresent(rend);
        }
     
  }  
      if(flag==1&&k==2)
    {
     close_requested=0;
     SDL_RenderClear(rend); 
    
    while (!close_requested)
    {       
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
             switch (event.type)
            {
            case SDL_QUIT:
                close_requested = 1;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.scancode==SDL_SCANCODE_W)
                up2=1;
                if(event.key.keysym.scancode==SDL_SCANCODE_UP)
                    up1 = 1;
                if(event.key.keysym.scancode==SDL_SCANCODE_A)
                left2=1;
                if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
                 left1 = 1;
                if(event.key.keysym.scancode==SDL_SCANCODE_S)
                down2=1;
                if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
                    down1 = 1;
                if(event.key.keysym.scancode==SDL_SCANCODE_D)
                right2=1;
                if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)
                    right1 = 1;
                 if(event.key.keysym.scancode==SDL_SCANCODE_SPACE)
                  { k1++;
                   t1=destp1r.x;
                   destp1r.x=destp1b.x;
                   destp1b.x=t1;
                   t2=destp1r.y;
                   destp1r.y=destp1b.y;
                   destp1b.y=t2;
                   }
                if(event.key.keysym.scancode==SDL_SCANCODE_TAB)
                  { k2++;
                   p1=destp2r.x;
                   destp2r.x=destp2b.x;
                   destp2b.x=p1;
                   p2=destp2r.y;
                   destp2r.y=destp2b.y;
                   destp2b.y=p2;
                   }
                if(event.key.keysym.scancode== SDL_SCANCODE_ESCAPE)
                    pause++;
               break;
            case SDL_KEYUP:
               if(event.key.keysym.scancode== SDL_SCANCODE_W)
                up2=0;
                if(event.key.keysym.scancode==SDL_SCANCODE_UP)
                    up1 = 0;
                if(event.key.keysym.scancode==SDL_SCANCODE_A)
                left2=0;
                if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
                    left1 = 0;
                if(event.key.keysym.scancode==SDL_SCANCODE_S)
                down2=0;
                if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
                    down1 = 0;
                if(event.key.keysym.scancode==SDL_SCANCODE_D)
                right2=0;
                if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)
                    right1 = 0;
            }
        }

        if (up1 && !down1) y_vel = -SPEED;
        if (down1 && !up1) y_vel = SPEED;
        if (left1 && !right1) x_vel = -SPEED;
        if (right1 && !left1) x_vel = SPEED;
         
        if (up2 && !down2) y_vel1 = -SPEED;
        if (down2 && !up2) y_vel1 = SPEED;
        if (left2 && !right2) x_vel1 = -SPEED;
        if (right2 && !left2) x_vel1 = SPEED;

        x_posp1 += x_vel / 60;
        y_posp1 += y_vel / 60;
        x_posp2 += x_vel1 / 60;
        y_posp2 += y_vel1 / 60;

        x_vel = y_vel = 0;
        x_vel1 = y_vel1 = 0;

        if (x_posp1 <= 0) x_posp1 = 0;
        if (y_posp1 <= 0) y_posp1 = 0;
        if (x_posp1 >= WINDOW_WIDTH - destp1r.w) x_posp1 = WINDOW_WIDTH - destp1r.w;
        if (y_posp1 >= WINDOW_HEIGHT - destp1r.h) y_posp1 = WINDOW_HEIGHT - destp1r.h;

        if (x_posp2 <= 0) x_posp2 = 0;
        if (y_posp2 <= 0) y_posp2 = 0;
        if (x_posp2 >= WINDOW_WIDTH - destp2r.w) x_posp2 = WINDOW_WIDTH - destp2r.w;
        if (y_posp2 >= WINDOW_HEIGHT - destp2r.h) y_posp2 = WINDOW_HEIGHT - destp2r.h;

         y_pos2 += y_vel2 / 60;
         y_pos3 += y_vel2 / 60;
          y_pos4 += y_vel2 / 60;
          
    if(y_pos2> WINDOW_HEIGHT)
{   
    score++;
    x_pos2 = rand()% (u+1);
    y_pos2 = 0;
}
     if(y_pos2>= WINDOW_HEIGHT/2 &&y_pos3> WINDOW_HEIGHT)
{
    score++;
    x_pos3 = rand() %(u+1);
    y_pos3 = 0;
 }
 
   if(y_pos2>= 3*WINDOW_HEIGHT/4 &&y_pos4> WINDOW_HEIGHT)
{    
    score++;
    x_pos4 = rand() %(u+1);
    y_pos4 = 0;
 }
  if(score==40||score==80||score==140||score==180||score==240||score==280)
    {dlife.x=rand()% (u+1);
    while((dlife.x>=dest2.x&&dlife.x<=dest2.x+dest2.w)||(dlife.x>=dest3.x&&dlife.x<=dest3.x+dest3.w)||(dlife.x>=dest4.x&&dlife.x<=dest4.x+dest4.w))
     dlife.x=rand()% (u+1);
     dlife.y=0;
     score++;
     }
    if(score==60||score==160||score==260)
    {
    dkill.x=rand()% (u+1);
    while((dkill.x>=dest2.x&&dkill.x<=dest2.x+dest2.w)||(dkill.x>=dest3.x&&dkill.x<=dest3.x+dest3.w)||(dkill.x>=dest4.x&&dkill.x<=dest4.x+dest4.w))
     dkill.x=rand()% (u+1);;
     dkill.y=0;
     score++;
     }


   if(pause%2==0)
      { 
        dlife.y+=y_vel2/60;
        dkill.y+=y_vel2/60;
        dest2.y = (int) y_pos2;
        dest2.x = (int) x_pos2;
        dest3.y = (int) y_pos3;
        dest3.x = (int) x_pos3;
        dest4.y = (int) y_pos4;
        dest4.x = (int) x_pos4;
        destps.x=WINDOW_WIDTH+100;
        destps.y=WINDOW_HEIGHT+100;
        
      if(k1%2==0)
        {
         destp1r.y = (int) y_posp1;
        destp1r.x = (int) x_posp1;
       }
    else
      {
       destp1b.y = (int) y_posp1;
        destp1b.x = (int) x_posp1;
       }
      if(k2%2==0)
        {
         destp2r.y = (int) y_posp2;
        destp2r.x = (int) x_posp2;
       }
    else
      {
       destp2b.y = (int) y_posp2;
        destp2b.x = (int) x_posp2;
       }
 }
    else
       {
         destps.x=WINDOW_WIDTH/2;
         destps.y=WINDOW_HEIGHT/2; 
          
      }

 if(SDL_HasIntersection(&destp1b,&dlife))
       {
       ++life1;
       dlife.x=WINDOW_WIDTH+101;
       dlife.y=WINDOW_HEIGHT+101;
       }
       if(SDL_HasIntersection(&destp1r,&dlife))
      { ++life1;
       dlife.x=WINDOW_WIDTH+101;
       dlife.y=WINDOW_HEIGHT+101;
       }
   
 if(SDL_HasIntersection(&destp2b,&dlife))
       {
       ++life2;
       dlife.x=WINDOW_WIDTH+101;
       dlife.y=WINDOW_HEIGHT+101;
       }
       if(SDL_HasIntersection(&destp2r,&dlife))
      { ++life2;
       dlife.x=WINDOW_WIDTH+101;
       dlife.y=WINDOW_HEIGHT+101;
       }
if(SDL_HasIntersection(&destp1b,&dkill))
       {
       SDL_RenderCopy(rend, texgo, NULL, &destgo);
       SDL_RenderCopy(rend, texpw2, NULL, &destpw2);
       SDL_RenderPresent(rend);
       SDL_Delay(2000);
       break;
       }
       if(SDL_HasIntersection(&destp1r,&dkill))
      { SDL_RenderCopy(rend, texgo, NULL, &destgo);
       SDL_RenderCopy(rend, texpw2, NULL, &destpw2);
       SDL_RenderPresent(rend);
       SDL_Delay(2000);
       break;
       }
  if(SDL_HasIntersection(&destp2b,&dkill))
       {
       SDL_RenderCopy(rend, texgo, NULL, &destgo);
       SDL_RenderCopy(rend, texpw1, NULL, &destpw1);
       SDL_RenderPresent(rend);
       SDL_Delay(2000);
       break;
       }
       if(SDL_HasIntersection(&destp2r,&dkill))
      { SDL_RenderCopy(rend, texgo, NULL, &destgo);
       SDL_RenderCopy(rend, texpw1, NULL, &destpw1);
       SDL_RenderPresent(rend);
       SDL_Delay(2000);
       break;
       }
 if(SDL_HasIntersection(&destp1r,&dest2) || SDL_HasIntersection(&destp1r,&dest4) || SDL_HasIntersection(&destp1b,&dest2) || SDL_HasIntersection(&destp1b,&dest3))
      {
       m1=0;
       }
       if(SDL_HasIntersection(&destp2r,&dest2) || SDL_HasIntersection(&destp2r,&dest4) || SDL_HasIntersection(&destp2b,&dest2) || SDL_HasIntersection(&destp2b,&dest3))
     {
      m2=0;
      }
       if(life1>3)
        life1=3;
       if(life2>3)
       life2=3;
   if(m1==1)
   life1--;
   if(life1==0)
     {
    SDL_RenderCopy(rend, texgo, NULL, &destgo);
       SDL_RenderCopy(rend, texpw2, NULL, &destpw2);
       SDL_RenderPresent(rend);
       SDL_Delay(2000);
       break;
    }
   if(life1==1)
    {
      dlife1.x=WINDOW_WIDTH-dlife1.w;
      dlife1.y=0;
      dlife2.x=WINDOW_WIDTH+101;
   dlife2.y=WINDOW_HEIGHT+101;
    dlife3.x=WINDOW_WIDTH+101;
   dlife3.y=WINDOW_HEIGHT+101; 
   
     }
    if(life1==2)
     {
       dlife1.x=WINDOW_WIDTH-dlife1.w;
      dlife1.y=0;
       dlife2.x=WINDOW_WIDTH-dlife1.w-dlife2.w;
       dlife2.y=0;
       dlife3.x=WINDOW_WIDTH+101;
   dlife3.y=WINDOW_HEIGHT+101; 
   
     }
     if(life1==3)
     {
      dlife1.x=WINDOW_WIDTH-dlife1.w;
      dlife1.y=0;
      dlife2.x=WINDOW_WIDTH-dlife1.w-dlife2.w;
       dlife2.y=0;
      dlife3.x=WINDOW_WIDTH-dlife1.w-dlife2.w-dlife3.w;
      dlife3.y=0; 
     }
  if(m2==1)
   life2--;
   if(life2==0)
     {
     SDL_RenderCopy(rend, texgo, NULL, &destgo);
       SDL_RenderCopy(rend, texpw1, NULL, &destpw1);
       SDL_RenderPresent(rend);
       SDL_Delay(2000);
       break;
     }
   if(life2==1)
    {
      dlife1m.x=0;
      dlife1m.y=0;
      dlife2m.x=WINDOW_WIDTH+101;
   dlife2m.y=WINDOW_HEIGHT+101;
    dlife3m.x=WINDOW_WIDTH+101;
   dlife3m.y=WINDOW_HEIGHT+101; 
   
     }
    if(life2==2)
     {
       dlife1m.x=0;
      dlife1m.y=0;
       dlife2m.x=dlife1m.w;
       dlife2m.y=0;
       dlife3m.x=WINDOW_WIDTH+101;
   dlife3m.y=WINDOW_HEIGHT+101; 
   
     }
     if(life2==3)
     {
      dlife1m.x=0;
      dlife1m.y=0;
      dlife2m.x=dlife1m.w;
       dlife2m.y=0;
      dlife3m.x=dlife1m.w+dlife2m.w;
      dlife3m.y=0; 
     }
    
m2++;
m1++;
y_vel2+=0.1;
       
        SDL_RenderCopy(rend, tex2, NULL, &dest2);
        SDL_RenderCopy(rend, tex2, NULL, &dest2);
        SDL_RenderCopy(rend, tex3, NULL, &dest3);
        SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopy(rend, tlife, NULL, &dlife);
        SDL_RenderCopy(rend, tlife1, NULL, &dlife1);
      SDL_RenderCopy(rend, tlife2, NULL, &dlife2);
      SDL_RenderCopy(rend, tlife3, NULL, &dlife3);
      SDL_RenderCopy(rend, tlife1m, NULL, &dlife1m);
      SDL_RenderCopy(rend, tlife2m, NULL, &dlife2m);
      SDL_RenderCopy(rend, tlife3m, NULL, &dlife3m);
      SDL_RenderCopy(rend, tkill, NULL, &dkill);
        SDL_RenderPresent(rend);
        SDL_RenderClear(rend);
           SDL_RenderCopy(rend, texps, NULL, &destps);
          SDL_RenderCopy(rend, texp1r, NULL, &destp1r);
         SDL_RenderCopy(rend, texp1b, NULL, &destp1b);
         SDL_RenderCopy(rend, texp2r, NULL, &destp2r);
         SDL_RenderCopy(rend, texp2b, NULL, &destp2b);
         SDL_RenderCopy(rend, tex2, NULL, &dest2);
        SDL_RenderCopy(rend, tex3, NULL, &dest3);
         SDL_RenderCopy(rend, tex4, NULL, &dest4);
         SDL_RenderCopy(rend, tlife, NULL, &dlife);
        SDL_RenderCopy(rend, tlife1, NULL, &dlife1);
      SDL_RenderCopy(rend, tlife2, NULL, &dlife2);
      SDL_RenderCopy(rend, tlife3, NULL, &dlife3);
      SDL_RenderCopy(rend, tlife1m, NULL, &dlife1m);
      SDL_RenderCopy(rend, tlife2m, NULL, &dlife2m);
      SDL_RenderCopy(rend, tlife3m, NULL, &dlife3m);
      SDL_RenderCopy(rend, tkill, NULL, &dkill);
        SDL_RenderPresent(rend);
        SDL_Delay(1000/60);
    }
       SDL_FreeSurface(slife);
       SDL_FreeSurface(slife1);
       SDL_FreeSurface(slife2);
       SDL_FreeSurface(slife3);
     SDL_FreeSurface(slife1m);
      SDL_FreeSurface(slife2m);
      SDL_FreeSurface(slife3m);
      SDL_FreeSurface(skill);
      SDL_DestroyTexture(tlife);
      SDL_DestroyTexture(tlife1);
      SDL_DestroyTexture(tlife2);
      SDL_DestroyTexture(tlife3);
      SDL_DestroyTexture(tlife1m);
      SDL_DestroyTexture(tlife2m);
      SDL_DestroyTexture(tlife3m);
      SDL_DestroyTexture(tkill);
}


if(flag==1&&k==1)
    {
     close_requested=0;
     SDL_RenderClear(rend); 
 while (!close_requested)
    {       
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
             switch (event.type)
            {
            case SDL_QUIT:
                close_requested = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up1 = 1;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left1 = 1;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down1 = 1;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right1 = 1;
                    break;
                case SDL_SCANCODE_SPACE:
                   k1++;
                   t1=destp1r.x;
                   destp1r.x=destp1b.x;
                   destp1b.x=t1;
                   t2=destp1r.y;
                   destp1r.y=destp1b.y;
                   destp1b.y=t2;
                   break;
                case SDL_SCANCODE_ESCAPE:
                    pause++;
                    break;
           
                 }
               break;
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up1 = 0;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left1 = 0;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down1 = 0;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right1 = 0;
                    break;
                }
                break;
            }
        }

      
        x_vel1 = y_vel1 = 0;
        if (up1 && !down1) y_vel1 = -SPEED;
        if (down1 && !up1) y_vel1 = SPEED;
        if (left1 && !right1) x_vel1 = -SPEED;
        if (right1 && !left1) x_vel1 = SPEED;


        x_posp1 += x_vel1 / 60;
        y_posp1 += y_vel1 / 60;


        if (x_posp1 <= 0) x_posp1 = 0;
        if (y_posp1 <= 0) y_posp1 = 0;
        if (x_posp1 >= WINDOW_WIDTH - destp1r.w) x_posp1 = WINDOW_WIDTH - destp1r.w;
        if (y_posp1 >= WINDOW_HEIGHT - destp1r.h) y_posp1 = WINDOW_HEIGHT - destp1r.h;

        y_pos2 += y_vel2 / 60;
         y_pos3 += y_vel2 / 60;
          y_pos4 += y_vel2 / 60;

    if(y_pos2> WINDOW_HEIGHT)
{   
    score++;
    x_pos2 = rand()% (u+1);
    y_pos2 = 0;
}
     if(y_pos2>= WINDOW_HEIGHT/2 &&y_pos3> WINDOW_HEIGHT)
{
    score++;
    x_pos3 = rand() %(u+1);
    y_pos3 = 0;
 }
 
   if(y_pos2>= 3*WINDOW_HEIGHT/4 &&y_pos4> WINDOW_HEIGHT)
{    
    score++;
    x_pos4 = rand() %(u+1);
    y_pos4 = 0;
 }

  if(score==40||score==80||score==140||score==180||score==240||score==280)
    {
     dlife.x=rand()% (u+1);
    while((dlife.x>=dest2.x&&dlife.x<=dest2.x+dest2.w)||(dlife.x>=dest3.x&&dlife.x<=dest3.x+dest3.w)||(dlife.x>=dest4.x&&dlife.x<=dest4.x+dest4.w))
     dlife.x=rand()% (u+1);
     dlife.y=0;
     score++;
     }
    if(score==60||score==160||score==260)
    {
     dkill.x=rand()% (u+1);
    while((dkill.x>=dest2.x&&dkill.x<=dest2.x+dest2.w)||(dkill.x>=dest3.x&&dkill.x<=dest3.x+dest3.w)||(dkill.x>=dest4.x&&dkill.x<=dest4.x+dest4.w))
     dkill.x=rand()% (u+1);
     dkill.y=0;
     score++;
     }

   if(pause%2==0)
      {
        dlife.y+=y_vel2 /60;
        dkill.y+=y_vel2 /60;
        dest2.y = (int) y_pos2;
        dest2.x = (int) x_pos2;
        dest3.y = (int) y_pos3;
        dest3.x = (int) x_pos3;
        dest4.y = (int) y_pos4;
        dest4.x = (int) x_pos4;
        destps.x=WINDOW_WIDTH+100;
        destps.y=WINDOW_HEIGHT+100;
        
      if(k1%2==0)
        {
         destp1r.y = (int) y_posp1;
        destp1r.x = (int) x_posp1;
       }
    else
      {
       destp1b.y = (int) y_posp1;
        destp1b.x = (int) x_posp1;
       }
 }
    else
       {
         destps.x=WINDOW_WIDTH/2;
         destps.y=WINDOW_HEIGHT/2; 
          
      }
      
       if(SDL_HasIntersection(&destp1b,&dlife))
       {
       ++life;
       dlife.x=WINDOW_WIDTH+101;
       dlife.y=WINDOW_HEIGHT+101;
       }
       if(SDL_HasIntersection(&destp1r,&dlife))
      { ++life;
       dlife.x=WINDOW_WIDTH+101;
       dlife.y=WINDOW_HEIGHT+101;
       }
      
       if(SDL_HasIntersection(&destp1b,&dkill))
       {
       break;
       }
       if(SDL_HasIntersection(&destp1r,&dkill))
      { break;
       }
       if(SDL_HasIntersection(&destp1r,&dest2))
       {
       m=0;
        }
 if(SDL_HasIntersection(&destp1r,&dest4))
       {
        m=0;
        }
 if(SDL_HasIntersection(&destp1b,&dest2))
       {
        m=0;
        }
 if(SDL_HasIntersection(&destp1b,&dest3))
       {
        m=0;
        }
  if(life>3)
  life=3;
   if(m==1)
   life--;
   if(life==0)
     break;
   if(life==1)
    {
      dlife1.x=WINDOW_WIDTH-dlife1.w;
      dlife1.y=0;
      dlife2.x=WINDOW_WIDTH+101;
   dlife2.y=WINDOW_HEIGHT+101;
    dlife3.x=WINDOW_WIDTH+101;
   dlife3.y=WINDOW_HEIGHT+101; 
   
     }
    if(life==2)
     {
       dlife1.x=WINDOW_WIDTH-dlife1.w;
       dlife1.y=0;
       dlife2.x=WINDOW_WIDTH-dlife1.w-dlife2.w;
       dlife2.y=0;
       dlife3.x=WINDOW_WIDTH+101;
   dlife3.y=WINDOW_HEIGHT+101; 
   
     }
     if(life==3)
     {
      dlife1.x=WINDOW_WIDTH-dlife1.w;
      dlife1.y=0;
      dlife2.x=WINDOW_WIDTH-dlife1.w-dlife2.w;
       dlife2.y=0;
      dlife3.x=WINDOW_WIDTH-dlife1.w-dlife2.w-dlife3.w;
      dlife3.y=0; 
     }
   
        m++;
        y_vel2+=0.1;
        if(score==0)
        {
         SDL_RenderCopy(rend, tlvl1, NULL, &dlvl1);
         SDL_RenderPresent(rend);
         SDL_Delay(1000);
         score++;
         SDL_RenderClear(rend);
         }
        if(score==100)
        {
         SDL_RenderCopy(rend, tlvl2, NULL, &dlvl2);
         SDL_RenderPresent(rend);
         SDL_Delay(1000);
         score++;
         SDL_RenderClear(rend);
         }
       if(score==200)
        {
         SDL_RenderCopy(rend, tlvl3, NULL, &dlvl3);
         SDL_RenderPresent(rend);
         SDL_Delay(1000);
         score++;
         SDL_RenderClear(rend);
         }
       
        SDL_RenderCopy(rend, tex2, NULL, &dest2);
        SDL_RenderCopy(rend, tex3, NULL, &dest3);
        SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopy(rend, tlife, NULL, &dlife);
        SDL_RenderCopy(rend, tlife1, NULL, &dlife1);
      SDL_RenderCopy(rend, tlife2, NULL, &dlife2);
      SDL_RenderCopy(rend, tlife3, NULL, &dlife3);
      SDL_RenderCopy(rend, tkill, NULL, &dkill);
      SDL_RenderPresent(rend);
        SDL_RenderClear(rend);
        
         SDL_RenderCopy(rend, tkill, NULL, &dkill);
         SDL_RenderCopy(rend, tlife, NULL, &dlife);
           SDL_RenderCopy(rend, tlife1, NULL, &dlife1);
      SDL_RenderCopy(rend, tlife2, NULL, &dlife2);
      SDL_RenderCopy(rend, tlife3, NULL, &dlife3);
           SDL_RenderCopy(rend, texps, NULL, &destps);
          SDL_RenderCopy(rend, texp1b, NULL, &destp1b);
         SDL_RenderCopy(rend, texp1r, NULL, &destp1r);
         SDL_RenderCopy(rend, tex2, NULL, &dest2);
        SDL_RenderCopy(rend, tex3, NULL, &dest3);
         SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderPresent(rend);
        SDL_Delay(1000/60);
    }

     copy=score;
       while(copy!=0)
       {
       last=copy%10;
       copy=copy/10;
       switch(last)
       {
        
        case 0:
        sc[g]='0';
        break;
        case 1:
        sc[g]='1';
        break;
        case 2:
        sc[g]='2';
        break;
        case 3:
        sc[g]='3';
        break;
        case 4:
        sc[g]='4';
        break;
        case 5:
        sc[g]='5';
        break;
        case 6:
        sc[g]='6';
        break;
        case 7:
        sc[g]='7';
        break;
        case 8:
        sc[g]='8';
        break;
        case 9:
        sc[g]='9';
        break;
     }
     g--;
}

 SDL_Surface * surfscr = TTF_RenderText_Solid(font,sc, colorscr);

 SDL_Texture * texscr = SDL_CreateTextureFromSurface(rend,
  surfscr);

SDL_Rect destscr;
 SDL_QueryTexture(texscr, NULL, NULL, &destscr.w, &destscr.h);
   destscr.x=WINDOW_WIDTH/2+destpscr.w;
   destscr.y=WINDOW_HEIGHT/2+destgo.h;
 
prsc=hsc;
fp=fopen("integer","w");
if(score>=hsc)
putw(score,fp);
else
putw(hsc,fp);
fclose(fp);
fp=fopen("integer","r");
hsc=getw(fp);
fclose(fp);
g=2;

    SDL_RenderCopy(rend, texgo, NULL, &destgo);
     SDL_RenderCopy(rend, texpscr, NULL, &destpscr);
     SDL_RenderCopy(rend, texscr, NULL, &destscr);
     if(score>prsc)
     SDL_RenderCopy(rend, texphscr, NULL, &destphscr);
     SDL_RenderPresent(rend);
     SDL_Delay(2000);
     SDL_FreeSurface(surfscr);   
     SDL_DestroyTexture(texscr);
}
     SDL_DestroyTexture(texgo);
     SDL_FreeSurface(surfgo);
     SDL_DestroyTexture(texps);
     SDL_FreeSurface(surfps);
     SDL_FreeSurface(surfphscr);
     SDL_DestroyTexture(texpscr);
     SDL_DestroyTexture(texphscr);
     SDL_FreeSurface(surfpscr);
     SDL_FreeSurface(surfhscr);
     SDL_FreeSurface(surfhigh);
    SDL_DestroyTexture(texp1r);
    SDL_DestroyTexture(texp2r);
    SDL_DestroyTexture(texp1b);
    SDL_DestroyTexture(texp2b);
    SDL_DestroyTexture(tex2);
    SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);
    SDL_DestroyTexture(tfr);
    SDL_DestroyTexture(tlvl1);
    SDL_DestroyTexture(tlvl2);
    SDL_DestroyTexture(tlvl3);
    SDL_DestroyTexture(texplays);
    SDL_DestroyTexture(texplaym);
    SDL_DestroyTexture(texhelp);
    SDL_DestroyTexture(texhighscore);
    SDL_DestroyTexture(texexit);
        SDL_DestroyTexture(texhscr);
        SDL_DestroyTexture(texhigh);
     SDL_DestroyTexture(tinstr);

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
     Mix_FreeMusic(music);
   Mix_CloseAudio();
    TTF_Quit();
SDL_Quit();
}

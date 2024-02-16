#include "raylib.h"
#include <iostream>
#include <vector>

using namespace std;

void drawCheckeredBoard(int xOS,int yOS,int xWidth,int yWidth,int boarderSize,Color currentColor);
void playClick();

int main()
{
  int screenX(0);
  int screenY(0);
  int screenWidth(1920);
  int screenHeight(1080);
  vector<Color> currentColorList{RED,ORANGE,LIME,GREEN,BLUE,MAGENTA};
  int currentColorIndex(0);
  InitAudioDevice();
  Color currentColor = currentColorList.at(currentColorIndex);

  InitWindow(screenWidth,screenHeight,"Raylib window!");  
  while(!IsWindowReady())
  {
  }
  SetTargetFPS(60);
  ToggleFullscreen();
  int xPosition(5);
  int yPosition(5);
  int boarderSize(10);
  int xVelocity(2);
  int yVelocity(2);
  int xWidth(5);
  int yWidth(5);
  Sound bounceClick = LoadSound("pingpong.wav");
  // this sound effect is from the youtube studio sound library

  while(!IsAudioDeviceReady())
  {
  }

  while(WindowShouldClose() == false)
  {

    BeginDrawing();
    ClearBackground(currentColor);
    DrawRectangle(0,0,1920,1080,Fade(BLACK,.9));
      
    DrawText("Bouncing Cube",xPosition - (boarderSize),yPosition+(yWidth*20)+10,30,WHITE);
    DrawText("By Zach",xPosition - (boarderSize),yPosition+(yWidth*20)+40,20,WHITE);
    drawCheckeredBoard(xPosition,yPosition,xWidth,yWidth,boarderSize,currentColor);
    EndDrawing();
    xPosition += xVelocity;
    yPosition += yVelocity;
    
    if(xPosition - (boarderSize / 2) <= 0 || (xPosition + (boarderSize/2) + (xWidth*20)) >= screenWidth)
    {
      //ClearBackground(BLACK);
      if(IsSoundPlaying(bounceClick))
      {
        StopSound(bounceClick);
      }
      PlaySound(bounceClick);
      currentColorIndex += 1;
      currentColorIndex %= currentColorList.size();
      currentColor = currentColorList[currentColorIndex]; 
      xVelocity *= -1;
      while(xPosition <= 0 || xPosition >= screenWidth)
      {
        xPosition += xVelocity;
      }
    }

    if(yPosition <= 0 + (boarderSize/2)|| yPosition >= screenHeight - (boarderSize/2) - (yWidth*20))
    {
      //ClearBackground(BLACK);
      if(IsSoundPlaying(bounceClick))
      {
        StopSound(bounceClick);
      }
      PlaySound(bounceClick);
      currentColorIndex += 1;
      currentColorIndex %= currentColorList.size();
      currentColor = currentColorList[currentColorIndex]; 
      yVelocity *= -1;
      while(yPosition <= 0 || yPosition >= screenHeight)
      {
        yPosition += yVelocity;
      }
    }

  }
  UnloadSound(bounceClick);
  CloseAudioDevice();
  CloseWindow();

  return 0;
}


void drawCheckeredBoard(int xOS,int yOS,int xWidth,int yWidth,int boarderSize,Color currentColor)
{

  DrawRectangle(xOS-boarderSize,yOS-boarderSize,(xWidth*20) + (boarderSize*2),(yWidth*20) + (boarderSize * 2),currentColor);
  DrawRectangle(xOS-boarderSize,yOS-boarderSize,(xWidth*20) + (boarderSize*2),(yWidth*20) + (boarderSize * 2),Fade(RAYWHITE,.5));

  for(int y=0;y<yWidth;++y)
  {
    for(int x=0;x<xWidth;++x)
    {

      if(y % 2 == 0 && x % 2 == 0)
      {
        DrawRectangle(x*20+xOS,y*20+yOS,20,20,currentColor);
      }else if(y % 2 == 0 || x % 2 == 0)
      {
        DrawRectangle(x*20+xOS,y*20+yOS,20,20,BLACK);
      }else
      {
        DrawRectangle(x*20+xOS,y*20+yOS,20,20,currentColor);
      }

    }
  }

}







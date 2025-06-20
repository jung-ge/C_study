#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 플레이어 행동 
bool block = false;
bool swing = false;
bool slash = false;
bool Thrust = false;
bool is_attack = false;
bool counter_swing = false;
bool counter_slash = false;
bool counter_Thrust = false;
// 적 행동 
bool is_first = true;
bool ememy_block = false;
bool ememy_swing = false;
bool ememy_slash = false;
bool ememy_Thrust = false;
bool ememy_counter_swing = false;
bool ememy_counter_slash = false;
bool ememy_counter_Thrust = false;


bool painting = false; 

void Ememy()
{
  printf("=================\n적 : 기사\n=================\n");
}

void Ememy_action()
{
  int r = (rand() % 3) + 1;

  const char* action_name;
  if (is_first == true)
  {
    ememy_block = true;
    action_name = "막기";
  }
  else
  {
    if (r == 1)
    {
      ememy_swing = true;
      action_name = "휘두르기";
    } 
    else if (r == 2)
    {
      ememy_slash = true;
      action_name = "내려 휘두르기";
    }
    else if (r == 3)
    {
      ememy_Thrust = true;
      action_name = "찌르기";
    }
    else if (r == 4)
    {
      ememy_block = true;
      action_name = "막기";
    }
  }
  printf("=================\n적 : 기사\n행동 : %s\n=================\n", action_name);
}

void Ememy_counter()
{
  int counter_r = (rand() % 2) + 1;

  const char* ememy_counter_name;
  
  if (counter_r == 1)
  {
    if (swing == true)
    {
      ememy_counter_swing = true;
      ememy_counter_name = "휘두르기 반격";
    }
    else if (slash == true)
    {
      ememy_counter_slash = true;
      ememy_counter_name = "내려 휘두르기 반격";
    }
    else if (Thrust == true)
    {
      ememy_counter_Thrust = true;
      ememy_counter_name = "찌르기 반격";
    }
    //printf("=================\n적 : 기사\n행동 : %s\n=================\n",ememy_counter_name);
  }
}

void clear()
{
  bool block = false;
  bool swing = false;
  bool slash = false;
  bool Thrust = false;

  bool painting = false; 
}

void Action()
{
  int action_temp;
  printf("=================\n행동\n1.휘두르기\n2.내려휘두리기\n3.찌르기\n4.막기\n=================\n");
  scanf("%d",&action_temp);

  if (action_temp == 1)
  {
    printf("=================\n휘두르기 선택\n=================\n");
    swing = true;
    is_attack = true;
  }
  else if (action_temp == 2)
  {
    printf("=================\n내려휘두르기 선택\n=================\n");
    slash = true;
    is_attack = true;
  }
  else if (action_temp == 3)
  {
    printf("=================\n찌르기 선택\n=================\n");
    Thrust = true;
    is_attack = true;
  }
  else
  {
    printf("=================\n막기 선택\n=================\n");
    block = true;
    is_attack = false;
  } 
}

void Painting()
{
  int temp_painting = 0;
  if (block == true)
  {
    printf("=================\n막기 선택하였기때문에 페인트 공격을 사용할수 없습니다.\n=================\n");
    return;	
  }
  else
  {
    printf("=================\n1.페인트\n2.사용안하기\n=================\n");	
  }

  scanf("%d",&temp_painting);

  if (temp_painting == 1)
  {
    printf("=================\n페인트공격 사용\n=================\n");
    painting = true; 
    swing = false;
    slash = false;
    Thrust = false;

    swing = false;
    slash = false;
    Thrust = true;
  }
  else
  {
    printf("=================\n페인트공격 사용하지 않음\n=================\n");
    painting = false;
  }
}

void Final()
{
  if (is_attack == true)
  {
    
  }
}

int main()
{
  bool play = true;
  int temp;
  int action = 0;

  while (play)
  {

    printf("=================\nknight's of honor\n1.play\n2.나가기\n=================\n");
    scanf("%d",&temp);
    if (temp == 1)
    {
    play = true;
    }
    else if (temp == 2)
    {
      break;
    }
    else
    {
      continue;
    }

    // 게임 시작
    while (1)
      {
        Ememy(); 
        Action();
        Ememy_action();
        if (ememy_block == true)
        {
          Ememy_counter();
        }
        else if (block == true)
        {
          1+ 1 =2;
        }
        Painting();
      }
    
  }	
}

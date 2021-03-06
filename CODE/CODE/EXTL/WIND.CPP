﻿#pragma once
#ifndef WIND_CPP
#define WIND_CPP
#include"HEAD.CPP"
#include"DBUG.CPP"
int WIND_INIT(int DBUG_INIT_ARGC,char** DBUG_INIT_ARGV)
{
    /*------------------------------创建窗口------------------------------*/
    DBUG_INIT(DBUG_INIT_ARGC,DBUG_INIT_ARGV);
    if(SDL_Init(SDL_INIT_VIDEO)<0) return -1;
    WIND_WINDP=SDL_CreateWindow(WIND_TITLE,         //窗口标题
                            SDL_WINDOWPOS_UNDEFINED,//垂直位置
                            SDL_WINDOWPOS_UNDEFINED,//水平位置
                            WIND_WIDTH,             //窗口宽度
                            WIND_HEIGH,             //窗口高度
                            SDL_WINDOW_SHOWN        //显示窗口
                            );
    DBUG_OUTP(WIND_WINDP," LOAD_WINDOW","WIND_WINDP");//输出调试信息
    srand((unsigned)time(nullptr));                   //随机种子生成
    TTF_Init();                                       //字体初始化
    return 0;
}
int WIND_EXIT()
{
    /*------------------------------退出程序------------------------------*/
  SDL_DestroyRenderer(WIND_RENDP);                  //销毁渲染
    SDL_DestroyWindow(WIND_WINDP);                  //销毁窗口
    SDL_Quit();                                     //退出GUI
    system("taskkill /IM 奔跑吧*");                    //销毁进程
    system("taskkill /IM JUM*  ");                    //销毁进程
    system("taskkill /IM GAM*  ");                    //销毁进程
    system("EXIT.CMD");                             //销毁进程
    exit(0);                                        //退出程序
    return 0;
}
#endif

// a.h
#ifdef __cplusplus
extern "C" {  // 告诉C++编译器：以下符号是C风格的
#endif


#ifndef _5SC_H
#define _5SC_H

// 游戏相关的常量和全局变量
#define MAX_ROW 12
#define MAX_COL 12
extern int a, b;        // 玩家输入的坐标
extern int AIMOVE;      // 电脑的落子
extern char chess_board[MAX_ROW][MAX_COL];  // 棋盘

// 游戏相关函数的声明
extern int menu();                  // 显示菜单并返回用户选择
void InitializeChessBoard(); // 初始化棋盘
void Print();                // 打印棋盘
void PlayerMove();           // 玩家落子
int ComputerMove();          // 电脑落子
int ChessBoardIsFull();      // 判断棋盘是否已满
char CheckWinner();          // 检查胜利者
void game();                 // 启动游戏

// 由于AI函数是外部定义的，声明它
int AI(void); // 声明AI函数，实际定义应在ai.c中
int fAI(void);
#endif // _5SC_H
#ifdef __cplusplus
}
#endif
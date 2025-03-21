#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"5sc.h"
#define MAX_ROW 12
#define MAX_COL 12
int a,b,AIMOVE=0;
char chess_board[MAX_ROW][MAX_COL];
#include"ai.c"
int menu()
{
	printf("=========================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=========================\n");
	printf("请输入您的选择:");
	//fflush(stdout);
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void InitializeChessBoard()
{
	int row,col;
	for ( row = 0; row < MAX_ROW; row++)
	{
		for ( col = 0; col < MAX_COL; col++)
        {
			chess_board[row][col] = ' ';
		}
	}
}

void Print()
{
	int row,col,i;
    printf("  ");
    for ( i = 1; i <=MAX_COL; i++)
    {
        printf("  %d ",i%10);
    }
    printf("\n  ");
    for( i=1;i<=MAX_COL;i++)
                printf(" ---");
			printf("\n");
	for ( row = 0; row < MAX_ROW; row++)
    {
        printf("%2d|",row+1);
        for( col=0;col<MAX_COL;col++)
        {
            printf(" %c |",chess_board[row][col]);
        }
        printf("\n  ");
		if (row!= MAX_ROW)
        {
            for( i=1;i<=MAX_COL;i++)
                printf(" ---");
			printf("\n");
		}
	}
}

void PlayerMove()
{
	printf("轮到您落子!\n");
	while (1){
		printf("请输入落子位置的坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &a, &b);
        row=a-1;col=b-1;
		//检查输入//
		printf("您输入的行是: %d, 列是: %d\n", row + 1, col + 1);
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COL){
			printf("坐标超出范围,请重新输入\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("坐标已被占用!\n");
			continue;
		}
		chess_board[row][col] = '*';
		break;
	}
	printf("您已落子!\n");
}

int ComputerMove()
{
    int AI(void);
	printf("轮到阿尔法锋落子!\n");
    AIMOVE=AI();
	/*while (1)
    {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' ')
        {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}*/
	printf("阿尔法锋落子完毕!\n");
}

//如果棋盘满了,返回1,否则返回0//
int ChessBoardIsFull()
{
	int row,col;
	for ( row = 0; row < MAX_ROW; ++row)
    {
		for ( col = 0; col < MAX_COL; col++)
        {
			if (chess_board[row][col] == ' ')
            {
				return 0;
			}
		}
	}return 1;
}
//返回胜利者    q和//
char  CheckWinner()
{
	int row,col;
	if (ChessBoardIsFull())
    {
		return'q';
	}
    //检查行
    for ( row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<MAX_COL-4;col++)
        {
            if(chess_board[row][col]!=' ')
            {
                int chess=1,check;
                for( check=1;check<=4;check++)
                {
                    if(chess_board[row][col]==chess_board[row][col+check])
                        chess++;
                }
                if ( chess==5)
                {
                    return chess_board[row][col];
                }
            }
        }
    }
	//检查列
	for ( col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<MAX_ROW-4;row++)
        {
            if(chess_board[row][col]!=' ')
            {
                int chess=1,check;
                for( check=1;check<=4;check++)
                {
                    if(chess_board[row][col]==chess_board[row+check][col])
                        chess++;
                }
                if ( chess==5)
                {
                    return chess_board[row][col];
                }
            }
        }
	}
	//检查所有对角线  '\'  //
	for( row=0;row<(MAX_ROW-4);row++)
    {
        for( col=0;col<(MAX_COL-4);col++)
        {
            if(chess_board[row][col]!=' ')
            {
                int chess=1,check;
                for( check=1;check<=4;check++)
                {
                    if(chess_board[row][col]==chess_board[row+check][col+check])
                        chess++;
                    else
                        break;
                }
                if(chess==5)
                    return chess_board[row][col];
            }
            
        }
    }
	//检查所有对角线  '/'  //
    for( row=MAX_ROW-1;row>=4;row--)
    {
        for( col=0;col<MAX_COL-4;col++)
        {
            if(chess_board[row][col]!=' ')
            {
                    int chess=1,check;
                for( check=1;check<=4;check++)
                {
                    if(chess_board[row][col]==chess_board[row-check][col+check])
                        chess++;
                    else
                        break;
                }
                if(chess==5)
                    return chess_board[row][col];
            }
        }
    }
	return ' ';

}
void game()
{
	//初始化//
	InitializeChessBoard();
	char winner = ' ';
	while (1)
    {
		//打印//
		Print();
		//人//
		PlayerMove();
		//检测胜负//
		winner = CheckWinner();
		if (winner != ' ')
        {
			break;
		}
		//电脑
		ComputerMove();
		#ifdef DEBUG
		printf("%d\n",AIMOVE);
		#endif
		winner = CheckWinner();
		if (winner != ' ')
        {
			break;
		}
	}
	Print();
	if (winner == '*')
        printf("\n\t恭喜你赢了阿尔法锋!\n阿尔法锋还会继续完善的！\n");
	else if (winner == 'o')
        printf("很遗憾，您输给了阿尔法锋！！\n");
	else if (winner == 'q')
		printf("平局!\n");
}

/*int main()
{
	while (1)
    {
		int choice = menu();
		if (choice == 1)
            game();
		else if (choice == 0)
		{
			printf("游戏结束！");
			break;
		}
		else
			printf("输入有误!");
	}
	return 0;
}*/


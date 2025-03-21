#include"5sc.h"
int AI(void)
{
	int row,col,chess,check,count,dangerous; 
    srand((unsigned int)time(0));

    //o4//
    for (row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for(check=1;check<=3;check++)
                {
                    if(chess_board[row][col+check]=='o')
                        chess++;
                }
                if (chess==4)
                {
                    if((chess_board[row][col+4]==' ')&&(col+4<MAX_COL))
                        {chess_board[row][col+4]='o';return 1;}
                    else if((chess_board[row][col-1]==' ')&&(col-1>=0))
                    {chess_board[row][col-1]='o';return 2;}
                }
            }
        }
    }
   //o检查列4//
	for (col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<MAX_ROW;row++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for(check=1;check<=3;check++)
                {
                    if(chess_board[row+check][col]=='o')
                        chess++;
                }
                if ( chess==4)
                {
                    if(chess_board[row+4][col]==' ')
                    {chess_board[row+4][col]='o';return 3;}
                    else if(chess_board[row-1][col]==' ')
                    {chess_board[row-1][col]='o';return 4;}
                }
            }
        }
    }
                
	//o检查所有对角线  '\' 4 //
	for(row=0;row<MAX_ROW;row++)
    {
        for( col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for(check=1;check<=3;check++)
                {
                    if((chess_board[row+check][col+check]=='o')&&(col+3<MAX_COL))
                        chess++;
                }
                if(chess==4)
                {
                    if((chess_board[row+4][col+4]==' ')&&(col+4<MAX_COL))
                    {chess_board[row+4][col+4]='o';return 5;}
                    else if((chess_board[row-1][col-1]==' ')&&(col-1>=0))
                    {chess_board[row-1][col-1]='o';return 6;}
                }
            }
        }
    }
                
	//o检查所有对角线  '/' 4 //
    for( row=MAX_ROW-1;row>=0;row--)
    {
        for( col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for(check=1;check<=3;check++)
                {
                    if(chess_board[row-check][col+check]=='o')
                        chess++;
                }
                if(chess==4)
                {
                    if((chess_board[row-4][col+4]==' ')&&(col+4<MAX_COL))
                    {chess_board[row-4][col+4]='o';return 7;}
                    else if((chess_board[row+1][col-1]==' ')&&(col-1>=0))
                    {chess_board[row+1][col-1]='o';return 8;}
                }
            }
        }
    }
	//** **//
	for(row=0;row<MAX_ROW;row++)
	{
		for( col=0;col<MAX_COL;col++)
		{
			if(chess_board[row][col]==' ')
			{
				if((chess_board[row][col+1]=='*')&&(chess_board[row][col+2]=='*')&&(chess_board[row][col-1]=='*')&&(chess_board[row][col-2]=='*'))
				{chess_board[row][col]='o';return 9;}
				if((chess_board[row+1][col]=='*')&&(chess_board[row+2][col]=='*')&&(chess_board[row-1][col]=='*')&&(chess_board[row-2][col]=='*'))
				{chess_board[row][col]='o';return 10;}
				if((chess_board[row+1][col+1]=='*')&&(chess_board[row+2][col+2]=='*')&&(chess_board[row-1][col-1]=='*')&&(chess_board[row-2][col-2]=='*'))
				{chess_board[row][col]='o';return 11;}
				if((chess_board[row-1][col+1]=='*')&&(chess_board[row-2][col+2]=='*')&&(chess_board[row+1][col-1]=='*')&&(chess_board[row+2][col-2]=='*'))
				{chess_board[row][col]='o';return 12;}
			}
		}
	} 
	//*** *//
    for ( row = 0; row < MAX_ROW; row++)
    {
        for(col=0;col< MAX_COL;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row][col+check]=='*')
                        chess++;
                }
                if ((chess==3)&&(chess_board[row][col+3]==' ')&&(chess_board[row][col+4]=='*'))
                {chess_board[row][col+3]='o';return 13;}
                else if((chess==3)&&(chess_board[row][col-1]==' ')&&(chess_board[row][col-2]=='*'))
                {chess_board[row][col-1]='o';return 14;}
            }
        }
    }
    for ( col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<MAX_ROW;row++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col]=='*')
                        chess++;
                }
                if ( (chess==3)&&(chess_board[row+3][col]==' ')&&(chess_board[row+4][col]=='*'))
                {chess_board[row+3][col]='o';return 15;}
                else if( (chess==3)&&(chess_board[row-1][col]==' ')&&(chess_board[row-2][col]=='*'))
                {chess_board[row-1][col]='o';return 16;}
            }
        }
    }
    for( row=0;row<MAX_ROW;row++)
    {
        for( col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col+check]=='*')
                        chess++;
                }
                if ( (chess==3)&&(chess_board[row+3][col+3]==' ')&&(chess_board[row+4][col+4]=='*'))
                {chess_board[row+3][row+3]='o';return 17;}
                else if( (chess==3)&&(chess_board[row-1][col-1]==' ')&&(chess_board[row-2][col-2]=='*'))
                {chess_board[row-1][col-1]='o';return 18;}
            }
        }
    }
    for( row=MAX_ROW-1;row>=0;row--)
    {
        for( col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row-check][col+check]=='*')
                        chess++;
                }
                if ( (chess==3)&&(chess_board[row-3][col+3]==' ')&&(chess_board[row-4][col+4]=='*'))
                {chess_board[row-3][col+3]='o';return 19;}
                else if( (chess==3)&&(chess_board[row+1][col-1]==' ')&&(chess_board[row+2][col-2]=='*'))
                {chess_board[row+1][col-1]='o';return 20;}
            }
        }
    }
    //*检查行4//
	for (row = 0; row < MAX_ROW; row++)
    {
        for(col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for(check=1;check<=3;check++)
                {
                    if(chess_board[row][col+check]=='*')
                        chess++;
                }
                if (chess==4)
                {
                    if(col+4<=MAX_COL-1)
                    {
                        if((col==0)&&(chess_board[row][col+4]==' '))
                            {chess_board[row][col+4]='o';return 21;}
                        else if((chess_board[row][col+4]==' ')&&(chess_board[row][col-1]=='o'))
                            {chess_board[row][col+4]='o';return 22;}
                        else if((chess_board[row][col-1]==' ')&&(chess_board[row][col+4]=='o'))
                            {chess_board[row][col-1]='o';return 23;}
                        else if((chess_board[row][col-1]==' ')&&(chess_board[row][col+4]==' '))
                        {
                            int i = rand() % 2;
                            if(i==0)
                            {chess_board[row][col-1]='o';return 24;}
                            else
                            {chess_board[row][col+4]='o';return 25;}
                        }
                    }
                    else if(col+4==MAX_COL)
                    {
                        if((col>=1)&&(chess_board[row][col-1]==' '))
                            {chess_board[row][col-1]='o';return 26;}
                    }
                }
            }
        }
    }
	//检*查列4//
	for ( col = 0; col < MAX_COL; col++)
    {
		for(row=0;row<MAX_ROW;row++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for(check=1;check<=3;check++)
                {
                    if(chess_board[row+check][col]=='*')
                        chess++;
                }
                if ( chess==4)
                {
                    if(row+4<=MAX_ROW-1)
                    {
                        if((row==0)&&(chess_board[row+4][col]==' '))
                            {chess_board[row+4][col]='o';return 27;}
                        else if((chess_board[row+4][col]==' ')&&(chess_board[row-1][col]=='o'))
                            {chess_board[row+4][col]='o';return 28;}
                        else if((chess_board[row-1][col]==' ')&&(chess_board[row+4][col]=='o'))
                            {chess_board[row-1][col]='o';return 29;}
                        else if((chess_board[row-1][col]==' ')&&(chess_board[row+4][col]==' '))
                        {
                            int i = rand() % 2;
                            if(i==0)
                            {chess_board[row-1][col]='o';return 30;}
                            else
                            {chess_board[row+4][col]='o';return 31;}
                        }
                    }
                    else if(row+4==MAX_ROW)
                    {
                        if((row>=1)&&(chess_board[row-1][col]==' '))
                            {chess_board[row-1][col]='o';return 32;}
                    }
                }
            }
        }
	}
	//检*查所有对角线  '\' 4 //
	for( row=0;row<MAX_ROW;row++)
    {
        for(col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=3;check++)
                {
                    if(chess_board[row+check][col+check]=='*')
                        chess++;
                }
                if(chess==4)
                {
                    if(((row==0)||(col==0))&&(chess_board[row+4][col+4]==' '))
                    {chess_board[row+4][col+4]='o';return 33;}
                    else if(((row+4==MAX_ROW)||(col+4==MAX_COL))&&(chess_board[row-1][col-1]==' '))
                    {chess_board[row-1][col-1]='o';return 34;}
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+4][col+4]=='o'))
                    {chess_board[row-1][col-1]='o';return 35;}
                    else if((chess_board[row-1][col-1]=='o')&&(chess_board[row+4][col+4]==' '))
                    {chess_board[row+4][col+4]='o';return 36;}
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+4][col+4]==' '))
                    {
                        int i = rand() % 2;
                        if(i==0)
                        {chess_board[row-1][col-1]='o';return 37;}
                        else
                        {chess_board[row+4][col+4]='o';return 38;}
                    }
                }
            }
            
        }
    }
	//检*查所有对角线  '/' 4 //
    for( row=MAX_ROW-1;row>=3;row--)
    {
        for(col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for(check=1;check<=3;check++)
                {
                    if(chess_board[row-check][col+check]=='*')
                        chess++;
                }
                if(chess==4)
                {
                    if(((row==MAX_ROW-1)||(col==0))&&(chess_board[row-4][col+4]==' '))
                    {chess_board[row-4][col+4]='o';return 39;}
                    else if(((row-4==-1)||(col+4==MAX_COL))&&(chess_board[row+1][col-1]==' '))
                    {chess_board[row+1][col-1]='o';return 40;}
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-4][col+4]=='o'))
                    {chess_board[row+1][col-1]='o';return 41;}
                    else if((chess_board[row+1][col-1]=='o')&&(chess_board[row-4][col+4]==' '))
                    {chess_board[row-4][col+4]='o';return 042;}
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-4][col+4]==' '))
                    {
                        int i = rand() % 2;
                        if(i==0)
                        {chess_board[row+1][col-1]='o';return 043;}
                        else
                        {chess_board[row-4][col+4]='o';return 044;}
                    }
                }
            }
        }
    }

    

	// oo o hang//
    for ( row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row][col+check]=='o')
                        chess++;
                }
                if ((chess==2)&&((chess_board[row][col-1]==' ')||(chess_board[row][col+4]==' ')))
                {
                    if((chess_board[row][col+2]==' ')&&(chess_board[row][col+3]=='o'))
                        {chess_board[row][col+2]='o';return 045;}
                    else if((chess_board[row][col-1]==' ')&&(chess_board[row][col-2]=='o'))
                    {chess_board[row][col-1]='o';return 046;}
                }
            }
        }
    }
   //o检查列  oo o //
	for ( col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<=MAX_ROW-2;row++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row+check][col]=='o')
                        chess++;
                }
                if ((chess==2)&&((chess_board[row-1][col]==' ')||(chess_board[row+4][col]==' ')))
                {
                    if((chess_board[row+2][col]==' ')&&(chess_board[row+3][col]=='o'))
                    {chess_board[row+2][col]='o';return 047;}
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row-2][col]=='o'))
                    {chess_board[row-1][col]='o';return 48;}
                }
            }
        }
    }
                
	//检o查所有对角线  '\' oo o //
	for( row=0;row<=(MAX_ROW-2);row++)
    {
        for( col=0;col<=(MAX_COL-2);col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row+check][col+check]=='o')
                        chess++;
                }
                if ((chess==2)&&((chess_board[row-1][col-1]==' ')||(chess_board[row+4][col+4]==' ')))
                {
                    if((chess_board[row+2][col+2]==' ')&&(chess_board[row+3][col+3]=='o'))
                    {chess_board[row+2][col+2]='o';return  49;}
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row-2][col-2]=='o'))
                    {chess_board[row-1][col-1]='o';return 50;}
                }
            }
        }
    }
                
	//o检查所有对角线  '/' oo o //
    for( row=MAX_ROW-1;row>=1;row--)
    {
        for( col=0;col<=MAX_COL-2;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row-check][col+check]=='o')
                        chess++;
                }
                if ((chess==2)&&((chess_board[row+1][col-1]==' ')||(chess_board[row-4][col+4]==' ')))
                {
                    if((chess_board[row-2][col+2]==' ')&&(chess_board[row-3][col+3]=='o'))
                    {chess_board[row-2][col+2]='o';return 051;}
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row+2][col-2]=='o'))
                    {chess_board[row+1][col-1]='o';return 052;}
                }
            }
        }
    }


	//o检查行3 ooo // 
	for ( row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<=MAX_COL-4;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row][col+check]=='o')
                        chess++;
                }
                if(chess==3)
				{
					if (((chess_board[row][col-1]==' ')&&(chess_board[row][col+3]==' '))||
					((chess_board[row][col-1]==' ')&&(chess_board[row][col-2]==' '))||
					((chess_board[row][col+3]==' ')&&(chess_board[row][col+4]==' ')))
	                {
	                	if(chess_board[row][col+4]==' ')
	                    {chess_board[row][col+3]='o';return 053;}
	                    else if(chess_board[row][col-2]==' ')
	                    {chess_board[row][col-1]='o';return 054;}
	                }
				}
	                
            }
        }
    }
	//o检查列3//
	for ( col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<=MAX_ROW-4;row++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col]=='o')
                        chess++;
                }
	            if(chess==3)
	            {
	            	if (((chess_board[row-1][col]==' ')&&(chess_board[row+3][col]==' '))||
					((chess_board[row-1][col]==' ')&&(chess_board[row-2][col]==' '))||
					((chess_board[row+3][col]==' ')&&(chess_board[row+4][col]==' ')))
	                {
	                    if(chess_board[row-2][col]==' ')
	                    {chess_board[row-1][col]='o';return 055;}
	                    else if(chess_board[row+4][col]==' ')
	                    {chess_board[row+3][col]='o';return 056;}
	                }
				}
            }
        }
	}
	//o检查所有对角线  '\' 3 //
	for( row=0;row<=(MAX_ROW-4);row++)
    {
        for( col=0;col<=(MAX_COL-4);col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col+check]=='o')
                        chess++;
                }
                if(chess==3)
                {
                	if (((chess_board[row-1][col-1]==' ')&&(chess_board[row+3][col+3]==' '))||
					((chess_board[row-1][col-1]==' ')&&(chess_board[row-2][col-2]==' '))||
					((chess_board[row+3][col+3]==' ')&&(chess_board[row+4][col+4]==' ')))
	                {
	                   if(chess_board[row-2][col-2]==' ')
	                    {chess_board[row-1][col-1]='o';return 057;}
	                    else if(chess_board[row+4][col+4]==' ')
	                    {chess_board[row+3][col+3]='o';return 58;}
	                }
				}
            }
            
        }
    }
	//o检查所有对角线  '/' 3 //
    for( row=MAX_ROW-1;row>=0;row--)
    {
        for( col=0;col<MAX_COL;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row-check][col+check]=='o')
                        chess++;
                }
                if(chess==3)
                {
                	if (((chess_board[row+1][col-1]==' ')&&(chess_board[row-3][col+3]==' '))||
					((chess_board[row+1][col-1]==' ')&&(chess_board[row+2][col-2]==' '))||
					((chess_board[row-3][col+3]==' ')&&(chess_board[row-4][col+4]==' ')))
	                {
	                    if(chess_board[row+2][col-2]==' ')
	                    {chess_board[row+1][col-1]='o'; return 59;}
	                    else if(chess_board[row-4][col+4]==' ')
	                    {chess_board[row-3][col+3]='o';return 60;}
	                }
				}
            }
        }
    }

	for( row=0;row<MAX_ROW;row++)
    {
        count=0;dangerous=0; 
        for( col=0;col<MAX_COL;col++)
        {
            if((chess_board[row+1][col]=='*')&&(chess_board[row+2][col]=='*'))  count++;
            if((chess_board[row+1][col+1]=='*')&&(chess_board[row+2][col+2]=='*'))  count++;
            if((chess_board[row][col+1]=='*')&&(chess_board[row][col+2]=='*'))  count++;
            if((chess_board[row-1][col+1]=='*')&&(chess_board[row-2][col+2]=='*'))  count++;
            if((chess_board[row-1][col]=='*')&&(chess_board[row-2][col]=='*'))  count++;
            if((chess_board[row-1][col-1]=='*')&&(chess_board[row-2][col-2]=='*'))  count++;
            if((chess_board[row][col-1]=='*')&&(chess_board[row][col-2]=='*'))  count++;
            if((chess_board[row+1][col-1]=='*')&&(chess_board[row+2][col-2]=='*'))  count++;

            if((chess_board[row+1][col]=='*')&&(chess_board[row+2][col]=='*')&&(chess_board[row+3][col]=='*'))  dangerous++;
            if((chess_board[row+1][col+1]=='*')&&(chess_board[row+2][col+2]=='*')&&(chess_board[row+3][col+3]=='*'))  dangerous++;
            if((chess_board[row][col+1]=='*')&&(chess_board[row][col+2]=='*')&&(chess_board[row][col+3]=='*'))  dangerous++;
            if((chess_board[row-1][col+1]=='*')&&(chess_board[row-2][col+2]=='*')&&(chess_board[row-3][col+3]=='*'))  dangerous++;
            if((chess_board[row-1][col]=='*')&&(chess_board[row-2][col]=='*')&&(chess_board[row-3][col]=='*'))  dangerous++;
            if((chess_board[row-1][col-1]=='*')&&(chess_board[row-2][col-2]=='*')&&(chess_board[row-3][col-3]=='*'))  dangerous++;
            if((chess_board[row][col-1]=='*')&&(chess_board[row][col-2]=='*')&&(chess_board[row][col-3]=='*'))  dangerous++;
            if((chess_board[row+1][col-1]=='*')&&(chess_board[row+2][col-2]=='*')&&(chess_board[row+3][col-3]=='*'))  dangerous++;
            
            if((count>=2)&&(chess_board[row][col]==' ')&&(dangerous>=1))
            {chess_board[row][col]='o';return 061;}
        }
    }

    //检查行3//
	for ( row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<=MAX_COL-4;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row][col+check]=='*')
                        chess++;
                }
                if ((chess==3)&&(col!=0))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+3]==' '))
                    {
                        if((chess_board[row][col-2]=='*')&&(col-2>=0))
                        {chess_board[row][col-1]='o';return 062;}
                        else if((chess_board[row][col+4]=='*')&&(col+4<MAX_COL))
                        {chess_board[row][col+3]='o';return 063;}
                        else
                        {
                            int i = rand() % 2;
                            if(i==0)
                            {chess_board[row][col-1]='o';return 064;}
                            else
                            {chess_board[row][col+3]='o';return 065;}
                        }
                        
                    }
                    else if((chess_board[row][col-1]==' ')&&((chess_board[row][col+3]=='o')||(col+3==MAX_COL)))
                    {
                        if((chess_board[row][col-2]=='*')&&(col-2>=0))
                        {chess_board[row][col-1]='o';return 066;}
                    }
                    else if(((chess_board[row][col-1]=='o')||(col==0))&&(chess_board[row][col+3]==' '))
                    {
                        if((col+4<MAX_COL)&&(chess_board[row][col+4]=='*'))
                        {chess_board[row][col+3]='o';return 067;}
                    }
                }
            }
        }
    }
	//检查列3//
	for ( col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<MAX_ROW;row++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col]=='*')
                        chess++;
                }
                if ( (chess==3)&&(row!=0))
                {
                    if((chess_board[row-1][col]==' ')&&(chess_board[row+3][col]==' '))
                    {
                        if((chess_board[row-2][col]=='*')&&(row-2>=0))
                        {chess_board[row-1][col]='o';return 68;}
                        else if((chess_board[row+4][col]=='*')&&(row+4<MAX_ROW))
                        {chess_board[row+3][col]='o';return 69;}
                        else
                        {
                            int i = rand() % 2;
                            if(i==0)
                            {chess_board[row-1][col]='o';return 70;}
                            else
                            {chess_board[row+3][col]='o';return 071;}
                        }
                    }
                    else if(((chess_board[row-1][col]=='o')||(row==0))&&(chess_board[row+3][col]==' '))
                    {
                        if((chess_board[row+4][col]=='*')&&(row+4<=MAX_ROW))
                        {chess_board[row+3][col]='o';return 072;}
                    }   
                    else if((chess_board[row-1][col]==' ')&&((chess_board[row+3][col]=='o')||(row+3==MAX_ROW)))
                    {
                        if((chess_board[row-2][col]=='*')&&(row-2>=0))
                        {chess_board[row-1][col]='o';return 073;}
                    } 
                    
                }
            }
        }
	}
	//检查所有对角线  '\' 3 //
	for( row=0;row<=(MAX_ROW-4);row++)
    {
        for( col=0;col<=(MAX_COL-4);col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col+check]=='*')
                        chess++;
                }
                if((chess==3)&&(row!=0)&&(col!=0))
                {
                    if((chess_board[row-1][col-1]==' ')&&(chess_board[row+3][col+3]==' '))
                    {
                        if((chess_board[row-2][col-2]=='*')&&(row-2>=0)&&(col-2>=0))
                        {chess_board[row-1][col-1]='o';return 074;}
                        else if((chess_board[row+4][col+4]=='*')&&(row+4<MAX_ROW)&&(col+4<MAX_COL))
                        {chess_board[row+3][col+3]='o';return 075;}
                        else
                        {
                            int i = rand() % 2;
                            if(i==0)
                            {chess_board[row-1][col-1]='o';return 076;}
                            else
                            {chess_board[row+3][col+3]='o';return 077;}
                        }
                    }
                    else if (((chess_board[row-1][col-1]=='o')||(row==0)||(col==0))&&(chess_board[row+3][col+3]==' '))
                    {
                        if((col+4<MAX_COL)&&(row+4<MAX_ROW)&&(chess_board[row+4][col+4]=='*'))
                        {chess_board[row+3][col+3]='o';return 78;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&( (chess_board[row+3][col+3]=='o') || (row+3==MAX_ROW) || (col+3==MAX_COL) ))
                    {
                        if((row-2>=0)&&(col-2>=0)&&(chess_board[row-2][col-2]=='*'))
                        {chess_board[row-1][col-1]='o';return 79;}
                    }
                }
            }
            
        }
    }
	//检查所有对角线  '/' 3 //
    for( row=MAX_ROW-1;row>=3;row--)
    {
        for( col=0;col<=MAX_COL-4;col++)
        {
            if(chess_board[row][col]=='*')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row-check][col+check]=='*')
                        chess++;
                }
                if((chess==3)&&(row!=MAX_ROW-1)&&(col!=0))
                {
                    if((chess_board[row+1][col-1]==' ')&&(chess_board[row-3][col+3]==' '))
                    {
                        if((chess_board[row+2][col-2]=='*')&&(row+2<MAX_ROW)&&(col-2>=0))
                        {chess_board[row+1][col-1]='o';return 80;}
                        else if((chess_board[row-4][col+4]=='*')&&(row-4>=0)&&(col+4<MAX_COL))
                        {chess_board[row-3][col+3]='o';return 81;}
                        else
                        {
                            int i = rand() % 2;
                            if(i==0)
                            {chess_board[row+1][col-1]='o';return 82;}
                            else
                            {chess_board[row-3][col+3]='o';return 83;}
                        }
                    }
                    else if(((chess_board[row+1][col-1]=='o')||(row+1==MAX_ROW)||(col==0))&&(chess_board[row-3][col+3]==' '))
                    {
                        if((row-4>=0)&&(col+4<MAX_COL)&&(chess_board[row-4][col+4]=='*'))
                        {chess_board[row-3][col+3]=='o';return 84;}
                    }
                    else if(((chess_board[row-3][col+3]=='o')||(row-3==-1)||(col+3==MAX_COL))&&(chess_board[row+1][col-1]==' '))
                    {
                        if((row+2<MAX_ROW)&&(col-2>=0)&&(chess_board[row+2][col-2]=='*'))
                        {chess_board[row+1][col-1]='o';return 85;}
                    }
                }
            }
        }
    }
   
	//***//
    //* *//
    //***//
    for( row=0;row<MAX_ROW;row++)
    {
        for( col=0;col<MAX_COL;col++)
        {
        	count=0;
        	if(chess_board[row][col]==' ')
        	{
        		if((chess_board[row+1][col]=='*')&&(chess_board[row+2][col]=='*'))  count++;
	            if((chess_board[row+1][col+1]=='*')&&(chess_board[row+2][col+2]=='*'))  count++;
	            if((chess_board[row][col+1]=='*')&&(chess_board[row][col+2]=='*'))  count++;
	            if((chess_board[row-1][col+1]=='*')&&(chess_board[row-2][col+2]=='*'))  count++;
	            if((chess_board[row-1][col]=='*')&&(chess_board[row-2][col]=='*'))  count++;
	            if((chess_board[row-1][col-1]=='*')&&(chess_board[row-2][col-2]=='*'))  count++;
	            if((chess_board[row][col-1]=='*')&&(chess_board[row][col-2]=='*'))  count++;
	            if((chess_board[row+1][col-1]=='*')&&(chess_board[row+2][col-2]=='*'))  count++;
	
	            if((chess_board[row][col-1]=='*')&&(chess_board[row][col+1]=='*'))  count++;
	            if((chess_board[row+1][col]=='*')&&(chess_board[row-1][col]=='*'))  count++;
	            if((chess_board[row+1][col-1]=='*')&&(chess_board[row-1][col+1]=='*'))  count++;
	            if((chess_board[row-1][col-1]=='*')&&(chess_board[row+1][col+1]=='*'))  count++;
	            
	            if(count>=2)
	            {chess_board[row][col]='o';return 86;}	
			}
        }
    }

	

    //3o//
    for ( row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<=MAX_COL-3;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row][col+check]=='o')
                        chess++;
                }
                if (chess==3)
                {
                    if(chess_board[row][col+3]==' ')
                        {chess_board[row][col+3]='o';return 87;}
                    else if(chess_board[row][col-1]==' ')
                    {chess_board[row][col-1]='o';return 88;}
                }
            }
        }
    }
   //o检查列3//
	for ( col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<=MAX_ROW-3;row++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col]=='o')
                        chess++;
                }
                if ( chess==3)
                {
                    if(chess_board[row+3][col]==' ')
                    {chess_board[row+3][col]='o';return 89;}
                    else if(chess_board[row-1][col]==' ')
                    {chess_board[row-1][col]='o';return 90;}
                }
            }
        }
    }
                
	//检o查所有对角线  '\' 3 //
	for( row=0;row<=(MAX_ROW-3);row++)
    {
        for( col=0;col<=(MAX_COL-3);col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row+check][col+check]=='o')
                        chess++;
                }
                if(chess==3)
                {
                    if(chess_board[row+3][col+3]==' ')
                    {chess_board[row+3][col+3]='o';return 91;}
                    else if(chess_board[row-1][col-1]==' ')
                    {chess_board[row-1][col-1]='o';return 92;}
                }
            }
        }
    }
                
	//o检查所有对角线  '/' 3//
    for( row=MAX_ROW-1;row>=2;row--)
    {
        for( col=0;col<=MAX_COL-3;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=2;check++)
                {
                    if(chess_board[row-check][col+check]=='o')
                        chess++;
                }
                if(chess==3)
                {
                    if(chess_board[row-3][col+3]==' ')
                    {chess_board[row-3][col+3]='o';return 93;}
                    else if(chess_board[row+1][col-1]==' ')
                    {chess_board[row+1][col-1]='o';return 94;}
                }
            }
        }
    }

    //  oo  //
    for( row=0;row<MAX_ROW;row++)
    {
        for( col=0;col<MAX_COL;col++)
        {
            count=0;
            if(chess_board[row][col]==' ')
            {
                if((chess_board[row][col-1]=='o')&&(chess_board[row][col+1]=='o')&&(chess_board[row][col-2]==' ')&&(chess_board[row][col+2]==' ')) count++;
                if((chess_board[row-1][col]=='o')&&(chess_board[row+1][col]=='o')&&(chess_board[row+2][col]==' ')&&(chess_board[row-2][col]==' ')) count++;
                if((chess_board[row-1][col-1]=='o')&&(chess_board[row+1][col+1]=='o')&&(chess_board[row-2][col-2]==' ')&&(chess_board[row+2][col+2]==' ')) count++;
                if((chess_board[row-1][col+1]=='o')&&(chess_board[row+1][col-1]=='o')&&(chess_board[row-2][col+2]==' ')&&(chess_board[row+2][col-2]==' ')) count++;
                if((chess_board[row][col-1]=='o')&&(chess_board[row][col+1]=='o')&&(chess_board[row][col-2]==' ')&&(chess_board[row][col+2]==' ')) count++;

                if(count!=0)
                {chess_board[row][col]='o';return 95;}
            }
        }
    }
    
    
	//o o//
	for ( row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<=MAX_COL-2;col++)
        {
        	if(chess_board[row][col]==' ')
        	{
        		if((chess_board[row][col-1]=='o')&&(chess_board[row][col+1]=='o')&&((chess_board[row][col-2]==' ')||(chess_board[row][col+2]==' ')))
				{chess_board[row][col]='o';return 96;}
				if((chess_board[row+1][col]=='o')&&(chess_board[row-1][col]=='o')&&((chess_board[row+2][col]==' ')||(chess_board[row-2][col]==' ')))
				{chess_board[row][col]='o';return 97;}
				if((chess_board[row-1][col-1]=='o')&&(chess_board[row+1][col+1]=='o')&&((chess_board[row-2][col-2]==' ')||(chess_board[row+2][col+2]==' ')))
				{chess_board[row][col]='o';return 98;}
				if((chess_board[row+1][col-1]=='o')&&(chess_board[row-1][col+1]=='o')&&((chess_board[row+2][col-2]==' ')||(chess_board[row-2][col+2]==' ')))
				{chess_board[row][col]='o';return 99;}
			}
	    }
	} 
    // oo //
    for ( row = 0; row < MAX_ROW; row++)
    {
        for( col=0;col<=MAX_COL-2;col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row][col+check]=='o')
                        chess++;
                }
                if ((chess==2)&&(chess_board[row][col+2]==' ')&&(chess_board[row][col-1]==' '))
                {
                    if(chess_board[row][col+3]==' ')
                        {chess_board[row][col+2]='o';return 100;}
                    else if(chess_board[row][col-2]==' ')
                    {chess_board[row][col-1]='o';return 101;}
                }
            }
        }
    }
   //o检查列  oo //
	for ( col = 0; col < MAX_COL; col++)
    {
		for( row=0;row<=MAX_ROW-2;row++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row+check][col]=='o')
                        chess++;
                }
                if ( (chess==2)&&(chess_board[row+2][col]==' ')&&(chess_board[row-1][col]==' '))
                {
                    if(chess_board[row+3][col]==' ')
                    {chess_board[row+2][col]='o';return 0102;}
                    else if(chess_board[row-2][col]==' ')
                    {chess_board[row-1][col]='o';return 103;}
                }
            }
        }
    }
                
	//检o查所有对角线  '\' oo //
	for( row=0;row<=(MAX_ROW-2);row++)
    {
        for( col=0;col<=(MAX_COL-2);col++)
        {
            if(chess_board[row][col]=='o')
            {
                chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row+check][col+check]=='o')
                        chess++;
                }
                if((chess==2)&&(chess_board[row+2][col+2]==' ')&&(chess_board[row-1][col-1]==' '))
                {
                    if(chess_board[row+3][col+3]==' ')
                    {chess_board[row+2][col+2]='o';return 104;}
                    else if(chess_board[row-2][col-2]==' ')
                    {chess_board[row-1][col-1]='o';return 105;}
                }
            }
        }
    }
                
	//o检查所有对角线  '/' oo //
    for( row=MAX_ROW-1;row>=1;row--)
    {
        for( col=0;col<=MAX_COL-2;col++)
        {
            if(chess_board[row][col]=='o')
            {
                 chess=1;
                for( check=1;check<=1;check++)
                {
                    if(chess_board[row-check][col+check]=='o')
                        chess++;
                }
                if((chess==2)&&(chess_board[row-2][col+2]==' ')&&(chess_board[row+1][col-1]==' '))
                {
                    if(chess_board[row-3][col+3]==' ')
                    {chess_board[row-2][col+2]='o';return 106;}
                    else if(chess_board[row+2][col-2]==' ')
                    {chess_board[row+1][col-1]='o';return 0107;}
                }
            }
        }
    }

    int r=a-1,c=b-1,suiji;
    suiji=rand()%4;
    switch (suiji)
    {
    case 0:
        for( row=r;row>=0;row--)//1
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 108;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 109;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 110;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 111;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 112;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 113;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 114;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 115;}
                    }
                }
            }
        }
        for( row=r;row>=0;row--)//2
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 116;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 117;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 118;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 119;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 120;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 121;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 122;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 123;}
                    }
                }
            }
        }
        for( row=r;row<MAX_ROW;row++)//3
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 124;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 125;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 126;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 127;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 128;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 129;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 130;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 131;}
                    }
                }
            }
        }
        for( row=r;row<MAX_ROW;row++)//4
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 132;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 133;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 134;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 135;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 136;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 137;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 138;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 139;}
                    }
                }
            }
        }
        break;
       
    case 1:
        for( row=r;row>=0;row--)//2
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 140;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 141;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 142;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 143;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 144;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 145;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 146;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 147;}
                    }
                }
            }
        }
        for( row=r;row>=0;row--)//1
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 148;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 149;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 150;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 151;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 152;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 153;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 154;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 155;}
                    }
                }
            }
        }
        for( row=r;row<MAX_ROW;row++)//3
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 156;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 157;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 158;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 159;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 160;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 161;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 162;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 163;}
                    }
                }
            }
        }
        for( row=r;row<MAX_ROW;row++)//4
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 164;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 165;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 166;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 167;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 168;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 169;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 170;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 171;}
                    }
                }
            }
        }
        break;
    case 2:
        for( row=r;row<MAX_ROW;row++)//3
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 172;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 173;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 174;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 175;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 176;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 177;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 178;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 179;}
                    }
                }
            }
        }
        for( row=r;row<MAX_ROW;row++)//4
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 180;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 181;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 182;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 183;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 184;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 185;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 186;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 187;}
                    }
                }
            }
        }
        for( row=r;row>=0;row--)//1
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 188;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 189;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 190;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 191;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 192;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 193;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 194;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 195;}
                    }
                }
            }
        }
        for( row=r;row>=0;row--)//2
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 196;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 197;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 198;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 199;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 200;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 201;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 202;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 203;}
                    }
                }
            }
        }
        break;
    case 3:
        for( row=r;row<MAX_ROW;row++)//4
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 204;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 205;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 206;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 207;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 208;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 209;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 210;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 211;}
                    }
                }
            }
        }
        for( row=r;row>=0;row--)//1
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 212;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 213;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 214;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 215;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 216;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 217;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 218;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 219;}
                    }
                }
            }
        }
        for( row=r;row>=0;row--)//2
        {
            for( col=c;col<MAX_COL;col++)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 220;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 221;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 222;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 223;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 224;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 225;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 226;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 227;}
                    }
                }
            }
        }
        for( row=r;row<MAX_ROW;row++)//3
        {
            for( col=c;col>=0;col--)
            {
                if((chess_board[row][col]=='o')&&( 
                    ((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))||
                ((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))||
                ((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))||
                ((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))))
                {
                    if((chess_board[row][col-1]==' ')&&(chess_board[row][col+1]==' '))
                    {
                        if(chess_board[row][col-2]==' ')
                        {chess_board[row][col-1]='o';return 228;}
                        else if(chess_board[row][col+2]==' ')
                        {chess_board[row][col+1]='o';return 229;}
                    }
                    else if((chess_board[row-1][col]==' ')&&(chess_board[row+1][col]==' '))
                    {
                        if(chess_board[row-2][col]==' ')
                        {chess_board[row-1][col]='o';return 230;}
                        else if(chess_board[row+2][col]==' ')
                        {chess_board[row+1][col]='o';return 231;}
                    }
                    else if((chess_board[row+1][col-1]==' ')&&(chess_board[row-1][col+1]==' '))
                    {
                        if(chess_board[row+2][col-2]==' ')
                        {chess_board[row+1][col+1]='o';return 232;}
                        else if(chess_board[row-2][col+2]==' ')
                        {chess_board[row-1][col+1]='o';return 233;}
                    }
                    else if((chess_board[row-1][col-1]==' ')&&(chess_board[row+1][col+1]==' '))
                    {
                        if(chess_board[row-2][col-2]==' ')
                        {chess_board[row-1][col-1]='o';return 234;}
                        else if(chess_board[row+2][col+2]==' ')
                        {chess_board[row+1][col+1]='o';return 235;}
                    }
                }
            }
        }
        break;
    }

    
    {//follow tightly//
    int empty=0,i=0;
    int situation[8][2];
    if(chess_board[r+1][c-1]==' ')  {empty++;situation[i][0]=r+1;situation[i++][1]=c-1;}
    if(chess_board[r+1][c]==' ')    {empty++;situation[i][0]=r+1;situation[i++][1]=c;}
    if(chess_board[r+1][c+1]==' ')  {empty++;situation[i][0]=r+1;situation[i++][1]=c+1;}
    if(chess_board[r][c-1]==' ')    {empty++;situation[i][0]=r;situation[i++][1]=c-1;}
    if(chess_board[r][c+1]==' ')    {empty++;situation[i][0]=r;situation[i++][1]=c+1;}
    if(chess_board[r-1][c-1]==' ')  {empty++;situation[i][0]=r-1;situation[i++][1]=c-1;}
    if(chess_board[r-1][c]==' ')    {empty++;situation[i][0]=r-1;situation[i++][1]=c;}
    if(chess_board[r-1][c+1]==' ')  {empty++;situation[i][0]=r-1;situation[i++][1]=c+1;}
    srand((unsigned int)time(0));
    i= rand()%empty;
    r=situation[i][0];c=situation[i][1];
    chess_board[r][c]='o';return 236;
    }

while (1)
    {
		row = rand() % MAX_ROW;
		col = rand() % MAX_COL;
		if (chess_board[row][col] != ' ')
        {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}

return 237;	
}


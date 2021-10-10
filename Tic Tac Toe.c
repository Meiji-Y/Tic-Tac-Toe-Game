#include <stdio.h>


void prep_board();
void put_board(int,char,int*,int*,char[3][3]);
void display_board(char*,int,int,char[3][3],int*,int*);
void win_check(int*,int*,int*,int*,char[3][3],int*);


int main()
{
	int gametype;

		start:

	printf("\n                                     WELCOME TO THE TIC TAC TOE GAME \n\a");
	printf("\n                                     Single Player ====> Press 1 \n");
	printf("\n                                     Multiplayer   ====> Press 2 \n");
	printf("\n                                     Exit          ====> Press 3 \n");

	scanf("%d",&gametype);

    int flag1=1,adder=0;
    int count=0;
	if(gametype==1)
	{
		printf("\n Single Player mode is not available now ...");
		goto start;
	}
	else if(gametype==2)
	{
			int number,playernum=1,x,y;

			char xox_changer='X';
			char chrboard[3][3]={{178,178,178},{178,178,178},{178,178,178}};
			prep_board();



			while(flag1) // flag=1 => game continues flag=0 => game finish
			{
				printf("Player %d's Turn ... \n",playernum);
				printf("Select the number that you want to put X or O ...\n");
				scanf("%d",&number);

				put_board(number,xox_changer,&x,&y,chrboard);
				display_board(&xox_changer,x,y,chrboard,&playernum,&adder);
				win_check(&x,&y,&flag1,&count,chrboard,&adder);


			
				if(flag1==2)
				{
					goto start;
				}

			 }

				}
				else if(gametype==3)
				{
					flag1=0;
				}
				else
				{
					printf("\n You entered invalid number...");
					printf("\n Please enter 1 or 2 ...");
					goto start;
				}



	return 0;
}

void prep_board() 	//Shows which keys the game is played with.
{
	int board[3][3]={{7,8,9},{4,5,6},{1,2,3}};

	for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				printf("    %d",board[i][j]);
			}
			printf("\n");
			printf("\n");
		}

}

void put_board(int number, char xox_changer,int* x, int* y,char chrboard[3][3])
{
	//Calculates which numbers come in which indexes


	if(number == 7)
	{
		*x=0;
		*y=0;
	}
	else if(number == 8)
	{
		*x=0;
		*y=1;
	}
	else if(number == 9)
	{
		*x=0;
		*y=2;
	}
	else if(number == 4)
	{
		*x=1;
		*y=0;
	}
	else if(number == 5)
	{
		*x=1;
		*y=1;
	}
	else if(number == 6)
	{
		*x=1;
		*y=2;
	}
	else if(number == 1)
	{
		*x=2;
		*y=0;
	}
	else if(number == 2)
	{
		*x=2;
		*y=1;
	}
	else if(number == 3)
	{
		*x=2;
		*y=2;
	}
	else
	{
		printf("Invalid number ...");
	}


}


void display_board(char *xox_changer,int x,int y,char chrboard[3][3],int *playernum,int *adder)   	//prints the current state of the game board
{

		
			
			if(chrboard[x][y]!='X' && chrboard[x][y]!='O'){
					chrboard[x][y]=*xox_changer;
					for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						printf("    % c",chrboard[i][j]);
					}
					printf("\n");
					printf("\n");
				}
				
					if(*xox_changer =='X')
				{
					*xox_changer='O';
					*playernum=2;
				}
				else
				{
					*xox_changer='X';
					*playernum=1;
				}

			}
			else{
					for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						printf("    % c",chrboard[i][j]);
					}
					printf("\n");
					printf("\n");
						
					if(*xox_changer =='X'){
						*xox_changer='X';
						*playernum=1;
					}
					else{
						*xox_changer='O';
						*playernum=2;
					}
						
				}
				(*adder)++;				
			}

}

void win_check(int* x,int* y,int* flag1 ,int* count ,char chrboard[3][3],int* adder)		//checks who wins
{

	if((chrboard[0][0]=='X' && chrboard[0][1]=='X' && chrboard[0][2]=='X') || (chrboard[1][0]=='X' && chrboard[1][1]=='X' && chrboard[1][2]=='X') || (chrboard[2][0]=='X' && chrboard[2][1]=='X' && chrboard[2][2]=='X') || (chrboard[0][0]=='X' && chrboard[1][0]=='X' && chrboard[2][0]=='X') || (chrboard[0][1]=='X' && chrboard[1][1]=='X' && chrboard[2][1]=='X') || (chrboard[0][2]=='X' && chrboard[1][2]=='X' && chrboard[2][2]=='X') || (chrboard[0][0]=='X' && chrboard[1][1]=='X' && chrboard[2][2]=='X') || (chrboard[0][2]=='X' && chrboard[1][1]=='X' && chrboard[2][0]=='X') )
	{
		*flag1=2;
		printf("\n PLAYER 1 WON THE GAME ... \a");
	}
	else if ((chrboard[0][0]=='O' && chrboard[0][1]=='O' && chrboard[0][2]=='O') || (chrboard[1][0]=='O' && chrboard[1][1]=='O' && chrboard[1][2]=='O') || (chrboard[2][0]=='O' && chrboard[2][1]=='O' && chrboard[2][2]=='O') || (chrboard[0][0]=='O' && chrboard[1][0]=='O' && chrboard[2][0]=='O') || (chrboard[0][1]=='O' && chrboard[1][1]=='O' && chrboard[2][1]=='O') || (chrboard[0][2]=='O' && chrboard[1][2]=='O' && chrboard[2][2]=='O') || (chrboard[0][0]=='O' && chrboard[1][1]=='O' && chrboard[2][2]=='O') || (chrboard[0][2]=='O' && chrboard[1][1]=='O' && chrboard[2][0]=='O') )
	{
		*flag1=2;
		printf("\n PLAYER 2 WON THE GAME ... \a");
 }
	else{
        (*count)++;

	}

    if((*count)==(9+(*adder))){
                    printf("TIE Nobody Won...\n\a");
                    *flag1=2;
                }

}

#include<iostream>
#include<cstdlib>
using namespace std;

int board[6][7];
bool gameContinues();

int main()
{
    int player=1;
    int from[2],to[2];

    //setting up board
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            board[i][j]=0;
        }
    }
    board[0][0]=board[5][6]=1;
    board[0][6]=board[5][0]=2;

	//the logic
    for(int turn=1;turn<=10;){
        if(gameContinues()){
            cout<<endl;
            cout<<"Turn:   "<<turn<<endl;
            cout<<"Player: "<<player<<endl;

            cout<<endl;

            cout<<"From: ";
                cin>>from[0]>>from[1];
            cout<<"To:   ";
                cin>>to[0]>>to[1];

            if(board[from[0]][from[1]]==player){
                if(!(abs(from[0]-to[0])==2 && abs(from[1]-to[1])==2)){
                    if(abs(from[0]-to[0])==2 || abs(from[1]-to[1])==2){
                        board[from[0]][from[1]]=0;
                        board[to[0]][to[1]]=player;
                    }
                    else if(abs(from[0]-to[0])<2 || abs(from[1]-to[1])<2){
                        board[to[0]][to[1]]=player;
                    }
                    for(int i=to[0]-1;i<=to[0]+1;i++){
                        for(int j=to[1]-1;j<=to[1]+1;j++){
                            if(board[i][j]!=player && board[i][j]!=0)
                                board[i][j]=player;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid jump, click to try again!"<<endl;
                    system("pause");
                    player--;
                }
            }
            else{
                cout<<"\nInvalid coordinates, click to try again!"<<endl;
                system("pause");
                player--;
            }

            player++;
            if(player>2){
                player=1;
                turn++;
            }
        }
        else{
            cout<<"\nGAME OVER!"<<endl;
            break;
        }
    }

    return 0;
}

//function to print board and check if game ends
bool gameContinues(){
    system("cls");
    int plyr1=0,plyr2=0;

    cout<<"   ";
    for(int i=0;i<7;i++)
        cout<<i<<" ";

    cout<<endl<<endl;

    for(int i=0;i<6;i++){
        cout<<i<<"  ";
        for(int j=0;j<7;j++){
            cout<<board[i][j]<<" ";
            if(board[i][j]==1)
                plyr1=1;
            if(board[i][j]==2)
                plyr2=1;
        }
        cout<<endl;
    }
    if(plyr1==1 && plyr2==1)
        return true;
    else
        return false;
}

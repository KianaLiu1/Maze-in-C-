#include "maze.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;



int main()
{
    char option, finished;
    int seed, width, height, score;
    bool SolveMaze, success;
    string name;
    int time = 90;
    
    success=false;
    ofstream file;
    
    file.open("Record.txt", ios::app);
    
    //setting the maze as default
    width = 10;
    height = 10;
    seed = 100;
    SolveMaze = false;
    score = 100;
    
    //giving out the instruction
    cout<<"Welcome to amaze! You are to solve a maze with three layers in a given amount of time. The initial credit is 100. Once you hit a wall, you will get 10 points deduced. The faster you solve, the higher score you will get. The difficulty level increases with the larger size and the smaller amount of time."<<endl;
    cout<<"1st Tom: 90"<<endl;
    cout<<"2nd Sally: 88"<<endl;
    cout<<"3rd Paul: 72"<<endl;
    cout<<"4th Ella: 70"<<endl;
    cout<<"5th Jim: 66"<<endl;
    
    
    cout<<"Please enter your name: "<<endl;
    cin>>name;
    
    cout<<"Would you like to set the maze? (y/n)"<<endl;
    cin>>finished;
    
    //showing the menu
    while(finished == 'y'||finished == 'Y')
    {
        cout<<"amazing"<<endl;
        cout<<"Press w to set the width of the maze"<<endl;
        cout<<"Press h to set the height of the maze"<<endl;
        cout<<"Press r to set the seed of the random number generator"<<endl;
        cout<<"Press s to solve the maze using depth-first-search"<<endl;
        cout<<"Press b to solve the maze using bread-first-search"<<endl;
        cout<<"Press ? to show the help screen"<<endl;
        
        cin>>option;
        
        if(option == 'w')
        {
            cout<<"Please enter the width of the maze";
            cin>>width;
        }

        else if(option == 'h')
        {
            cout<<"Please enter the height of the maze";
            cin>>height;
        }
        
        else if(option == 'r')
        {
            cout<<"Please enter a seed";
            cin>>seed;
            srand(seed);
        }
        else if(option == 's')
        {
            SolveMaze=false;
            cout<<"Solve the maze using stack"<<endl;
            
        }
        else if(option == 'b')
        {
            SolveMaze = true;
            cout<<"Solve the maze using queue"<<endl;
        }
        else if(option == '?')
        {
            cout<<"You are to solve a maze with three layers. The initial credit is 100. Once you hit a wall, you will get 10 points deduced. The faster you solve, the higher score you will get.";
        }
        
        cout<<"Would you like to cotinue setting the maze? (y/n)"<<endl;
        cin>>finished;
        
    }
    for(int i =0; i<3; i++)
    {
        maze Maze;
        
        Maze.SetHeight(height+i*2);
        Maze.SetWidth(width+i*2);
        
        cout<<"The maze has a height of "<<height+i*2<<" and a width of "<<width+i*2<<endl;
        
        //calling the functions from cell.h
        Maze.CreateMaze();
        Maze.InitializeNeighbour();
        Maze.GenerateMaze();
        Maze.PrintMaze();
        
        //if the player won
        if(Maze.PlayMaze(time-i*10, &score)==true)
        {
            cout<<'\a';
            cout<<"Congratulations! Your score is "<<score;
        }
        
        //if the player lost
        else
        {
            if(SolveMaze == false)
            {
                cout<<"Solve maze using stack."<<endl;
                Maze.SolveMazeStack();
                Maze.PrintWall();
            }
            else
            {
                cout<<"Solve maze using queue."<<endl;
                Maze.SolveMazeQueue();
                Maze.PrintWall();
            }
            
            success=false;
            break;

        }
        if(i==2)
            success=true;
        else success = false;
        
        
        

    }
    
    //writing to the file of the score
    if(success==true)
    {
        file<<name<<" "<<score<<endl;
    }
    file.close();

   
    return 0;
    
}

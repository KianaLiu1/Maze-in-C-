#include <iostream>
#include <random>
#include "stack.h"
#include <vector>
#include "queue.h"
#include <ctime>
#include "list.h"
//#include <cstdlib>
using namespace std;

class maze
{
private:
    int height;
    int width;
    cell** matrix;
    
public:
    ~maze();
    //set the settings of the maze
    void SetHeight(int h)
    {
        height = h;
    }
    
    void SetWidth(int w)
    {
        width = w;
    }
    void CreateMaze();
    void PrintMaze();
    void InitializeNeighbour();
    void PrintNeighbour();
    void GenerateMaze();
    void GetUnvisitedNeighbours(cell, vector<neighbour>&);
    void RemoveWall(int,int,int,int);
    void PrintWall();
    int CheckWall(int, int,int,int);
    void SolveMazeStack();
    void FindUnvisitedReachable(cell a, vector<neighbour>& UnvisitedReachableList);
    void SolveMazeQueue();
    bool PlayMaze(int, int *);
    bool CheckNext(int,int,int,int,int*);
    void FindCell(int *, int *, int);
    
    vector<cell> path;
};

maze::~maze()
{
    for(int i=0; i<height; i++)
        delete[] matrix[i];
    
    delete[] matrix;
}

//creating the maze
void maze::CreateMaze()
{
    int number=0;
    matrix = new cell* [height];
    for(int i=0; i<height; i++)
    {
        matrix[i]=new cell[width];
        for(int j=0; j<width; j++)
        {
            cell NewCell;
            NewCell.SetRow(i);
            NewCell.SetColumn(j);
            NewCell.SetVisit(false);
            NewCell.SetNeighbour(0);
            NewCell.SetNumber(++number);
            matrix[i][j]=NewCell;
        }
    }
}

//print maze
void maze::PrintMaze()
{
    for(int i =0; i<height-1; i++)
    {
        for(int j=0; j<width-1; j++)
        {
            //check if there's a wall between two cells
            if(CheckWall(i, j, i, j+1)==0)
            {
                //check the digit number of the current cell so that the numbers can line up
                if(matrix[i][j].GetNumber()<10)
                    cout<<" "<<matrix[i][j].GetNumber()<<" ";
                else if((matrix[i][j].GetNumber()<100) && (matrix[i][j].GetNumber()>=10))
                    cout<<" "<<matrix[i][j].GetNumber();
                else if((matrix[i][j].GetNumber()<1000) && (matrix[i][j].GetNumber()>=100))
                    cout<<matrix[i][j].GetNumber();
                cout<<" ";
            }
            else
            {
                if(matrix[i][j].GetNumber()<10)
                    cout<<" "<<matrix[i][j].GetNumber()<<" ";
                else if((matrix[i][j].GetNumber()<100) && (matrix[i][j].GetNumber()>=10))
                    cout<<" "<<matrix[i][j].GetNumber();
                else if((matrix[i][j].GetNumber()<1000) && (matrix[i][j].GetNumber()>=100))
                    cout<<matrix[i][j].GetNumber();
                //printing the wall
                cout<<"|";
            }
            
    
        }
        if(matrix[i][width-1].GetNumber()<10)
            cout<<" "<<matrix[i][width-1].GetNumber()<<" ";
        else if((matrix[i][width-1].GetNumber()<100) && (matrix[i][width-1].GetNumber()>=10))
            cout<<" "<<matrix[i][width-1].GetNumber();
        else if((matrix[i][width-1].GetNumber()<1000) && (matrix[i][width-1].GetNumber()>=100))
            cout<<matrix[i][width-1].GetNumber();
        cout<<endl;

        for(int j=0; j<width-1; j++)
        {
            if(CheckWall(i, j, i+1, j)==0)
            {
                cout<<"    ";
            }
            else cout<<" -- ";
        }
        
        if(CheckWall(i, width-1, i+1, width-1)==0)
            cout<<"    ";
        else cout<<" -- ";
        cout<<endl;
    }
    for(int j=0; j<width-1; j++)
    {
        if(CheckWall(height-1, j, height-1, j+1)==0)
        {
            if(matrix[height-1][j].GetNumber()<10)
                cout<<" "<<matrix[height-1][j].GetNumber()<<" ";
            else if((matrix[height-1][j].GetNumber()<100) && (matrix[height-1][j].GetNumber()>=10))
                cout<<" "<<matrix[height-1][j].GetNumber();
            else if((matrix[height-1][j].GetNumber()<1000) && (matrix[height-1][j].GetNumber()>=100))
                cout<<matrix[height-1][j].GetNumber();
            cout<<" ";
            
        }
        else
        {
            if(matrix[height-1][j].GetNumber()<10)
                cout<<" "<<matrix[height-1][j].GetNumber()<<" ";
            else if((matrix[height-1][j].GetNumber()<100) && (matrix[height-1][j].GetNumber()>=10))
                cout<<" "<<matrix[height-1][j].GetNumber();
            else if((matrix[height-1][j].GetNumber()<1000) && (matrix[height-1][j].GetNumber()>=100))
                cout<<matrix[height-1][j].GetNumber();
           cout<<"|";
        }
    }
    if(matrix[height-1][width-1].GetNumber()<10)
        cout<<" "<<matrix[height-1][width-1].GetNumber()<<" ";
    else if((matrix[height-1][width-1].GetNumber()<100) && (matrix[height-1][width-1].GetNumber()>=10))
        cout<<" "<<matrix[height-1][width-1].GetNumber();
    else if((matrix[height-1][width-1].GetNumber()<1000) && (matrix[height-1][width-1].GetNumber()>=100))
        cout<<matrix[height-1][width-1].GetNumber();
    cout<<endl;
}

//set random neighbours
void maze::InitializeNeighbour()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i-1>=0)
            {
                neighbour AddNeighbour1;
                AddNeighbour1.SetRow(i-1);
                AddNeighbour1.SetColumn(j);
                AddNeighbour1.SetWall(1);
                int c = matrix[i][j].GetNeighbour();
                matrix[i][j].GetNeighbourList()[c]=AddNeighbour1;
                matrix[i][j].SetNeighbour(c+1);
            }
            if(j-1>=0)
            {
                neighbour AddNeighbour2;
                AddNeighbour2.SetRow(i);
                AddNeighbour2.SetColumn(j-1);
                AddNeighbour2.SetWall(1);
                int c = matrix[i][j].GetNeighbour();
                matrix[i][j].GetNeighbourList()[c]=AddNeighbour2;
                matrix[i][j].SetNeighbour(c+1);
            
            }
            if(i+1<height)
            {
                neighbour AddNeighbour3;
                AddNeighbour3.SetRow(i+1);
                AddNeighbour3.SetColumn(j);
                AddNeighbour3.SetWall(1);
                int c = matrix[i][j].GetNeighbour();
                matrix[i][j].GetNeighbourList()[c]=AddNeighbour3;
                matrix[i][j].SetNeighbour(c+1);

            }
            if(j+1<width)
            {
                neighbour AddNeighbour4;
                AddNeighbour4.SetRow(i);
                AddNeighbour4.SetColumn(j+1);
                AddNeighbour4.SetWall(1);
                int c = matrix[i][j].GetNeighbour();
                matrix[i][j].GetNeighbourList()[c]=AddNeighbour4;
                matrix[i][j].SetNeighbour(c+1);

            }
        }
    }
}

//print neighbours to debug
void maze::PrintNeighbour()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int c=matrix[i][j].GetNeighbour();
            cout<<"Current i:"<<i<<"Current j:"<<j<<endl;
            for(int k=0; k<c; k++)
            {
                cout<<"Row"<<matrix[i][j].GetNeighbourList()[k].GetRow()<<endl;
                cout<<"Column"<<matrix[i][j].GetNeighbourList()[k].GetColumn()<<endl;

            }
        }
    }
}

//create a neighbour list that includes unvisited neighbours
void maze::GetUnvisitedNeighbours(cell a, vector<neighbour>& UnvisitedList)
{
    int row, column;
    
    row = a.GetRow();
    column = a.GetColumn();
    
    int NeighbourNumber = matrix[row][column].GetNeighbour();
    
    for(int i=0; i<NeighbourNumber; i++)
    {
        neighbour n = matrix[row][column].GetNeighbourList()[i];
        
        int nrow = n.GetRow();
        int ncolumn=n.GetColumn();
        
        if(matrix[nrow][ncolumn].GetVisit()==false)
        {
            UnvisitedList.push_back(n);
        }
    }
    
    
}

void maze::GenerateMaze()
{
    stack s;
    s.CreateStack();
    cell start;
    start=matrix[0][0];
    matrix[0][0].SetVisit(true);
    s.PushStack(start);
    
    while(s.EmptyStack()==false)
    {
        cell current = s.PopStack();
        vector<neighbour> UnvisitedList;
        GetUnvisitedNeighbours(current, UnvisitedList);
        if(UnvisitedList.size()!=0)
        {
            int RandomNumber = rand()% UnvisitedList.size();
            neighbour RandomNeighbour = UnvisitedList.at(RandomNumber);
            //removing the wall by choosing a neighbour randomly
            RemoveWall(current.GetRow(), current.GetColumn(), RandomNeighbour.GetRow(), RandomNeighbour.GetColumn());
            matrix[RandomNeighbour.GetRow()][RandomNeighbour.GetColumn()].SetVisit(true);
            //pushing the current cell into the stack
            s.PushStack(matrix[current.GetRow()][current.GetColumn()]);
            s.PushStack(matrix[RandomNeighbour.GetRow()][RandomNeighbour.GetColumn()]);
        }
    }
    
}

//creating a function to remove the wall between the cell and the neighbour
void maze::RemoveWall(int a, int b, int c, int d)
{
    neighbour* NeighbourList = matrix[a][b].GetNeighbourList();
    for(int i=0; i<matrix[a][b].GetNeighbour(); i++)
    {
        if(NeighbourList[i].GetRow()==c && NeighbourList[i].GetColumn()==d)
        {
            //setting the number of the wall from 1 to 0
            NeighbourList[i].SetWall(0);
        }
    }
    neighbour* NeighbourList2 = matrix[c][d].GetNeighbourList();
    for(int i=0; i<matrix[c][d].GetNeighbour(); i++)
    {
        if(NeighbourList2[i].GetRow()==a && NeighbourList2[i].GetColumn()==b)
        {
            NeighbourList2[i].SetWall(0);
        }
    }
    
}

//printing the answer
void maze::PrintWall()
{
    for(int i =0; i<height-1; i++)
    {
        for(int j=0; j<width-1; j++)
        {
            if(CheckWall(i, j, i, j+1)==0)
            {
                if(matrix[i][j].CheckPath()==1)
                    cout<<"@";
                else if(matrix[i][j].CheckPath()==0)
                    cout<<"*";
                else
                    cout<<" ";
                cout<<" ";
            }
            else
            {
                if(matrix[i][j].CheckPath()==1)
                    cout<<"@";
                else if(matrix[i][j].CheckPath()==0)
                    cout<<"*";
                else
                    cout<<" ";
                cout<<"|";
            }
        }
        if(matrix[i][width-1].CheckPath()==1)
            cout<<"@";
        else if(matrix[i][width-1].CheckPath()==0)
            cout<<"*";
        else
            cout<<" ";
        cout<<endl;
        for(int j=0; j<width; j++)
        {
            if(CheckWall(i, j, i+1, j)==0)
            {
                cout<<"  ";
            }
            else cout<<"- ";
        }
        cout<<endl;
    }
    for(int j=0; j<width-1; j++)
    {
        if(CheckWall(height-1, j, height-1, j+1)==0)
        {
            if(matrix[height-1][j].CheckPath()==1)
                cout<<"@";
            else if(matrix[height-1][j].CheckPath()==0)
                cout<<"*";
            else
                cout<<" ";
            cout<<" ";

        }
        else
        {
            if(matrix[height-1][j].CheckPath()==1)
                cout<<"@";
            else if(matrix[height-1][j].CheckPath()==0)
                cout<<"*";
            else
                cout<<" ";
            cout<<"|";
        }
    }
        cout<<"@"<<endl;
    
}

//check the number of the wall between two cells
int maze::CheckWall(int a, int b, int c, int d)
{
    neighbour* NeighbourList = matrix[a][b].GetNeighbourList();
    for(int i=0; i<matrix[a][b].GetNeighbour(); i++)
    {
        if(NeighbourList[i].GetRow()==c && NeighbourList[i].GetColumn()==d)
        {
            return NeighbourList[i].GetVisit();
        }
    }
    return -1;
}

//solve maze using stack
void maze::SolveMazeStack()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            matrix[i][j].SetVisit(false);
        }
    }
    stack s;
    s.CreateStack();
    cell current;
    current = matrix[0][0];
    s.PushStack(current);
    path.push_back(current);
    matrix[0][0].OnPath(1);
    
    while(!(current.GetRow()==height/2 && current.GetColumn()==width/2))
    {
        matrix[current.GetRow()][current.GetColumn()].SetVisit(true);

        
        vector<neighbour> UnvisitedReachableList;
        
        FindUnvisitedReachable(current, UnvisitedReachableList);
        
        if(UnvisitedReachableList.size()!=0)
        {
            int RandomNumber = rand()% UnvisitedReachableList.size();
            neighbour RandomNeighbour = UnvisitedReachableList.at(RandomNumber);
         
            s.PushStack(matrix[RandomNeighbour.GetRow()][RandomNeighbour.GetColumn()]);


        }
        else
        {
            matrix[current.GetRow()][current.GetColumn()].OnPath(0);
            s.PopStack();
            
        }
        
        current = s.peak();
        path.push_back(current);
        matrix[current.GetRow()][current.GetColumn()].OnPath(1);

        
    }
    
}

//find the unvistied and reachable neighbours while solving
void maze::FindUnvisitedReachable(cell a, vector<neighbour>& UnvisitedReachableList)
{
    neighbour* nlist = matrix[a.GetRow()][a.GetColumn()].GetNeighbourList();
    for(int i=0; i<matrix[a.GetRow()][a.GetColumn()].GetNeighbour(); i++)
    {
        if(nlist[i].GetVisit()==0 && matrix[nlist[i].GetRow()][nlist[i].GetColumn()].GetVisit()==false)
        {
            UnvisitedReachableList.push_back(nlist[i]);
        }
    }
}

//solve maze using queue
void maze::SolveMazeQueue()
{
    path.clear();
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            matrix[i][j].SetVisit(false);
        }
    }
    
    queue Q;
    Q.CreateQueue();
    cell current;
    current = matrix[0][0];
    path.push_back(current);
        
    Q.PushQueue(current);
    
    while(!(current.GetRow()==height/2 && current.GetColumn()==width/2))
    {
        matrix[current.GetRow()][current.GetColumn()].SetVisit(true);
        vector<neighbour> UnvisitedReachableList;
        FindUnvisitedReachable(current, UnvisitedReachableList);
        
        if(UnvisitedReachableList.size()!=0)
        {
            for(int i=0; i<UnvisitedReachableList.size();i++)
            {
                int NeighbourRow=UnvisitedReachableList.at(i).GetRow();
                int NeighbourColumn=UnvisitedReachableList.at(i).GetColumn();
                
                Q.PushQueue(matrix[NeighbourRow][NeighbourColumn]);
            }

        }
        else
        {
            matrix[current.GetRow()][current.GetColumn()].OnPath(0);
        }
        
        Q.PopQueue();
        
        current=Q.peak();
        matrix[current.GetRow()][current.GetColumn()].OnPath(1);

        path.push_back(current);
        
        
        
    }

}

bool maze::PlayMaze(int time, int * score)
{
    cell current;
    int next;
    int row, column;
    current=matrix[0][0];
    
    clock_t StartTime, EndTime;
    
    //start counting time
    StartTime = clock();
    
    cout<<"Now you are at "<<current.GetNumber()<<endl;
    while(!(current.GetRow()==height/2 && current.GetColumn()==width/2))
    {
        cout<<"Please enter your next step: "<<endl;
        cin>>next;
        FindCell(&row, &column, next);
        if(CheckNext(current.GetRow(), current.GetColumn(), row, column, score)==true)
        {
            current=matrix[row][column];
        }
        EndTime = clock();
        
        //if the score went below 0, it's a failure
        if(*score<0)
        {
            cout<<"Sorry! You don't have enough credit"<<endl;
            return false;
        }

        //if running out of time
        if((EndTime-StartTime)/1000>=time)
        {
            cout<<"Time out!!";
            return false;
        }
        
    }
    *score = *score - (EndTime-StartTime)/1000;
    return true;
}

bool maze::CheckNext(int CurrentRow, int CurrentColumn, int NextRow, int NextColumn, int *score)
{
    neighbour* NeighbourList = matrix[CurrentRow][CurrentColumn].GetNeighbourList();
    
    int NeighbourNumber = matrix[CurrentRow][CurrentColumn].GetNeighbour();

    for(int i=0; i<NeighbourNumber; i++)
    {
        if(NeighbourList[i].GetRow()==NextRow && NeighbourList[i].GetColumn()==NextColumn)
        {
            if(NeighbourList[i].GetVisit()==1)
            {
                cout<<"You hit a wall"<<endl;
                *score= *score-10;
                //playing a sound
                cout<<'\a';
                return false;
            }
            else return true;
        }
    }
    cout<<"It's not a reachable neighbour."<<endl;
    return false;
}

void maze::FindCell(int *row, int *column, int number)
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(matrix[i][j].GetNumber()==number)
            {
                *row = i;
                *column = j;
            }
            
        }
    }
}

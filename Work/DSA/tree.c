#include <stdio.h>
#include <stdlib.h>

typedef double Elementtype;

typedef struct Treestruct *Ptrnode;

typedef struct Treestruct Dir;

struct Treestruct
{

    Elementtype Key;
    Ptrnode Firstchild;
    Ptrnode Sibling;
};


// printing the tree ie we will do post order traversal of the tree
// which means we will go on printing names from the root to the child
// till we have traversed the entire directory

//numspaces are required for doing the proper indentation so as the folders and subfolders 
//are properly displayed on the terminal

void printname(Dir D,int numspaces){

    for (int i=0;i<numspaces;i++)
    {
        printf(" ");
    }

    //printf(name of directory);
}



void PrintDir(Dir D,int numspaces)
{

    printname(D, numspaces);

    Ptrnode C = D ->Firstchild;
    if (IsDir(D))
    {
        while (C != NULL)
        {
            PrintDir(D,numspaces+1);
            C= D ->Sibling;
        }


    }
}

// user interface function

void Printdirectory(Dir D){
    PrintDir(D , 0);

}


GetdirTotalsize(Dir D)
{
    if (IsDir(D))
    {
        int ds=0;
        Ptrnode C = D->Firstchild;
        while (C!=NULL)
        {
            ds+=GetdirTotalsize(C);
            C=C->Sibling;

        }

        ds += GetDirsize(D);
    }
        else  
        ds += Getfilesize(D);

        return ds;

    }



int main(){

    Dir D;

}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stland *land;
typedef land *Lol;
int flag = 0;
struct stland
{
    bool isfield;
    int edgesurr;
    // land pnext;
};

Lol MakeLand(int n, int m)
{
    land *L;
    L = (land *)malloc(sizeof(land) * n);

    for (int i = 0; i < n; i++)
    {
        L[i] = (land)malloc(sizeof(struct stland) * m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            L[i][j].isfield = false;
            // L[i][j].pnext=NULL;
            L[i][j].edgesurr = 4;
        }
    }

    return L;
}

void calculatperi(Lol L, int num_rows, int num_cols)
{

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {

            if (i - 1 >= 0 && L[i - 1][j].isfield == true)
            {
                L[i][j].edgesurr--;
            }

            if (i + 1 < num_rows && L[i + 1][j].isfield == true)
            {
                L[i][j].edgesurr--;
            }

            if (j - 1 >= 0 && L[i][j - 1].isfield == true)
            {
                L[i][j].edgesurr--;
            }

            if (j + 1 < num_cols && L[i][j + 1].isfield == true)
            {
                L[i][j].edgesurr--;
            }
        }
    }
}
// CALCULATE EDGES OF ALL NODES

void DFS_visit(Lol L, int r, int c, int **visitarray, int *peri, int *area, int num_rows, int num_cols)
{
    int x = r;
    int y = c;
    visitarray[x][y] = 1;
    *area += 1;
    *peri += L[x][y].edgesurr;
    if (x - 1 >= 0 && visitarray[x - 1][y] == 0 && L[x - 1][y].isfield == true)
    {
        DFS_visit(L, x - 1, y, visitarray, peri, area, num_rows, num_cols);
        // *area += 1;
        // printf("(%d, %d):-ka peri %d\n",x,y,L[x][y].edgesurr);
        // *peri += L[x][y].edgesurr;
    }

    if (x + 1 < num_rows && visitarray[x + 1][y] == 0 && L[x + 1][y].isfield == true)
    {
        DFS_visit(L, x + 1, y, visitarray, peri, area, num_rows, num_cols);
        // *area += 1;
        // printf("(%d, %d):-ka peri %d\n",x,y,L[x][y].edgesurr);
        // *peri += L[x][y].edgesurr;
    }

    if (y - 1 >= 0 && visitarray[x][y - 1] == 0 && L[x][y - 1].isfield == true)
    {
        DFS_visit(L, x, y - 1, visitarray, peri, area, num_rows, num_cols);
        // *area += 1;
        // printf("(%d, %d):-ka peri %d\n",x,y,L[x][y].edgesurr);
        // *peri += L[x][y].edgesurr;
    }

    if (y + 1 < num_cols && visitarray[x][y + 1] == 0 && L[x][y + 1].isfield == true)
    {
        DFS_visit(L, x, y + 1, visitarray, peri, area, num_rows, num_cols);
        // *area += 1;
        // printf("(%d, %d):-ka peri %d\n",x,y,L[x][y].edgesurr);
        // *peri += L[x][y].edgesurr;
    }

    // printf("(%d,%d ):%d %d\n", r, c, *peri, *area);
    return;
}

int DFS(Lol G, int num_rows, int num_cols)
{
    int cost = 0;

    int count = 0;
    int v;
    int nodes = num_rows * num_cols;
    Lol temp;

    int **visitarray = (int **)malloc(sizeof(int *) * num_rows);

    for (int i = 0; i < num_rows; i++)
    {
        visitarray[i] = (int *)malloc(sizeof(int) * num_cols);
    }

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            visitarray[i][j] = 0;
        }
    }

    int trackcost = 0;

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            int peri = 0;
            int area = 0;
            if (G[i][j].isfield == true && visitarray[i][j] == 0)
            {
                DFS_visit(G, i, j, visitarray, &peri, &area, num_rows, num_cols);
                // printf("area :%d\n", area);
                // printf("perimeter: %d\n", peri);

                int newcost = 4 * area - peri;
                // printf("%d\n",newcost);

                // printf("\n");

                if (newcost > cost)
                    cost = newcost;
            }
        }
    }

    return cost;
}

int main()
{
    int num_fields;
    int num_rows;
    int num_cols;

    scanf("%d", &num_rows);
    scanf("%d", &num_cols);
    scanf("%d", &num_fields);

    Lol L;
    L = MakeLand(num_rows, num_cols);

    int r;
    int c;

    for (int t = 0; t < num_fields; t++)
    {

        scanf("%d %d", &r, &c);
        r = r - 1;
        c = c - 1;
        L[r][c].isfield = true;
    }

    // printf("adjmatrix formed\n");
    calculatperi(L,num_rows,num_cols);

    int maxper;
    maxper = DFS(L, num_rows, num_cols);
    // printf("dfs done\n");

    printf("%d\n", maxper);
}

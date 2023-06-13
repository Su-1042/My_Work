#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define INFINITY 1000001

typedef struct node *Node;
typedef Node *Queue;
typedef struct stfloor *floor;
typedef floor *Building;
typedef struct storecoords coord;
Node rear = NULL;
Node head = NULL;

struct storecoords
{
    int x;
    int y;
};

struct stfloor
{
    int min_lifts_used;
    int height;
    int visitedflag;
};

Building CreateBuilding(int r, int c)
{
    floor *R;
    R = (floor *)malloc(sizeof(floor) * r);

    for (int i = 0; i < r; i++)
    {
        R[i] = (floor)malloc(sizeof(struct stfloor) * c);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                R[i][j].height = 0;
                R[i][j].min_lifts_used = 0;
                R[i][j].visitedflag = 0;
            }

            else
            {
                R[i][j].height = 0;
                R[i][j].min_lifts_used = INFINITY;
                R[i][j].visitedflag = 0;
            }
        }
    }

    return R;
}

int MinFloors(Building B, int r, int c)
{
    int total = 0;
    struct storecoords frontka[10 * (r * c)];
    struct storecoords endka[10* (r * c)];
    int currow = 0;
    int curcol = 0;
    B[currow][curcol].visitedflag = 1;
    frontka[0].x = 0;
    frontka[0].y = 0;
    frontka[1].x = -1;
    frontka[1].y = -1;
    int trackfrontextract = 0;
    int trackendextract = 0;
    total++;

    int trackfrontinsert = 1;
    int trackendinsert = 0;

    while (total != 0)
    {
        if (frontka[trackfrontextract].x == -1 && frontka[trackfrontextract].y == -1)
        {
            currow = endka[trackendextract].x;
            curcol = endka[trackendextract].y;
            total--;
            B[currow][curcol].visitedflag = 2;
            trackendextract++;
        }

        else
        {
            currow = frontka[trackfrontextract].x;
            curcol = frontka[trackfrontextract].y;
            total--;
            B[currow][curcol].visitedflag = 2;
            trackfrontextract++;
        }
        // printf("current process %d %d\n", currow, curcol);

        B[currow][curcol].visitedflag = 2;

        // printf("hello\n");

        if ((currow - 1) >= 0)
        {
            if (B[currow - 1][curcol].visitedflag == 0)
            {
                B[currow - 1][curcol].visitedflag = 1;
                if (B[currow - 1][curcol].height == B[currow][curcol].height)
                {
                    frontka[trackfrontinsert].x = currow - 1;
                    frontka[trackfrontinsert].y = curcol;
                    frontka[trackfrontinsert + 1].x = -1;
                    frontka[trackfrontinsert + 1].y = -1;
                    trackfrontinsert++;
                    B[currow - 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used;
                    // printf("updated %d %d from %d %d\n", currow - 1, curcol, currow, curcol);
                    total++;
                }

                else
                {
                    endka[trackendinsert].x = currow - 1;
                    endka[trackendinsert].y = curcol;
                    trackendinsert++;
                    B[currow - 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                    // printf("updated %d %d from %d %d\n", currow - 1, curcol, currow, curcol);

                    total++;
                }
            }

            else if (B[currow - 1][curcol].visitedflag != 0)
            {
                if (B[currow - 1][curcol].height == B[currow][curcol].height)
                {
                    if (B[currow - 1][curcol].min_lifts_used > B[currow][curcol].min_lifts_used)
                    {
                        B[currow - 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used;
                        frontka[trackfrontinsert].x = currow - 1;
                        frontka[trackfrontinsert].y = curcol;
                        frontka[trackfrontinsert + 1].x = -1;
                        frontka[trackfrontinsert + 1].y = -1;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow - 1, curcol, currow, curcol);
                        trackfrontinsert++;
                    }

                    // total--;
                }
                else
                {
                    if (B[currow - 1][curcol].min_lifts_used > B[currow][curcol].min_lifts_used + 1)
                    {

                        B[currow - 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                        endka[trackendinsert].x = currow - 1;
                        endka[trackendinsert].y = curcol;
                        trackendinsert++;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow - 1, curcol, currow, curcol);
                    }
                }
            }
        }

        if ((curcol - 1) >= 0)
        {
            if (B[currow][curcol - 1].visitedflag == 0)
            {
                B[currow][curcol - 1].visitedflag = 1;
                if (B[currow][curcol - 1].height == B[currow][curcol].height)
                {
                    frontka[trackfrontinsert].x = currow;
                    frontka[trackfrontinsert].y = curcol - 1;
                    frontka[trackfrontinsert + 1].x = -1;
                    frontka[trackfrontinsert + 1].y = -1;
                    trackfrontinsert++;
                    // printf("updated %d %d from %d %d\n", currow, curcol - 1, currow, curcol);
                    total++;
                    B[currow][curcol - 1].min_lifts_used = B[currow][curcol].min_lifts_used;
                }

                else
                {
                    endka[trackendinsert].x = currow;
                    endka[trackendinsert].y = curcol - 1;
                    trackendinsert++;
                    B[currow][curcol - 1].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                    total++;
                    // printf("updated %d %d from %d %d\n", currow, curcol - 1, currow, curcol);
                }
            }

            else if (B[currow][curcol - 1].visitedflag != 0)
            {

                if (B[currow][curcol - 1].height == B[currow][curcol].height)
                {
                    if (B[currow][curcol - 1].min_lifts_used > B[currow][curcol].min_lifts_used)
                    {
                        B[currow][curcol - 1].min_lifts_used = B[currow][curcol].min_lifts_used;

                        frontka[trackfrontinsert].x = currow;
                        frontka[trackfrontinsert].y = curcol - 1;
                        frontka[trackfrontinsert + 1].x = -1;
                        frontka[trackfrontinsert + 1].y = -1;
                        trackfrontinsert++;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow, curcol - 1, currow, curcol);
                    }
                }

                else
                {
                    if (B[currow][curcol - 1].min_lifts_used > B[currow][curcol].min_lifts_used + 1)
                    {
                        B[currow][curcol - 1].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                        endka[trackendinsert].x = currow;
                        endka[trackendinsert].y = curcol - 1;
                        trackendinsert++;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow, curcol - 1, currow, curcol);
                    }
                    // total--;
                }
            }
        }

        if ((currow + 1) < r)
        {
            if (B[currow + 1][curcol].visitedflag == 0)
            {
                B[currow + 1][curcol].visitedflag = 1;

                if (B[currow + 1][curcol].height == B[currow][curcol].height)
                {
                    frontka[trackfrontinsert].x = currow + 1;
                    frontka[trackfrontinsert].y = curcol;
                    frontka[trackfrontinsert + 1].x = -1;
                    frontka[trackfrontinsert + 1].y = -1;
                    trackfrontinsert++;
                    total++;
                    B[currow + 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used;
                    // printf("updated %d %d from %d %d\n", currow + 1, curcol, currow, curcol);
                }

                else
                {
                    if (B[currow + 1][curcol].min_lifts_used > B[currow][curcol].min_lifts_used + 1)
                    {
                        endka[trackendinsert].x = currow + 1;
                        endka[trackendinsert].y = curcol;
                        trackendinsert++;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow + 1, curcol, currow, curcol);

                        B[currow + 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                    }
                }
            }

            else if (B[currow + 1][curcol].visitedflag != 0)
            {

                if (B[currow + 1][curcol].height == B[currow][curcol].height)
                {
                    if (B[currow + 1][curcol].min_lifts_used > B[currow][curcol].min_lifts_used)
                    {

                        B[currow + 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used;
                        // printf("updated %d %d from %d %d\n", currow + 1, curcol, currow, curcol);

                        frontka[trackfrontinsert].x = currow + 1;
                        frontka[trackfrontinsert].y = curcol;
                        frontka[trackfrontinsert + 1].x = -1;
                        frontka[trackfrontinsert + 1].y = -1;
                        total++;
                        trackfrontinsert++;
                    }
                }
                else
                {
                    if (B[currow + 1][curcol].min_lifts_used > B[currow][curcol].min_lifts_used + 1)
                    {
                        B[currow + 1][curcol].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                        endka[trackendinsert].x = currow + 1;
                        endka[trackendinsert].y = curcol;
                        trackendinsert++;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow + 1, curcol, currow, curcol);
                    }
                }
                // total--;
            }
        }

        if ((curcol + 1) < c)
        {
            if (B[currow][curcol + 1].visitedflag == 0)
            {
                B[currow][curcol + 1].visitedflag = 1;
                if (B[currow][curcol + 1].height == B[currow][curcol].height)
                {
                    frontka[trackfrontinsert].x = currow;
                    frontka[trackfrontinsert].y = curcol + 1;
                    frontka[trackfrontinsert + 1].x = -1;
                    frontka[trackfrontinsert + 1].y = -1;
                    trackfrontinsert++;
                    total++;
                    // printf("updated %d %d from %d %d\n", currow, curcol + 1, currow, curcol);

                    B[currow][curcol + 1].min_lifts_used = B[currow][curcol].min_lifts_used;
                }

                else
                {
                    endka[trackendinsert].x = currow;
                    endka[trackendinsert].y = curcol + 1;
                    trackendinsert++;
                    total++;
                    // printf("updated %d %d from %d %d\n", currow, curcol + 1, currow, curcol);

                    B[currow][curcol + 1].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                }
            }

            else if (B[currow][curcol + 1].visitedflag != 0)
            {

                if (B[currow][curcol + 1].height == B[currow][curcol].height)
                {
                    if (B[currow][curcol + 1].min_lifts_used > B[currow][curcol].min_lifts_used)
                    {
                        B[currow][curcol + 1].min_lifts_used = B[currow][curcol].min_lifts_used;
                        frontka[trackfrontinsert].x = currow;
                        frontka[trackfrontinsert].y = curcol + 1;
                        frontka[trackfrontinsert + 1].x = -1;
                        frontka[trackfrontinsert + 1].y = -1;
                        trackfrontinsert++;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow, curcol + 1, currow, curcol);
                    }
                }
                else
                {
                    if (B[currow][curcol + 1].min_lifts_used > B[currow][curcol].min_lifts_used + 1)
                    {

                        B[currow][curcol + 1].min_lifts_used = B[currow][curcol].min_lifts_used + 1;
                        endka[trackendinsert].x = currow;
                        endka[trackendinsert].y = curcol + 1;
                        trackendinsert++;
                        total++;
                        // printf("updated %d %d from %d %d\n", currow, curcol + 1, currow, curcol);
                    }
                }
                // total--;
            }
        }

        // free(Q);
    }
    return B[r - 1][c - 1].min_lifts_used;
}

void DestroyBuilding(Building B, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(B[i]);
    }

    free(B);
}

int main()
{
    int num_testcases;
    int num_rows;
    int num_cols;

    scanf("%d", &num_testcases);

    for (int t = 0; t < num_testcases; t++)
    {
        scanf("%d", &num_rows);
        scanf("%d", &num_cols);
        Building B;
        B = CreateBuilding(num_rows, num_cols);

        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                scanf("%d", &B[i][j].height);
            }
        }

        int ans;
        ans = MinFloors(B, num_rows, num_cols);

        printf("%d\n", ans);

        // printf("\n");
        // for (int i = 0; i < num_rows; i++)
        // {
        //     for (int j = 0; j < num_cols; j++)
        //     {
        //         printf("%d ", B[i][j].min_lifts_used);
        //     }
        //     printf("\n");
        // }

        // DestroyBuilding(B, num_rows);
    }
}


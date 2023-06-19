#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX 2e8

typedef struct stbrick *brick;
typedef struct storecoords coord;

typedef struct stHeap *Heap;
struct stHeap
{
    int current;
    int capacity;
    brick elements;
};

struct storecoords
{
    int x;
    int y;
};

struct stbrick
{
    bool brick_visited;
    coord data;
    int cost;
    int currentmincost;
};

Heap CreateHeap(int cap)
{
    Heap H;
    H = (Heap)malloc(sizeof(struct stHeap));
    H->capacity = 15 * cap;
    H->elements = (brick)malloc(sizeof(struct stbrick) * 15 * (cap));
    H->current = 0;
    H->elements[0].currentmincost = -999999;
    H->elements[0].data.x = -999999;
    H->elements[0].data.y = -999999;
    return H;
}

void swap(brick *a, brick *b)
{
    brick temp = *a;
    *a = *b;
    *b = temp;
}

// the heap is having zero indexing and hence the left child will be at 2i+1 sand the right child will bve at 2i+2
int IsFull(Heap H)
{
    return (H->current == H->capacity);
}

int IsEmpty(Heap H)
{
    return (H->current == 0);
}

void InsertHeap(Heap H, struct stbrick x)
{
    int i;
    if (IsFull(H))
    {
        assert(NULL);
        return;
    }

    for (i = ++H->current; H->elements[i / 2].currentmincost >= x.currentmincost; i = i / 2)
    {
        H->elements[i] = H->elements[i / 2];
    }

    H->elements[i] = x;
    return;
}

struct stbrick MinEle(Heap H)
{
    int i, child;
    // for (int i=0;i<H->current;i++)
    // {
    //     printf("%d ",H->elements[i].currentmincost);
    // }
    // printf("\n");
    struct stbrick minelement, last;
    minelement = H->elements[1];
    last = H->elements[H->current];
    H->current--;
    for (i = 1; 2 * i <= H->current; i = child)
    {
        child = 2 * i;

        if ((child != H->current) && (H->elements[child + 1].currentmincost < H->elements[child].currentmincost))
        {
            child++;
        }

        if (last.currentmincost > H->elements[child].currentmincost)
        {
            H->elements[i] = H->elements[child];
        }
        else
            break;
    }

    H->elements[i] = last;
    return minelement;
}

brick *MakeCity(int num_rows, int num_cols)
{
    brick *City;

    City = (brick *)malloc(sizeof(brick *) * num_rows);

    for (int i = 0; i < num_rows; i++)
    {
        City[i] = (brick)malloc(sizeof(struct stbrick) * num_cols);
    }

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            City[i][j].brick_visited = false;
            City[i][j].currentmincost = MAX;
        }
    }
    return City;
}

int FindMinCost_from_HomeBase(brick *City, int num_rows, int num_cols, Heap H)
{

    while (!IsEmpty(H))
    {
        struct stbrick temp;
        temp = MinEle(H);
        int currow = temp.data.x;
        int curcol = temp.data.y;

        // for (int i = 0; i < num_rows; i++)
        // {
        //     for (int j = 0; j < num_cols; j++)
        //         printf("%d ", City[i][j].brick_visited);
        //     printf("\n");
        // }
        // printf("\n");

        if (City[currow][curcol].brick_visited == true)
        {
            continue;
        }
        City[currow][curcol].brick_visited = true;

        if ((currow - 1) >= 0)
        {
            if (City[currow - 1][curcol].brick_visited == false)
            {

                if (City[currow - 1][curcol].currentmincost > City[currow][curcol].currentmincost + City[currow - 1][curcol].cost)
                {
                    City[currow - 1][curcol].currentmincost = City[currow][curcol].currentmincost + City[currow - 1][curcol].cost;
                    InsertHeap(H, City[currow - 1][curcol]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }

        if ((curcol + 1) < num_cols)
        {
            if (City[currow][curcol + 1].brick_visited == false)
            {
                if (City[currow][curcol + 1].currentmincost > City[currow][curcol].currentmincost + City[currow][curcol + 1].cost)
                {
                    City[currow][curcol + 1].currentmincost = City[currow][curcol].currentmincost + City[currow][curcol + 1].cost;
                    InsertHeap(H, City[currow][curcol + 1]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }

        if ((currow + 1) < num_rows)
        {
            if (City[currow + 1][curcol].brick_visited == false)
            {

                if (City[currow + 1][curcol].currentmincost > City[currow][curcol].currentmincost + City[currow + 1][curcol].cost)
                {
                    City[currow + 1][curcol].currentmincost = City[currow][curcol].currentmincost + City[currow + 1][curcol].cost;
                    InsertHeap(H, City[currow + 1][curcol]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }
        if ((curcol - 1) >= 0)
        {
            if (City[currow][curcol - 1].brick_visited == false)
            {

                if (City[currow][curcol - 1].currentmincost > City[currow][curcol].currentmincost + City[currow][curcol - 1].cost)
                {
                    City[currow][curcol - 1].currentmincost = City[currow][curcol].currentmincost + City[currow][curcol - 1].cost;
                    InsertHeap(H, City[currow][curcol - 1]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }

        if ((curcol - 1) >= 0 && (currow - 1) >= 0)
        {
            if (City[currow - 1][curcol - 1].brick_visited == false)
            {

                if (City[currow - 1][curcol - 1].currentmincost > City[currow][curcol].currentmincost + City[currow - 1][curcol - 1].cost)
                {
                    City[currow - 1][curcol - 1].currentmincost = City[currow][curcol].currentmincost + City[currow - 1][curcol - 1].cost;
                    InsertHeap(H, City[currow - 1][curcol - 1]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }

        if ((curcol + 1) < num_cols && (currow - 1) >= 0)
        {
            if (City[currow - 1][curcol + 1].brick_visited == false)
            {
                if (City[currow - 1][curcol + 1].currentmincost > City[currow][curcol].currentmincost + City[currow - 1][curcol + 1].cost)
                {
                    City[currow - 1][curcol + 1].currentmincost = City[currow][curcol].currentmincost + City[currow - 1][curcol + 1].cost;
                    InsertHeap(H, City[currow - 1][curcol + 1]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }

        if ((curcol + 1) < num_cols && (currow + 1) < num_rows)
        {
            if (City[currow + 1][curcol + 1].brick_visited == false)
            {
                if (City[currow + 1][curcol + 1].currentmincost > City[currow][curcol].currentmincost + City[currow + 1][curcol + 1].cost)
                {
                    City[currow + 1][curcol + 1].currentmincost = City[currow][curcol].currentmincost + City[currow + 1][curcol + 1].cost;
                    InsertHeap(H, City[currow + 1][curcol + 1]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }

        if ((curcol - 1) >= 0 && (currow + 1) < num_rows)
        {
            if (City[currow + 1][curcol - 1].brick_visited == false)
            {
                if (City[currow + 1][curcol - 1].currentmincost > City[currow][curcol].currentmincost + City[currow + 1][curcol - 1].cost)
                {
                    City[currow + 1][curcol - 1].currentmincost = City[currow][curcol].currentmincost + City[currow + 1][curcol - 1].cost;
                    InsertHeap(H, City[currow + 1][curcol - 1]);
                    // City[currow][curcol].brick_visited = true;
                }
            }
        }
    }

    int mincost = 1000000;
    for (int i = 0; i < num_rows; i++)
    {
        if (City[i][num_cols - 1].currentmincost < mincost)
        {
            mincost = City[i][num_cols - 1].currentmincost;
        }
    }

    for (int i = 0; i < num_cols; i++)
    {
        if (City[0][i].currentmincost < mincost)
        {
            mincost = City[0][i].currentmincost;
        }
    }

    return mincost;
}

int main()
{
    int testcases;
    scanf("%d", &testcases);

    for (int k = 0; k < testcases; k++)
    {

        int num_rows;
        int num_cols;

        scanf("%d %d", &num_rows, &num_cols);

        brick *City;
        City = MakeCity(num_rows, num_cols);

        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                scanf("%d", &City[i][j].cost);
                City[i][j].data.x = i;
                City[i][j].data.y = j;
            }
        }

        // City[0][0].currentmincost = City[0][0].cost;
        // City[num_rows - 1][num_cols - 1].currentmincost = City[num_rows - 1][num_cols - 1].cost;
        // City[num_rows - 1][num_cols - 1].brick_visited = true;
        // City[0][0].brick_visited = true;

        Heap H;
        H = CreateHeap((num_rows * num_cols));

        for (int i = 0; i < num_rows - 1; i++)
        {
            City[i][0].currentmincost = City[i][0].cost;
            InsertHeap(H, City[i][0]);
            // City[i][0].brick_visited = false;
        }

        for (int i = 0; i < num_cols; i++)
        {
            City[num_rows - 1][i].currentmincost = City[num_rows - 1][i].cost;
            InsertHeap(H, City[num_rows - 1][i]);
            //  City[num_rows - 1][i].brick_visited = true;
        }

        int mincost;
        mincost = FindMinCost_from_HomeBase(City, num_rows, num_cols, H);

        // for (int i = 0; i < num_rows; i++)
        // {
        //     for (int j = 0; j < num_cols; j++)
        //         printf("%d ", City[i][j].cost);
        //     printf("\n");
        // }
        // printf("\n");

        // for (int i = 0; i < num_rows; i++)
        // {
        //     for (int j = 0; j < num_cols; j++)
        //         printf("%d ", City[i][j].currentmincost);
        //     printf("\n");
        // }
        // printf("\n");

        printf("%d\n", mincost);
    }
}

/*

3 10
91 69 71 54 85 91 11 65 43 98
53 6 53 89 84 35 44 97 61 4
38 50 5 23 75 40 53 88 15 93

*/
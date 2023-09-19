#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

bool yut[4]; // true: front, false: back;

struct player {
    int pos;
};

player p1, p2;

void move(int p_num, int pos_i, int num)
{
    int road_num = 0;
    
    if (pos_i == 11 || pos_i == 201 || pos_i == 202 || pos_i == 203 || pos_i == 204 || pos_i == 205)
        road_num = 2;
    
    else if (pos_i == 6 || pos_i == 101 || pos_i == 102 || pos_i == 103 || pos_i == 104)
        road_num = 1;
}

int throw_yut(int p_num)
{
    int tmp, i;
    srand (time(NULL));
    
    for (i = 0; i < 4; i++)
    {
        tmp = rand() % 2;
        
        if (tmp % 2 == 0)
            yut[i] = true;
        else
            yut[i] = false;
    }
    
    int b_cnt = 0;
    for (i = 0; i < 4; i++)
    {
        if (yut[i])
            printf("F ");
           
        else
        {
            printf("B ");
            b_cnt++;
        }
    }
    
    printf("\n");
    
    switch(b_cnt)
    {
        case 0:
            printf("모(Mo)");
            break;
        case 1:
            printf("도(Do)");
            break;
        case 2:
            printf("개(Gae)");
            break;
        case 3:
            printf("걸(Gul)");
            break;
        case 4:
            printf("윷(Yut)");
            break;
        default:
            printf("error");
            break;
    }
    
    return 0;
}

int main() {
    p1.pos = 0;
    p2.pos = 0;
    throw_yut(1);
}

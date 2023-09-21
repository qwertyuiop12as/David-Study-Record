#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

bool yut[4]; // true: front, false: back;

struct player {
    int pos;
};

player p[2];
bool token;

bool check_win(int pos_f)
{
    if (pos_f > 21 && pos_f < 100)
        return true;
    else
        return false;
}

void move(int p_num, int pos_i, int num)
{
    int road_num = 0, pos_f;
    
    if (pos_i == 11 || pos_i == 201 || pos_i == 202 || pos_i == 203 || pos_i == 204 || pos_i == 205)
        road_num = 2;
    
    else if (pos_i == 6 || pos_i == 101 || pos_i == 102 || pos_i == 103 || pos_i == 104 || pos_i == 105)
        road_num = 1;
        
    if (road_num == 0)
    {
        pos_f = pos_i + num;
    }
    
    else if (road_num == 1)
    {
        if (pos_i == 6)
        {
            if (num == 3)
                pos_f = 203;
            else
                pos_f = 100 + num;
        }

        else if ((pos_i + num) == 103)
            pos_f = 203;
            
        else if ((pos_i + num) > 105)
            pos_f = (pos_i + num - 105 + 15);
            
        else
            pos_f = pos_i + num;
    }
    
    else if (road_num == 2)
    {
        if (pos_i == 11)
            pos_f = 200 + num;

        if (pos_i + num > 205)
            pos_f = (pos_i + num - 205 + 20);
            
        else
            pos_f = pos_i + num;
    }
    
    p[p_num].pos = pos_f;
}

void throw_yut(int p_num)
{
    int tmp, i;
    
    // Throw 4 individual yuts
    
    // Use random function to decide "Front (F)" or "Back (B)"
    for (i = 0; i < 4; i++)
    {
        tmp = (rand() % 2);
        
        if (tmp % 2 == 0)
            yut[i] = true;
        else
            yut[i] = false;
    }
    
    // Print the result of each yut
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
    
    // Based on number of front and back, decide the outcome as Do, Gae, Gul, Yut, or Mo.
    switch(b_cnt)
    {
        case 0:
            printf("모(Mo)\n");
            move(p_num, p[p_num].pos, 5);
            printf("p%d: %d\n", p_num+1, p[p_num].pos);
            break;
        case 1:
            printf("도(Do)\n");
            move(p_num, p[p_num].pos, 1);
            printf("p%d: %d\n", p_num+1, p[p_num].pos);
            break;
        case 2:
            printf("개(Gae)\n");
            move(p_num, p[p_num].pos, 2);
            printf("p%d: %d\n", p_num+1, p[p_num].pos);
            break;
        case 3:
            printf("걸(Gul)\n");
            move(p_num, p[p_num].pos, 3);
            printf("p%d: %d\n", p_num+1, p[p_num].pos);
            break;
        case 4:
            printf("윷(Yut)\n");
            move(p_num, p[p_num].pos, 4);
            printf("p%d: %d\n", p_num+1, p[p_num].pos);
            break;
        default:
            printf("error");
            break;
    }
    
    printf("\n-----*----\n\n");

    if (check_win(p[p_num].pos))
    {
        token = false;
    }
    return;
}

int main() {
    token = true;
    srand (time(NULL));
    p[0].pos = 0;
    p[1].pos = 0;
    
    int cur_p = 0;

    while (token)
    {
        throw_yut(cur_p);
        cur_p = 1 - cur_p;
    }

}

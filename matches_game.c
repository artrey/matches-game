#include <stdio.h>

int mini(int a, int b)
{
    return a > b ? b : a;
}

void print_matches(int r)
{
    printf("[%3d] ", r);
    for (int i = 0; i < r; ++i)
    {
        printf("|");
    }
    printf("\n");
}

int check_input(int min, int max)
{
    int x;
    do
    {
        scanf("%d", &x);
        if (x < min || x > max)
        {
            printf("Incorrect, try again (from %d to %d): ", min, max);
        }
    } while (x < min || x > max);
    return x;
}

int human_turn(int player, int p)
{
    return check_input(1, p);
}

int virtual_turn(int p, int r)
{
    if (r <= p)
    {
        return r;
    }
  
    switch (r % p)
    {
        case 0: return p - 1;
        case 1: return 1;
        default: return r % p - 1; 
    }
}

int turn(int player, int p, int r)
{
    printf("Player %d: ", player);
    if (player == 1)
    {
        return human_turn(player, mini(p, r));
    }
    else
    {
        int count = virtual_turn(p, r);
        printf("%d\n", count);
        return count;
    }
}

void game(int matches_count, int max_extract, int players_count)
{
    int player = 0;

    while (matches_count > 0)
    {
        print_matches(matches_count);
        player++;
        if (player > players_count)
        {
            player = 1;
        }
        matches_count -= turn(player, max_extract, matches_count);
    }

    printf("Winner is player %d\n", player);
}

int main(int argc, char** argv)
{
    printf("Input count of matches: ");
    int matches_count = check_input(10, 999);
    
    printf("Input count of maximum extracted matches: ");
    int max_extract = check_input(2, matches_count / 2);
    
    printf("Input count of players: ");
    int players_count = check_input(2, matches_count - 1);
    
    game(matches_count, max_extract, players_count);
    return 0;
}

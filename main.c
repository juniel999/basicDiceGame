#include <stdio.h>
#include <time.h>

void prizePool(int *prize, int arr[], int *prizeCheck);
void printing(int arr[]);
void assignVal(int arr[]);

int main()
{
    int dice[6];
    int prize = 8;
    int prizeCheck[] = {1,1,1,1,1,1,1,1};
    char name[20];
    int x, choice;

    do
    {
        printf("\nEnter player name: ");
        scanf(" %s", &name);
        printf("[1] to roll the dice!\n");
        assignVal(dice);
        printf("\nAll dices of %s are: ", name);
        printing(dice);
        prizePool(&prize,dice,&prizeCheck);

        if(prize !=0)
            printf("\nThere is/are %d prize(s) left!\nNext player's turn!\n", prize);

    }while (prize != 0);

    return 0;
}

//printing the obtained random values
void printing(int arr[])
{
    int x;

    for(x=0; x<6; x++)
    {
        printf("%d ", arr[x]);
    }
}

// giving values to the dice
void assignVal(int arr[])
{
    int x;
    int choice;

    for(x=0; x<6; x++)
    {
        scanf(" %d", &choice);

        if( choice == 1)
        {
            srand(time(NULL));
            arr[x] = rand() %6 +1;
            printf("Dice result : %d\n", arr[x]);
        }
    }
}

//function to know what prize the player gets
void prizePool(int *prize, int arr[], int *prizeCheck)
{
    int x;

    int count[6] = {0};

    for(x=0; x<6; x++)
    {
        if(arr[x]==1)
            count[0]++;
        else if(arr[x] == 2)
            count[1]++;
        else if(arr[x]== 3)
            count[2]++;
        else if(arr[x]== 4)
            count[3]++;
        else if(arr[x]==5)
            count[4]++;
        else if(arr[x] ==6)
            count[5]++;
    }

    if(count[0] == 6 || count[1]==6 || count[2]==6 || count[3]==6 || count[4]==6 || count[5]==6)
    {
        printf("\nCongratulations! This is Embargo and you can get all the remaining prizes!\n");
        *prize -= *prize;
    }
    else if(count[0] == 5 || count[1] == 5 || count[2] == 5 || count[3] == 5 || count[4] == 5 || count[5] == 5)
    {
        if(prizeCheck[6] == 1)
        {
            printf("\nCongratulations! This is Ngo-Tsi Tai <Kicker>!\nYou got the 1st Prize - Level 1!\n");
            *prize -= 1;
            prizeCheck[6]-= 1;
        }
        else
        {
            printf("\nThis is Ngo-Tsi Tai <Kicker>. But someone got the prize :<");
        }
    }
    else if(count[0]==1 && count[1]==1 && count[2]==1 && count[3]==1 && count[4]==1 && count[5]==1)
    {
        if(prizeCheck[4] == 1)
        {
            printf("\nCongratulations! This is Tui-Teng!\nYou got the 2nd prize!\n");
            *prize -= 1;
            prizeCheck[4] -= 1;
        }
        else
        {
            printf("\nThis is Ngo-Tsi Tui-Teng. But someone got the prize :<");
        }
    }
    else if(count[0] == 4 || count[1] == 4 || count[2] == 4 || count[3] == 4 || count[4] == 4 || count[5] == 4)
    {
        if(prizeCheck[5] == 1)
        {
            printf("\nCongratulations! This is Tsiong-Wan Tai <Kicker>!\nYou got the 1st Prize - Level 2!\n");
            *prize -= 1;
            prizeCheck[5] -= 1;
        }
        else
        {
            printf("\nThis is Tsiong-Wan Tai <Kicker>. But someone got the prize :<");
        }
    }
    else if(count[3] ==3)
    {
        if(prizeCheck[3] == 1)
        {
            printf("\nCongratulations! This is Sam-Hong!\nYou got the 3rd Prize!\n");
            *prize -= 1;
            prizeCheck[3] -= 1;
        }
        else
        {
            printf("\nThis is Sam-Hong. But someone got the prize :<");
        }
    }
    else if(count[0] == 4 || count[1] == 4 || count[2] == 4 || count[4] == 4 || count[5] == 4)
    {
        if(prizeCheck[2]==1)
        {
            printf("\nCongratulations! This is Si-Jin!\nYou got the 4th Prize!");
            *prize -= 1;
            prizeCheck[2]-= 1;
        }
        else
        {
            printf("\nThis is Si-Jun. But someone got the prize :<");
        }
    }
    else if(count[3] == 2)
    {
        if(prizeCheck[1] == 1)
        {
            printf("\nCongratulations! This is Di-ku!\nYou got the 5th Prize!\n");
            *prize -= 1;
            prizeCheck[3] -= 1;
        }
        else
        {
            printf("\nThis is Di-ku. But someone got the prize :<");
        }
    }
    else if(count[3]==1)
    {
        if(prizeCheck[0] == 1)
        {
            printf("\nCongratulations! This is It-siu!\nYou got the 6th Prize!\n");
            *prize -= 1;
            prizeCheck[0]-=1;
        }
        else
        {
            printf("\nThis is It-siu. But someone got the prize :<");
        }
    }
    else
    {
        printf("\nYou got no prize! Better luck next time.\n");
    }

}




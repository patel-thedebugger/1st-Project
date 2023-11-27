#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>


#define WORD_LEN_MAX 90

// Challeng given to Player 
char challengeWord[WORD_LEN_MAX];

// User Choice: 
char playerChoiced[WORD_LEN_MAX] = {'\0'} ;
int challengeWordlength = 0;
int choices = 0 ;
int checkthechoice(char a);
int successful_attempt = 0 ;
int Total_attempt = 0 ;
char filledChallenge[WORD_LEN_MAX];
// function prototype 

void insertchoice(char h);
void DrawTitle();
void GetChallenge();
int IsCharAvailable(char ch);
void PrintAcceptedWord();
char GetPlayerInput();
void ScreenToGetChallenge();
void PrintIdleResult();
void PrintFailResult();
void ScreenAfterPlayersInput(char ch );
void ScreenToPopupFail(char ch , int fails);
int isrepeated(char ch);
void rest();



void main()
{

    // clearing the screen
    again:
    system("cls");
    
    char choice = '\0';
    int failed_attempt = 0  ;
    char wish = 'Y';
    

    // gettinng the input of word from the challeger
    DrawTitle();
    ScreenToPopupFail(choice , failed_attempt);
    ScreenToGetChallenge();
    

    

    
        while( failed_attempt <= 8 )
        {

            // clearing the screen
            system("cls");


            // displaying the idle diagram of the structure
            DrawTitle();
            ScreenToPopupFail(choice , failed_attempt);
            
            printf("\n");
            choice = GetPlayerInput();
            if(isrepeated(choice))
            {
                printf("\nThe Entered value is already enter.");
                getch();
                continue;
            }
            
            getch();
            // clearing the screen
            system("cls");
            
            insertchoice(choice);

            
            Total_attempt = Total_attempt + 1;

            printf("\n");
                
            if(Total_attempt !=0)
            {
                DrawTitle();
            }
                
            ScreenToPopupFail(choice , failed_attempt);
            
            

            if (checkthechoice(choice) == 0)
            {
                failed_attempt ++ ;   
            }
            
            

            if(strcmp(filledChallenge,challengeWord) == 0)
            {

                system("cls");
                DrawTitle();
                ScreenToPopupFail(choice , failed_attempt);

                printf("\nCongratulation....Man is alive.");
                break;
            }
             
        }

        printf("\n\nDo you want to play it again : ");
        wish = getch();
        printf("%c", wish);

        if (wish == 'Y' || wish == 'y')
        {
            rest();
            goto again;
        }      
    }

void rest()
{
    playerChoiced[0] = '\0';
    challengeWordlength = 0;
    choices = 0 ;
    //checkthechoice(char a);
    successful_attempt = 0 ;
    Total_attempt = 0 ;
    filledChallenge[0] = '\0';


}


int isrepeated(char ch)
{
    for(int i = 0 ; playerChoiced[i] != '\0';i++)
    {
        if (playerChoiced[i]==ch)
        {
            return 1;
        }
    }
    return 0 ;
}

// checking whether the player choiced word is in the challenge word or not

int checkthechoice(char ch)

{
    int flag = 0 ;
    
    for ( int x = 0 ; challengeWord[x]!= '\0' ; x ++)
    {
        if (ch == challengeWord[x])
        {
            flag = 1 ;
            successful_attempt = successful_attempt + 1 ;
        }
           
    }
    return flag ;
}

// the choiced alaphate will be inserted inside the choiced string

void insertchoice(char ch )
{

     

    for(int i = 0 ; playerChoiced[i] != '\0' || playerChoiced[i] == '\0' ; i++ )
    {
        if (playerChoiced[i] == '\0' )
        {
            playerChoiced[i] = ch;
            playerChoiced[i+1] ='\0';
            break;

        }
    }    
}

// drawing the title of the game 

void DrawTitle()
{
    printf("\n***********************************************************************************");
    printf("\n*                         HANGMAN GAME                                            *");
    printf("\n***********************************************************************************\n");
}

// fetching the word from the challeger  as well as evaluating the length of the word 

void GetChallenge()
{
    // taking the word from challenger
    printf("\nEnter Challenge: ");
    gets(challengeWord);

    // Findiing the length of the challenger's word
    for(int i = 0 ; challengeWord[i] !=0 ; i++ )
    {
        challengeWordlength++;
    }
    
}

// checking whether the character of challenge word  is available or not in the playerchoiced

int IsCharAvailable(char ch)
{
    for(int i=0;playerChoiced[i] != '\0';i++)
    {
        if(playerChoiced[i] == ch)
            return 1;
    }

    return 0;
}

// Function to print the accepted word 

void PrintAcceptedWord()
{

    printf("\n\t\t");
    
    
    int i=0;
    for(i=0;i<challengeWordlength;i++)
    {
        char ch = challengeWord[i];
        if(IsCharAvailable(ch))
        {
            filledChallenge[i] = ch;
        }
        else if (ch ==' ')
        {
            filledChallenge[i] = ch;
        }
        else
            filledChallenge[i] = '_';

    }
    filledChallenge[i] = '\0';
    for(int i = 0 ; filledChallenge[i] != '\0' ; i++)
    {
        printf(" %c ", filledChallenge[i]);
    }
    
    printf("\n");
    /* printf("Enter Challenge: ");
    puts(filledChallenge); */

    
}


char GetPlayerInput()
{

    /* system("cls");
    // GETTING THE INPUT FROM THE PLAYER */

    printf("\n");
    printf("\nEnter Alphabet (CAPITAL ALPHABET ONLY): ");
    char ch = getch();
    printf("%c",ch);


    return ch ;
}

void ScreenToGetChallenge()
{
    /* // clearing the screen
    system("cls"); */

    // displaying the title of the project 


    //fetching the word to be guessed and evaluating the length 
    GetChallenge();


}

void PrintIdleResult()
{
    //clrscrn();

    for ( int i =1 ; i<=challengeWordlength ; i++)
    {
        printf(" _ ");
    }
    
    printf("\t\t ____________________               \n");
    printf("\t\t|                    |              \n");
    printf("\t\t|                    |              \n");                             
    printf("\t\t|                    |              \n");                             
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n"); 
    printf("\t\t|                                   \n"); 
    printf("\t\t|                                   \n"); 
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
    printf("\t\t|                                   \n");
 
}



void PrintFailResult()
{

}

/* void ScreenAfterPlayersInput(char ch )
{
    /* // clearing the screen
    system("cls");

    // displaying the title of the project 
    DrawTitle();
 */
    //PrintAcceptedWord(); 
       

void ScreenToPopupFail(char ch , int fails)
{
    

    // displaying the title of the project         
    
    
    PrintAcceptedWord();
  
        
    //PrintAcceptedWord();

    switch(fails)


    {


    case 0 :

        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        break;



    case 1 :
        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  ^    ^ |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -===-  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        break;

    case 2 :

        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  ^    ^ |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -===-  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        break;


    case 3 :

        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  ^    ^ |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -===-  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                  //               \n");
        printf("\t\t|                 //                \n");
        printf("\t\t|                //                 \n");
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                  \n"); 
        printf("\t\t|                                  \n"); 
        printf("\t\t|                                  \n");
        printf("\t\t|                                  \n");
        printf("\t\t|                                  \n");
        break;

    case 4 :

        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  ^    ^ |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -===-  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                  // \\\\            \n");
        printf("\t\t|                 //   \\\\          \n");
        printf("\t\t|                //     \\\\         \n");
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                  \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        break; 

    case 5 :

        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  ^    ^ |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -===-  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                  //|\\\\            \n");
        printf("\t\t|                 // | \\\\          \n");
        printf("\t\t|                //  |  \\\\          \n");
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n"); 
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        printf("\t\t|                                   \n");
        break;

    case 6 :

        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  ^    ^ |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -===-  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                  //|\\\\            \n");
        printf("\t\t|                 // | \\\\           \n");
        printf("\t\t|                //  |  \\\\          \n");
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                                   \n");
        printf("\t\t|                                  \n");
        printf("\t\t|                                  \n");
        break;

    case 7 :
            printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  ^    ^ |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -===-  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                  //|\\\\           \n");
        printf("\t\t|                 // | \\\\          \n");
        printf("\t\t|                //  |  \\\\          \n");
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                  //               \n");
        printf("\t\t|                 //                \n");
        printf("\t\t|                //                 \n");
        break;

    case 8 :

        printf("\n");
        printf("\t\t ____________________               \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                    |              \n");                             
        printf("\t\t|                ----------         \n");
        printf("\t\t|               |  -    - |         \n");
        printf("\t\t|               |    |    |         \n");
        printf("\t\t|               |  -----  |         \n");
        printf("\t\t|                ---------          \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                    |              \n");
        printf("\t\t|                  //|\\\\            \n");
        printf("\t\t|                 // | \\\\          \n");
        printf("\t\t|                //  |  \\\\          \n");
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                    |              \n"); 
        printf("\t\t|                  // \\\\           \n");
        printf("\t\t|                 //   \\\\          \n");
        printf("\t\t|                //     \\\\         \n");

        printf("\nBad luck!....man is hanged now !!!");
        printf("\nThe Give word was : ");
        for(int i = 0 ; challengeWord[i] != '\0' ; i++)
        {
            printf("%c" , challengeWord[i]);
        }
        break;
    }

    
}

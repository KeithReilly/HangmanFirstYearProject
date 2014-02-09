/*
My assiment of hang-man
Repersenting my flowchart

The layout of the processes is
different to the flowchart 
in order for my loops to work.

names of the varibles have been 
changed as it was to diffecult
to work with the ones I set on 
the flowchart. I also added some 
new features like sleep so my programe
can end without user hitting exit.
and a beep that will sound when the
user gets the word:

Keith Reilly
15/11/2012
*/

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h> // for sleep; eg for exit gracefully:
#include <stdlib.h>
#include <string.h> // in book (page 84)
#include <ctype.h> // in book (page 176)

// define-ing Arrays
#define WORDS 13
#define LETTERS_ENTERED 26


main()
{
    // Varibles being used:
    
    int i; //index
    
    int j; // index for letters entered
    
    int zero = 0; // for user when they want to leave
    
    int wrong; // for incorrect & correct loop
    
    int len; // lenght of word
    
    int loop = 0; // for loops

    int win; // for winning counter
    
    int r; // random number
    
    char wordchosen[WORDS]; // to pick word randomly
    
    char letter; // to store leter entered
    
    char word_len[LETTERS_ENTERED]="_ _ _ _ _ _ _ _ _ _ _ _ _ ";  // to show lenght of words
    
    char letters[LETTERS_ENTERED] = "                          "; // To store letters entered
    
    int lives; //lives
    
    // Words that will be used
    char word1[WORDS] = {'n','e','c','e','s','s','a','r','i','l','y'};
    char word2[WORDS] = {'b','i','s','c','u','i','t'};
    char word3[WORDS] = {'s','o','m','e','t','h','i','n','g'};
    char word4[WORDS] = {'h','a','n','g','m','a','n'};
    char word5[WORDS] = {'h','a','p','p','y'};
    

    while (loop == 0)
    {        
        printf("WELCOME TO HANGMAN\n\n");
        printf("\nAre you sure you want to play?\nEnter 0 to quit game\nOr enter 1 to start\n\n");
        scanf("%d",&zero);
        if (zero == 0)
        {
            return 0;
        }
        
        if (zero == 1)
        {
            loop = 1; // to get to next loop
        }
        
        else if (zero != 1 || zero != 0) 
        {
            printf("\n\nInvalid\n\n");
            Sleep(1500);
        }
        
        // Random number generator
        srand(time(NULL));  
        r = rand() % 5 + 1;
        
        /* Assignee numbers to words
            which will be picked randomly */ 
        
        for (i = 0; i < WORDS; i++)
        {
            if (r == 1)
            {
                wordchosen[i] = word1[i];
            }
                
            if (r == 2)
            {
                wordchosen[i] = word2[i];
            }
                
            if (r == 3)
            {
                wordchosen[i] = word3[i];
            }
            
            if (r == 4)
            {
                wordchosen[i] = word4[i];
            }
                
            if (r == 5)
            {
                wordchosen[i] = word5[i];
            }
            
        }
        
        
        len=strlen(wordchosen); // this will set the lenght the same as the word:
        
        
        // this will use the lenght for the spaces:
        // to create the lenght of word:
        for (i=0; i <len*2; i++)
        {
            word_len[i*2] = '_';
            word_len[(i*2)+1] = ' '; 
        }
        
        for (i=0; i <LETTERS_ENTERED; i++)
        {
            letters[i]=' '; // so loop starts with no letters entered
        }
        
        lives = 6; //setting lives
        j = 0; // setting array index to zero
        win = 0; //setting win back to zero
        
        
        system("cls"); //clear screen
        
        // menu that user see's
        while (loop == 1)
        {
            printf("\nIf you want to quit enter 0\n\n"); // to allow player to quit
            printf("Lives are %d\n\n",lives); //showing lives
            printf("Word is  ");
            
            for (i = 0; i < len*2 ;i++)
            {
                printf("%c",word_len[i]); //showing lenght of the word:
            }
            
            printf("\n\nLetters Entered: ");
            
            for (i = 0; i < LETTERS_ENTERED;i++)
            {
                printf("%c ",letters[i]); // showing letters entered
            }
            
            loop = 2; // to start next loop
            
            while (loop == 2)
            {    
                printf("\n\nPlease guess a letter: ");
                scanf("%1s",&letter); //1s for no white spaces
                flushall();
                
                if (letter == '0') // to quit
                {
                    printf("\nThank you for playing");
                    Sleep(2000);
                    return 0;
                }
                
                
                // to tell what chareter user entered:
                else if (isascii(letter)) // was it a charter
                {
                    if (isalpha(letter)) // was it a letter
                    { 
                        if (isupper(letter)) // was it a upper case
                        {
                            letter = tolower(letter); // to convert into lower letter:
                        }
                    }
                }
                
                for (i=0; i < LETTERS_ENTERED;i++) // if the letter is the same or was already entered
                {
                    if (letter == letters[i])
                    {
                        printf("\n\nletter already entered\nGuess a new letter\n");
                    }
                }
                
                
                if (letter != letters[i]) 
                {
                    loop = 1; //to get back to other loop
                }
                
            } // end while loop 3
            
            
            for (i=0; i < len; i++)
            {
                
                if ( letter == wordchosen[i])
                {
                    word_len[i * 2] =letter; //incase it is word more than once:
                    
                    if (letter != letters[i])
                    {
                        win++;
                    }
                    
                }
               
                else if (letter != wordchosen[i])
                {
                    wrong++;
                }
              
            } // end for loop:
            
            
            if ( letters[j] != letter)
            {
                if (islower (letter)) // to only add lower case letters
                {
                    letters[j] = letter; // storeing letter/s entered
                    j++; // add one eg next space in memory of array.
                }
            }
            
            if (wrong == len) //meaning no right letters are entered:
            {
                lives--;
                printf("\n\nIncorrect\n\n");
                getchar();
            }
            
            else if (wrong != len) //meaning a right letter was entered:
            {
                printf("\n\nCorrect\n\n");
                getchar();
            }
            
            if (win == len)
            {
                printf("The word was "); // showing user the right word :
                for (i = 0; i < len*2 ;i++)
                {  
                    printf("%c",word_len[i]);
                }
                
                printf("\n\n\aYou won\n\nDo you want to play again Y / N\n\n");
                loop = 2;
            }
            
            if (lives  <1 )
            {
                printf("\n\nYou lost\n\nDo you want to play again Y / N\n\n");
                loop = 2;
            }
            
            while (loop == 2)
            {
                scanf("%c",&letter); // user gives answer y / n
                flushall();
                
                if (letter == 'Y' || letter == 'y')
                {
                    loop = 0;
                }
                
                else if (letter == 'N' || letter == 'n')
                {
                    printf("\n\nThank you for playing\n\n");
                    Sleep(2000); // mile-seconds
                    return 0;
                }
                
                else if (letter != 'y' || letter != 'Y' || letter != 'N' || letter != 'n')
                {
                    printf("\n\nInvalid Please enter Y / N\n\n");
                }
            } // end if loop 2:
            
            
            wrong = 0; //setting wrong to zero at end of loop:
            
            system ("cls");
            
        } // end while loop 1:
        
    } // end while loop 0:
    
} //end main:
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main3()
{
 
    char initialInput[length];
    
    for(int counter = 0 ; counter < length ; counter ++){

    scanf("%c", &initialInput[counter]);

    }
    printf("The inputed cipher is:\n");
    for(int counter = 0 ; counter < length ; counter ++){ //test code

    printf("%c", initialInput[counter]);

    }                                                     
    printf("\n\n");//test code

    char input[length];
    for(int counter = 0 ; counter < length ; counter ++){
        
        input[counter] = initialInput[counter];
        
    }
    
    char ASCIIvalues[length];
    for(int counter = 0 ; counter < length ; counter ++){
        
        ASCIIvalues[counter] = (int)input[counter];
        
    }
    
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char subsitutionAlphabet[26];
    
    printf("Please enter the letter you wish to associate with the alphabetic letters:\n");
    
    for(int counter = 0; counter < 26; counter++){
        
        scanf("%c", &subsitutionAlphabet[counter]);
        printf("%c = %c\n", (char)subsitutionAlphabet[counter], (char)alphabet[counter]);
        
    }
    
    char repeatcount[length];
    int Zeroer;
    
    for(Zeroer = 0 ; Zeroer < length ; Zeroer ++){
        
        repeatcount[Zeroer] = 0;
        
    }
    
    for(int original = 0 ; original < length ; original ++){
        
        for(int counter = 0 ; counter < length ; counter ++){
            
            if (ASCIIvalues[original] == ASCIIvalues[counter]){
                
                repeatcount[original] ++;
                
            }
        
        }
        
    }
        
    for(int original = 0 ; original < length ; original ++){
        
        for(int counter = 0 ; counter < 26 ; counter ++){
            
            if(ASCIIvalues[original] == subsitutionAlphabet[counter] && repeatcount[original] > 1){
                
                ASCIIvalues[original] = alphabet[counter];
                repeatcount[original] = repeatcount[original] - 1;
                break ;

            }
            
            else if(ASCIIvalues[original] == subsitutionAlphabet[counter]){
                
                ASCIIvalues[original] = alphabet[counter];
                break ;
                
            }
        }
        
    }
    
    printf("\nThe decrypted substitution cipher is:\n");
    for(int counter = 0 ; counter < length ; counter ++){
        
        printf("%c", (char)ASCIIvalues[counter]);    //change to %c and (char) later
        
    }

 
}
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//no clue about the main statement, something about reaching a non-void function although the code for the RC Encryption is complete
int main2(){
    
    char initialInput[length];
    
    for(int counter = 0 ; counter < length ; counter ++){

    scanf("%c", &initialInput[counter]);

    }
    
    char input[length];
    
    for(int counter = 0 ; counter < length ; counter ++){
        
        input[counter] = initialInput[counter];
        
    }
    
    char ASCIIvalues[length];
    /*defines the arrays and identifies the length, provided with the length the letters inputted are converted 
    into their ASCII decimal numbers*/
   
    for(int counter = 0 ; counter < length ; counter ++){
        
        ASCIIvalues[counter] = (int)input[counter];
        
    }
    
    printf("Please press enter after identifying the shift you desire for the encrypted cipher:\n");  
    int desiredshift = 6;
    //scanf("%d", &desiredshift); //for some reason the scanf statement isnt working...
    
    if (desiredshift <= 0){
        for(int n = 0; n < length; n ++){
            
            ASCIIvalues[n] = (int)ASCIIvalues[n] + desiredshift;
            if (ASCIIvalues[n] < 65){
                
                ASCIIvalues[n] = (int)ASCIIvalues[n] + 26;
                
            }
        
        }
    
    }
    
    else if (desiredshift > 0){
        
        for(int n = 0; n < length; n ++){
            
            ASCIIvalues[n] = (int)ASCIIvalues[n] + abs(desiredshift);
            if (ASCIIvalues[n] > 90){
                
                ASCIIvalues[n] = (int)ASCIIvalues[n] - 26;
                
            }
        
        }

    }


    printf("The Encrypted Cipher with a shift of %d, is:\n", desiredshift);
    
    for(int counter = 0 ; counter < length ; counter ++){
        
        printf("%c", (char)ASCIIvalues[counter]);
        
    }



}

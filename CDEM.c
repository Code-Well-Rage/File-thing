#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
    
    int length;
    int option;
    printf("Welcome to the cipher decoding/encoding machine(CDEM).\n");
    printf("Please enter the length of the message you wish to utalise in the CDEM (length = total count or elements):\n");
    scanf("%d", &length);
    printf("The length of the message is %d elements long.\n", length);
    printf("To conduct the following options, please enter the coresponding number for the option:\n\n");
    printf("Rotaional Cipher Decryption ===> 1                    (Requires encrypted code to be inputed)\n\n");
    printf("Rotaional Cipher Encryption ===> 2                    (Requires input of desired shift and message to be coded)\n\n");
    printf("Substitution Cipher Decryption ===> 3                 (Requires encrypted code and key to be inputed)\n\n");
    printf("Substitution Cipher Encryption ===> 4                 (Requires message and key to be inputed)\n\n");
    printf("Substitution Cipher Decryption Without Key ===> 5     (Requires encrypted code to be inputed)\n\n");
    scanf("%d", &option);
    
    if(option == 1){
        
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
    
        //An if inside a for, inside a for statement used to find any copies of the ASCII letters in the array
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
    
        /*A repeated if statement based off the repition statement above that finds the largest element 
        and its location, which is then applied back to the original ASCII version of the Cypher to find 
        the element that will be used to find the offset from E (and then offset from T, A & O)*/
        int offsetbase = 65;
        do{
            int maxcount;
            maxcount = repeatcount[0];
            int elementNum;
            int ogASCIINum;
            int offset;
    
            for(int repeatNum = 0 ; repeatNum < length ; repeatNum ++){

                if (maxcount < repeatcount[repeatNum]){
                    maxcount = repeatcount[repeatNum];
                    elementNum = repeatNum;
                }

            }
    
            ogASCIINum = ASCIIvalues[elementNum];
            offset = offsetbase - ogASCIINum;
            char solutionASCII[length];
            printf("The offset is %d\n", offset);
        
            if (offset <= 0){
        
                for(int n = 0; n < length; n ++){
            
                    solutionASCII[n] = ASCIIvalues[n] + offset;
                    if (solutionASCII[n] < 65){
                
                        solutionASCII[n] = solutionASCII[n] + 26;
                
                    }
            
                }
        
            }
            else if (offset > 0){
        
                for(int n = 0; n < length; n ++){
            
                    solutionASCII[n] = ASCIIvalues[n] + abs(offset);
                    if (solutionASCII[n] > 90){
                
                        solutionASCII[n] = solutionASCII[n] - 26;
                
                    }
        
                }

            }
    
            for(int counter = 0 ; counter < length ; counter ++){
        
                solutionASCII[counter] = (char)solutionASCII[counter];
        
            }
    
            printf("The Decrypted Cipher is:\n");
            for(int counter = 0 ; counter < length ; counter ++){
        
                    printf("%c", (char)solutionASCII[counter]);
        
            }
        printf("\n");
        printf("The base letter was %c\n\n", (char)offsetbase);
        offsetbase ++;
        }while(offsetbase < 91);

        
    }
    
    else if(option == 2){
        
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
    
    printf("Your desired shift is:\n");  
    int desiredshift;
    scanf("%d", &desiredshift);
    printf("%d\n", desiredshift);
    
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


    printf("The Encrypted Cipher is:\n");
    
    for(int counter = 0 ; counter < length ; counter ++){
        
        printf("%c", (char)ASCIIvalues[counter]);
        
    }


        
    }
    
    
    else if(option == 3){
        
        char initialInput[length];
    
    for(int counter = 0 ; counter < length ; counter ++){

    scanf("%c", &initialInput[counter]);

    }
    printf("The Encrypted Cipher Is:\n");
    for(int counter = 0 ; counter < length ; counter ++){

    printf("%c", initialInput[counter]);

    }                                                     
    printf("\n\n");

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
    
    printf("The Inputed Key Is:\n");
    
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
        
        printf("%c", (char)ASCIIvalues[counter]);
        
    }

        
    }
    
    
    else if(option == 4){
        
        char initialInput[length];
    
    for(int counter = 0 ; counter < length ; counter ++){

    scanf("%c", &initialInput[counter]);

    }
    printf("The Inputed Message Is:\n");
    for(int counter = 0 ; counter < length ; counter ++){

    printf("%c", initialInput[counter]);

    }                                                     
    printf("\n\n");

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
    
    printf("The Inputed Key Is:\n");
    
    for(int counter = 0; counter < 26; counter++){
        
        scanf("%c", &subsitutionAlphabet[counter]);
        printf("%c = %c\n", (char)alphabet[counter], (char)subsitutionAlphabet[counter]);
        
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
            
            if(ASCIIvalues[original] == alphabet[counter] && repeatcount[original] > 1){
                
                ASCIIvalues[original] = subsitutionAlphabet[counter];
                repeatcount[original] = repeatcount[original] - 1;
                break ;

            }
            
            else if(ASCIIvalues[original] == alphabet[counter]){
                
                ASCIIvalues[original] = subsitutionAlphabet[counter];
                break ;
                
            }
        }
        
    }
    
    printf("\nThe encrypted substitution cipher is:\n");
    for(int counter = 0 ; counter < length ; counter ++){
        
        printf("%c", (char)ASCIIvalues[counter]);    //change to %c and (char) later
        
    }

        
    }
    else if(option == 5){
        
        printf("Error 501 : Code Not Implemented");
        
    }
    
}
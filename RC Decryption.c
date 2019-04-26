#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    //counting and assigning the length of the encrypted array to the input array
    char initialInput[] = "zsszbjzsrtmqhrd";           
    int length;
        length = strlen(initialInput);
        printf("The cipher is %d element/s long\n", length);
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
    int offsetbase = 97;
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
                if (solutionASCII[n] < 97){
                
                    solutionASCII[n] = solutionASCII[n] + 26;
                
                }
            
            }
        
        }
        else if (offset > 0){
        
            for(int n = 0; n < length; n ++){
            
                solutionASCII[n] = ASCIIvalues[n] + abs(offset);
                if (solutionASCII[n] > 122){
                
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
    printf("\n\n");
    printf("The base letter was %c\n", (char)offsetbase);
    offsetbase ++;
    }while(offsetbase < 123);

}
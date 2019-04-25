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
        printf("The cypher is %d element/s long\n", length);
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
    printf("%d\n", ASCIIvalues[0]); //test print, delete later
    //An if inside a for, inside a for statement used to find any copies of the ASCII letters in the array
    char repeatcount[length];
    
    for(int original = 0 ; original < length ; original ++){
        
        for(int counter = 0 ; counter < length ; counter ++){
            
            if (ASCIIvalues[original] == ASCIIvalues[counter]){
                
                repeatcount[original] ++;
                
            }
        
        }
        
    }
    printf("%d\n", repeatcount[0]); //test print, delete later
    /*A repeated if statement based off the repition statement above that finds the largest element 
    and its location, which is then applied back to the original ASCII version of the Cypher to find 
    the element that will be used to find the offset from E (and then offset from T, A & O)*/
    double ASCIIaeot[4] = {97, 101, 111, 116};
    int aeot;
    
    for(aeot = 0; aeot < 4; aeot++);{
        int maxcount;
        maxcount = repeatcount[0];
        int elementNum;
        int ogASCIINum;
        int offset;
        int maxASCIIletter;
    
        for(int repeatNum = 0 ; repeatNum < length ; repeatNum ++){

            if (maxcount < repeatcount[repeatNum]){
                maxcount = repeatcount[repeatNum];
                elementNum = repeatNum;
            }

            
        }
    
        maxASCIIletter = maxcount;
        ogASCIINum = ASCIIvalues[elementNum];
        offset = ASCIIaeot[aeot] - ogASCIINum;
        printf("The most common lettter repeats %d time/s \n", maxASCIIletter);
    
        char solutionASCII[length];
    
        if (offset <= 0){
        
            for(int n = 0; n < length; n ++){
            
                solutionASCII[n] = ASCIIvalues[n] + abs(offset);
                if (solutionASCII[n] > 122){
                
                    solutionASCII[n] = solutionASCII[n] - 26;
                
                }
            
            }
        
        }
        else if (offset > 0){
        
            for(int n = 0; n < length; n ++){
            
                solutionASCII[n] = ASCIIvalues[n] - abs(offset);
                if (solutionASCII[n] < 97){
                
                    solutionASCII[n] = solutionASCII[n] + 26;
                
                }
        
            }

        }
    
        for(int counter = 0 ; counter < length ; counter ++){
        
            solutionASCII[counter] = (char)solutionASCII[counter];
        
        }
    
        printf("The Decrypted Cypher is:\n");
            for(int counter = 0 ; counter < length ; counter ++){
        
                printf("%c", (char)solutionASCII[counter]);
        
            }
    
    }

}
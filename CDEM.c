#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
    //open of Input file and its initialisation (thanks callum c3329280)
    int length;
    int option;
    FILE *Input;
    Input = fopen("Input", "r");
    if(Input == NULL){
        perror("fopen()");
        return 1;
    }4
    //User interface that takes in the length of the message aswell as the users option of code
    //The user is made to imput the length
    //RC cant account for elements that arn't letters
    //RC need only upper case letter input
    printf("Welcome to the cipher decoding/encoding machine(CDEM). (All inputed code must be UPPER CASE)\n");
    printf("Please enter the length of the message you wish to utalise in the CDEM (length = total count of elements):\n");
    scanf("%d", &length);
    printf("The length of the message is %d elements long.\n", length);
    printf("To conduct the following options, please enter the coresponding number for the option:\n\n");
    printf("Rotaional Cipher Decryption ===> 1                    (Requires encrypted code to be inputed without any elements that are not considered uppercase letters)\n\n");
    printf("Rotaional Cipher Encryption ===> 2                    (Requires input of desired shift and message to be coded)\n\n");
    printf("Substitution Cipher Decryption ===> 3                 (Requires encrypted code and key to be inputed)\n\n");
    printf("Substitution Cipher Encryption ===> 4                 (Requires message and key to be inputed)\n\n");
    printf("Substitution Cipher Decryption Without Key ===> 5     (Requires encrypted code to be inputed)\n\n");
    scanf("%d", &option);
    
    if(option == 1){
        /*Rotaional Cipher which takes in all-capital letter code without any non-letter elements and outputs all
        26 possiblities of Cipher shift to the user(the disadvantage is that all non letter elements need to be taken
        out of the code to allow it to work)*/ 
        char initialInput[length];
    
        for(int counter = 0 ; counter < length ; counter ++){

        fscanf(Input, "%c", &initialInput[counter]); /* takes the message from the input file, individually 
                                                        assigning the letter to each array element for the 
                                                       length that the user inputed*/
        }

        char input[length];
        for(int counter = 0 ; counter < length ; counter ++){
        
            input[counter] = initialInput[counter]; //kind of useless, just asigns the array again as another array
        
        }
    
        char ASCIIvalues[length];
        /*just making sure that the array is in 'int' for so that the ASCII values can be used*/
        for(int counter = 0 ; counter < length ; counter ++){
        
        ASCIIvalues[counter] = (int)input[counter]; 
        
        }
    
        char repeatcount[length];
        int Zeroer;
    
        for(Zeroer = 0 ; Zeroer < length ; Zeroer ++){ /* makes all the numbers in the repeatcount
                                                        array so that random numbers dont become 
                                                        registered in the following code*/
            repeatcount[Zeroer] = 0;
        
        }
    
        for(int original = 0 ; original < length ; original ++){
        
            for(int counter = 0 ; counter < length ; counter ++){ /* for every repeat of a letter in the array, 
                                                                    the repeatcount for that letters position goes 
                                                                    up one giving the code a base letter to calculate
                                                                    the shift from*/
                if (ASCIIvalues[original] == ASCIIvalues[counter]){
                
                    repeatcount[original] ++;
                
                }
        
            }
        
        }
    
        /*A repeated if statement based off the repition statement above that finds the largest element 
        and its location, which is then applied back to the original ASCII version of the Cypher to find 
        the element that will be used to find the base letter to calculate the offset from*/
        int offsetbase = 65;
        do{
            int maxcount;
            maxcount = repeatcount[0];
            int elementNum;
            int ogASCIINum;
            int offset;
    
            for(int repeatNum = 0 ; repeatNum < length ; repeatNum ++){

                if (maxcount < repeatcount[repeatNum]){//finds the most repeated letter
                    maxcount = repeatcount[repeatNum];
                    elementNum = repeatNum;
                }

            }
    
            ogASCIINum = ASCIIvalues[elementNum];
            offset = offsetbase - ogASCIINum; //most repeated letter is used to get the offset for the decrypted cipher
            char solutionASCII[length];
            printf("The offset is %d\n", offset);
        
            if (offset <= 0){ //if the shift is to the left in the alphabet then the shift/offset is negative 
        
                for(int n = 0; n < length; n ++){
            
                    solutionASCII[n] = ASCIIvalues[n] + offset; //the ASCII values for the letter is shifed to the left
                    if (solutionASCII[n] < 65){ //if the shift is below the lower limit of capital ASCII letter, its snet back up by a shift of 26(ie. the alphabet length)
                
                        solutionASCII[n] = solutionASCII[n] + 26;
                
                    }
            
                }
       
            }
            else if (offset > 0){ //Same thing as above but if the shift is to the right ie. positive and if the upper limit is surpassed
        
                for(int n = 0; n < length; n ++){
            
                    solutionASCII[n] = ASCIIvalues[n] + abs(offset);
                    if (solutionASCII[n] > 90){
                
                        solutionASCII[n] = solutionASCII[n] - 26;
                
                    }
        
                }

            }
    
            for(int counter = 0 ; counter < length ; counter ++){//alos kinda of useless, just converts the ASCII to the letters
        
                solutionASCII[counter] = (char)solutionASCII[counter];
        
            }
    
            printf("The Decrypted Cipher is:\n");
            for(int counter = 0 ; counter < length ; counter ++){
        
                    printf("%c", (char)solutionASCII[counter]); // prints the decrypted code
        
            }
        printf("\n");
        printf("The base letter was %c\n\n", (char)offsetbase);
        offsetbase ++; // for each letter that was used, the letter is printed to the used to show the letter offset/shift
        }while(offsetbase < 91);//allows the code to repeat for all 26 alphabetical letters

        
    }
    
    else if(option == 2){
        /*The ASCII values for each array element are shifted by the users inputed desired amount and then printed to the screen*/
        char initialInput[length];
    
        for(int counter = 0 ; counter < length ; counter ++){

        fscanf(Input, "%c", &initialInput[counter]); // same as above, makes the array the users inputed message

        }
    
        char input[length];
    
        for(int counter = 0 ; counter < length ; counter ++){
        
            input[counter] = initialInput[counter];//same as above, again kinda useless
        
        }
    
        char ASCIIvalues[length];
        /*defines the arrays and identifies the length, provided with the length the letters inputted are converted 
        into their ASCII decimal numbers*/
   
        for(int counter = 0 ; counter < length ; counter ++){
        
            ASCIIvalues[counter] = (int)input[counter];
        
        }
    
        printf("What Is Your Desired Shift? :\n");  
        int desiredshift;
        scanf("%d", &desiredshift);
        printf("%d\n", desiredshift);//scans and prints the shift that the user desires of the encrypted code
    
        if (desiredshift <= 0){
            for(int n = 0; n < length; n ++){
            
                ASCIIvalues[n] = (int)ASCIIvalues[n] + desiredshift; // the desired shift, if its to the left ie. negative, is applied
                if (ASCIIvalues[n] < 65){//if the lower bounds of the ASCII code is surpassed, then the code is shifted back up by 26 to print the ltter on the 'other' side of the alphabet
                
                    ASCIIvalues[n] = (int)ASCIIvalues[n] + 26;
                
                }
        
            }
    
        }
    
        else if (desiredshift > 0){
        
            for(int n = 0; n < length; n ++){//for the shift to the right ie. a positive shift, the shift is applied
            
                ASCIIvalues[n] = (int)ASCIIvalues[n] + abs(desiredshift);
                if (ASCIIvalues[n] > 90){// if the ASCII value surpasses the upper bounds, the letter is shifted back to the other side of the alphabet
                
                    ASCIIvalues[n] = (int)ASCIIvalues[n] - 26;
                
                }
        
            }

        }


        printf("The Encrypted Cipher is:\n");
    
        for(int counter = 0 ; counter < length ; counter ++){
        
            printf("%c", (char)ASCIIvalues[counter]); // prints the encrypted cipher for the user
        
        }
        printf("\n");
        
    }
    
    
    
    else if(option == 3){
        /*two array are created and aligned side by side, the key and the alphabet. when an encrypted element aligns with an element
        in the key, the key, the alphabet letter that aligns with that key is used to replace that encrypted element to decrypt it
         Spaces and other elements work for this*/
        char initialInput[length];
    
        for(int counter = 0 ; counter < length ; counter ++){

        fscanf(Input, "%c", &initialInput[counter]);//assigns values to the array

        }
        printf("The Encrypted Cipher Is:\n");
        for(int counter = 0 ; counter < length ; counter ++){

        printf("%c", initialInput[counter]);//the encrypted cipher is printed for the user

        }                                                     
        printf("\n\n");

        char input[length];
        for(int counter = 0 ; counter < length ; counter ++){
        
            input[counter] = initialInput[counter];// useless but is resigns the name hence i didnt want to remove it
        
        }
    
        char ASCIIvalues[length];
        for(int counter = 0 ; counter < length ; counter ++){
        
            ASCIIvalues[counter] = (int)input[counter];//asigns ASCII values for the array elements
        
        }
    
        char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//the alphabet to compare the substitution alphabet
        char subsitutionAlphabet[26];//used for the SC key
    
        printf("The Inputed Key Is:\n");
    
        for(int counter = 0; counter < 26; counter++){
        
            fscanf(Input, "%c", &subsitutionAlphabet[counter]);// scans the key from the input and prints the comparison to the original alphabet
            //scanf("%c", &subsitutionAlphabet[counter //incase i fucked it up
            printf("%c = %c\n", (char)subsitutionAlphabet[counter], (char)alphabet[counter]);
        
        }
    
        char repeatcount[length];
        int Zeroer;
    
        for(Zeroer = 0 ; Zeroer < length ; Zeroer ++){
        
            repeatcount[Zeroer] = 0;// makes the elements of the repeatcount = 0
        
        }
    
        for(int original = 0 ; original < length ; original ++){//counts the letter repeat for all array elements
        
            for(int counter = 0 ; counter < length ; counter ++){
            
                if (ASCIIvalues[original] == ASCIIvalues[counter]){
                
                    repeatcount[original] ++;
                
                }
        
            }
        
        }
        
        for(int original = 0 ; original < length ; original ++){
        
            for(int counter = 0 ; counter < 26 ; counter ++){
            
                if(ASCIIvalues[original] == subsitutionAlphabet[counter] && repeatcount[original] > 1){//if the element from the array matches a letter in the key and is repeated more than one in the array, it is replaced and the loops breaks and moves to the next element of the array
                
                    ASCIIvalues[original] = alphabet[counter];
                    repeatcount[original] = repeatcount[original] - 1;//nulifies the original ++, honestly not needed but it worked so i just left it in
                    break ;

                }
            
                else if(ASCIIvalues[original] == subsitutionAlphabet[counter]){//if the array element matches a letter in the key and is only in the array once, the letter is replaced and the loop is broken, the original ++ is not nulified and the next element is tested
                
                    ASCIIvalues[original] = alphabet[counter];
                    break ;
                
                }
                
            }
        
        }
    
        printf("\nThe decrypted substitution cipher is:\n");
        for(int counter = 0 ; counter < length ; counter ++){
        
            printf("%c", (char)ASCIIvalues[counter]);//prints the decrypted cipher
        
        }

        printf("\n");
    }
        
    
    
    else if(option == 4){
        /*two array are created and aligned side by side, the key and the alphabet. when an message element aligns with an element
        in the alphabet, the key letter that aligns with the alphabet letter is used to replace that message element to encrypt it
        Spaces and other elements work for this*/
        /*Note:The code for the encryption is the same but the asignments of the key and alphabet are switched around so that is the array 
        element matches the a key element then the alphabet element that the key element is assigned to replaces the array element.
        apart from that the rest of the code functions is the same*/
        
        char initialInput[length];
    
        for(int counter = 0 ; counter < length ; counter ++){

        fscanf(Input, "%c", &initialInput[counter]);

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
        
            fscanf(Input, "%c", &subsitutionAlphabet[counter]);
            //scanf("%c", &subsitutionAlphabet[counter]);
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

        printf("\n");
        
    }
    
    
    
        else if(option == 5){
        
            printf("Error 501 : Code Not Implemented");
        
        }
    
}
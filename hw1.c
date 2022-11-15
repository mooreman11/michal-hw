#include <stdio.h>
#include <math.h>
#include <errno.h>

int convertOctToDec(int oct){
    int count =0, octCopy = oct, dec = 0;
    while (octCopy != 0){
        octCopy -= octCopy % 10;
        octCopy /= 10;
        count++;
    }
    for (int i = count-1; i>=0; i--){
        if (oct%10 >= 0 && oct%10 < 8){
            dec += oct%10 * pow(8, i);
            oct -= oct % 10;
            oct /= 10;
        }
        else{
            return -1;
        }
    }
    return dec;
}

void convertDecToHex(int dec){
    int remainder, count = 0, decCopy = dec;
    while (decCopy != 0){
        remainder = decCopy % 16;
        decCopy = (decCopy - remainder) / 16;
        count++;
    }
    int hex [count];
    count = 0;
    while (dec != 0){
        remainder = dec % 16;
        dec = (dec - remainder) / 16;
        hex[count] = remainder;
        count++;
    }
    //redundant code above (both while loops) -- try to optimize
    for (int i = count; i >= 0; i--){
        if (hex[i] >= 10){
            switch(hex[i]){
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                case 13:
                    printf("D");
                    break;
                case 14:
                    printf("E");
                    break;
                case 15:
                    printf("F");
                    break;
            }
        }
        else {
            printf("%d", hex[i]);
        }
    }
    printf("\n");
}

int main (){
    int oct;
    printf("Please enter number in octal base... \n");
    scanf("%d", &oct);
    int dec = convertOctToDec(oct);
    if (dec == -1){
        printf("error \n");
    }
    convertDecToHex(dec);
}

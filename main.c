#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_bits(uint8_t val) {
    int count_one = 0;
    for (int i = 7; i >= 0; i--) {
        if ((val >> i) & 1 == 1 ) {
            count_one += 1;
        }
    }
    return count_one;
}

void print_binary(uint8_t val) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}

int main(void) {
    char input[100];
    int temp;
    uint8_t val;

    while(1) {
        printf("Please enter the number (0 - 255): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Input error. Try again\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';
       int is_number = 1;
       for (size_t i = 0; i < strlen(input); i++) {
           if(!isdigit((unsigned char)input[i])) {
               is_number = 0;
               break;
           }
       }

       if(!is_number) {
           printf("Invalid input. Please enter a numeric value.\n");
    continue;
       }

       temp = atoi(input);
       if (temp < 0 || temp > 255 ) {
           printf("Out of range. Please enter a number between 0 and 255.\n");
           continue;
       }

       val = (uint8_t)temp;
       break;
    }
    
    printf("You enterd: %u\n", val);
    printf("Binary: 0b");
    print_binary(val);
    printf("\n");
    printf("Number of set bits: %d\n", count_bits(val));
    return 0;
}

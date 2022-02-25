// CS354 SP22 Project 2 Sample Tester by Ruixuan Tu

#include <stdio.h>
#include <string.h>
#include "enigma.h"

int main() {
    char message[80];
    char encrypted_message[80];
    char decrypted_message[80];
    char which_rotors[5];
    char encryption_rotors[4][27];
    int rotations;
    int num_active_rotors;
    int num_read;
    int num_actual_read;

    Get_Message(message);
    scanf("%d", &num_read);
    num_read--;
    num_actual_read = strlen(message);
    if (num_read != num_actual_read) {
        printf("Error: NUM READ 1\n");
        return 1;
    }

    num_active_rotors = Get_Which_Rotors(which_rotors);
    scanf("%d", &num_read);
    num_read--;
    num_actual_read = strlen(which_rotors);
    if (num_read != num_actual_read) {
        printf("Error: NUM READ 2\n");
        return 1;
    }

    rotations = Get_Rotations();

    printf("Inside Set_Up_Rotors\n");
    Set_Up_Rotors(encryption_rotors, which_rotors);
    for (int i = 0; i < 4; i++) {
        printf("i = %d  which_rotors[i] = %d (<= in char not in int)\n", i, which_rotors[i]);
        printf("ROTOR_CONSTANTS %s\n", encryption_rotors[i]);
    }
    printf("Exiting Set_Up_Rotors\n");

    printf("Inside Apply_Rotation\n");
    Apply_Rotation(rotations, encryption_rotors);
    for (int i = 0; i < 4; i++) {
        printf("\n\nrotatedString %s\n", encryption_rotors[i]);
    }
    printf("Exiting Apply_Rotation\n");

    Encrypt(encryption_rotors, num_active_rotors, message, encrypted_message);
    Decrypt(encryption_rotors, num_active_rotors, encrypted_message, decrypted_message);

    printf("The encrypted message is: %s\n", encrypted_message);
    printf("The decrypted message is: %s\n", decrypted_message);

    return 0;
}

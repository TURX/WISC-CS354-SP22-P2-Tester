// CS354 SP22 Project 2 Sample Tester by Ruixuan Tu

#include <stdio.h>
#include "enigma.h"

int main() {
    char message[80];
    char encrypted_message[80];
    char decrypted_message[80];
    char which_rotors[5];
    char encryption_rotors[4][27];
    int rotations;
    int num_active_rotors;

    Get_Message(message);

    num_active_rotors = Get_Which_Rotors(which_rotors);

    rotations = Get_Rotations();

    Set_Up_Rotors(encryption_rotors, which_rotors);
    Apply_Rotation(rotations, encryption_rotors);
    Encrypt(encryption_rotors, num_active_rotors, message, encrypted_message);
    Decrypt(encryption_rotors, num_active_rotors, encrypted_message, decrypted_message);

    printf("The encrypted message is: %s\n", encrypted_message);
    printf("The decrypted message is: %s\n", decrypted_message);

    return 0;
}

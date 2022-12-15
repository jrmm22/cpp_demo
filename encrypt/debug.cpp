
#include <iostream>
#include <stdlib.h>
#include <cstring>

// Copied from previous project
// generates a random number
int generateRandom( int min, int max )
{
    int number = (std::rand() % (max-min+1)) + min;
    return number;
}

void generate_key( char key[16] )
{
    for( int byte = 0; byte < 5; byte++ )
    {
        int letter = generateRandom( 'a', 'z' );

        key[byte] = letter;
    }
    key[5] = '\0';
}

/* Prints the lower 4 bits: */
void dump_nibble_binary( char nibble )
{
    for( int i = 0; i < 4; i++ )
    {
        /* ANDing with 0x01 will give 0 if the lower bit is 0,
           and 1 if the lower bit is 1. */
        char value = (nibble >> (3-i)) & 0x01;
        printf( "%d", value );

        /* Now we just move all the bits to the right (from Most Significant bits
          to Less Significant Bit)
          this is called a Right Shift*/
        //nibble = (nibble >> 1);
    }
}

/* This function only helps us understand what we do to our */
void dump_letter( char letter )
{

    printf( "%c \t 0x%02x\t", letter, letter );

    /*We print the 4 most-significant-bits first:
        (we pass down a copy of 'letter' that has been right shifted by 4) */

    dump_nibble_binary( letter >> 4 );

    printf( " " );

    /* And then we print the 4 less-significant bits:
        (we pass another copy of letter, this one without modifying it) */

    dump_nibble_binary( letter );

}

char encrypt_letter( char letter, char key )
{
    int result;

    /* This makes the letter go to lowercase

        'A' is 0x41, 'a' is 0x61,
        so OR-ing with 0x20 forces 'A' to become 'a', 'B' -> 'b' and so forth.
     */
    letter = letter | 0x20;

    /* Next we add the 5 lowest bits from the 'key'
       This effectively is like adding the letters together. */
    result = letter + (key & 0x1f);

    /* However if we go past 'z', we need to loop back to start from 'a' again */
    if( result > 'z' )
    {
        /* We substract 'z'+1 because that is our first invalid character,
         and add 'a' since that is our first good character */
        result = result - ('z'+1) + 'a';
    }

    /* NOTE that we declared result as an int (not a char) to avoid deal with overflows. */
    return (char) result;
}

void dump_message( char * msg, char key[5] )
{
    int msg_len = strlen( msg );

    int key_position = 0;

    for( int i = 0; i < msg_len; i++ )
    {
        if( msg[i] != ' ' )
        {
            dump_letter( msg[i] );

            printf( "\n" );
        }
        else
        {
            printf( "<SPACE>\n" );
        }
    }
}

void encrypt_message( char * msg, char * encrypted, char key[5] )
{
    int msg_len = strlen( msg );

    int key_position = 0;
    int byte = 0;
    for( int i = 0; i < msg_len; i++ )
    {
        if( msg[i] != ' ' )
        {
            if( msg[i] <= 'z' && msg[i] >= 'a' )
            {
                encrypted[byte] = encrypt_letter( msg[i], key[key_position] );

                key_position++;
                byte ++;
                if( key_position >= 5 )
                {
                    key_position = 0;
                }
            }
            else
            {
                std::cout << "Message can only contain lowercase characters." << std::endl;
                return;
            }
        }
        else
        {
            encrypted[byte] = ' ';
            byte ++;
        }
    }
    encrypted[byte] = '\0';
}



int main()
{
    char message[ 256 ];
    char encrypted[ 256 ];
    char generated_key[16];
    char key[16];

    generate_key( generated_key );

    std::cout << "Generated key" << std::endl;
    std::cout << generated_key << std::endl;

    std::cout << "What message?" << std::endl;

    std::cin.getline( message, 256, '\n' );

    std::cout << "What key? ('GEN' to use the generated one)" << std::endl;

    std::cin >> key ;

    if( key[0] == 'G' && key[1] == 'E' && key[2] == 'N' )
    {
        std::cout << "Using generated key " << generated_key << std::endl;
        encrypt_message( message, encrypted, generated_key );

        std::cout << "Encrypted message: " << std::endl;
        std::cout << encrypted << std::endl;

    }
    else
    {
        int key_len = strlen( key );
        if( key_len == 5 )
        {
            encrypt_message( message, encrypted, key );

            std::cout << "Encrypted message: " << std::endl;
            std::cout << encrypted << std::endl;
        }
        else
        {
            std::cout << "Key needs to be 5 characters long" << std::endl;
        }
    }
    return 0;
}

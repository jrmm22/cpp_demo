
#include <iostream>

#define ARRAY_SIZE      100

int main( int argc, char * argv[] )
{
    // this defines and initializes the array.
    // note the +1.
    // since 0 is not a valid input number, we'll skip that spot,
    // but 100 is, so technically we need 101 entries in our array (0 to 100, even when we are skipping 0)
    // another way to do this is to store the number 1 in location 0, 2 in 1, ... 100 in 99.
    int numbers[ARRAY_SIZE + 1] = {0};
    int numbers_received = 0;
    bool done = false;
    std::cout << "Enter numbers. 0 or 101+ to end." << std::endl;
    while (done == false) //this is the sentinel var
    {
        int input;
        std::cout << "What number do you want?" << std::endl;
        std::cin >> input;
        if( input > 0 && input <= 100 )
        {
            numbers[ input ] ++;
            numbers_received++;
        }
        else
        {
            done = true;
        }
        // Make sure we don't overflow the array.
        if( numbers_received == ARRAY_SIZE )
        {
            done = true;
        }
    }
    // Now printing.
    // this controls how large our grouping is.
    int print_block_size = 10;
    for( int i = 1; i < ARRAY_SIZE; i+= print_block_size )
    {
        // for every print-block, count how many '*' we need to dump.
        int numbers_in_block = 0;
        std::cout << i << ":" << (i + print_block_size - 1) << ":" ;
        for( int j = 0; j < print_block_size; j++ )
        {
            //notice here that i+j will reach entry 100 (91 + 9) for the last entry,
            // so will grab garbage data (outside of 'numbers' array) if it is declared only
            // as 'numbers[ARRAY_SIZE]'
            numbers_in_block += numbers[i + j];
        }
        for( int j = 0; j < numbers_in_block; j++ )
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    exit(0);
}

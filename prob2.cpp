
#include <cstdlib>
#include <iostream>
#include <ctime>

// generates a random number
int generateRandom( int min, int max )
{
    int number = (std::rand() % (max-min+1)) + min;
    return number;
}

// checks if number is prime
bool checkIfPrime( int number )
{
    bool result = true; //assumes the number is prime
    for( int i = 2; i < number; i++ )
    {
        // if we find out number is not prime, stop checking.
        if( (number % i) == 0 )
        {
            result = false;
            break;
        }
    }
    return result;
}

// This prints out an array using c++ std::cout i/o streams.
void printArray( int * arr, int arr_len )
{
    for( int i = 0; i < arr_len; i++ )
    {
        std::cout << i << ": " << arr[i] << std::endl;
    }
}

// This prints out an array using C print-format
void printArray_c( int * arr, int arr_len )
{
    for( int i = 0; i < arr_len; i++ )
    {
        printf( "%d : %d\n", i, arr[i] );
    }
}


#define ARRAY_SIZE          100
#define MAX_RAND_VAL        100
// entry function.
int main( int argc, char * argv[] )
{
    int initial_array[ARRAY_SIZE]; //initial array
    int array_size = ARRAY_SIZE;
    // argc is the number of inputs given in the command line. if no inputs,
    // then random seed wont be updated, and the program will always generate the same
    // sequence of numbers.
    if( argc > 1 )
    {
        std::srand(std::time(nullptr));
    }
    for( int i = 0; i < array_size; i++ )
    {
       initial_array[i] = generateRandom( 1, MAX_RAND_VAL );
    }
    int number_primes = 0;
    for( int i = 0; i <array_size; i++ )
    {
        if( checkIfPrime( initial_array[i] ) )
        {
            number_primes ++;
        }
    }

    int * array_of_primes = new int[ number_primes ];
    int j = 0;
    for( int i = 0; i < array_size; i++ )
    {
        if( checkIfPrime( initial_array[i] ) )
        {
            array_of_primes[j] = initial_array[i];
            j++;
        }
    }
    std::cout << "Initial array " << std::endl;
    printArray( initial_array, array_size );
    std::cout << "Array of primes" << std::endl;
    printArray( array_of_primes, number_primes );
    delete [] array_of_primes;
    exit(0);
}

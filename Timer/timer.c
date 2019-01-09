# include <avr/io.h>
int main ( void ) 
{
    DDRC |= (1 << 7) ; // Set LED as output
    TCCR1B |= ( (1 << CS10) |  (1 << CS11) ); // Set up timer
    for (;;)
    {
        // Check timer value in if statement , true when count matches 1/20 of a second
        if ( TCNT1 >= 65525)
        {
            PORTC ^= (1 << 7) ; // Toggle the LED
            TCNT1 = 0; // Reset timer value
        }
    }
}

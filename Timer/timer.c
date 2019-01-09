# include <avr/io.h>
int main ( void ) 
{
    DDRB |= (1 << 0) ; // Set LED as output
    TCCR1B |= (1 << CS10 ); // Set up timer
    for (;;)
    {
        // Check timer value in if statement , true when count matches 1/20 of a second
        if ( TCNT1 >= 49999)
        {
            PORTB ^= (1 << 0) ; // Toggle the LED
            TCNT1 = 0; // Reset timer value
        }
    }
}
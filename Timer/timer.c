# include <avr/io.h>
int main ( void ) 
{
    DDRC |= (1 << 7) ; // Set LED as output
    TCCR1B |= ( (1 << CS10) |  (1 << CS11) ); // Set up timer

    int cnt = 0;
    for (;;)
    {
        // Check timer value in if statement , true when count matches 1/20 of a second
        if ( TCNT1 >= 50000)
        {
            TCNT1 = 0; // Reset timer value
            cnt += 1;
        }
        
        if (cnt == 5) {
            PORTC ^= (1 << 7) ; // Toggle the LED
            cnt = 0;
        }
        
    }
}
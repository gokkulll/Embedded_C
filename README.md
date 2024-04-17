# Embedded_C

Embedded C programming involves writing code specifically for embedded systems, which are computers designed to perform dedicated functions within a larger system. These systems often have resource constraints such as limited memory, processing power, and sometimes real-time operation requirements. Here are a few examples of embedded C programs:

    1)Blinking LED: This is a classic example often used for testing and learning embedded systems. It involves writing code to toggle an LED connected to a microcontroller or a development board like Arduino at a specific frequency, creating a blinking effect.

c

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << DDB0); // Set PB0 as output
    while (1) {
        PORTB ^= (1 << PB0); // Toggle PB0
        _delay_ms(500); // Delay 500 ms
    }
    return 0;
}

    2)Temperature Sensor Readings: Suppose you have a temperature sensor connected to an embedded system. You can write a program to read the sensor data and perform actions based on the temperature value.

c

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Initialize ADC for temperature sensor
    ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    ADMUX |= (1 << REFS0);

    DDRB |= (1 << DDB0); // Set PB0 as output for LED

    while (1) {
        ADCSRA |= (1 << ADSC); // Start conversion
        while (ADCSRA & (1 << ADSC)); // Wait for conversion to complete
        uint16_t adc_value = ADC; // Read ADC value

        // Check temperature threshold and turn on LED accordingly
        if (adc_value > 512) {
            PORTB |= (1 << PB0); // Turn on LED
        } else {
            PORTB &= ~(1 << PB0); // Turn off LED
        }

        _delay_ms(1000); // Delay 1 second
    }
    return 0;
}

    3)UART Communication: UART (Universal Asynchronous Receiver-Transmitter) is commonly used for serial communication between embedded systems and other devices. Here's an example of sending and receiving data via UART:

c

#include <avr/io.h>
#include <util/delay.h>

void UART_init(unsigned int baud) {
    UBRR0H = (unsigned char)(baud >> 8);
    UBRR0L = (unsigned char)baud;
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data format
}

void UART_transmit(unsigned char data) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait for empty transmit buffer
    UDR0 = data; // Transmit data
}

unsigned char UART_receive(void) {
    while (!(UCSR0A & (1 << RXC0))); // Wait for data to be received
    return UDR0; // Return received data
}

int main(void) {
    UART_init(9600); // Initialize UART with baud rate 9600

    while (1) {
        unsigned char received_data = UART_receive(); // Receive data
        UART_transmit(received_data); // Transmit received data back
    }
    return 0;
}

These examples demonstrate basic concepts in embedded C programming such as GPIO manipulation, sensor interfacing, and serial communication. Keep in mind that the specific code may vary depending on the microcontroller or development board you are using.


/**
 * File:   main.c
 * Author: cstep
 *
 * Created on December 18, 2025, 8:21 AM
 * Description: Music player for PIC16F1719
 *              Wakes from sleep on button press using IOC (Port B)
 */

#include "config.h"
#include "music_player.h"
#include "mario_tune.h"
#include "tetris_tune.h"

#define _XTAL_FREQ 8000000UL    // 8 MHz internal oscillator

// Button definitions (using weak pull-ups, active low)
// Using Port B for IOC capability (wake from sleep)
#define MODE_MUSIC_BTN    PORTBbits.RB0

void music_mode(void);
void setup_ioc_wake(void);

// Interrupt Service Routine for wake-up
void __interrupt() ISR(void) {
    // Check for Interrupt-on-Change
    if (INTCONbits.IOCIE && INTCONbits.IOCIF) {
        // Clear IOC flags
        IOCBF = 0;  // Clear all Port B IOC flags
        INTCONbits.IOCIF = 0;  // Clear IOC interrupt flag
    }
}

void main(void) {
    // Initialize the music player hardware
    music_player_init();
    
    // Configure button pin (RB0) and keep RB1/RB2 as inputs (unused)
    TRISBbits.TRISB0 = 1;   // Input
    TRISBbits.TRISB1 = 1;   // Input
    TRISBbits.TRISB2 = 1;   // Input
    
    ANSELBbits.ANSB0 = 0;   // Digital
    ANSELBbits.ANSB1 = 0;   // Digital
    ANSELBbits.ANSB2 = 0;   // Digital
    
    // Enable weak pull-ups on port B
    OPTION_REGbits.nWPUEN = 0;  // Enable weak pull-ups
    WPUBbits.WPUB0 = 1;         // Pull-up on RB0
    
    // Setup Interrupt-on-Change for wake from sleep
    setup_ioc_wake();
    
    // Small delay to let pull-ups stabilize
    __delay_ms(50);
    
    // Enter music mode (single-mode build)
    music_mode();
}

// Setup Interrupt-on-Change for wake from sleep
void setup_ioc_wake(void) {
    // Enable Interrupt-on-Change on negative edge (button press) for RB0
    IOCBNbits.IOCBN0 = 1;  // RB0 negative edge
    
    // Clear IOC flags
    IOCBF = 0;
    
    // Enable IOC interrupt
    INTCONbits.IOCIE = 1;  // Enable IOC interrupt
    INTCONbits.GIE = 1;    // Enable global interrupts
}

// Music mode: Play melodies and sleep, wake on button press
void music_mode(void) {
    while(1) {
        // Play the Mario theme
        play_mario_theme();
        
        // Short pause between songs
        delay_ms(1000);
        
        // Play the Tetris theme
        play_tetris_theme();
        
        // Pause before sleep
        delay_ms(1000);
        
        // Clear any pending IOC flags before sleep
        IOCBF = 0;
        INTCONbits.IOCIF = 0;
        
        // Enter sleep mode - wake on any button press
        SLEEP();
        
        // Woken up! Small delay for debounce
        __delay_ms(100);
        
        // Loop will repeat songs
    }
}
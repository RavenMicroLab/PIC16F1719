/**
 * File:   music_player.c
 * Author: cstep
 *
 * Created on December 18, 2025
 * Description: Common music player implementation for PIC16F1719
 */

#include "config.h"
#include "music_player.h"

#define _XTAL_FREQ 8000000UL    // 8 MHz internal oscillator

// ---------------- Play routine ----------------
void play_note(unsigned char pr2, unsigned int duration_ms) {
    if (pr2 == REST) {
        delay_ms(duration_ms);
        return;
    }
    PR2 = pr2;
    CCPR1L = pr2 >> 1;      // 50% duty cycle (optimized with bit shift)
    CCP1CON = PWM_MODE_ENABLE;   // PWM mode
    delay_ms(duration_ms);
    CCP1CON = PWM_MODE_DISABLE;  // stop PWM
}

// ---------------- Play melody ----------------
void play_melody(const Note* melody, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        play_note(melody[i].pr2, melody[i].duration_ms);
    }
}

// ---------------- Setup ----------------
void music_player_init(void) {
    // Configure internal oscillator to 8 MHz
    OSCCON = 0b01110000;    // 8 MHz HF internal oscillator
    while(!OSCSTATbits.HFIOFS); // Wait for oscillator to stabilize
    
    // Configure CCP1 output pin (RC5 on PIC16F1719)
    TRISCbits.TRISC5 = 0;   // RC5 output
    
    // PPS: Route CCP1 to RC5
    PPSLOCK = 0x55;         // Unlock PPS
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0;
    RC5PPS = 0b01100;       // RC5 = CCP1 (0x0C)
    PPSLOCK = 0x55;         // Lock PPS
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 1;
    
    // Disable analog on port C
    ANSELC = 0x00;          // All digital
    
    // Configure Timer2 (done once for efficiency)
    T2CON = TIMER2_PRESCALE16;  // Timer2 on, prescaler=16, postscaler=1
}

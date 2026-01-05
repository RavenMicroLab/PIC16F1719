/**
 * File:   music_player.h
 * Author: cstep
 *
 * Created on December 18, 2025
 * Description: Common music player interface for PIC16F1719
 */

#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <xc.h>

// ---------------- Note structure ----------------
typedef struct {
    unsigned char pr2;
    unsigned int duration_ms;
} Note;

/**
 *  ---------------- PR2 lookup (prescaler=16, Fosc=8 MHz) ----------------
 * Formula: PR2 = (Fosc / (4 * freq * prescaler)) - 1
 * Using prescaler=16 to fit in 8-bit PR2 register (0-255)
 * Lower octave notes (C3-B3)
*/
#define NOTE_C3  255    // ~247 Hz (C3) - capped at 255
#define NOTE_D3  225    // ~277 Hz (D3)
#define NOTE_E3  200    // ~311 Hz (E3)
#define NOTE_F3  189    // ~330 Hz (F3)
#define NOTE_G3  168    // ~370 Hz (G3)
#define NOTE_A3  150    // ~415 Hz (A3)
#define NOTE_B3  133    // ~468 Hz (B3)

// Middle octave notes (C4-B4)
#define NOTE_C4  238    // ~261 Hz (C4)
#define NOTE_D4  212    // ~294 Hz (D4)
#define NOTE_E4  189    // ~330 Hz (E4)
#define NOTE_F4  178    // ~349 Hz (F4)
#define NOTE_G4  159    // ~392 Hz (G4)
#define NOTE_A4  141    // ~440 Hz (A4)
#define NOTE_B4  126    // ~494 Hz (B4)

// Higher octave notes (C5-A5)
#define NOTE_C5  118    // ~523 Hz (C5)
#define NOTE_D5  106    // ~587 Hz (D5)
#define NOTE_E5   94    // ~659 Hz (E5)
#define NOTE_F5   89    // ~698 Hz (F5)
#define NOTE_G5   79    // ~784 Hz (G5)
#define NOTE_A5   70    // ~880 Hz (A5)

#define REST       0

// ---------------- PWM Configuration Constants ----------------
#define PWM_MODE_ENABLE   0b00001100  // CCP1CON PWM mode bits
#define PWM_MODE_DISABLE  0b00000000  // CCP1CON disable
#define TIMER2_PRESCALE16 0b00000110  // Timer2 on, prescaler=16, postscaler=1

/**
 *  ---------------- Tempo calculation macros ----------------
 * These macros calculate note durations based on BPM
 * Usage: Define BPM before including this header, or use default 180
*/
#ifndef BPM
#define BPM 180
#endif

#define HALF      (120000 / BPM)      // Half note
#define QUARTER   (60000  / BPM)      // Quarter note
#define EIGHTH    (30000  / BPM)      // Eighth note
#define SIXTEENTH (15000  / BPM)      // Sixteenth note
#define DOTTED8   (45000  / BPM)      // Dotted eighth (1.5x eighth)
#define DOTTED16  (22500  / BPM)      // Dotted sixteenth

// ---------------- Function prototypes ----------------

/**
 * Initialize the music player hardware
 * Configures oscillator, PWM output pin, and PPS
 */
void music_player_init(void);

/**
 * Play a single note
 * @param pr2 PR2 value for the note frequency (or REST for silence)
 * @param duration_ms Duration in milliseconds
 */
void play_note(unsigned char pr2, unsigned int duration_ms);

/**
 * Play a melody (array of notes)
 * @param melody Pointer to array of Note structures
 * @param length Number of notes in the array
 */
void play_melody(const Note* melody, unsigned int length);

/**
 * Variable delay macro (inline for efficiency)
 * @param ms Delay in milliseconds
 */
#define delay_ms(ms) do { unsigned int _i = (ms); while(_i--) __delay_ms(1); } while(0)

#endif /* MUSIC_PLAYER_H */

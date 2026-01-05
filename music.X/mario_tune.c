/**
 * File:   mario_tune.c
 * Author: cstep
 *
 * Created on December 18, 2025
 * Description: Super Mario Bros main theme melody data and playback
 */

#include "mario_tune.h"

// Set BPM for Mario theme before using tempo macros
#undef BPM
#define BPM 180

// ---------------- Mario Theme ----------------
// Super Mario Bros main theme
const Note mario_melody[] = {
    // Opening phrase: E5-E5-E5-C5-E5-G5-G4
    {NOTE_E5,EIGHTH}, {NOTE_E5,EIGHTH}, {REST,EIGHTH}, {NOTE_E5,EIGHTH}, 
    {REST,EIGHTH}, {NOTE_C5,EIGHTH}, {NOTE_E5,EIGHTH}, {REST,EIGHTH},
    {NOTE_G5,EIGHTH}, {REST,EIGHTH*3}, {NOTE_G4,EIGHTH}, {REST,EIGHTH*3},
    
    // Second phrase: C5-G4-E4-A4-B4-A4-G4
    {NOTE_C5,DOTTED8}, {REST,EIGHTH}, {NOTE_G4,DOTTED8}, {REST,DOTTED8}, 
    {NOTE_E4,DOTTED8}, {REST,EIGHTH}, {NOTE_A4,EIGHTH}, {REST,SIXTEENTH},
    {NOTE_B4,EIGHTH}, {REST,SIXTEENTH}, {NOTE_A4,EIGHTH}, {NOTE_G4,DOTTED8},
    {REST,EIGHTH},
    
    // Third phrase: G4-E5-G5-A5-F5-G5-E5-C5-D5-B4
    {NOTE_G4,EIGHTH}, {NOTE_E5,EIGHTH}, {NOTE_G5,EIGHTH}, {NOTE_A5,EIGHTH}, 
    {REST,SIXTEENTH}, {NOTE_F5,EIGHTH}, {NOTE_G5,EIGHTH}, {REST,SIXTEENTH}, 
    {NOTE_E5,EIGHTH}, {REST,SIXTEENTH}, {NOTE_C5,EIGHTH}, {NOTE_D5,EIGHTH},
    {NOTE_B4,EIGHTH}, {REST,EIGHTH},
    
    // Loop second and third phrases again
    
    // Second phrase: C5-G4-E4-A4-B4-A4-G4
    {NOTE_C5,DOTTED8}, {REST,EIGHTH}, {NOTE_G4,DOTTED8}, {REST,DOTTED8}, 
    {NOTE_E4,DOTTED8}, {REST,EIGHTH}, {NOTE_A4,EIGHTH}, {REST,SIXTEENTH},
    {NOTE_B4,EIGHTH}, {REST,SIXTEENTH}, {NOTE_A4,EIGHTH}, {NOTE_G4,DOTTED8},
    {REST,EIGHTH},
    
    // Third phrase: G4-E5-G5-A5-F5-G5-E5-C5-D5-B4
    {NOTE_G4,EIGHTH}, {NOTE_E5,EIGHTH}, {NOTE_G5,EIGHTH}, {NOTE_A5,EIGHTH}, 
    {REST,SIXTEENTH}, {NOTE_F5,EIGHTH}, {NOTE_G5,EIGHTH}, {REST,SIXTEENTH}, 
    {NOTE_E5,EIGHTH}, {REST,SIXTEENTH}, {NOTE_C5,EIGHTH}, {NOTE_D5,EIGHTH},
    {NOTE_B4,EIGHTH}, {REST,EIGHTH},
    
    {REST,HALF}, // final pause
};

// ---------------- Public functions ----------------
void play_mario_theme(void) {
    play_melody(mario_melody, sizeof(mario_melody) / sizeof(mario_melody[0]));
}

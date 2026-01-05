/**
 * File:   tetris_tune.c
 * Author: cstep
 *
 * Created on December 18, 2025
 * Description: Tetris theme (Korobeiniki) melody data and playback
 */

#include "tetris_tune.h"

// Set BPM for Tetris theme
#undef BPM
#define BPM 144

// ---------------- Tetris Theme (Korobeiniki) ----------------
// Classic Tetris Type A music theme
const Note tetris_melody[] = {
    // First phrase: E5-B4-C5-D5-C5-B4-A4-A4-C5-E5-D5-C5-B4-C5-D5-E5-C5-A4-A4
    {NOTE_E5,QUARTER}, {NOTE_B4,EIGHTH}, {NOTE_C5,EIGHTH}, {NOTE_D5,QUARTER},
    {NOTE_C5,EIGHTH}, {NOTE_B4,EIGHTH}, {NOTE_A4,QUARTER}, {NOTE_A4,EIGHTH},
    {NOTE_C5,EIGHTH}, {NOTE_E5,QUARTER}, {NOTE_D5,EIGHTH}, {NOTE_C5,EIGHTH},
    {NOTE_B4,QUARTER}, {NOTE_B4,EIGHTH}, {NOTE_C5,EIGHTH}, {NOTE_D5,QUARTER},
    {NOTE_E5,QUARTER}, {NOTE_C5,QUARTER}, {NOTE_A4,QUARTER}, {NOTE_A4,QUARTER},
    {REST,QUARTER},
    
    // Second phrase: D5-F5-A5-G5-F5-E5-C5-E5-D5-C5-B4-B4-C5-D5-E5-C5-A4-A4
    {NOTE_D5,QUARTER}, {NOTE_D5,EIGHTH}, {NOTE_F5,EIGHTH}, {NOTE_A5,QUARTER},
    {NOTE_G5,EIGHTH}, {NOTE_F5,EIGHTH}, {NOTE_E5,QUARTER}, {NOTE_E5,EIGHTH},
    {NOTE_C5,EIGHTH}, {NOTE_E5,QUARTER}, {NOTE_D5,EIGHTH}, {NOTE_C5,EIGHTH},
    {NOTE_B4,QUARTER}, {NOTE_B4,EIGHTH}, {NOTE_C5,EIGHTH}, {NOTE_D5,QUARTER},
    {NOTE_E5,QUARTER}, {NOTE_C5,QUARTER}, {NOTE_A4,QUARTER}, {NOTE_A4,QUARTER},
    {REST,QUARTER},
    
    {REST,HALF}, // final pause
};

// ---------------- Public functions ----------------
void play_tetris_theme(void) {
    play_melody(tetris_melody, sizeof(tetris_melody) / sizeof(tetris_melody[0]));
}

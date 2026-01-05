/**
 * File:   tetris_tune.h
 * Author: cstep
 *
 * Created on December 18, 2025
 * Description: Tetris theme (Korobeiniki) melody
 */

#ifndef TETRIS_TUNE_H
#define TETRIS_TUNE_H

#include "music_player.h"

// ---------------- Function prototypes ----------------

/**
 * Play the Tetris theme (Korobeiniki)
 * Uses the music player to play the complete melody
 */
void play_tetris_theme(void);

/**
 * Get the Tetris theme melody array
 * @return Pointer to the melody array
 */
const Note* get_tetris_melody(void);

/**
 * Get the length of the Tetris theme melody
 * @return Number of notes in the melody
 */
unsigned int get_tetris_melody_length(void);

#endif /* TETRIS_TUNE_H */

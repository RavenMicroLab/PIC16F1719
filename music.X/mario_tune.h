/**
 * File:   mario_tune.h
 * Author: cstep
 *
 * Created on December 18, 2025
 * Description: Super Mario Bros main theme melody
 */

#ifndef MARIO_TUNE_H
#define MARIO_TUNE_H

#include "music_player.h"

// ---------------- Function prototypes ----------------

/**
 * Play the Super Mario Bros main theme
 * Uses the music player to play the complete melody
 */
void play_mario_theme(void);

/**
 * Get the Mario theme melody array
 * @return Pointer to the melody array
 */
const Note* get_mario_melody(void);

/**
 * Get the length of the Mario theme melody
 * @return Number of notes in the melody
 */
unsigned int get_mario_melody_length(void);

#endif /* MARIO_TUNE_H */

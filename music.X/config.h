// ---------------- Configuration bits ----------------
#pragma config FOSC = INTOSC    // Internal oscillator
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = ON       // Power-up Timer enabled
#pragma config MCLRE = ON       // MCLR pin enabled
#pragma config CP = OFF         // Code protection off
#pragma config BOREN = ON       // Brown-out reset enabled
#pragma config CLKOUTEN = OFF   // Clock out disabled
#pragma config IESO = OFF       // Internal/External switchover disabled
#pragma config FCMEN = OFF      // Fail-safe clock monitor disabled
#pragma config WRT = OFF        // Flash write protection off
#pragma config PPS1WAY = ON     // PPS locked after one change
#pragma config ZCDDIS = ON      // Zero-cross detect disabled
#pragma config PLLEN = OFF      // PLL disabled
#pragma config STVREN = ON      // Stack overflow reset enabled
#pragma config BORV = LO        // Brown-out reset voltage low
#pragma config LPBOR = OFF      // Low-power brown-out reset disabled
#pragma config LVP = OFF        // Low-voltage programming disabled

#include <xc.h>
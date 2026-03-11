
#include "analog.h"

// uint16_t fsr_prev = 0;

#ifndef FSR_THRES
#   define FSR_THRES 650
#endif

// After X time of input or NONE input to determine if action is viable
#ifndef FSR_INPUT_C
#   define FSR_INPUT_C 200
#endif

uint16_t thres_actual = FSR_THRES; // Adjustable actual threshold level
uint16_t fsr_reading = 0;
uint16_t fsr_stack = 0;

void fsr_sense(void) {

    fsr_reading = analogReadPin(FSR_PIN);

    if (fsr_reading >= thres_actual) {
        if (fsr_stack < FSR_INPUT_C) fsr_stack += 1;
    } else {
        if (fsr_stack > 0) fsr_stack -= 1;
    }
    
    // return (fsr_reading >= thres_actual) ? true : false;

}


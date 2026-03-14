
#include "analog.h"
#include "util.h"

#ifndef FSR_THRES
#   define FSR_THRES {500, 600, 700}
#endif
#define NUM_FSR_THRES ARRAY_SIZE(((uint16_t[])FSR_THRES))

const uint16_t fsr_thres_options[NUM_FSR_THRES] = FSR_THRES;
        
#ifndef KEYPRESS_COUNT_THRES
#   define KEYPRESS_COUNT_THRES 50 /* keypress count counter as low pass filter */
#endif

#ifndef FSR_STACK_THRES
#   define FSR_STACK_THRES 50 /* FSR reading counter used as low pass filter */
#endif

#ifndef LAYER_OFF_TIMING
#   define LAYER_OFF_TIMING 225 /* Timer (in ms) before mouse layer is on again after it's previous off state */
#endif

#ifndef MOUSE_IDLE_TIMING
#   define MOUSE_IDLE_TIMING 2000 /* Time (in ms) before mouse layer if turned off */
#endif

uint16_t thres_actual = fsr_thres_options[(unsigned int) NUM_FSR_THRES / 2];
unsigned int thres_id = 0;
uint16_t fsr_reading = 0;
uint16_t fsr_stack = 0;

bool fsr_sense(void) {
    
    fsr_reading = analogReadPin(FSR_PIN);
    
    if (fsr_reading >= thres_actual) {
        if (fsr_stack < FSR_STACK_THRES) fsr_stack += 1;
    } else {
        if (fsr_stack > 0) fsr_stack -= 1;
    }

    return (fsr_reading >= thres_actual) ? true : false;
    
}


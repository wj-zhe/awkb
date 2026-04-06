
#include "analog.h"

#ifndef FSR_THRES_LOW
#   define FSR_THRES_LOW 357
#endif

#ifndef FSR_BASE_RESET_TIMING
#   define FSR_BASE_RESET_TIMING 500
#endif
        
#ifndef COUNT_STACK_THRES
#   define COUNT_STACK_THRES 30 /* keypress count counter as low pass filter */
#endif

#ifndef MOUSE_IDLE_TIMING
#   define MOUSE_IDLE_TIMING 2000 /* Time (in ms) before mouse layer if turned off */
#endif

typedef struct fsr_struct {
    uint16_t reading;
    uint16_t base;
    uint8_t thres;
    uint8_t stack; // counter
    uint16_t acc;
    uint16_t timer;
    bool reset;
} fsr_t;

fsr_t fsr = {
    .reading = 0,
    .base = 500,
    .thres = 50,
    .reset = false,
};

uint16_t time_passed = 0;
bool flip_switch = false;

bool fsr_sense(void) {

    fsr.reading = (fsr.reading + analogReadPin(FSR_PIN)) / 2;

    if (fsr.reset) {
        if ( fsr.reading < fsr.base || fsr.reading > (fsr.base + fsr.thres) ) {
            if (!flip_switch) {
                flip_switch = true;
                fsr.timer = timer_read();
                fsr.acc = FSR_THRES_LOW;
            }
        }
    }
    
    if (fsr.acc > 0) {
        time_passed = timer_elapsed(fsr.timer);
        
        if (time_passed < FSR_BASE_RESET_TIMING ) {
            if (fsr.reset && fsr.reading > fsr.acc && fsr.reading > FSR_THRES_LOW) {
                fsr.acc = (fsr.acc + fsr.reading) / 2;
                dprintf("%u %u \n", fsr.reading, fsr.acc);
            }
        }
        else {
            fsr.base = (uint16_t) (fsr.acc / 10) * 10;
            dprintf("a %u b %u : r %u \n", fsr.acc, fsr.base, fsr.reading);
        
            // Reset
            fsr.acc = 0;
            flip_switch = false;
        }
    }

    if (fsr.reading >= fsr.base) {
        if (fsr.stack < COUNT_STACK_THRES) {
            fsr.stack += 1;
        } else {
            return true;
        }
    } else {
        if (fsr.stack > 0) fsr.stack -= 1;
    }
    
    return false;
    
}

void fsr_send_string(void) {
    char tv[32]; // thres_actual value string
    sprintf(tv, "b %u r %u", fsr.base, fsr.reading);
    SEND_STRING(tv);

}

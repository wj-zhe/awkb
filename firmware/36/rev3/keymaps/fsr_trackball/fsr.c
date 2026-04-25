
#include "analog.h"

#ifndef FSR_PIN
#   define FSR_PIN GP26
#endif

#ifndef BASE_INIT
#   define BASE_INIT 500
#endif

#ifndef COUNT_STACK_THRES
#   define COUNT_STACK_THRES 50
#endif

#ifndef FSR_RESET_TIMING
#   define FSR_RESET_TIMING 195
#endif

struct adj_t {
    const uint8_t a;
    const uint8_t b;
}; 

struct fsr_t {
    uint16_t reading;
    uint16_t base;
    struct adj_t adj;
    uint8_t stack; // counter
    uint8_t r;
} fsr = {
    .reading = 0,
    .base = BASE_INIT,
    .adj = {.a=10, .b=50},
    .r = 0 /* 0 for idle, 1 for move, 2 for no reset */
};

static uint16_t acc[2] = {BASE_INIT}; // sum result
static uint16_t timer[2];
static bool _return = false;

void base_set_f(uint8_t f_id); // base line setting function

bool fsr_sense(void) {
    // Calculate FSR reading value
    fsr.reading = (fsr.reading + analogReadPin(FSR_PIN)) /2;

    // Fetch fsr reading and calculate base line
    if (timer[fsr.r] ==0) {
        timer[fsr.r] = timer_read();
    } else {
        if (fsr.r <=1) base_set_f(fsr.r);
    }

    // Decide return value
    if (fsr.reading > fsr.base) {
        if (fsr.stack < COUNT_STACK_THRES) ++fsr.stack;
    } else {
        if (fsr.stack > 0) fsr.stack--;
    }

    if (fsr.stack >= COUNT_STACK_THRES) {
        _return = true;
    } else if (fsr.stack ==0) {
        _return = false;
    }
    
    return _return;
}

void base_set_f (uint8_t id) {
    // Calculate time
    uint16_t time_passed = timer_elapsed(timer[id]);

    if (time_passed < FSR_RESET_TIMING) {
        if ( id ==0 || (id ==1 && fsr.reading > acc[1] - fsr.adj.b ) ) {
            acc[id] = acc[id] * 1/2 + fsr.reading * 1/2;
        }
    }    
    else if (time_passed < FSR_RESET_TIMING + 5){
        if (acc[0] > acc[1] && acc[1] >0 ) acc[0] = acc[1] - fsr.adj.b;
        
        if (acc[1] > 0 && acc[0] >0) {
            fsr.base = (uint16_t) ((acc[0] * 1/2 + acc[1] * 1/2) /10) * 10 + fsr.adj.a;
        }
    }
    else {
        // Display data
        dprintf("%3d | %4u %4u > %4u | %5u \n", 
            id,
            acc[0], acc[1], 
            fsr.base,
            time_passed
        );

        // Reset
        timer[id] = 0;
    }
}

void fsr_info_string(void) {
    char ch[64];
    sprintf(ch, "b %u r %u", fsr.base, fsr.reading );
    SEND_STRING(ch);
}
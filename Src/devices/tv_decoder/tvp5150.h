#include "main.h"

#define IMG_ROWS 800
#define IMG_COLUMNS 306

extern uint8_t *frame_buffer;//[IMG_ROWS* IMG_COLUMNS];

void tvp5150_init_register();
void tvp5150_reset();
uint8_t tvp5150_get_status();
void tvp5150_capture_snapshot();

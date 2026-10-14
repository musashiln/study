#include <stdio.h>

typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_ERROR
} State;

static State next_state(State state, int event)
{
    if (event < 0) return STATE_ERROR;
    if (event > 0) return STATE_RUNNING;
    return state;
}

int main(void)
{
    State state = STATE_IDLE;
    state = next_state(state, 1);
    printf("state=%d\n", state);
    return 0;
}

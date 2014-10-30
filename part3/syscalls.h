#pragma once

#include "shuttle.h"

int start_shuttle(void);
int stop_shuttle(void);
int issue_request(char passenger_type, int initial_terminal, int destination_terminal);

#ifndef LIMIT_SWITCH_UNIT_TEST_H
#define LIMIT_SWITCH_UNIT_TEST_H

void aFunction(int gpio, int level, uint32_t tick);
void monitorSwitch(int switchPin, int ledPin, const char* switchName);
int LimitSwitchExecutable();

#endif
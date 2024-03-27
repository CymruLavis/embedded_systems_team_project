// Header file: limit switch unit test
#ifndef LimitSwitchUnitTest_h
#define LimitSwitchUnitTest_h

class LimitGateSwitch {
public:
    // Initialize the light gate switch pin number
    LimitGateSwitch(int switchPin);
    
    
    // Start monitoring the switch
    void startMonitoring();
    
    // Stop monitoring the switch
    void stopMonitoring();
    
    // Check if the switch is activated
    bool isActivated() const;

private:
    int switchPin_; // GPIO pin number of the switch
    bool activated_; // Flag indicating whether the switch is activated
};

#endif



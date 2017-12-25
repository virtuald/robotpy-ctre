




#include <CANifier_CCI.h>

class CANifier {

  void * m_handle;

public:
  CANifier(int deviceNumber) {
    m_handle = c_CANifier_Create1(deviceNumber);
  }
  
  void setLEDOutput(uint32_t dutyCycle, uint32_t ledChannel) {
    
    return CheckCTRCode( c_CANifier_SetLEDOutput(m_handle, dutyCycle, ledChannel ));
  }
  
  void setGeneralOutputs(uint32_t outputsBits, uint32_t isOutputBits) {
    
    return CheckCTRCode( c_CANifier_SetGeneralOutputs(m_handle, outputsBits, isOutputBits ));
  }
  
  void setGeneralOutput(uint32_t outputPin, bool outputValue, bool outputEnable) {
    
    return CheckCTRCode( c_CANifier_SetGeneralOutput(m_handle, outputPin, outputValue, outputEnable ));
  }
  
  void setPWMOutput(uint32_t pwmChannel, uint32_t dutyCycle) {
    
    return CheckCTRCode( c_CANifier_SetPWMOutput(m_handle, pwmChannel, dutyCycle ));
  }
  
  void enablePWMOutput(uint32_t pwmChannel, bool bEnable) {
    
    return CheckCTRCode( c_CANifier_EnablePWMOutput(m_handle, pwmChannel, bEnable ));
  }
  
  void getGeneralInputs(bool allPins, uint32_t capacity) {
    
    return CheckCTRCode( c_CANifier_GetGeneralInputs(m_handle, allPins, capacity ));
  }
  
  void getGeneralInput(uint32_t inputPin, bool measuredInput) {
    bool measuredInput;
    return CheckCTRCode( c_CANifier_GetGeneralInput(m_handle, inputPin, &measuredInput ));
  }
  
  void getPWMInput(uint32_t pwmChannel, float dutyCycleAndPeriod) {
    
    return CheckCTRCode( c_CANifier_GetPWMInput(m_handle, pwmChannel, dutyCycleAndPeriod ));
  }
  
  void getLastError() {
    
    return CheckCTRCode( c_CANifier_GetLastError(m_handle ));
  }
  
  void getBatteryVoltage(float batteryVoltage) {
    float batteryVoltage;
    return CheckCTRCode( c_CANifier_GetBatteryVoltage(m_handle, &batteryVoltage ));
  }
  
  void setLastError(int error) {
    
     c_CANifier_SetLastError(m_handle, error );
  }
  
};

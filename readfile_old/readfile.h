#include "BetaDecay.h"
#include "/user/e14066/ddasdumper/DDASEvent.h"

void readfile_fun(const Char_t*,const Int_t,const Char_t *);
void ResetChannelList(void);
void DDAS2Event(BetaDecay *bdecay);
void SortPID(BetaDecay *bdecay);
void CalculateTimes(BetaDecay *bdecay);
void ReadCalibrationParameters(Char_t * name);

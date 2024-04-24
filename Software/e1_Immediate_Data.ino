// This part is processed with the highest priority. It should ony contain asynchonus communication tasks that are triggered from an external device

void immediateData(){
 #if defined(D7_IS_VICTRON)
  RecvWithEndMarker();               //Get Victron serial stream
  HandleNewData();                   //Interpret Results
  EstimateIOhm();                    //Estimate internal resistance
#endif 
}

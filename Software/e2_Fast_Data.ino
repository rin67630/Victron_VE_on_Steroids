// This part is processed every 128mS
void data125mSRun()
{
#ifdef DASHBRD_IS_THINGER
  thing.handle();
#endif
}

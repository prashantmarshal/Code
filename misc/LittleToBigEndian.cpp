short convert_short(short in)
{
  short out;
  char *p_in = (char *) &in;
  char *p_out = (char *) &out;
  p_out[0] = p_in[1];
  p_out[1] = p_in[0];  
  return out;
}

long convert_long(long in)
{
  long out;
  char *p_in = (char *) &in;
  char *p_out = (char *) &out;
  p_out[0] = p_in[3];
  p_out[1] = p_in[2];
  p_out[2] = p_in[1];
  p_out[3] = p_in[0];  
  return out;
}
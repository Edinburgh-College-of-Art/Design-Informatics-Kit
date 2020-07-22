void halt(const char* =""); // forward declare with default argument
void halt(const char* errorMessage)
{
  Serial.println("Halting firmware\n");
  Serial.println(errorMessage);
  Serial.println();
  while (1) {}
}

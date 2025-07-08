void playAudio(int audioLength, const unsigned char audioData[]){
  for (int i = 1; i<audioLength; i++){
    dacWrite(26,audioData[i]);
    delayMicroseconds(125);
  }
}
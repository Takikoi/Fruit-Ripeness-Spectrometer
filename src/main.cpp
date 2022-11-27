#include <Arduino.h>

// INPUT
#define SPEC_TRG          A0
#define SPEC_VIDEO        A3
#define SPEC_EOS          A5

// OUTPUT
#define SPEC_CLK          A2
#define SPEC_ST           A1
#define WHITE_LED         A4

const uint8_t CLK_FREQ_MHz = 3;
const uint8_t SPEC_NUM_PIXELS = 288;   // sensor has 288 pixel

const uint16_t SPEC_WAVELENGTH_MIN = 340;
const uint16_t SPEC_WAVELENGTH_MAX = 850;

uint16_t spectrumData[SPEC_NUM_PIXELS];

void setup()
{
  // Output pins
  pinMode(SPEC_CLK, OUTPUT);
  pinMode(SPEC_ST, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);

  // Input pins
  pinMode(SPEC_EOS, INPUT);
  pinMode(SPEC_VIDEO, INPUT);

  // Init pin logic
  digitalWrite(SPEC_CLK, HIGH); 
  digitalWrite(SPEC_ST, LOW);
  digitalWrite(WHITE_LED, LOW);

  Serial.begin(115200); 
}


void ReadSpectrometer()
{
  float clockInterval = 1.f / CLK_FREQ_MHz; // microseconds

  // look at datasheet and github for reference
}


void PrintSpectrumData()
{
  for (int i = 0; i < SPEC_NUM_PIXELS; i++)
  {
    Serial.print(spectrumData[i]);
    (i >= SPEC_NUM_PIXELS) ? Serial.print("\n") : Serial.print(",");
  }
}

void loop()
{
  ReadSpectrometer();
  PrintSpectrumData();
}

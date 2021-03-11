// Link do artigo https://bibliotecadigital.ipb.pt/bitstream/10198/21588/1/pauta-relatorio-9.pdf

int led_pin = PD6; 
int pot_pin = A0;
int output;
int refreshRate;

uint32_t lastTimeRef;
uint32_t periodUs = 0; // Periodo em microsegundos
uint32_t dutyCycle = 0;

void setup() 
{
  pinMode(led_pin, OUTPUT);
}

void loop() 
{
  // Se estamos no fim do periodo lê o novo periodo e desliga a luz
  if((micros() - lastTimeRef) >= periodUs)
  {
    lastTimeRef = micros();    

    //Reading from potentiometer
    output = analogRead(pot_pin);

    //Mapping the Values between 0 to 255 because we can give output
    //from 0 -255 using the analogwrite funtion
    periodUs = map(output, 1, 1023, 100000, 1); // Converte para microsegundos

    dutyCycle = (periodUs * 1) / 10;

    digitalWrite(led_pin, HIGH);
    delayMicroseconds(dutyCycle);
    digitalWrite(led_pin, LOW);
  }
}

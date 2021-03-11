// Link do artigo #1 - https://bibliotecadigital.ipb.pt/bitstream/10198/21588/1/pauta-relatorio-9.pdf

int led_pin = PD6; 
int pot_pin = A0;
int output;
int refreshRate;

uint32_t lastTimeRef;
uint32_t periodUs   = 0; // Periodo em microsegundos
uint32_t dutyCycle  = 0;

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

    // Lê o potenciometro
    output = analogRead(pot_pin);

    // Transforma o valor lido do ADC (0 - 1023) para 100000 - 1 
    // este valor vai ser usado para calcular o tempo que a luz está ligada e desligada
    periodUs = map(output, 0, 1023, 100000, 1);

    dutyCycle = (periodUs * 1) / 10; // Duty cycle é 1/10 do periodo total (Ler o artigo #1)
    
    digitalWrite(led_pin, HIGH);  // Liga a luz 
    delayMicroseconds(dutyCycle); // Espera 10% do periodo total
    digitalWrite(led_pin, LOW);   // Desliga a luz
  }
}

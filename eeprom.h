#include <EEPROM.h>

//******************** EEPROM *******************//
// Endereços reservados na memória
uint8_t addr1 = 7;    // status_auto
uint8_t eeAddress;

// Funções para gerenciamento
// A função Save_Data foi montada de forma a evitar o desgaste da memoria EEPROM Salvando apenas os valores se o mesmo for alterado
void Save_Data() {// adicione essa função onde os dados são alterados
 EEPROM.put(addr1,  status_auto);
  eeAddress = 9;    //endereço inicial eeprom
  EEPROM.put(eeAddress , tempoD1);      // Grava a variavel somente se o valor for diferente do anterior
  eeAddress += sizeof(int);              // Incrementa o endereco com valor do tamanho da variavel gravada (int).
  EEPROM.put(eeAddress , tempoD2);      // Grava a variavel se o valor for diferente
  eeAddress += sizeof(int);             // Incrementa o endereco com valor do tamanho da variavel gravada (int).
  EEPROM.put(eeAddress , tempoD3);      // Grava a variavel se o valor for diferente
  eeAddress += sizeof(int);
  EEPROM.commit();
  Serial.println("*WifiRTC: Dados salvos na EEPROM");
}

void Read_Data() {// incluida no void Eeprom()
 eeAddress = 9; // recupera o endereço
  EEPROM.get(addr1,  status_auto);//
  EEPROM.get(eeAddress , tempoD1);    // Le a EEPROM e salva na variavel
  eeAddress += sizeof(int);               // Incrementa o endereco com valor do tamanho da variavel gravada (int).
  EEPROM.get(eeAddress , tempoD2);    // Le a EEPROM e salva na variavel
  eeAddress += sizeof(int);               // Incrementa o endereco com valor do tamanho da variavel gravada (int).
  EEPROM.get(eeAddress , tempoD3);    // Le a EEPROM e salva na variavel
  eeAddress += sizeof(int);

  Serial.println("*WifiRTC: Dados lidos da EEPROM");
}


//
void Eeprom() { //colocar no setup
  EEPROM.begin(512);
  Read_Data();
  delay(250);
}

void clearEeprom() {// função para limpar a memoria eeprom 
  for (int i = 0; i <= 512; i++) {
    EEPROM.write(i, 0);
    EEPROM.end();
  }
}



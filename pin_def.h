#ifndef PIN_DEF_H_
#define PIN_DEF_H_
//pin definitions for the Arduino Mega

//RFID pins
#define RFID_SS       53
#define RFID_RST      A13  // TODO: inteferes with the RFID pin, need to change

//Keypad pins
const uint8_t rowPins[4] = {A15, A14, 6, A12};
const uint8_t colPins[4] = {A11, A10, A9, A8};

//servo
#define SERVO_PIN     11

//reed switch pin
#define REED_SWITCH_PIN 2


//Arduno pin defines
// ---------------
//   Pin Defines
// ---------------

#define LED_PORT                PORTB
#define LED_PIN                 PINB
#define LED_DDR                 DDRB

#define LED0                    PB0
#define LED1                    PB1
#define LED2                    PB2
#define LED3                    PB3
#define LED4                    PB4
#define LED5                    PB5
#define LED6                    PB6
#define LED7                    PB7

#define BUTTON_PORT             PORTD
#define BUTTON_PIN              PIND
#define BUTTON_DDR              DDRD

#define BUTTON                  PD2
#define BUTTON2                 PD3
#define BUTTON3                 PD4

#define SPEAKER                 PB4                            /* OC0A */
#define SPEAKER_PORT            PORTB
#define SPEAKER_PIN             PINB
#define SPEAKER_DDR             DDRB

#define ANTENNA                 PD5                            /* OC0B */
#define ANTENNA_PORT            PORTD
#define ANTENNA_PIN             PIND
#define ANTENNA_DDR             DDRD

#define MODULATION              PD3                            /* OC2B */
#define MODULATION_PORT         PORTD
#define MODULATION_PIN          PIND
#define MODULATION_DDR          DDRD

#define LIGHT_SENSOR            PC0                            /* ADC0 */
#define LIGHT_SENSOR_PORT       PORTC
#define LIGHT_SENSOR_PIN        PINC
#define LIGHT_SENSOR_DDR        DDRC

#define CAP_SENSOR              PC1                            /* ADC1 */
#define CAP_SENSOR_PORT         PORTC
#define CAP_SENSOR_PIN          PINC
#define CAP_SENSOR_DDR          DDRC

#define PIEZO                   PC2                            /* ADC2 */
#define PIEZO_PORT              PORTC
#define PIEZO_PIN               PINC
#define PIEZO_DDR               DDRC

#define POT                     PC3                            /* ADC3 */
#define POT_PORT                PORTC
#define POT_PIN                 PINC
#define POT_DDR                 DDRC

//  SPI and I2C serial mode defines

#define SPI_SS                     PB2
#define SPI_SS_PORT                PORTB
#define SPI_SS_PIN                 PINB
#define SPI_SS_DDR                 DDRB

#define SPI_MOSI                     PB3
#define SPI_MOSI_PORT                PORTB
#define SPI_MOSI_PIN                 PINB
#define SPI_MOSI_DDR                 DDRB

#define SPI_MISO                     PB4
#define SPI_MISO_PORT                PORTB
#define SPI_MISO_PIN                 PINB
#define SPI_MISO_DDR                 DDRB

#define SPI_SCK                     PB5
#define SPI_SCK_PORT                PORTB
#define SPI_SCK_PIN                 PINB
#define SPI_SCK_DDR                 DDRB

#define I2C_SDA                     PC4
#define I2C_SDA_PORT                PORTC
#define I2C_SDA_PIN                 PINC
#define I2C_SDA_DDR                 DDRC

#define I2C_SCL                     PC5
#define I2C_SCL_PORT                PORTC
#define I2C_SCL_PIN                 PINC
#define I2C_SCL_DDR                 DDRC
#endif
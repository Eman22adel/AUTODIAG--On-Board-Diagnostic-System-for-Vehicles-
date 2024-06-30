#ifdef ESP8266
  #include <ESP8266WiFi.h> // Pins for board ESPE266 Wemos-NodeMCU
  #else
  #include <WiFi.h>
#endif

#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiclientSecure.h>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "C:\Users\emana\Desktop\ESP_FF24_Final\Final_ESP8266\SPI.h"
#include "HardwareSerial.h"
#include "Arduino.h"

const int led = 5;

#define SPI_PINS_HSPI			0 // Normal HSPI mode (MISO = GPIO12, MOSI = GPIO13, SCLK = GPIO14);
#define SPI_PINS_HSPI_OVERLAP	1 // HSPI Overllaped in spi0 pins (MISO = SD0, MOSI = SDD1, SCLK = CLK);

#define SPI_OVERLAP_SS 0

// Wi-Fi credentials
const char* ssid = "Eng";
const char* password = "010011012";
/*
const char* ssid = "Risk";
const char* password = "Risk2040";

const char* ssid = "iTi-Guest";
const char* password = "iti@su&&HH";*/


// MQTT broker credentials
const char* mqtt_server = "ba56550c63b34369a905b1bf7dfcb61f.s2.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_username = "ahmedsamir4299";
const char* mqtt_password = "01060402354aA";

WiFiClientSecure espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

static const char *root_ca PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIFazCCA10gAwIBAgIRAIIQZ7DSQONZRGPgu20CiwAwDQYJKOZIhvcNAQELBQAW 
TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFN1Y3VyaXR5IFJ1c2Vh 
cmNoIEdyb3VWMRUWEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMTUwNjA0MTEwNDM4
WhcNMzUwNjA0MTEwNDM4WjBPMQswCQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJu 
ZXQgU2VjdXJpdHkgUmVzZWFyY2ggR3JvdXAXFTATBgNVBAMTDE1TUkcgUm9vdCBY 
MTCCAIIWDQYJKOZIhvcNAQEBBQADggIPADCCAgoCggIBAK30JHP0FDfzm54rVygc 
h77ct984kIxuPOZXoHj3dcKi/vVqbvYATyjb3miGbESTtrFj/RQSa78f0uoxmyF+ 
0TM8ukj13Xnfs7j/EvEhmkvBioZxaUpmZmyPfjxwv60pIgbz5MDmgK7iS4+3mX6U 
A5/TR5d8mUgjU+g4rk8Kb4Mu UlXjIBOttov DiNewNwIRt18jA8+o+u3dpjq+sW 
T8KOEUt+zwvo/7V3LvSye0rgTBI1DHCNAymg4VMk7BPZ7hm/ELNKjD+Jo2FR3qyH 
B5T0Y3HsLuJvW5iB4YlcNHlsdu87kGJ55tukmi8mxdAQ4Q7e2RCOFvu396j3x+UC 
B5iPNgiV5+131g02dZ77DnKxHZu8A/1JBdiB3QW0KtZB6awBdpUKD9jf1b0SHzUv
KBds0pjBqAlkd25HN7rOrFleaJ1/ctaJxQZBKT5ZPt0m9STJEadao0xAH0ahmbWn
OlFuhjuefXKnEgV4We0+UXgVCwOPjdAvBbI+e0ocS3MFEvzG6uBQE3xDk3SzynTn
jh8BCNAw1FtxNrQHusEwMFxIt4I7mKZ9YIqioymCzLq9gwQbooMDQaHWBfEbwrbw 
qHyGO0aoSCqI3Haadr8faqU9GY/rOPNk3sgrDQoo//fb4hVC1CLQJ13hef4Y53CI 
rU7m2Ys6xt0nUW7/vGT1M0NPAgMBAAGJQJBAMA4GA1UdDWEB/WQEAWIBBJAPBgNV 
HRMBAF8EBTADAQH/MBOGA1UdDgQWBBR5tFnme7b15AFzgAiIyBpY9umbbjANBgkq 
hkiG9w0BAQSFAAOCAgEAVR9YqbyyqFDQDLHYGmkgJykIrGF1XIpu+ILlaS/V91ZL 
ubhzEFnTIZd+50xx+7LSYK05qAvqFyFWhfFQDlnrzuBZ6brJFe+GnY+EgPbk6ZGQ 
3BebYhtF8GaVenxvwuo77x/Py9auJ/GpsMiu/X1+mvoiBOv/2X/qkSsisRcOj/KK
NFtY2PwByVS5uCbMiogziUwthDyC3+6WVwW6LLv3xLfHTjuCvjHIInNzktHCgKQ5 
ORAZI4JMPJ+Gs1WYHb4phowim57iaztXOoJwTdwJx4nLCgdNbOhdjsnvzqvHu7Ur
TkXWStAmzOVvvghapZXiFaH30O3JLF+1+/+sKAIuvtd7u+Nxe5AW0wdeR1N8NwdC
jNPE1pzVmbUq4JUagEiuTDkHzsxHpFKVK7q4+63SM1N95R1NbdWhscdCb+ZAJzVc 
oyi3843njTOQ5yOf+1CceWxG1bQVs5ZufpsMljq4Ui0/1lvh+wjChP4kqKOJ2qxq 
4RgqsahDYVVTH9w7jXbyLeiNdd8XM2w9U/t7y0Ff/9yi0GE44Za4rF2LN9d11TPA
mRGunUHBcnWEvgJBQ19nJEiU0Zsnvgc/ubhPgXRR4Xq37Z0j4r7g1SgEEzwxA57d 
emyPxgcYxn/eR44/KJ4EBs+1VDR3veyJm+kXQ99b21/+jh5Xos1AnX5iItreGCc= 
-----END CERTIFICATE----- 
)EOF";



typedef union {
        uint32_t regValue;
        struct {
                unsigned regL :6;
                unsigned regH :6;
                unsigned regN :6;
                unsigned regPre :13;
                unsigned regEQU :1;
        };
} spiClk_t;

SPIClass::SPIClass() {
    useHwCs = false;
    pinSet = SPI_PINS_HSPI;
}

bool SPIClass::pins(int8_t sck, int8_t miso, int8_t mosi, int8_t ss)
{
    if (sck == 6 &&
        miso == 7 &&
        mosi == 8 &&
        ss == 0) {
        pinSet = SPI_PINS_HSPI_OVERLAP;
    } else if (sck == 14 &&
	           miso == 12 &&
               mosi == 13) {
        pinSet = SPI_PINS_HSPI;
    } else {
        return false;
    }

    return true;
}


void SPIClass::begin() {
    switch (pinSet) {
    case SPI_PINS_HSPI_OVERLAP:
        IOSWAP |= (1 << IOSWAP2CS);
        //SPI0E3 |= 0x1; This is in the MP3_DECODER example, but makes the WD kick in here.
        SPI1E3 |= 0x3;

        setHwCs(true);
        break;
    case SPI_PINS_HSPI:
    default:
        pinMode(SCK, SPECIAL);  ///< GPIO14
        pinMode(MISO, SPECIAL); ///< GPIO12
        pinMode(MOSI, SPECIAL); ///< GPIO13
        break;
    }

    SPI1C = 0;
    setFrequency(1000000); ///< 1MHz
    SPI1U = SPIUMOSI | SPIUDUPLEX | SPIUSSE;
    SPI1U1 = (7 << SPILMOSI) | (7 << SPILMISO);
    SPI1C1 = 0;
}

void SPIClass::end() {
    switch (pinSet) {
    case SPI_PINS_HSPI:
        pinMode(SCK, INPUT);
        pinMode(MISO, INPUT);
        pinMode(MOSI, INPUT);
        if (useHwCs) {
            pinMode(SS, INPUT);
        }
        break;
    case SPI_PINS_HSPI_OVERLAP:
        IOSWAP &= ~(1 << IOSWAP2CS);
        if (useHwCs) {
            SPI1P |= SPIPCS1DIS | SPIPCS0DIS | SPIPCS2DIS;
            pinMode(SPI_OVERLAP_SS, INPUT);
        }
        break;
    }
}


void SPIClass::setHwCs(bool use) {
    switch (pinSet) {
    case SPI_PINS_HSPI:
        if (use) {
            pinMode(SS, SPECIAL); ///< GPIO15
            SPI1U |= (SPIUCSSETUP | SPIUCSHOLD);
    } else {
            if (useHwCs) {
                pinMode(SS, INPUT);
            SPI1U &= ~(SPIUCSSETUP | SPIUCSHOLD);
            }
        }
        break;
    case SPI_PINS_HSPI_OVERLAP:
        if (use) {
            pinMode(SPI_OVERLAP_SS, FUNCTION_1); // GPI0 to SPICS2 mode
            SPI1P &= ~SPIPCS2DIS;
            SPI1P |= SPIPCS1DIS | SPIPCS0DIS;
            SPI1U |= (SPIUCSSETUP | SPIUCSHOLD);
        }
        else {
            if (useHwCs) {
                pinMode(SPI_OVERLAP_SS, INPUT);
                SPI1P |= SPIPCS1DIS | SPIPCS0DIS | SPIPCS2DIS;
                SPI1U &= ~(SPIUCSSETUP | SPIUCSHOLD);
            }
        }
        break;
    }

    useHwCs = use;
}


void SPIClass::beginTransaction(SPISettings settings) {
    while(SPI1CMD & SPIBUSY) {}
    setFrequency(settings._clock);
    setBitOrder(settings._bitOrder);
    setDataMode(settings._dataMode);
}

void SPIClass::endTransaction() {
}


void SPIClass::setDataMode(uint8_t dataMode) {

    /**
     SPI_MODE0 0x00 - CPOL: 0  CPHA: 0
     SPI_MODE1 0x01 - CPOL: 0  CPHA: 1
     SPI_MODE2 0x10 - CPOL: 1  CPHA: 0
     SPI_MODE3 0x11 - CPOL: 1  CPHA: 1
     */

    bool CPOL = (dataMode & 0x10); ///< CPOL (Clock Polarity)
    bool CPHA = (dataMode & 0x01); ///< CPHA (Clock Phase)

    // https://github.com/esp8266/Arduino/issues/2416
    // https://github.com/esp8266/Arduino/pull/2418
    if(CPOL)          // Ensure same behavior as
        CPHA ^= 1;    // SAM, AVR and Intel Boards

    if(CPHA) {
        SPI1U |= (SPIUSME);
    } else {
        SPI1U &= ~(SPIUSME);
    }

    if(CPOL) {
        SPI1P |= 1<<29;
    } else {
        SPI1P &= ~(1<<29);
        //todo test whether it is correct to set CPOL like this.
    }

}


void SPIClass::setBitOrder(uint8_t bitOrder) {
    if(bitOrder == MSBFIRST) {
        SPI1C &= ~(SPICWBO | SPICRBO);
    } else {
        SPI1C |= (SPICWBO | SPICRBO);
    }
}



/**
 * calculate the Frequency based on the register value
 * @param reg
 * @return
 */
static uint32_t ClkRegToFreq(spiClk_t * reg) {
    return (ESP8266_CLOCK / ((reg->regPre + 1) * (reg->regN + 1)));
}

void SPIClass::setFrequency(uint32_t freq) {
    static uint32_t lastSetFrequency = 0;
    static uint32_t lastSetRegister = 0;

    if(freq >= ESP8266_CLOCK) {
        // magic number to set spi sysclock bit (see below.)
        setClockDivider(0x80000000);
        return;
    }

    if(lastSetFrequency == freq && lastSetRegister == SPI1CLK) {
        // do nothing (speed optimization)
        return;
    }

    const spiClk_t minFreqReg = { 0x7FFFF020 };
    uint32_t minFreq = ClkRegToFreq((spiClk_t*) &minFreqReg);
    if(freq < minFreq) {
        // use minimum possible clock regardless
        setClockDivider(minFreqReg.regValue);
        lastSetRegister = SPI1CLK;
        lastSetFrequency = freq;
        return;
    }

    uint8_t calN = 1;

    spiClk_t bestReg = { 0 };
    int32_t bestFreq = 0;

    // aka 0x3F, aka 63, max for regN:6
    const uint8_t regNMax = (1 << 6) - 1;

    // aka 0x1fff, aka 8191, max for regPre:13
    const int32_t regPreMax = (1 << 13) - 1;

    // find the best match for the next 63 iterations
    while(calN <= regNMax) {

        spiClk_t reg = { 0 };
        int32_t calFreq;
        int32_t calPre;
        int8_t calPreVari = -2;

        reg.regN = calN;

        while(calPreVari++ <= 1) { // test different variants for Pre (we calculate in int so we miss the decimals, testing is the easyest and fastest way)
            calPre = (((ESP8266_CLOCK / (reg.regN + 1)) / freq) - 1) + calPreVari;
            if(calPre > regPreMax) {
                reg.regPre = regPreMax;
            } else if(calPre <= 0) {
                reg.regPre = 0;
            } else {
                reg.regPre = calPre;
            }

            reg.regL = ((reg.regN + 1) / 2);
            // reg.regH = (reg.regN - reg.regL);

            // test calculation
            calFreq = ClkRegToFreq(&reg);
            //os_printf("-----[0x%08X][%d]\t EQU: %d\t Pre: %d\t N: %d\t H: %d\t L: %d = %d\n", reg.regValue, freq, reg.regEQU, reg.regPre, reg.regN, reg.regH, reg.regL, calFreq);

            if(calFreq == static_cast<int32_t>(freq)) {
                // accurate match use it!
                memcpy(&bestReg, &reg, sizeof(bestReg));
                break;
            } else if(calFreq < static_cast<int32_t>(freq)) {
                // never go over the requested frequency
                auto cal = std::abs(static_cast<int32_t>(freq) - calFreq);
                auto best = std::abs(static_cast<int32_t>(freq) - bestFreq);
                if(cal < best) {
                    bestFreq = calFreq;
                    memcpy(&bestReg, &reg, sizeof(bestReg));
                }
            }
        }
        if(calFreq == static_cast<int32_t>(freq)) {
            // accurate match use it!
            break;
        }
        calN++;
    }

    // os_printf("[0x%08X][%d]\t EQU: %d\t Pre: %d\t N: %d\t H: %d\t L: %d\t - Real Frequency: %d\n", bestReg.regValue, freq, bestReg.regEQU, bestReg.regPre, bestReg.regN, bestReg.regH, bestReg.regL, ClkRegToFreq(&bestReg));

    setClockDivider(bestReg.regValue);
    lastSetRegister = SPI1CLK;
    lastSetFrequency = freq;

}

void SPIClass::setClockDivider(uint32_t clockDiv) {
    if(clockDiv == 0x80000000) {
        GPMUX |= (1 << 9); // Set bit 9 if sysclock required
    } else {
        GPMUX &= ~(1 << 9);
    }
    SPI1CLK = clockDiv;
}



inline void SPIClass::setDataBits(uint16_t bits) {
    const uint32_t mask = ~((SPIMMOSI << SPILMOSI) | (SPIMMISO << SPILMISO));
    bits--;
    SPI1U1 = ((SPI1U1 & mask) | ((bits << SPILMOSI) | (bits << SPILMISO)));
}

uint8_t SPIClass::transfer(uint8_t data) {
    while(SPI1CMD & SPIBUSY) {}
    // reset to 8Bit mode
    setDataBits(8);
    SPI1W0 = data;
    SPI1CMD |= SPIBUSY;
    while(SPI1CMD & SPIBUSY) {}
    return (uint8_t) (SPI1W0 & 0xff);
}

uint16_t SPIClass::transfer16(uint16_t data) {
    union {
            uint16_t val;
            struct {
                    uint8_t lsb;
                    uint8_t msb;
            };
    } in, out;
    in.val = data;

    if((SPI1C & (SPICWBO | SPICRBO))) {
        //LSBFIRST
        out.lsb = transfer(in.lsb);
        out.msb = transfer(in.msb);
    } else {
        //MSBFIRST
        out.msb = transfer(in.msb);
        out.lsb = transfer(in.lsb);
    }
    return out.val;
}

void SPIClass::transfer(void *buf, uint16_t count) {
    uint8_t *cbuf = reinterpret_cast<uint8_t*>(buf);

    // cbuf may not be 32bits-aligned
    for (; (((unsigned long)cbuf) & 3) && count; cbuf++, count--)
        *cbuf = transfer(*cbuf);

    // cbuf is now aligned
    // count may not be a multiple of 4
    uint16_t count4 = count & ~3;
    transferBytes(cbuf, cbuf, count4);

    // finish the last <4 bytes
    cbuf += count4;
    count -= count4;
    for (; count; cbuf++, count--)
        *cbuf = transfer(*cbuf);
}

void SPIClass::write(uint8_t data) {
    while(SPI1CMD & SPIBUSY) {}
    // reset to 8Bit mode
    setDataBits(8);
    SPI1W0 = data;
    SPI1CMD |= SPIBUSY;
    while(SPI1CMD & SPIBUSY) {}
}

void SPIClass::write16(uint16_t data) {
    write16(data, !(SPI1C & (SPICWBO | SPICRBO)));
}

void SPIClass::write16(uint16_t data, bool msb) {
    while(SPI1CMD & SPIBUSY) {}
    // Set to 16Bits transfer
    setDataBits(16);
    if(msb) {
        // MSBFIRST Byte first
        SPI1W0 = (data >> 8) | (data << 8);
    } else {
        // LSBFIRST Byte first
        SPI1W0 = data;
    }
    SPI1CMD |= SPIBUSY;
    while(SPI1CMD & SPIBUSY) {}
}

void SPIClass::write32(uint32_t data) {
    write32(data, !(SPI1C & (SPICWBO | SPICRBO)));
}

void SPIClass::write32(uint32_t data, bool msb) {
    while(SPI1CMD & SPIBUSY) {}
    // Set to 32Bits transfer
    setDataBits(32);
    if(msb) {
        union {
                uint32_t l;
                uint8_t b[4];
        } data_;
        data_.l = data;
        // MSBFIRST Byte first
        data = (data_.b[3] | (data_.b[2] << 8) | (data_.b[1] << 16) | (data_.b[0] << 24));
    }
    SPI1W0 = data;
    SPI1CMD |= SPIBUSY;
    while(SPI1CMD & SPIBUSY) {}
}

/**
 * Note:
 *  data need to be aligned to 32Bit
 *  or you get an Fatal exception (9)
 * @param data uint8_t *
 * @param size uint32_t
 */
void SPIClass::writeBytes(const uint8_t * data, uint32_t size) {
    while(size) {
        if(size > 64) {
            writeBytes_(data, 64);
            size -= 64;
            data += 64;
        } else {
            writeBytes_(data, size);
            size = 0;
        }
    }
}

void SPIClass::writeBytes_(const uint8_t * data, uint8_t size) {
    while(SPI1CMD & SPIBUSY) {}
    // Set Bits to transfer
    setDataBits(size * 8);

    uint32_t * fifoPtr = (uint32_t*)&SPI1W0;
    const uint32_t * dataPtr = (uint32_t*) data;
    uint32_t dataSize = ((size + 3) / 4);

    while(dataSize--) {
        *fifoPtr = *dataPtr;
        dataPtr++;
        fifoPtr++;
    }

    __sync_synchronize();
    SPI1CMD |= SPIBUSY;
    while(SPI1CMD & SPIBUSY) {}
}

/**
 * @param data uint8_t *
 * @param size uint8_t  max for size is 64Byte
 * @param repeat uint32_t
 */
void SPIClass::writePattern(const uint8_t * data, uint8_t size, uint32_t repeat) {
    if(size > 64) return; //max Hardware FIFO

    while(SPI1CMD & SPIBUSY) {}

    uint32_t buffer[16];
    uint8_t *bufferPtr=(uint8_t *)&buffer;
    const uint8_t *dataPtr = data;
    volatile uint32_t * fifoPtr = &SPI1W0;
    uint8_t r;
    uint32_t repeatRem;
    uint8_t i;

    if((repeat * size) <= 64){
        repeatRem = repeat * size;
        r = repeat;
        while(r--){
            dataPtr = data;
            for(i=0; i<size; i++){
                *bufferPtr = *dataPtr;
                bufferPtr++;
                dataPtr++;
            }
        }

        r = repeatRem;
        if(r & 3) r = r / 4 + 1;
        else r = r / 4;
        for(i=0; i<r; i++){
            *fifoPtr = buffer[i];
            fifoPtr++;
        }
        SPI1U = SPIUMOSI | SPIUSSE;
    } else {
        //Orig
        r = 64 / size;
        repeatRem = repeat % r * size;
        repeat = repeat / r;

        while(r--){
            dataPtr = data;
            for(i=0; i<size; i++){
                *bufferPtr = *dataPtr;
                bufferPtr++;
                dataPtr++;
            }
        }

        //Fill fifo with data
        for(i=0; i<16; i++){
            *fifoPtr = buffer[i];
            fifoPtr++;
        }

        r = 64 / size;

        SPI1U = SPIUMOSI | SPIUSSE;
        setDataBits(r * size * 8);
        while(repeat--){
            SPI1CMD |= SPIBUSY;
            while(SPI1CMD & SPIBUSY) {}
        }
    }
    //End orig
    if (repeatRem) {
        setDataBits(repeatRem * 8);
        SPI1CMD |= SPIBUSY;
        while(SPI1CMD & SPIBUSY) {}
    }

    SPI1U = SPIUMOSI | SPIUDUPLEX | SPIUSSE;
}

/**
 * @param out uint8_t *
 * @param in  uint8_t *
 * @param size uint32_t
 */
void SPIClass::transferBytes(const uint8_t * out, uint8_t * in, uint32_t size) {
    while(size) {
        if(size > 64) {
            transferBytes_(out, in, 64);
            size -= 64;
            if(out) out += 64;
            if(in) in += 64;
        } else {
            transferBytes_(out, in, size);
            size = 0;
        }
    }
}

/**
 * Note:
 *  in and out need to be aligned to 32Bit
 *  or you get an Fatal exception (9)
 * @param out uint8_t *
 * @param in  uint8_t *
 * @param size uint8_t (max 64)
 */

void SPIClass::transferBytesAligned_(const uint8_t * out, uint8_t * in, uint8_t size) {
    if (!size)
        return;

    while(SPI1CMD & SPIBUSY) {}
    // Set in/out Bits to transfer

    setDataBits(size * 8);

    volatile uint32_t *fifoPtr = &SPI1W0;

    if (out) {
        uint8_t outSize = ((size + 3) / 4);
        uint32_t *dataPtr = (uint32_t*) out;
        while (outSize--) {
            *(fifoPtr++) = *(dataPtr++);
        }
    } else {
        uint8_t outSize = ((size + 3) / 4);
        // no out data only read fill with dummy data!
        while (outSize--) {
            *(fifoPtr++) = 0xFFFFFFFF;
        }
    }

    SPI1CMD |= SPIBUSY;
    while(SPI1CMD & SPIBUSY) {}

    if (in) {
        uint32_t *dataPtr = (uint32_t*) in;
        fifoPtr = &SPI1W0;
        int inSize = size;
        // Unlike outSize above, inSize tracks *bytes* since we must transfer only the requested bytes to the app to avoid overwriting other vars.
        while (inSize >= 4) {
            *(dataPtr++) = *(fifoPtr++);
            inSize -= 4;
            in += 4;
        }
        volatile uint8_t *fifoPtrB = (volatile uint8_t *)fifoPtr;
        while (inSize--) {
            *(in++) = *(fifoPtrB++);
        }
    }
}


void SPIClass::transferBytes_(const uint8_t * out, uint8_t * in, uint8_t size) {
    if (!((uint32_t)out & 3) && !((uint32_t)in & 3)) {
        // Input and output are both 32b aligned or NULL
        transferBytesAligned_(out, in, size);
    } else {
        // HW FIFO has 64b limit and ::transferBytes breaks up large xfers into 64byte chunks before calling this function
        // We know at this point at least one direction is misaligned, so use temporary buffer to align everything
        // No need for separate out and in aligned copies, we can overwrite our out copy with the input data safely
        uint8_t aligned[64]; // Stack vars will be 32b aligned
        if (out) {
            memcpy(aligned, out, size);
        }
        transferBytesAligned_(out ? aligned : nullptr, in ? aligned : nullptr, size);
        if (in) {
            memcpy(in, aligned, size);
        }
    }
}


#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SPI)
SPIClass SPI;
#endif



/*** Connect to Wi-Fi ************/
void setup_wifi() {
  delay(10);
  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}


/*** Connect to MQTT Broker ************/
void reconnect() {
 // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-"; // Create a random client ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("led_state");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds"); // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void callback(char* topic, byte* payload, unsigned int length) {

  String incommingMessage = "";
  for (int i = 0; i < length; i++) incommingMessage+= (char)payload[i];
  Serial.println("Message arrived ["+String(topic)+"]"+incommingMessage);
// check the incomming message
    if(strcmp(topic, "led_state") == 0) {
      if (incommingMessage.equals("1")) digitalWrite(led, HIGH); // Turn the LED on 
      else digitalWrite(led, LOW); // Turn the LED off
  }
}
/**** Method for Publishing MQTT Messages ******/
void publishMessage(const char* topic, String payload, boolean retained) {
    if (client.publish(topic, payload.c_str(), true)) 
    Serial.println("Message publised ["+String(topic)+"]: "+payload);
}



void setup() {
  

  pinMode(led, OUTPUT); //set up LED 
  Serial.begin(9600);
  while (!Serial) delay(1); 
  setup_wifi();
  
  #ifdef ESP8266
    espClient.setInsecure();
  #else
    espClient.setCACert(root_ca); // enable this line and the the "certificate" code for secure connection
  #endif

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

    // Initialize SPI
  // Configure SPI pins for HSPI mode (MISO = GPIO12, MOSI = GPIO13, SCLK = GPIO14)
  SPI.pins(14, 12, 13, 15);
  // Begin SPI communication
  SPI.begin();
  // Set bit order to MSBFIRST
  SPI.setBitOrder(MSBFIRST);
  // Set data mode to SPI_MODE0 (CPOL: 0, CPHA: 0)
  SPI.setDataMode(SPI_MODE0);
  // Set SPI frequency to 4 MHz
  SPI.setFrequency(SPI_CLOCK_DIV4);

}

void splitArrayAndPrint(char arr[], int size, int step,std::string* first, std::string* second, std::string* third) {
    int count = 0;
    if(step <= 0) {
        std::cerr << "Invalid step value." << std::endl;
        return;
    }

    for (int i = 0; i < size; i += step) {
        std::string str;
        for (int j = i; j < std::min(i + step, size); ++j) {
            str += arr[j];
        }
        //std::cout << "DTC " << count+1 << ": "<< str << std::endl;
        if(count == 0) {
          *first = str;
          count++;
        }else if(count == 1) {
          *second = str;
          count++;
        }else if(count == 2) {
          *third = str;
          count++;
        }
       
    }
}


uint8_t strat_mode = 0;
void loop(){
  
  if (!client.connected()) reconnect(); // check if client is connected 
  client.loop();
  // Add your MQTT publishing/subscribing logic here

  uint8_t Counter = 0;
  uint16_t dataToSend = 30;
  uint16_t Sensors [8] = {0,0,0,0,0,0,0,0};
  char DTC [15] = {};
  std::string DTC1;
  std::string DTC2;
  std::string DTC3;
  if(strat_mode == 0) {
    delay(1000);
    strat_mode =1;
  }
  int step = 5; 
  uint16_t dataReceived = SPI.transfer16(dataToSend);

  if (Counter == 0  && dataReceived == 14) {
    Sensors[0] = dataReceived;
    Serial.print("Sensor1: ");
    Serial.println(Sensors[Counter]);
    Counter++;
    for (; Counter < 8; Counter ++){
      Sensors[Counter] = SPI.transfer16(dataToSend);
      Serial.print("Sensor");
      Serial.print(Counter + 1);
      Serial.print(": ");
      Serial.println(Sensors[Counter]);
      dataReceived = 0;
      delay(1000);
     }
      
      DTC [0] = (char)SPI.transfer16(dataToSend);
     for(uint8_t i = 1; i < 15 ; i++){
      DTC [i] = (char)SPI.transfer16(dataToSend);
      if(i == 4) {
        Serial.print("DTC1 : ");
        Serial.print(DTC[0]);
        Serial.print(DTC[1]);
        Serial.print(DTC[2]);
        Serial.print(DTC[3]);
        Serial.print(DTC[4]);
        Serial.print("\n");
      }
      if(i == 9) {
        Serial.print("DTC2 : ");
        Serial.print(DTC[5]);
        Serial.print(DTC[6]);
        Serial.print(DTC[7]);
        Serial.print(DTC[8]);
        Serial.print(DTC[9]);
        Serial.print("\n");
      }
      if(i == 14) {
        Serial.print("DTC3 : ");
        Serial.print(DTC[10]);
        Serial.print(DTC[11]);
        Serial.print(DTC[12]);
        Serial.print(DTC[13]);
        Serial.print(DTC[14]);
        Serial.print("\n");
      }
      delay(200);
     }
    int size = sizeof(DTC) / sizeof(DTC[0]);
    splitArrayAndPrint(DTC,size,step,&DTC1,&DTC2,&DTC3);

DynamicJsonDocument Sensors_Readings_DTCs(2048);

    Sensors_Readings_DTCs["s_100_1"] = Sensors[1];
    Sensors_Readings_DTCs["s_101_100"] = Sensors[6];
    Sensors_Readings_DTCs["s_102_100"] = Sensors[7];
    Sensors_Readings_DTCs["s_103_1"] = Sensors[5];
    Sensors_Readings_DTCs["s_104_1"] = Sensors[3];
    Sensors_Readings_DTCs["s_105_1"] = Sensors[4];
    Sensors_Readings_DTCs["s_106_10"] = Sensors[0];
    Sensors_Readings_DTCs["s_107_100"] = Sensors[2];
  
  Sensors_Readings_DTCs["t_1: "] = DTC1;
  Sensors_Readings_DTCs["t_2: "] = DTC2;
  Sensors_Readings_DTCs["t_3: "] = DTC3;


//6346bed2-a0ec-4626-bea4-ab39775ed221  
  char mqtt_message[1024];
  serializeJson(Sensors_Readings_DTCs, mqtt_message);
  publishMessage("18cfa891-b3c4-4ee7-b467-ca0c9ec39950", mqtt_message, true);

    dataReceived = 0;
  }
  //exit(0);
  dataReceived = 0;
  delay(1000);
}

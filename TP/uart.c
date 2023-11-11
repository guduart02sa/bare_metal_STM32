#include "uart.h"
//PB6 E PB7

void uart_init(){
    USART1->CR1 &= ~USART_CR1_UE;

    USART1->RQR |= USART_RQR_TXFRQ;

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;        /* Configuration de les bits necessaires pour les ports B   */
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;       /* et le USART1.                                            */

    //REVER
    GPIOB->MODER = (GPIOB->MODER & ~(GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0)) | GPIO_MODER_MODE6_1 | GPIO_MODER_MODE7_1; /* Configuration de le moder pour USART 1 TX et RX   */
                    /*METTRE A ZERO LE DERNIER BIT(POIDS FAIBLE) DE CHAQUE PORT*/

    GPIOB->AFR[0] = (GPIOB->AFR[0] & ~(GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL6_3)) | (0b0111 << GPIO_AFRL_AFSEL7_Pos) | (0b0111 << GPIO_AFRL_AFSEL6_Pos);
                    /*METTRE A ZERO LE PREMIER BIT(POIDS FORT) DE CHAQUE AFSEL*/
    
    RCC->CCIPR &= ~(RCC_CCIPR_USART1SEL);       //REVER

    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;

    USART1->BRR = 0x2B6;       //From oversampling table for USART

    USART1->CR2 = 0;
    
    USART1->CR1 = (USART_CR1_TE|USART_CR1_RE|USART_CR1_UE);
                /*METTRE A ZERO TOUS LE BITS À CR1, SAUF M1, OVER8 ET UE*/
}

void uart_putchar(uint8_t c){
    while (!(USART1->ISR & USART_ISR_TXE));
    USART1->TDR = c;
//    while (!(USART1->ISR & USART_ISR_TC));
}

uint8_t uart_getchar(){
    while (!(USART1->ISR & USART_ISR_RXNE));
    return (uint8_t)USART1->RDR;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putchar(*s);
        s++;
    }

    uart_putchar('\n'); //Bien qu'il n'y ait pas de X dans l'implémentation linux de puts (du moins dans les sources que j'ai trouvées)    
    uart_putchar('\r'); //, j'ai inséré \r pour faciliter le débogage dans putty.
}

void uart_gets(char *s, size_t size){
    size_t i = 0;
    
    while (i < size-1) { 
        s[i] = uart_getchar();
        if (s[i] == '\n' || s[i] == '\r') {         //Normalement le \n est generé quand l'utilisateur appuie sur enter, mais
            break;                                  //dans le cas de putty, j'ai reçu \r\n, donc j'ai du ajouter ce if.
        }
        i++;
    }
    s[i] = '\0';
}
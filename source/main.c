/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2018, 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_debug_console.h"
#if defined(FSL_FEATURE_SOC_PORT_COUNT) && (FSL_FEATURE_SOC_PORT_COUNT)
#include "fsl_port.h"
#endif
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "app.h"
#include "pin_mux.h"
#include "board.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define SW2_ACTIVE  0x00800000
#define SW3_ACTIVE  0x00000040

/*******************************************************************************
 * Private functions prototypes
 ******************************************************************************/
static void GPIO_Init( void );

/*******************************************************************************
 * Private global data.
 ******************************************************************************/
static volatile uint8_t SW2PressCount = 0;
static volatile uint8_t SW3PressCount = 0;

/*******************************************************************************
 * Private functions definition
 ******************************************************************************/
/**
 * @brief This function initializes the required GPIOs for the project.
 * 
 */
static void GPIO_Init( void )
{
    //local data.
    gpio_pin_config_t sw2Config = { kGPIO_DigitalInput, 0 }; //SW2 GPIO config.
    gpio_pin_config_t sw3Config = { kGPIO_DigitalInput, 0 }; //SW3 GPIO config.

    /*Define the init structure for the output LED pin
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        0,
    };*/

    //Interrupt configuration.
    GPIO_SetPinInterruptConfig( GPIO0, BOARD_SW2_GPIO_PIN, kGPIO_InterruptFallingEdge );
    GPIO_SetPinInterruptConfig( GPIO0, BOARD_SW3_GPIO_PIN, kGPIO_InterruptFallingEdge );
    EnableIRQ( GPIO00_IRQn );

    //Initialize GPIOs configuration.
    GPIO_PinInit( GPIO0, BOARD_SW2_GPIO_PIN, &sw2Config );
    GPIO_PinInit( GPIO0, BOARD_SW3_GPIO_PIN, &sw3Config );
}

/*******************************************************************************
 * Public functions definition
 ******************************************************************************/
/*!
 * @brief Interrupt service fuction of GPIO0.
 * @note In this case is only used for the onboard push buttons.
 */
void BOARD_SW_IRQ_HANDLER( void )
{
    uint32_t gpio0InterruptRegister = GPIO_GpioGetInterruptFlags( GPIO0 );
    uint32_t gpio0ClearInterruptMask = 0;

    //Identify which pin set the interrupt.
    if ( gpio0InterruptRegister & SW2_ACTIVE )
    {
        //SW2 button pressed.
        gpio0ClearInterruptMask |= SW2_ACTIVE;
        SW2PressCount++;
    }

    if ( gpio0InterruptRegister & SW3_ACTIVE )
    {
        //SW3 button pressed.
        gpio0ClearInterruptMask |= SW3_ACTIVE;
        SW3PressCount++;
    }

    GPIO_GpioClearInterruptFlags( GPIO0, gpio0ClearInterruptMask );
}



/*!
 * @brief Main function
 */
int main(void)
{
    BOARD_InitHardware();
    GPIO_Init();
    
    /* Print a note to terminal. */
    //PRINTF("\r\n GPIO Driver example\r\n");
    //PRINTF("\r\n Press %s to turn on/off a LED \r\n", BOARD_SW_NAME);

    /* Init output LED GPIO. */
    //GPIO_PinInit(BOARD_LED_GPIO, BOARD_LED_GPIO_PIN, &led_config);

    while (1)
    {
       /* if (g_ButtonPress)
        {
            PRINTF(" %s is pressed \r\n", BOARD_SW_NAME);
            /* Toggle LED. 
            GPIO_PortToggle(BOARD_LED_GPIO, 1U << BOARD_LED_GPIO_PIN);
            /* Reset state of button. 
            g_ButtonPress = false;
        }
        */
    }
}

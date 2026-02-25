/**
 * @file Tasks.c
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This file contains the definition of tools and functions related to the scheduler tasks.
 * 
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Tasks.h"

/*******************************************************************************
 * Private function prototypes.
 ******************************************************************************/
static void System_Task1( uint32_t burstTime );
static void System_Task2( uint32_t burstTime );
static void System_Task3( uint32_t burstTime );
static void System_Task4( uint32_t burstTime );
static void System_Task5( uint32_t burstTime );
static void System_Task6( uint32_t burstTime );
static void System_Task7( uint32_t burstTime );
static void System_Task8( uint32_t burstTime );

/*******************************************************************************
 * Public function definitions.
 ******************************************************************************/
/**
 * @brief This function initialices the array control struct for the scheduler tasks.
 * 
 * @param ctrl Pointer to control structs.
 * @retval Operation result. 
 */
bool Task_Init( Task_Control_t* ctrl )
{
    bool result = false;

    if ( ctrl != NULL )
    {
        void* tasksAddr[NUM_TASKS] = { System_Task1, System_Task2, System_Task3, System_Task4,
                System_Task5, System_Task6, System_Task7, System_Task8 };

        for ( uint8_t i = 0; i < NUM_TASKS; i++ )
        {
            ctrl[i].TaskFunction = tasksAddr[i];
            ctrl[i].TaskId = i + 1;
            ctrl[i].Status = TASK_STATUS_BLOCKED_E;
            ctrl[i].BurstTime = TASK_DELAY_250_MS;
        }
                
        result = true;
    }

    return result;
}

/*******************************************************************************
 * Private function definitions.
 ******************************************************************************/
/**
 * @brief Task 1 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task1( uint32_t burstTime )
{
    PRINTF( "Executing Task 1\r\n" );

    //RGB LED off.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}

/**
 * @brief Task 2 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task2( uint32_t burstTime )
{
    PRINTF( "Executing Task 2\r\n" );

    //RGB LED RED on.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();
    LED_RED_ON();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}

/**
 * @brief Task 3 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task3( uint32_t burstTime )
{
    PRINTF( "Executing Task 3\r\n" );

    //RGB LED Yellow on.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();
    LED_RED_ON();
    LED_GREEN_ON();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}

/**
 * @brief Task 4 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task4( uint32_t burstTime )
{
    PRINTF( "Executing Task 4\r\n" );

    //RGB LED Magenta on.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();
    LED_RED_ON();
    LED_BLUE_ON();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}

/**
 * @brief Task 5 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task5( uint32_t burstTime )
{
    PRINTF( "Executing Task 5\r\n" );

    //RGB LED Green on.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();
    LED_GREEN_ON();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}

/**
 * @brief Task 6 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task6( uint32_t burstTime )
{
    PRINTF( "Executing Task 6\r\n" );

    //RGB LED Cyan on.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();
    LED_GREEN_ON();
    LED_BLUE_ON();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}

/**
 * @brief Task 7 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task7( uint32_t burstTime )
{
    PRINTF( "Executing Task 7\r\n" );

    //RGB LED Blue on.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();
    LED_BLUE_ON();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}

/**
 * @brief Task 8 function.
 * 
 * @param burstTime Delay for task in us.
 */
static void System_Task8( uint32_t burstTime )
{
    PRINTF( "Executing Task 8\r\n" );

    //RGB LED White on.
    LED_RED_OFF();
    LED_GREEN_OFF();
    LED_BLUE_OFF();
    LED_RED_ON();
    LED_GREEN_ON();
    LED_BLUE_ON();

    //Burst time.
    SDK_DelayAtLeastUs( burstTime, CORE_CLK );
}
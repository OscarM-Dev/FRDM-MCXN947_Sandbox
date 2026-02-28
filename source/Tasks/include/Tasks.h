/**
 * @file Tasks.h
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the declaration of tools and functions related to the scheduler tasks.
 * 
 */
#ifndef TASKS_H
#define TASKS_H
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "board.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define NUM_TASKS 8
#define CORE_CLK    150000000
#define TASK_DELAY_250_MS  250000
#define TASK_DELAY_500_MS  500000
#define TASK_DELAY_750_MS  750000
#define TASK_DELAY_1000_MS 1000000


/*******************************************************************************
 * Typedefs
 ******************************************************************************/
typedef void ( *Task ) ( uint32_t );

/*******************************************************************************
 * Enums
 ******************************************************************************/
/**
 * @brief Task ID enum.
 * 
 */
typedef enum Task_IDs
{
    TASK_ID_UNDEFINED_E,
    TASK_ID_1_E,
    TASK_ID_2_E,
    TASK_ID_3_E,
    TASK_ID_4_E,
    TASK_ID_5_E,
    TASK_ID_6_E,
    TASK_ID_7_E,
    TASK_ID_8_E
} Task_IDs_t;

/**
 * @brief Task status enum.
 * 
 */
typedef enum Task_Status
{
    TASK_STATUS_UNDEFINED,
    TASK_STATUS_READY_E,
    TASK_STATUS_RUNNING_E,
    TASK_STATUS_BLOCKED_E
} Task_Status_t;

/*******************************************************************************
 * Stucts and Unions.
 ******************************************************************************/
/**
 * @brief Task control struct.
 * 
 */
typedef struct Task_Control
{
    Task TaskFunction;
    Task_IDs_t TaskId;
    uint32_t BurstTime;     //us.
    volatile Task_Status_t Status;
} Task_Control_t;

/*******************************************************************************
 * Public function prototypes.
 ******************************************************************************/
bool Task_Init( Task_Control_t* ctrl );


#endif
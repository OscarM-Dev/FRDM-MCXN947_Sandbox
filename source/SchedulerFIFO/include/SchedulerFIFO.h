/**
 * @file SchedulerFIFO.h
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the declaration of tools and functions related to the FIFO scheduler. 
 * 
 */
#ifndef SCHEDULER_FIFO_H
#define SCHEDULER_FIFO_H
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"
#include "Tasks.h"
#include "Queue.h"

/*******************************************************************************
 * Stucts and Unions.
 ******************************************************************************/
/**
 * @brief Scheduler control struct.
 * 
 */
typedef struct Scheduler_FIFO
{
    Task_Control_t Tasks[NUM_TASKS];
    Queue_t Queue;
} Scheduler_FIFO_t;

/*******************************************************************************
 * Public function prototypes.
 ******************************************************************************/
bool Scheduler_FIFO_Init( Scheduler_FIFO_t* ctrl );
bool Scheduler_FIFO_ActivateTask( Scheduler_FIFO_t* ctrl, Task_IDs_t taskId );
bool Scheduler_FIFO_DeactivateTask( Scheduler_FIFO_t* ctrl, Task_IDs_t taskId );
bool Scheduler_FIFO_Run( Scheduler_FIFO_t* ctrl );

#endif

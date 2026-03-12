/**
 * @file SchedulerPriority.h
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the declaration of tools and functions related to the priority scheduler. 
 * 
 */
#ifndef SCHEDULER_PRIORITY_H
#define SCHEDULER_PRIORITY_H
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
typedef struct Scheduler_Priority
{
    Task_Control_t Tasks[NUM_TASKS];
    Queue_t Queue;
} Scheduler_Priority_t;

/*******************************************************************************
 * Public function prototypes.
 ******************************************************************************/
bool Scheduler_Priority_Init( Scheduler_Priority_t* ctrl );
bool Scheduler_Priority_ActivateTask( Scheduler_Priority_t* ctrl, Task_IDs_t taskId );
bool Scheduler_Priority_DeactivateTask( Scheduler_Priority_t* ctrl, Task_IDs_t taskId );
bool Scheduler_Priority_Run( Scheduler_Priority_t* ctrl );

#endif

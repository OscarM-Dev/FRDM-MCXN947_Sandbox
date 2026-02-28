/**
 * @file SchedulerFIFO.c
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the definition of tools and functions related to the FIFO scheduler. 
 * 
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "SchedulerFIFO.h"

/*******************************************************************************
 * Private global data.
 ******************************************************************************/
static Task_IDs_t TaskBuffer[NUM_TASKS];

/*******************************************************************************
 * Public function definitions.
 ******************************************************************************/
/**
 * @brief This function initialices the scheduler control struct. 
 * 
 * @param ctrl Pointer to scheduler control struct.
 * @retval Operation result.
 */
bool Scheduler_FIFO_Init( Scheduler_FIFO_t* ctrl )
{
    bool result = false;

    if ( ctrl != NULL )
    {
        Task_Init( ctrl->Tasks );
        Queue_InitQueue( &ctrl->Queue, NUM_TASKS, sizeof( Task_IDs_t ), TaskBuffer );
        result = true;
    }

    return result;
}

/**
 * @brief This function activates a task by changing its status to ready and registering it to the task queue.
 * 
 * @param ctrl Pointer to scheduler control struct.
 * @param taskId Task Id to active.
 * @retval Operation result.
 */
bool Scheduler_FIFO_ActivateTask( Scheduler_FIFO_t* ctrl, Task_IDs_t taskId )
{
    bool result = false;

    if ( ( ctrl != NULL ) && ( taskId != TASK_ID_UNDEFINED_E ) )
    {
        //Activate task  
        ctrl->Tasks[taskId - 1].Status = TASK_STATUS_READY_E;      

        //Register task in queue.
        Queue_WriteData( &ctrl->Queue, &taskId );

        result = true;
    }

    return result;
}

/**
 * @brief This function deactivates a task by changing its status to blocked and eliminating it from the task queue.
 * 
 * @param ctrl Pointer to the scheduler control struct.
 * @param taskId Task id to deactivate.
 * @retval Operation result.
 */
bool Scheduler_FIFO_DeactivateTask( Scheduler_FIFO_t* ctrl, Task_IDs_t taskId )
{
    bool result = false;

    if ( ( ctrl != NULL ) && ( taskId != TASK_ID_UNDEFINED_E ) )
    {
        //Deactivate task        
        ctrl->Tasks[taskId - 1].Status = TASK_STATUS_BLOCKED_E;

        //Eliminate task in queue.
        Queue_ReadData( &ctrl->Queue, NULL );

        result = true;
    }

    return result;   
}

/**
 * @brief This function runs the FIFO scheduler.
 * @note The scheduler traverse the queue only once.
 * @note Peek always starts from Tail index.
 * @note The data available count takes the current value of Datacount member of queue, if there is a change
 * in this data like increment o decrement caused by head or tail ( buttons ) the change will be present in the next
 * scheduler iteration.
 * 
 * @param ctrl Pointer to the scheduler control struct.
 * @retval Operation result.
 */
bool Scheduler_FIFO_Run( Scheduler_FIFO_t* ctrl )
{
    bool result = false;

    if ( ctrl != NULL )
    {
        uint8_t taskID = TASK_ID_UNDEFINED_E;
        uint8_t processDataCount = 0;
        uint8_t currentAvailableData = ctrl->Queue.DataCount;
        ctrl->Queue.Peek = ctrl->Queue.Tail;

        //Execute current activated tasks.
        while( processDataCount < currentAvailableData )
        {   
            Queue_PeekData( &ctrl->Queue, &taskID );

            if ( ctrl->Tasks[taskID - 1].Status == TASK_STATUS_READY_E )
            {   //Execute task.
                 ctrl->Tasks[taskID - 1].TaskFunction( ctrl->Tasks[taskID - 1].BurstTime );
            }

            processDataCount++;
        }

        result = true;
    }

    return result;
}

/**
 * @file SchedulerPriority.c
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the definition of tools and functions related to the priority scheduler. 
 * 
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "SchedulerPriority.h"

/*******************************************************************************
 * Private function prototypes.
 ******************************************************************************/
static uint8_t Get_TaskIndex_InQueue( Task_IDs_t* taskBuffer, Task_IDs_t taskId );
static Task_IDs_t Find_HighestPiority_Task( Scheduler_Priority_t* ctrl );

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
bool Scheduler_Priority_Init( Scheduler_Priority_t* ctrl )
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
bool Scheduler_Priority_ActivateTask( Scheduler_Priority_t* ctrl, Task_IDs_t taskId )
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
 * @note It eliminates the task using the special function of queue read data at. 
 * 
 * @param ctrl Pointer to the scheduler control struct.
 * @param taskId Task id to deactivate.
 * @retval Operation result.
 */
bool Scheduler_Priority_DeactivateTask( Scheduler_Priority_t* ctrl, Task_IDs_t taskId )
{
    bool result = false;

    if ( ( ctrl != NULL ) && ( taskId != TASK_ID_UNDEFINED_E ) )
    {
        uint8_t taskIndex = 0;

        //Deactivate task        
        ctrl->Tasks[taskId - 1].Status = TASK_STATUS_BLOCKED_E;

        //Eliminate task in queue.
        taskIndex = Get_TaskIndex_InQueue( ( Task_IDs_t* ) ctrl->Queue.Buffer, taskId );
        Queue_ReadDataAt( &ctrl->Queue, taskIndex, NULL );
        result = true;
    }

    return result;   
}

/**
 * @brief This function runs the Priority scheduler.
 * @note Peek always starts from Tail index.
 * @note The tasks are executed in priority order.
 * 
 * @param ctrl Pointer to the scheduler control struct.
 * @retval Operation result.
 */
bool Scheduler_Priority_Run( Scheduler_Priority_t* ctrl )
{
    bool result = false;

    if ( ctrl != NULL )
    {
        Task_IDs_t taskIdToRun = TASK_ID_UNDEFINED_E;
        Task_Control_t* taskToRun = NULL;

        //Execute available tasks in priority order.
        while ( ctrl->Queue.DataCount > 0 )
        {
            taskIdToRun = Find_HighestPiority_Task( ctrl );

            if ( taskIdToRun != TASK_ID_UNDEFINED_E )
            {
                taskToRun = &ctrl->Tasks[taskIdToRun - 1];
                taskToRun->Status = TASK_STATUS_RUNNING_E;
                taskToRun->TaskFunction( taskToRun->BurstTime );
                Scheduler_Priority_DeactivateTask( ctrl, taskIdToRun );
            }
        }

        result = true;
    }

    return result;
}

/*******************************************************************************
 * Private function definitions.
 ******************************************************************************/
/**
 * @brief This function gets the queue index of a given task id.
 * 
 * @param taskBuffer Pointer to task buffer.
 * @param taskId Task Id to search.
 * @retval Operation result.
 */
static uint8_t Get_TaskIndex_InQueue( Task_IDs_t* taskBuffer, Task_IDs_t taskId )
{
    uint8_t index = 0;

    if ( ( taskBuffer != NULL ) && ( taskId != TASK_ID_UNDEFINED_E ) )
    {
        for ( uint8_t i = 0; i < NUM_TASKS; i++ )
        {
            if ( taskBuffer[i] == taskId )
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

/**
 * @brief This function gets the highest priority task available in the task ready queue. 
 * @note Peek always start at tail element.
 * 
 * @param ctrl Pointer to scheduler control struct.
 * @retval Highest priority task present in queue.
 */
static Task_IDs_t Find_HighestPiority_Task( Scheduler_Priority_t* ctrl )
{
    Task_IDs_t taskId = TASK_ID_UNDEFINED_E;

    if ( ctrl != NULL )
    {
        Task_IDs_t currentTaskId = TASK_ID_UNDEFINED_E;
        Task_Priority_t highestPriority = TASK_PRIORITY_UNDEFINED;
        ctrl->Queue.Peek = ctrl->Queue.Tail;

        for ( uint8_t i = 0; i < ctrl->Queue.DataCount; i++ )
        {
            Queue_PeekData( &ctrl->Queue, &currentTaskId );
            
            //Verify task id.
            if ( currentTaskId != TASK_ID_UNDEFINED_E )
            {
                if ( ( ctrl->Tasks[currentTaskId - 1].Status == TASK_STATUS_READY_E ) && 
                    ( ctrl->Tasks[currentTaskId - 1].Task_Priority > highestPriority ) )
                {
                    highestPriority = ctrl->Tasks[currentTaskId - 1].Task_Priority;
                    taskId = currentTaskId;
                }
            }
        }
    }

    return taskId;
}
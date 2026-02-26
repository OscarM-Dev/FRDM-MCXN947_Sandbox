/**
 * @file Queue.h
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the declaration of tools and functions related to the queue operation.
 * 
 */
#ifndef QUEUE_H
#define QUEUE_H
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*******************************************************************************
 * Stucts and Unions.
 ******************************************************************************/
/**
  * @brief Control structure for operating the queue which members are 
  * related to the buffer and indexes for writing and reading.
*/
typedef struct Queue
{
    void *Buffer;       //Ptr to array (Queue).
    uint32_t Elements;  //Number of elements of the queue.
    uint8_t Size;       //Number of bytes of each element of the queue.
    uint8_t Head;       //Index for writing.
    uint8_t Tail;       //Index for reading.
    uint8_t Peek;       //Index for peeking.
    bool Empty;         //Bool flag that indicates if queue is empty.
    bool Full;          //Bool flag that indicates if queue is full.
} Queue_t;

/*******************************************************************************
 * Public function prototypes.
 ******************************************************************************/
void Queue_InitQueue( Queue_t *queue, uint32_t elements, uint8_t size, void *buffer );
bool Queue_WriteData( Queue_t *queue, void *data );
bool Queue_ReadData( Queue_t *queue, void *data );
bool Queue_PeekData( Queue_t *queue, void *data );
bool Queue_IsQueueEmpty( Queue_t *queue );
void Queue_FlushQueue( Queue_t *queue );

#endif
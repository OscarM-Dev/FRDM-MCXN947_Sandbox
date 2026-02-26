/**
 * @file Queue.h
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the definition of tools and functions related to the queue operation.
 * 
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Queue.h"

/*******************************************************************************
 * Public function definitions.
 ******************************************************************************/
/**
 * @brief This function initialices the queue.
 * 
 * @param queue Pointer to queue control structure.
 * @param elements Number of elements of the queue circular buffer.
 * @param size Size in bytes of each element of the queue.
 * @param buffer Pointer to queue circular buffer.
 */
void Queue_InitQueue( Queue_t *queue, uint32_t elements, uint8_t size, void *buffer )
{
    if ( ( queue != NULL ) && ( buffer != NULL ) && ( elements > 0 ) && ( size > 0 ) )
    {
        queue->Empty = true;
        queue->Full = false;
        queue->Head = 0;
        queue->Tail = 0;
        queue->Peek = 0;
        queue->Elements = elements;
        queue->Size = size;
        queue->Buffer = buffer;
    } 
}

/**
 * @brief This function writes a single data to the queue.
 * For achieving this it copies and pastes size bytes of info from data to the head element of the queue.
 * 
 * @note Once the writing operation is done it increments head by one.
 * @note It also determines wheter the queue is full or not after writing to it.
 * 
 * @param queue Pointer to queue control structure.
 * @param data Pointer to data to write.
 * @retval Operation result.
 */
bool Queue_WriteData( Queue_t *queue, void *data )
{
    bool status = false;

    if ( ( queue != NULL ) && ( data != NULL ) )
    {
        uint32_t baseAdd = ( uint32_t ) queue->Buffer;
        uint32_t actualAdd = 0;

        //Verifying if the queue is availabe to be written.
        if ( !queue->Full )
        {
            actualAdd = baseAdd + ( queue->Head * queue->Size );
            memcpy( ( void* ) actualAdd, data, queue->Size );
            queue->Head++;      //next value to be written.

            if ( queue->Head > queue->Elements - 1 )
            {   //Reseting write index.
                queue->Head = 0;
            }  
            
            if ( queue->Empty ) 
            {   //Once data is written the queue is no longer empty.
                queue->Empty = !queue->Empty;
            }

            //Verifying if queue is full with the last data written.
            if ( queue->Head == queue->Tail ) 
            {
                queue->Full = true;
            }

            status = true;  //Succesfull operation.
        } 
    }

    return status; 
}

/**
 * @brief This function reads a single data from the queue.
 * For achieving this it copies and pastes size bytes of info from the tail element of the queue to the data.
 * 
 * @note Once the reading operation is done it increments tail by one.
 * @note The data read no longer exists in the queue.
 * @note It also determines wheter the queue is empty or not after reading from it.
 * @note Is optional to read the info from the tail element, if not needed the tail element info is just discarded.
 * 
 * @param queue Pointer to queue control structure.
 * @param data Pointer to data to store read info.
 * @retval Operation result.
 */
bool Queue_ReadData( Queue_t *queue, void *data )
{
    bool status = false;

    if ( queue != NULL )
    {
        uint32_t baseAdd = ( uint32_t ) queue->Buffer;
        uint32_t actualAdd = 0;

        //Verifying if the queue has data available to be read.
        if ( !queue->Empty )
        {
            actualAdd = baseAdd + ( queue->Tail * queue->Size );

            //Copy info to data if needed.
            if ( data != NULL )
            {
                memcpy( data, ( void* ) actualAdd, queue->Size );
            }

            //Clearing data read from queue.
            memset( ( void* ) actualAdd, 0, queue->Size );
            queue->Tail++;      //next value to be read.

            if ( queue->Tail > queue->Elements - 1 ) 
            {   //Reseting read index.
                queue->Tail = 0;
            }
        
            if ( queue->Full ) 
            {   //Once data is read the queue is no longer full.
                queue->Full = !queue->Full;
            }

            //Verifying if the queue is empty with the last data read.
            if ( queue->Tail == queue->Head ) 
            {
                queue->Empty = true;
            }

            status = true;  //Succesfull operation.
        }        
    }

    return status;   
}

/**
 * @brief This function reads a single data from the queue without eliminating it.
 * For achieving this it copies and pastes size bytes of info from the peek element of the queue to the data.
 * 
 * @note Once the reading operation is done it increments peek by one.
 * @note The data read still exists in the queue.
 * 
 * @param queue Pointer to queue control structure.
 * @param data Pointer to data to store read info.
 * @retval Operation result.
 */
bool Queue_PeekData( Queue_t *queue, void *data )
{
    bool status = false;

    if ( ( queue != NULL ) && ( data != NULL ) )
    {
        uint32_t baseAdd = ( uint32_t ) queue->Buffer;
        uint32_t actualAdd = 0;

        //Verifying if the queue has data available to be read.
        if ( !queue->Empty )
        {
            actualAdd = baseAdd + ( queue->Peek * queue->Size );
            memcpy( data, ( void* ) actualAdd, queue->Size );

            queue->Peek++;      //next value to be read.

            if ( queue->Peek > queue->Elements - 1 ) 
            {   //Reseting peek index.
                queue->Peek = 0;
            }

            status = true;  //Succesfull operation.
        }        
    }

    return status;   
}

/**
 * @brief This function indicates if the queue is empty.
 * 
 * @param queue Pointer to queue control structure.
 * @retval Operation result.
 */
bool Queue_IsQueueEmpty( Queue_t *queue )
{
    bool status = false;

    if ( queue != NULL )
    {
        status = queue->Empty;
    }

    return status;
}

/**
 * @brief This function flushes the queue.
 * 
 * @param queue Pointer to queue control structure.
 */
void Queue_FlushQueue( Queue_t *queue )
{
    if ( queue != NULL )
    {   
        //Cleaning and restarting queue.
        memset( queue->Buffer, 0, queue->Elements * queue->Size );
        queue->Empty = true;
        queue->Full = false;
        queue->Head = 0;
        queue->Tail = 0;        
    }
}
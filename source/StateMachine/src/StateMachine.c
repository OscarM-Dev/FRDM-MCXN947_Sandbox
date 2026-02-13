/**
 * @file StateMachine.c
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This file contains the definition of the state machine related tools and functions.
 * 
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "StateMachine.h"

/*******************************************************************************
 * Private function prototypes.
 ******************************************************************************/
static void System_State1( System_State_Control_t *ctrl );
static void System_State2( System_State_Control_t *ctrl );
static void System_State3( System_State_Control_t *ctrl );
static void System_State4( System_State_Control_t *ctrl );
static void System_State5( System_State_Control_t *ctrl );
static void System_State6( System_State_Control_t *ctrl );
static void System_State7( System_State_Control_t *ctrl );
static void System_State8( System_State_Control_t *ctrl );
static void System_State9( System_State_Control_t *ctrl );

/*******************************************************************************
 * Public function definitions.
 ******************************************************************************/
/**
 * @brief This function initializes the state machine control structure.
 * 
 * @param ctrl Pointer to state machine control struct.
 * @retval Operation result.
 */
bool StateMachine_Init( System_State_Control_t *ctrl )
{
    bool result = false;

    if ( ctrl != NULL )
    {   
        void *state_addr[NUM_STATES] = { System_State1, System_State2, System_State3, System_State4, System_State5,
            System_State6, System_State7, System_State8, System_State9 }; 

       //Initialize parameters.
       for ( uint8_t i = 0; i < NUM_STATES; i++ )
       {
            ctrl->StateHandler[i] = state_addr[i];  
       }

       ctrl->CurrentState = SYSTEM_STATE_1_E;
       ctrl->StateNewCall = true;
       result = true;
    }

    return result; 
}

/**
 * @brief This function executes the state machine.
 * 
 * @param ctrl Pointer to state machine control struct.
 * @retval Operation result.
 */
bool StateMachine_Run( System_State_Control_t *ctrl )
{
    bool result = false;

    if ( ctrl != NULL )
    {
        ctrl->StateHandler[ctrl->CurrentState]( ctrl );
        result = true;
    }

    return result;
}

/*******************************************************************************
 * Private function definitions.
 ******************************************************************************/
/**
 * @brief State 1 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State1( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 2 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State2( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 3 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State3( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 4 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State4( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 5 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State5( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 6 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State6( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 7 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State7( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 8 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State8( System_State_Control_t *ctrl )
{

}

/**
 * @brief State 9 function.
 * 
 * @param ctrl Pointer to state machine control struct.
 */
static void System_State9( System_State_Control_t *ctrl )
{

}
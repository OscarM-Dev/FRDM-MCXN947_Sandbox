/**
 * @file StateMachine.h
 * @author Oscar Mercado, omercadorico@gmail.com
 * @brief This header contains the declaration of the state machine related tools and functions.
 *  
 */
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
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
#define NUM_STATES  8

/*******************************************************************************
 * Enums
 ******************************************************************************/
/**
 * @brief Enum for the different system states.
 * 
 */
typedef enum System_States
{
    SYSTEM_STATE_1_E,
    SYSTEM_STATE_2_E,
    SYSTEM_STATE_3_E,
    SYSTEM_STATE_4_E,
    SYSTEM_STATE_5_E,
    SYSTEM_STATE_6_E,
    SYSTEM_STATE_7_E,
    SYSTEM_STATE_8_E,
    SYSTEM_STATE_UNDEFINED_E
} System_States_t;

/*******************************************************************************
 * Typedefs
 ******************************************************************************/
typedef struct System_State_Control System_State_Control_t;   //Forward declaration of ctrl struct.
typedef void ( *SystemState ) ( System_State_Control_t * );     //Typedef for pointer to state function.


/*******************************************************************************
 * Stucts and Unions.
 ******************************************************************************/
/**
 * @brief Control struct for state machine.
 * 
 */
typedef struct System_State_Control
{
    SystemState StateHandler[NUM_STATES];   //Array of pointers to state functions.
    int8_t CurrentState;                   //Current state index.
    bool StateNewCall;                     //Flag for new state calls.
    bool Btn1Press;
    bool Btn2Press;
} System_State_Control_t;

/*******************************************************************************
 * Public function prototypes.
 ******************************************************************************/
bool StateMachine_Init( System_State_Control_t *ctrl );
bool StateMachine_Run( System_State_Control_t *ctrl );

#endif
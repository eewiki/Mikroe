/**
 * @file main.c
 * @brief DemoProject2 application.
 * 
 * # Description
 * This application horizontal scrolls the ECEDHA logo image on the screen.
 *
 * The demo application is composed of two sections :
 * 
 * ## Application Init 
 * Initializes the driver, sets the click default configuration and horizontal scrolls
 * the ECEDHA logo image on the screen.
 * 
 * ## Application Task  
 * Nothing.
 * 
 * \author Stefan Filipovic
 *
 */

#include "board.h"
#include "oledc.h"
#include "oledc_font.h"
#include "oledc_image.h"

// ------------------------------------------------------------------ VARIABLES

static oledc_t oledc;

// ------------------------------------------------------ APPLICATION FUNCTIONS

void application_init ( void )
{
    oledc_cfg_t oledc_cfg;

    //  Click initialization.

    oledc_cfg_setup( &oledc_cfg );
    OLEDC_MAP_MIKROBUS( oledc_cfg, MIKROBUS_1 );
    oledc_init( &oledc, &oledc_cfg );
    
    oledc_default_cfg( &oledc );
    oledc_fill_screen( &oledc, 0 );
    Delay_ms( 500 );
    
    oledc_image( &oledc, ECEDHA_bmp, 0, 0 ); 
    Delay_ms( 500 );
    oledc_horizontal_scroll( &oledc, 1, 0, 96, 1 );
    Delay_ms( 500 );
    oledc_write_command( &oledc, OLEDC_START_MOV );
    Delay_ms( 500 );
}

void application_task ( void )
{
    // Nothing to do here...
}

void main ( void )
{
    application_init( );

    for ( ; ; )
    {
        application_task( );
    }
}

